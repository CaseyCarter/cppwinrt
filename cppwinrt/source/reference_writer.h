#pragma once

#include "code_writer.h"

namespace cppwinrt
{
    struct reference_writer
    {
        reference_writer(
            std::string_view namespace_name,
            meta::namespace_types const& namespace_types,
            bool exclude_references = true
        ) :
            _namespace_name(namespace_name),
            _namespace_types(namespace_types),
            _exclude_references(exclude_references)
        {
            record();
        }

        bool types_found() const noexcept
        {
            return _types_found;
        }

        void write_forwards(output& out) const
        {
            write_forwards(out, _methods_forwards);
            write_forwards(out, _default_forwards);
        }

        void write_includes(output& out, std::string const& ext_h = ".h", std::string const& rel_path = "") const
        {
            write_includes(out, _method_namespaces, ext_h, rel_path);
            write_includes(out, _required_namespaces, ext_h, rel_path);
            if (ext_h != ".h")
            {
                write_projection_include(out, rel_path, _namespace_name, ext_h);
            }
        }

        void write_struct_includes(output& out, std::string const& ext_h = ".h", std::string const& rel_path = "") const
        {
            write_includes(out, _struct_namespaces, ext_h, rel_path);
        }

        void write_parent_include(output& out) const
        {
            meta::index_type const& index = meta::get_index();
            std::string parent_namespace = _namespace_name;
            auto last_dot = parent_namespace.find_last_of('.');
            if (last_dot == std::string::npos)
            {
                return;
            }
            parent_namespace = parent_namespace.substr(0, last_dot);
            if (index.find(parent_namespace) == index.end())
            {
                return;
            }
            write_projection_include(out, parent_namespace, ".h");
        }

        std::set<std::string> const& get_method_namespaces() const noexcept
        {
            return _method_namespaces;
        }

        std::set<std::string> const& get_required_namespaces() const noexcept
        {
            return _required_namespaces;
        }

    private:
        std::string _namespace_name;
        meta::namespace_types const& _namespace_types;
        bool _exclude_references;
        bool _types_found{};

        std::set<std::string> _method_namespaces;
        std::map<std::string, std::set<std::string>> _methods_forwards;

        std::set<std::string> _default_namespaces;
        std::map<std::string, std::set<std::string>> _default_forwards;

        std::set<std::string> _required_namespaces;
        std::map<std::string, std::set<std::string>> _required_forwards;

        std::set<std::string> _struct_namespaces;

        void record()
        {
            auto record_method_namespace = [&](meta::token const& token)
            {
                record_namespace(_method_namespaces, _methods_forwards, token);
            };

            for (meta::type const& type : get_projected_types(_exclude_references, _namespace_types.interfaces, _namespace_types.classes))
            {
                _types_found = true;

                for (auto& method : type.token.get_methods(record_method_namespace))
                {
                    unreferenced_parameter(method);
                }
            }

            for (meta::type const& type : get_projected_types(_exclude_references, _namespace_types.delegates))
            {
                _types_found = true;
                
                type.token.get_delegate(record_method_namespace);
            }

            for (meta::type const& type : get_projected_types(_exclude_references, _namespace_types.structs))
            {
                _types_found = true;

                for (auto& field : type.token.get_fields(record_method_namespace))
                {
                    // Record namespaces of struct field types
                    auto category = field.type.get_category();
                    if (category == ELEMENT_TYPE_VALUETYPE)
                    {
                        meta::token field_token = field.type.get_token();
                        std::string field_token_name = field_token.get_name();
                        if (!meta::is_foundation_type(field_token_name))
                        {
                            meta::type_category resolved_category{};
                            meta::find_type(field_token_name, &resolved_category);
                            if (resolved_category == meta::type_category::struct_v)
                            {
                                std::string const token_name = field_token.get_definition().get_name();
                                size_t ns_end = token_name.find_last_of('.');
                                std::string token_namespace = token_name.substr(0, ns_end);
                                _struct_namespaces.emplace(std::move(token_namespace));
                            }
                        }
                    }
                }
            }

            auto enums = get_projected_types(_exclude_references, _namespace_types.enums);
            if(enums.begin() != enums.end())
            {
                _types_found = true;
            }

            for (meta::type const& type : get_projected_types(_exclude_references, _namespace_types.classes))
            {
                meta::token default_interface = type.token.get_default();

                if (default_interface)
                {
                    record_namespace(_default_namespaces, _default_forwards, default_interface);
                }

                for (auto& required_interface : type.token.get_class_required_excluding_default())
                {
                    record_namespace(_required_namespaces, _required_forwards, required_interface.token);
                }
            }

            for (meta::type const& type : get_projected_types(_exclude_references, _namespace_types.interfaces))
            {
                for (auto& required_interface : type.token.get_interface_required())
                {
                    record_namespace(_required_namespaces, _required_forwards, required_interface.token);
                }
            }
        }

        void record_namespace(
            std::set<std::string>& ref_set,
            std::map<std::string, std::set<std::string>>& forwards,
            meta::token const& token)
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

            if (token_namespace != _namespace_name)
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

                if (_method_namespaces.find(token_namespace) == end(_method_namespaces))
                {
                    ref_set.emplace(std::move(token_namespace));
                }
            }
        }

        static void write_forwards(output& out, std::map<std::string, std::set<std::string>> const& externals) 
        {
            for (auto& external : externals)
            {
                if (!external.second.empty())
                {
                    out.write_meta_namespace(external.first);
                    out.write('\n');
                    for (auto& forward_type : external.second)
                    {
                        out.write("@;\n", forward_type);
                    }
                    out.write_close_namespace();
                }
            }
        }

        static void write_includes(output& out, std::set<std::string> const& refs, std::string const& ext_h, std::string const& rel_path = "") 
        {
            for (auto& ref : refs)
            {
                write_projection_include(out, rel_path, ref, ext_h);
            }
        }
    };
}