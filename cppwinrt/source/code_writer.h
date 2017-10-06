#pragma once

#include "text_writer.h"
#include "winmd_reader.h"

namespace cppwinrt
{
    struct reference_writer;

    void write_logo(output& out);
    void write_warning_push(output& out);
    void write_warning_pop(output& out);
    void write_base_header(output& out);

    void write_names(output& out, meta::namespace_types const& types);
    void write_categories(output& out, meta::namespace_types const& types);
    void write_guids(output& out, meta::namespace_types const& types);
    void write_default_interfaces(output& out, meta::namespace_types const& types);

    void write_forwards(output& out, meta::namespace_types const& types);
    void write_enum_flags(output& out, meta::namespace_types const& types);
    void write_abi(output& out, meta::namespace_types const& types);
    void write_consume(output& out, meta::namespace_types const& types);
    void write_produce(output& out, meta::namespace_types const& types);

    void write_interface_definitions(output& out, meta::namespace_types const& types);
    void write_delegate_definitions(output& out, meta::namespace_types const& types);
    void write_class_definitions(output& out, meta::namespace_types const& types);
    void write_struct_definitions(output& out, meta::namespace_types const& types);
    void write_struct_type_traits(output& out, meta::namespace_types const& types);
    void write_interface_member_definitions(output& out, meta::namespace_types const& types);
    void write_class_member_definitions(output& out, meta::namespace_types const& types);

    void write_interface_overrides(output& out, meta::namespace_types const& types);
    void write_interface_override_methods(output& out, meta::namespace_types const& types);
    void write_class_overrides(output& out, meta::namespace_types const& types);

    void write_delegate_produce(output& out, meta::namespace_types const& types);
    void write_delegate_member_definitions(output& out, meta::namespace_types const& types);
    
    void write_std_hashes(output& out, meta::namespace_types const& types);

    void write_test(output& out, std::string const& namespace_name, meta::namespace_types const& types);
    void write_tests();

    // These two should not be needing the types list as it should go into write_component_class_generated_header
    void write_component_header(std::vector<meta::type const*> const& types);
    void write_component_source(std::vector<meta::type const*> const& types);
    
    void write_component_project(std::vector<meta::type const*> const& types);
    void write_component_project_filters(std::vector<meta::type const*> const& types);
    void write_component_def();
    void write_component_pch_source();
    void write_component_pch_header(std::set<std::string> const& ref_namespaces, std::set<std::string> const& projected_namespaces);

    void write_component_class_generated_header(meta::type const& type, reference_writer const& ref_writer);
    void write_component_class_header(meta::type const& type);
    void write_component_class_source(meta::type const& type);

    void write_natvis(output& out);
    void write_namespace_special(output& out, std::string const& namespace_name);

    template <typename ... Args>
    void write_projection_include(output& out, Args const& ... include)
    {
        out.write("#include %winrt/", settings::brackets ? '<' : '\"');
        int ignored[] = { (out.write(include), 0) ... }; ignored;
        out.write("%\n", settings::brackets ? '>' : '\"');
    }

    void write_version_assert(output& out);
}
