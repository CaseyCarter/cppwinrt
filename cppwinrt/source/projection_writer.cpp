#include "pch.h"
#include "projection_writer.h"
#include "code_writer.h"
#include "reference_writer.h"
#include "component_writer.h"
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
        struct projection_paths
        {
            path _root;
            path _public;
            path _impl;
            path _tests;

            projection_paths() :
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

        struct namespace_recorder
        {
            std::set<std::string> _complex_namespaces;
            std::set<std::string> _projected_namespaces;
            winrt::impl::mutex _lock;

            void record_complex_struct_namespace(std::string const& ns)
            {
                lock_guard const guard(_lock);
                _complex_namespaces.emplace(ns);
            }

            void record_projected_namespace(std::string const& ns)
            {
                lock_guard const guard(_lock);
                _projected_namespaces.emplace(ns);
            }

            void write_complex_struct_header(projection_paths const& paths)
            {
                output out;

                // if componennt, intersect recorded headers with complex struct headers (exclude platform),
                // and #include complex_structs.h from platform projection
                if (settings::component)
                {
                    for (auto iter = _complex_namespaces.begin(); iter != _complex_namespaces.end(); ++iter)
                    {
                        if (std::find(_projected_namespaces.begin(), _projected_namespaces.end(), *iter) == _projected_namespaces.end())
                        {
                            _complex_namespaces.erase(iter);
                        }
                    }
                }

                for (auto& ns : _complex_namespaces)
                {
                    write_projection_include(out, "impl/", ns, ".0.h");
                }

                out.save_as(paths._impl / (get_complex_struct_name() + ".h"));
            }

            static void write_complex_struct_includes(output& out)
            {
                write_projection_include(out, "impl/complex_structs.h");
                if (settings::component)
                {
                    write_projection_include(out, "impl/", get_complex_struct_name(), ".h");
                }
            }

            static std::string get_complex_struct_name()
            {
                return settings::component ? 
                    settings::component_name + "_complex_structs" : "complex_structs";
            }
        };

        void create_base_header(path const& base_path)
        {
            output out;
            write_base_header(out);
            out.save_as(base_path / "base.h");
        }

        void create_natvis(path const& base_path)
        {
            std::string natvis_name(settings::component ? settings::component_name : "cppwinrt");
            if (natvis_name.empty())
            {
                return;
            }
            output out;
            write_natvis(out);
            out.save_as(base_path / (natvis_name + ".natvis"));
        }

        void ReportMetadataError(std::string_view context)
        {
            try
            {
                throw;
            }
            catch (meta::meta_error const& e)
            {
                print_error("    The %s projection is incomplete. A required reference may be missing.\n", context.data());
                throw std::exception(e.message.c_str());
            }
        }

        IAsyncAction create_base_files(projection_paths const& paths)
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
                ReportMetadataError("base");
            }
        }

        void create_projected_namespace(
            std::string const& namespace_name,
            meta::namespace_types const& namespace_types,
            projection_paths const& paths,
            namespace_recorder& namespace_recorder)
        {
            try
            {
                reference_writer ref_writer(namespace_name, namespace_types);
                if (!ref_writer.types_found())
                {
                    return;
                }

                if (settings::create_tests)
                {
                    output out;
                    write_test(out, namespace_name, namespace_types);
                    out.save_as(paths._tests / (namespace_name + ".cpp"));
                }

                static char const * forward_ext = ".0.h";
                static char const * interface_ext = ".1.h";
                static char const * definition_ext = ".2.h";

                std::string forward_h = namespace_name + forward_ext;
                std::string interface_h = namespace_name + interface_ext;
                std::string definition_h = namespace_name + definition_ext;

                // internal and external forward declarations, consume/abi definitions
                {
                    output out;
                    write_logo(out);

                    ref_writer.write_forwards(out);
                    out.write_meta_namespace(namespace_name);
                    write_forwards(out, namespace_types);
                    out.write_close_namespace();
                    out.write_impl_namespace();
                    out.write('\n');
                    write_categories(out, namespace_types);
                    write_names(out, namespace_types);
                    write_guids(out, namespace_types);
                    write_default_interfaces(out, namespace_types);
                    if (write_struct_abi(out, namespace_types))
                    {
                        namespace_recorder.record_complex_struct_namespace(namespace_name);
                    }
                    write_consume(out, namespace_types);
                    write_abi(out, namespace_types);
                    out.write_close_namespace();
                    out.save_as(paths._impl / forward_h);
                }

                // inteface definitions, which reference abi/consume definitions, potentially circularly
                {
                    output out;
                    write_logo(out);
                    ref_writer.write_includes(out, forward_ext, "impl/");
                    out.write_meta_namespace(namespace_name);
                    write_interface_definitions(out, namespace_types);
                    out.write_close_namespace();
                    out.save_as(paths._impl / interface_h);
                }

                // class definitions, which reference interface definitions, potentially circularly
                {
                    output out;
                    write_logo(out);
                    ref_writer.write_includes(out, interface_ext, "impl/");
                    ref_writer.write_struct_includes(out, definition_ext, "impl/");
                    out.write_meta_namespace(namespace_name);
                    write_delegate_definitions(out, namespace_types);
                    write_struct_definitions(out, namespace_types);
                    write_class_definitions(out, namespace_types);
                    write_interface_overrides(out, namespace_types);
                    out.write_close_namespace();
                    out.save_as(paths._impl / definition_h);
                }

                // implementations, which require full class definitions
                {
                    output out;
                    write_logo(out);
                    write_projection_include(out, "base.h");
                    if (settings::skip_base_headers)
                    {
                        write_version_assert(out);
                    }

                    if (!starts_with(namespace_name, "Windows.Foundation"))
                    {
                        write_projection_include(out, "Windows.Foundation.h");
                        write_projection_include(out, "Windows.Foundation.Collections.h");
                    }

                    namespace_recorder.write_complex_struct_includes(out);
                    write_warning_push(out);
                    ref_writer.write_includes(out, definition_ext, "impl/");
                    ref_writer.write_parent_include(out);
                    out.write_impl_namespace();
                    write_interface_member_definitions(out, namespace_types);
                    write_delegate_produce(out, namespace_types);
                    write_produce(out, namespace_types);
                    out.write_close_namespace();
                    out.write_meta_namespace(namespace_name);
                    write_class_member_definitions(out, namespace_types);
                    write_delegate_member_definitions(out, namespace_types);
                    write_interface_override_methods(out, namespace_types);
                    write_class_overrides(out, namespace_types);
                    out.write_close_namespace();

                    write_namespace_special(out, namespace_name);

                    out.write_std_namespace();
                    write_std_hashes(out, namespace_types);
                    out.write_close_namespace();

                    write_warning_pop(out);
                    out.save_as(paths._public / (namespace_name + ".h"));
                    namespace_recorder.record_projected_namespace(namespace_name);
                }
            }
            catch (...)
            {
                ReportMetadataError(namespace_name);
            }
        }

        IAsyncAction create_projected_namespace_async(
            std::string const& namespace_name,
            meta::namespace_types const& namespace_types,
            projection_paths const& paths,
            namespace_recorder& namespace_recorder)
        {
            co_await resume_background();

            create_projected_namespace(namespace_name, namespace_types, paths, namespace_recorder);
        }

        template <typename Collection>
        IAsyncAction wait_all(Collection & collection)
        {
            for (auto&& item : collection)
            {
                co_await item;
            }
        }

        void write_module()
        {
            std::string module_name(settings::component ? settings::component_name : "winrt");
            if (module_name.empty())
            {
                return;
            }

            output out;
            out.write("module %;\n", module_name);
            out.write("#define WINRT_EXPORT export\n\n");

            meta::index_type const& index = meta::get_index();

            for (meta::index_pair const& item : index)
            {
                if (item.second.has_projected_types())
                {
                    write_projection_include(out, item.first, ".h");
                }
            }

            out.save_as(settings::output / ("winrt\\" + module_name + ".ixx") );
        }
    }

    void write_projection()
    {
        projection_paths paths;

        meta::index_type const& index = meta::get_index();
        size_t num_writers = index.size() + 1;

        namespace_recorder namespace_recorder;

        std::vector<IAsyncAction> writers(num_writers);
        num_writers = 0;
        writers[num_writers++] = create_base_files(paths);
        for (auto&& item : index)
        {
            writers[num_writers++] = create_projected_namespace_async(item.first, item.second, paths, namespace_recorder);
        }
        writers.resize(num_writers);
        wait_all(writers).get();

        namespace_recorder.write_complex_struct_header(paths);
        write_module();

        if (settings::create_tests)
        {
            write_tests();
        }

        if (settings::component)
        {
            write_component_headers(namespace_recorder._projected_namespaces);
        }
    }
}
