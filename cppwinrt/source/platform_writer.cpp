#include "pch.h"
#include "platform_writer.h"
#include "code_writer.h"
#include "winmd_reader.h"
#include "settings.h"
#include "strings.h"

using namespace std::experimental::filesystem;
using namespace winrt;
using namespace winrt::impl;
using namespace winrt::Windows::Foundation;

namespace cppwinrt
{
    namespace
    {
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
                if (settings::skip_base_headers)
                {
                    if (!_headers.empty())
                    {
                        printf("Complex struct defined in non-reference metadata.  Projection may be incorrect.\n");
                    }
                    return;
                }

                output out;
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
            output out;
            write_base_header(out);
            path file_path = base_path / "base.h";
            out.save_as(file_path.string());
        }

        void create_natvis(path const& base_path)
        {
            output out;
            write_natvis(out);
            path file_path = base_path / "cppwinrt.natvis";
            out.save_as(file_path.string());
        }

        void ReportMetadataError()
        {
            try
            {
                throw;
            }
            catch (winrt::hresult_error const& e)
            {
                printf(strings::print_hresult_error, e.code(), e.message().c_str());
            }
            catch (std::exception const& e)
            {
                printf(strings::print_exception, E_FAIL, e.what());
            }
            catch (meta::meta_error const& e)
            {
                printf(strings::print_exception, E_INVALIDARG, e.message.c_str());
                printf("    The projection is incomplete. A required reference may be missing.\n");
            }
        }

        IAsyncAction create_base_files(platform_paths const& paths)
        {
            co_await resume_background();

            try
            {
                if (!settings::skip_base_headers)
                {
                    create_base_header(paths._public);
                }

                if (settings::create_natvis)
                {
                    create_natvis(paths._public);
                }
            }
            catch (...)
            {
                ReportMetadataError();
            }
        }

        void create_namespace_headers(
            std::string const& namespace_name,
            meta::namespace_types const& namespace_types,
            platform_paths const& paths,
            complex_structs& complex_structs)
        {
            try
            {
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
                    if (token.is_type_spec())
                    {
                        std::string const token_name = token.get_definition().get_name();
                        size_t ns_end = token_name.find_last_of('.');
                        std::string token_namespace = token_name.substr(0, ns_end);
                        ref_set.emplace(std::move(token_namespace));
                        return;
                    }

                    std::string const token_name = token.get_name();

                    if (meta::is_foundation_type(token_name))
                    {
                        return;
                    }

                    size_t ns_end = token_name.find_last_of('.');
                    auto token_namespace = token_name.substr(0, ns_end);

                    if (token_namespace != namespace_name)
                    {
                        ns_end = token_name.find_last_of('.');
                        std::string forward_ns = token_name.substr(0, ns_end);
                        std::string forward_type = token_name.substr(ns_end + 1);
                        meta::type_category resolved_category{};
                        meta::type const* resolved = meta::find_type(token_name, &resolved_category);
                        std::string forward_decl;

                        if (resolved_category == meta::type_category::enum_v)
                        {
                            forward_decl = "enum class " + forward_type;

                            if (resolved->token.is_flags())
                            {
                                forward_decl += " : unsigned";
                            }
                        }
                        else
                        {
                            forward_decl = "struct " + forward_type;
                        }

                        forwards[forward_ns].emplace(forward_decl);

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

                for (meta::type const & type : get_unfiltered_types(namespace_types.interfaces, namespace_types.classes))
                {
                    types_found = true;

                    for (auto& method : type.token.get_methods(record_method_namespace))
                    {
                        method;
                    }
                }

                for (meta::type const & type : get_unfiltered_types(namespace_types.delegates))
                {
                    types_found = true;
                    type.token.get_delegate(record_method_namespace);
                }

                for (meta::type const & type : get_unfiltered_types(namespace_types.structs))
                {
                    types_found = true;

                    for (auto& field : type.token.get_fields(record_struct_namespace))
                    {
                        field;
                    }
                }

                for (meta::type const & type : get_unfiltered_types(namespace_types.enums))
                {
                    type;
                    types_found = true;
                    break;
                }

                if (!types_found)
                {
                    return;
                }

                for (meta::type const & type : get_unfiltered_types(namespace_types.classes))
                {
                    meta::token default_interface = type.token.get_default();

                    if (default_interface)
                    {
                        record_namespace(default_namespaces, default_forwards, default_interface);
                    }

                    for (auto& required_interface : type.token.get_class_required_excluding_default())
                    {
                        record_namespace(required_namespaces, required_forwards, required_interface.token);
                    }
                }

                for (meta::type const & type : get_unfiltered_types(namespace_types.interfaces))
                {
                    for (auto& required_interface : type.token.get_interface_required())
                    {
                        record_namespace(required_namespaces, required_forwards, required_interface.token);
                    }
                }

                if (settings::create_tests)
                {
                    output out;
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
                        out.write("namespace @ {\n", external.first);
                        for (auto& forward_type : external.second)
                        {
                            out.write("@;\n", forward_type);
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
                    output out;
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
                    output out;
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
                    output out;
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
                    output out;
                    write_logo(out);
                    out.write("#include \"base.h\"\n");

                    if (!starts_with(namespace_name, "Windows.Foundation"))
                    {
                        out.write("#include \"Windows.Foundation.h\"\n");
                        out.write("#include \"Windows.Foundation.Collections.h\"\n");
                    }

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
            catch (...)
            {
                ReportMetadataError();
            }
        }

        IAsyncAction create_namespace_headers_async(
            std::string const& namespace_name,
            meta::namespace_types const& namespace_types,
            platform_paths const& paths,
            complex_structs& complex_structs)
        {
            co_await resume_background();

            create_namespace_headers(namespace_name, namespace_types, paths, complex_structs);
        }

        template <typename Collection>
        static IAsyncAction wait_all(Collection & collection)
        {
            for (auto&& item : collection)
            {
                co_await item;
            }
        }
    }

    void write_platform()
    {
        platform_paths paths;

        meta::index_type const& index = meta::get_index();
        size_t num_writers = index.size() + 1;

        complex_structs complex_structs;

        std::vector<IAsyncAction> writers(num_writers);
        num_writers = 0;
        writers[num_writers++] = create_base_files(paths);
        for (auto&& item : index)
        {
            writers[num_writers++] = create_namespace_headers_async(item.first, item.second, paths, complex_structs);
        }
        writers.resize(num_writers);

        wait_all(writers).get();

        complex_structs.write_header(paths);

        if (settings::create_tests)
        {
            write_tests();
        }
    }
}
