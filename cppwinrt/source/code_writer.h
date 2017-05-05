#pragma once

#include "text_writer.h"
#include "winmd_reader.h"

namespace cppwinrt
{
    void write_projection(output& out);
    void write_logo(output& out);
    void write_winrt_namespace_begin(output& out);
    void write_winrt_namespace_end(output& out);
    void write_base_header(output& out);

    void write_names(output& out, std::vector<meta::type> const& types);
    void write_categories(output& out, std::vector<meta::type> const& types);
    void write_guids(output& out, std::vector<meta::type> const& types);
    void write_default_interfaces(output& out, std::vector<meta::type> const& types);

    void write_forwards(output& out, std::vector<meta::type> const& types);
    void write_abi(output& out, std::vector<meta::type> const& types);
    bool write_struct_abi(output& out, std::vector<meta::type> const& types);
    void write_consume(output& out, std::vector<meta::type> const& types);
    void write_produce(output& out, std::vector<meta::type> const& types);

    void write_interface_definitions(output& out, std::vector<meta::type> const& types);
    void write_delegate_definitions(output& out, std::vector<meta::type> const& types);
    void write_class_definitions(output& out, std::vector<meta::type> const& types);
    void write_struct_definitions(output& out, std::vector<meta::type> const& types);
    void write_interface_member_definitions(output& out, std::vector<meta::type> const& types);
    void write_class_member_definitions(output& out, std::vector<meta::type> const& types);

    void write_interface_overrides(output& out, std::vector<meta::type> const& types);
    void write_interface_override_methods(output& out, std::vector<meta::type> const& types);
    void write_class_overrides(output& out, std::vector<meta::type> const& types);

    void write_delegate_produce(output& out, std::vector<meta::type> const& types);
    void write_delegate_member_definitions(output& out, std::vector<meta::type> const& types);
    
    void write_std_hashes(output& out, std::vector<meta::type> const& types);
    
    void write_include(output& out, std::string const& include);

    void write_test(output& out, std::string const& namespace_name, std::vector<meta::type> const& types);

    void write_component_header(std::vector<meta::type const*> const& types);
    void write_component_source(std::vector<meta::type const*> const& types);
    void write_component_class_header(meta::type const& type);
    void write_component_class_source(meta::type const& type);

    void write_warning_push(output& out);
    void write_warning_pop(output& out);

    void write_natvis(output& out, std::vector<meta::type const*> const& types);
    void write_namespace_special(output& out, std::string const& namespace_name);
}
