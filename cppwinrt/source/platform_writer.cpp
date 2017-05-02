#include "pch.h"
#include "platform_writer.h"
#include "code_writer.h"
#include "winmd_reader.h"
#include "settings.h"
#include <set>

using namespace std::experimental;
using namespace std::experimental::filesystem;
using namespace std::experimental::filesystem::v1;
using namespace cppwinrt::meta;
using namespace winrt::Windows::Foundation;
using namespace winrt;
using namespace winrt::impl;

namespace cppwinrt
{
    static constexpr size_t split_header_capacity{ 4 * 1024 * 1000 };

    struct platform_paths
    {
        path _root;
        path _public;
        path _impl;
        path _tests;

        platform_paths() :
            _root(settings::output),
            _public(_root / "winrt"),
            _impl(_public / "impl"),
            _tests(_root / "CompileTests")
        {
            create_directories(_impl);
            if (settings::create_tests)
            {
                create_directories(_tests);
            }
        }
    };

    struct complex_structs
    {
        std::set<std::string> _headers;
        lock _headers_lock;

        void record_header(std::string const& header)
        {
            lock_guard const guard(_headers_lock);
            _headers.emplace(header);
        }

        void write_header(platform_paths const& paths)
        {
            output out(split_header_capacity);
            for (auto& header : _headers)
            {
                out.write("#include \"%\"\n", header);
            }
            path base_path = paths._impl / "complex_structs.h";
            out.save_as(base_path.string());
        }
    };

    void create_base_header(path const& base_path)
    {
        output out(split_header_capacity);
        write_base_header(out);
        path file_path = base_path / "base.h";
        out.save_as(file_path.string());
    }

    void create_ppl_header(path const& base_path)
    {
        output out(split_header_capacity);
        write_ppl_header(out);
        path file_path = base_path / "ppl.h";
        out.save_as(file_path.string());
    }
    
    IAsyncAction create_base_headers(platform_paths const& paths)
    {
        co_await resume_background();

        create_base_header(paths._public);
        create_ppl_header(paths._public);
    }

    IAsyncAction create_namespace_headers(
        std::string const& namespace_name,
        std::vector<cppwinrt::meta::type> const& namespace_types,
        platform_paths const& paths,
        complex_structs& complex_structs)
    {
        co_await resume_background();

        std::set<std::string> method_namespaces;
        std::map<std::string, std::set<std::string>> methods_forwards;

        std::set<std::string> default_namespaces;
        std::map<std::string, std::set<std::string>> default_forwards;

        std::set<std::string> required_namespaces;
        std::map<std::string, std::set<std::string>> required_forwards;

        auto record_namespace = [&](std::set<std::string>& ref_set,
            std::map<std::string, std::set<std::string>>& forwards,
            meta::token const & token)
        {
            if (!token.is_type_def() && !token.is_type_ref())
            {
                return;
            }
            auto token_name = token.get_name(true);
            if (token_name.find("Windows.") == std::string::npos)
            {
                return;
            }
            size_t ns_end = token_name.find_last_of(L'.');
            auto token_namespace = token_name.substr(0, ns_end);
            if (token_namespace != namespace_name)
            {
                if (!meta::is_foundation_type(token_name) && (token_name.find('`') == std::string::npos))
                {
                    auto forward = token.get_name();
                    ns_end = forward.find_last_of(L':');
                    std::string forward_ns = forward.substr(0, ns_end - 1);
                    std::string forward_type = forward.substr(ns_end + 1);
                    type const* resolved = meta::resolve(token_name);
                    std::string forward_decl;
                    if (resolved->category() == meta::type_category::enum_v)
                    {
                        forward_decl = "enum class " + forward_type;
                        if (resolved->token().has_attribute(L"System.FlagsAttribute"))
                        {
                            forward_decl += " : unsigned";
                        }
                    }
                    else
                    {
                        forward_decl = "struct " + forward_type;
                    }
                    forwards[forward_ns].emplace(forward_decl);
                }
                if (method_namespaces.find(token_namespace) == end(method_namespaces))
                {
                    ref_set.emplace(std::move(token_namespace));
                }
            }
        };

        auto record_method_namespace = [&](meta::token const & token)
        {
            record_namespace(method_namespaces, methods_forwards, token);
        };

        auto record_struct_namespace = [&](meta::token const & token)
        {
            record_namespace(method_namespaces, methods_forwards, token);
        };

        method_namespaces.insert(namespace_name);
        bool types_found{};
        for (meta::type const & type : namespace_types)
        {
            if (type.is_filtered())
            {
                continue;
            }
            types_found = true;
            if (type.is_class() || type.is_interface())
            {
                for (auto& method : type.token().enum_methods(record_method_namespace))
                {
                    method;
                }
            }
            else if (type.is_delegate())
            {
                type.token().get_delegate(record_method_namespace);
            }
            else if (type.is_struct())
            {
                for (auto& field : type.token().enum_fields(record_struct_namespace))
                {
                    field;
                }
            }
        }
        if (!types_found)
        {
            return;
        }
        for (meta::type const & type : namespace_types)
        {
            if (type.is_filtered())
            {
                continue;
            }
            if (type.is_class() || type.is_interface())
            {
                token default_interface = type.token().find_default_interface();
                if (default_interface)
                {
                    record_namespace(default_namespaces, default_forwards, default_interface);
                }
                for (auto& required_interface : type.token().enum_required_interfaces(true))
                {
                    record_namespace(required_namespaces, required_forwards, required_interface);
                }
            }
        }

        if (settings::create_tests)
        {
            output out(split_header_capacity);
            write_test(out, namespace_name, namespace_types);
            path test_path = paths._tests / (namespace_name + ".cpp");
            out.save_as(test_path.string());
        }

        auto write_includes = [](output& out, std::set<std::string> const & refs, std::string const & ext_h, std::string const & rel_path = "")
        {
            for (auto& ref : refs)
            {
                write_include(out, rel_path + ref + ext_h);
            }
        };

        auto write_external_forwards = [](output& out, std::map<std::string, std::set<std::string>>& externals)
        {
            for (auto& external : externals)
            {
                out.write("namespace % {\n", external.first);
                for (auto& forward_type : external.second)
                {
                    out.write("%;\n", forward_type);
                }
                out.write("}\n");
            }
        };

        auto write_ancestor_includes = [](output& out, std::string const& namespace_name)
        {
            meta::index_type const& index = meta::get_index();
            std::string parent_namespace = namespace_name;
            while (true)
            {
                auto last_dot = parent_namespace.find_last_of('.');
                if (last_dot == std::string::npos)
                {
                    break;
                }
                parent_namespace = parent_namespace.substr(0, last_dot);
                if (index.find(parent_namespace) == index.end())
                {
                    break;
                }
                write_include(out, parent_namespace + ".h");
            }
        };

        static char const * forward_ext = ".0.h";
        static char const * interface_ext = ".1.h";
        static char const * definition_ext = ".2.h";

        std::string forward_h = namespace_name + forward_ext;
        std::string interface_h = namespace_name + interface_ext;
        std::string definition_h = namespace_name + definition_ext;
        std::string namespace_h = namespace_name + ".h";

        // internal and external forward declarations, consume/abi definitions
        {
            output out(split_header_capacity);
            write_logo(out);

            write_winrt_namespace_begin(out);
            write_external_forwards(out, methods_forwards);
            write_external_forwards(out, default_forwards);
            out.write_namespace(namespace_name);
            write_forwards(out, namespace_types);
            out.write_namespace("impl");
            write_categories(out, namespace_types);
            write_names(out, namespace_types);
            write_guids(out, namespace_types);
            write_default_interfaces(out, namespace_types);
            if (write_struct_abi(out, namespace_types))
            {
                complex_structs.record_header(forward_h);
            }
            write_consume(out, namespace_types);
            write_abi(out, namespace_types);
            write_winrt_namespace_end(out);
            path forward_path = paths._impl / forward_h;
            out.save_as(forward_path.string());
        }

        // inteface definitions, which reference abi/consume definitions, potentially circularly
        {
            output out(split_header_capacity);
            write_logo(out);
            write_includes(out, method_namespaces, forward_ext);
            write_includes(out, required_namespaces, forward_ext);
            write_winrt_namespace_begin(out);
            out.write_namespace(namespace_name);
            write_interface_definitions(out, namespace_types);
            write_winrt_namespace_end(out);
            path interface_path = paths._impl / interface_h;
            out.save_as(interface_path.string());
        }

        // class definitions, which reference interface definitions, potentially circularly
        {
            output out(split_header_capacity);
            write_logo(out);
            write_includes(out, method_namespaces, interface_ext);
            write_includes(out, required_namespaces, interface_ext);
            //write_includes(out, struct_namespaces, definition_ext);
            write_winrt_namespace_begin(out);
            out.write_namespace(namespace_name);
            write_delegate_definitions(out, namespace_types);
            write_struct_definitions(out, namespace_types);
            write_class_definitions(out, namespace_types);
            write_interface_overrides(out, namespace_types);
            out.write_namespace("impl");
            write_winrt_namespace_end(out);
            path interface_path = paths._impl / definition_h;
            out.save_as(interface_path.string());
        }

        // implementations, which require full class definitions
        {
            output out(split_header_capacity);
            write_logo(out);
            out.write("#include \"base.h\"\n");
            out.write("#include \"impl\\complex_structs.h\"\n");
            write_warning_push(out);
            write_includes(out, method_namespaces, definition_ext, std::string("impl\\"));
            write_ancestor_includes(out, namespace_name);
            write_winrt_namespace_begin(out);
            out.write_namespace("impl");
            write_interface_member_definitions(out, namespace_types);
            write_delegate_produce(out, namespace_types);
            write_produce(out, namespace_types);
            out.write_namespace(namespace_name);
            write_class_member_definitions(out, namespace_types);
            write_delegate_member_definitions(out, namespace_types);
            write_interface_override_methods(out, namespace_types);
            write_class_overrides(out, namespace_types);
            write_winrt_namespace_end(out);
            
            write_namespace_special(out, namespace_name);
            
            out.write_namespace("std");
            write_std_hashes(out, namespace_types);
            out.write_namespace();

            write_warning_pop(out);
            path namespace_path = paths._public / (namespace_name + ".h");
            out.save_as(namespace_path.string());
        }
    }

    template <typename Collection>
    static IAsyncAction wait_all(Collection & collection)
    {
        for (auto&& item : collection)
        {
            co_await item;
        }
    }

    void write_single_header_platform()
    {
        path sdk_path = settings::output;
        sdk_path /= "sdk.h";
        output sdk;
        write_projection(sdk);
        sdk.save_as(sdk_path.string());

        create_base_header(settings::output);
        create_ppl_header(settings::output);
    }

    void write_multi_header_platform()
    {
        platform_paths paths;

        meta::index_type const& index = meta::get_index();
        size_t num_writers = index.size() + 1;

        complex_structs complex_structs;

        std::vector<IAsyncAction> writers(num_writers);
        num_writers = 0;
        writers[num_writers++] = create_base_headers(paths);
        for (auto&& item : index)
        {
            writers[num_writers++] = create_namespace_headers(item.first, item.second, paths, complex_structs);
        }
        writers.resize(num_writers);

        wait_all(writers).get();

        complex_structs.write_header(paths);
    }

    void write_platform()
    {
        if (settings::single_header)
        {
            write_single_header_platform();
        }
        else
        {
            write_multi_header_platform();
        }
    }
}
