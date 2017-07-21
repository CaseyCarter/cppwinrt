#include "pch.h"
#include "code_writer.h"
#include "reference_writer.h"
#include "version.h"
#include "strings.h"
#include "settings.h"

using namespace std::experimental::filesystem;

namespace cppwinrt
{
    namespace
    {
        static std::vector<std::string> const empty_generic_params{};

        bool is_event_method(meta::method const& method)
        {
            if (method.is_special())
            {
                return starts_with(method.raw_name, "add_");
            }

            return false;
        }

        bool is_get_accessor(meta::method const& method)
        {
            if (method.is_special())
            {
                return starts_with(method.raw_name, "get_");
            }

            return false;
        }

        bool is_put_accessor(meta::method const& method)
        {
            if (method.is_special())
            {
                return starts_with(method.raw_name, "put_");
            }

            return false;
        }

        std::string get_impl_name(std::string_view name)
        {
            std::string result;

            for (char c : name)
            {
                if (c == '.')
                {
                    result += "_";
                }
                else
                {
                    result += c;
                }
            }

            return result;
        }

        void write_deprecated(output& out, meta::token const token)
        {
            std::string value;

            if (token.get_attribute_string(L"Windows.Foundation.Metadata.DeprecatedAttribute", value))
            {
                out.write("[[deprecated(\"%\")]] ", value);
            }
        }

        void write_enumerators(output& out, meta::token const token)
        {
            for (meta::enumerator const& enumerator : token.get_enumerators())
            {
                out.write("    % %= %,\n",
                    enumerator.name,
                    bind_output(write_deprecated, enumerator.token),
                    enumerator.value);
            }
        }

        void write_enumerators_flag(output& out, meta::token const token)
        {
            for (meta::enumerator const& enumerator : token.get_enumerators())
            {
                out.write("    % %= %,\n",
                    enumerator.name,
                    bind_output(write_deprecated, enumerator.token),
                    static_cast<uint32_t>(enumerator.value));
            }
        }

        void write_enumeration(output& out, meta::type const& type)
        {
            out.write(strings::write_enumeration,
                bind_output(write_deprecated, type.token),
                type.name(),
                bind_output(write_enumerators, type.token));
        }

        void write_enumeration_flag(output& out, meta::type const& type)
        {
            out.write(strings::write_enumeration_flag,
                bind_output(write_deprecated, type.token),
                type.name(),
                bind_output(write_enumerators_flag, type.token),
                type.name());
        }

        void write_enum(output& out, meta::type const& type)
        {
            if (type.token.is_flags())
            {
                write_enumeration_flag(out, type);
            }
            else
            {
                write_enumeration(out, type);
            }
        }

        void write_default_interface(output& out, meta::type const& type)
        {
            meta::token default_interface = type.token.get_default();

            if (default_interface)
            {
                out.write("template <> struct default_interface<@>{ using type = @; };\n",
                    type.full_name(),
                    default_interface.get_name());
            }
        }

        bool is_complex_struct(std::vector<meta::field> const & fields)
        {
            for (meta::field const& field : fields)
            {
                CorElementType const category = field.type.get_category();

                if (category == ELEMENT_TYPE_STRING || category == ELEMENT_TYPE_GENERICINST)
                {
                    return true;
                }
            }

            return false;
        }

        void write_struct_abi_fields(output& out, std::vector<meta::field> const& fields)
        {
            for (meta::field const& field : fields)
            {
                out.write("    @ %;\n",
                    field.type.get_abi_name(),
                    field.name);
            }
        }

        bool write_struct_abi(output& out, meta::type const& type)
        {
            std::vector<meta::field> fields = type.token.get_fields();

            if (!is_complex_struct(fields))
            {
                return false;
            }

            out.write(strings::write_struct_abi,
                type.full_name(),
                bind_output(write_struct_abi_fields, fields));

            return true;
        }

        void write_abi_param(output& out, meta::param const& param, bool is_return = false)
        {
            meta::signature signature = param.signature;
            CorElementType category = signature.get_category();
            bool by_ref{};

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                ++signature.data;
                category = signature.get_category();
            }

            WINRT_ASSERT(category != ELEMENT_TYPE_BYREF);

            if (category != ELEMENT_TYPE_SZARRAY)
            {
                out.write("@", signature.get_abi_name());

                if (param.is_in())
                {
                    if (category == ELEMENT_TYPE_CMOD_OPT)
                    {
                        out.write(" const&");
                    }
                }
                else
                {
                    out.write('*');
                }
            }
            else
            {
                ++signature.data;

                if (param.is_in())
                {
                    out.write("uint32_t __%Size, @*",
                        param.name,
                        signature.get_abi_name());
                }
                else if (by_ref || is_return)
                {
                    out.write("uint32_t* __%Size, @**",
                        param.name,
                        signature.get_abi_name());
                }
                else
                {
                    out.write("uint32_t __%Size, @*",
                        param.name,
                        signature.get_abi_name());
                }
            }

            out.write(" %", param.name);
        }

        bool has_reference_param(meta::method const& method)
        {
            // This function determines whether the method is async with respect to the behavior of its input parameters
            // in the sense that an input parameter is expected to be read synchronously or might well be held for later
            // inspection. In that case, we prefer to err on the side of safety and avoid providing no-copy behavior by
            // default. We use the convention of async methods ending with "Async" because checking whether the method's
            // return type implements one of the async interfaces (directly or required) is prohibitively expensive.
            // This may lead to false positives but these rare exceptions are easily dealt with by the developer.

            return is_put_accessor(method) || ends_with(method.raw_name, "Async");
        }

        void write_param_type(output& out, meta::method const& method, meta::param const& param, std::vector<std::string> const& generic_params)
        {
            meta::signature signature = param.signature;
            CorElementType category = signature.get_category();
            bool by_ref{};

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                ++signature.data;
                category = signature.get_category();
            }

            WINRT_ASSERT(category != ELEMENT_TYPE_BYREF);

            if (category < ELEMENT_TYPE_STRING)
            {
                out.write(signature.get_name(generic_params));

                if (!param.is_in())
                {
                    out.write('&');
                }

                return;
            }

            if (category == ELEMENT_TYPE_STRING)
            {
                if (param.is_in())
                {
                    out.write("param::hstring const&");
                }
                else
                {
                    out.write("hstring&");
                }

                return;
            }

            if (category == ELEMENT_TYPE_SZARRAY)
            {
                ++signature.data;

                if (param.is_in())
                {
                    out.write("array_view<@ const>", signature.get_name(generic_params));
                }
                else if (by_ref)
                {
                    out.write("com_array<@>&", signature.get_name(generic_params));
                }
                else
                {
                    out.write("array_view<@>", signature.get_name(generic_params));
                }

                return;
            }

            if (!param.is_in())
            {
                out.write("@&", signature.get_name(generic_params));
                return;
            }

            if (category != ELEMENT_TYPE_GENERICINST)
            {
                out.write("@ const&", signature.get_name(generic_params));
                return;
            }

            static std::string_view const optional("Windows.Foundation.IReference");
            static std::string_view const iterable("Windows.Foundation.Collections.IIterable");
            static std::string_view const vector_view("Windows.Foundation.Collections.IVectorView");
            static std::string_view const map_view("Windows.Foundation.Collections.IMapView");
            static std::string_view const vector("Windows.Foundation.Collections.IVector");
            static std::string_view const map("Windows.Foundation.Collections.IMap");

            std::string signature_name = signature.get_name(generic_params);

            if (starts_with(signature_name, optional))
            {
                out.write("optional@ const&", signature_name.data() + optional.size());
                return;
            }

            bool const async = has_reference_param(method);

            if (starts_with(signature_name, iterable))
            {
                if (async)
                {
                    out.write("param::async_iterable@ const&", signature_name.data() + iterable.size());
                }
                else
                {
                    out.write("param::iterable@ const&", signature_name.data() + iterable.size());
                }

                return;
            }

            if (starts_with(signature_name, vector_view))
            {
                if (async)
                {
                    out.write("param::async_vector_view@ const&", signature_name.data() + vector_view.size());
                }
                else
                {
                    out.write("param::vector_view@ const&", signature_name.data() + vector_view.size());
                }

                return;
            }

            if (starts_with(signature_name, map_view))
            {
                if (async)
                {
                    out.write("param::async_map_view@ const&", signature_name.data() + map_view.size());
                }
                else
                {
                    out.write("param::map_view@ const&", signature_name.data() + map_view.size());
                }

                return;
            }

            if (starts_with(signature_name, vector))
            {
                out.write("param::vector@ const&", signature_name.data() + vector.size());
                return;
            }

            if (starts_with(signature_name, map))
            {
                out.write("param::map@ const&", signature_name.data() + map.size());
                return;
            }

            out.write("@ const&", signature_name);
        }

        void write_param(output& out, meta::method const& method, meta::param const& param, std::vector<std::string> const& generic_params)
        {
            write_param_type(out, method, param, generic_params);
            out.write(" %", param.name);
        }

        void write_component_param_type(output& out, meta::param const& param, std::vector<std::string> const& generic_params)
        {
            meta::signature signature = param.signature;
            CorElementType category = signature.get_category();
            bool by_ref{};

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                ++signature.data;
                category = signature.get_category();
            }

            WINRT_ASSERT(category != ELEMENT_TYPE_BYREF);

            if (category < ELEMENT_TYPE_STRING)
            {
                out.write(signature.get_name(generic_params));

                if (!param.is_in())
                {
                    out.write('&');
                }

                return;
            }

            if (category == ELEMENT_TYPE_STRING)
            {
                if (param.is_in())
                {
                    out.write("hstring const&");
                }
                else
                {
                    out.write("hstring&");
                }

                return;
            }

            if (category == ELEMENT_TYPE_SZARRAY)
            {
                ++signature.data;

                if (param.is_in())
                {
                    out.write("array_view<@ const>", signature.get_name(generic_params));
                }
                else if (by_ref)
                {
                    out.write("com_array<@>&", signature.get_name(generic_params));
                }
                else
                {
                    out.write("array_view<@>", signature.get_name(generic_params));
                }

                return;
            }

            if (param.is_in())
            {
                out.write("@ const&", signature.get_name(generic_params));
            }
            else
            {
                out.write("@&", signature.get_name(generic_params));
            }
        }

        void write_component_param(output& out, meta::param const& param, std::vector<std::string> const& generic_params)
        {
            write_component_param_type(out, param, generic_params);
            out.write(" %", param.name);
        }

        void write_abi_params(output& out, meta::method const& method)
        {
            bool first = true;

            for (meta::param const& param : method.params)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    out.write(", ");
                }

                write_abi_param(out, param);
            }

            if (method.has_return_type())
            {
                if (!first)
                {
                    out.write(", ");
                }

                write_abi_param(out, method.return_type, true);
            }
        }

        void write_interface_abi_methods(output& out, meta::token const token)
        {
            for (meta::method const& method : token.get_methods())
            {
                out.write("    virtual HRESULT __stdcall %(%) = 0;\n",
                    method.get_abi_name(),
                    bind_output(write_abi_params, method));
            }
        }

        void write_delegate_abi_method(output& out, meta::token const token)
        {
            meta::method method = token.get_delegate();
            out.write("    virtual HRESULT __stdcall Invoke(%) = 0;\n", bind_output(write_abi_params, method));
        }

        void write_abi_arg(output& out, meta::param const& param, bool is_return = false)
        {
            meta::signature signature = param.signature;
            CorElementType category = signature.get_category();
            bool by_ref{};

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                ++signature.data;
                category = signature.get_category();
            }

            WINRT_ASSERT(category != ELEMENT_TYPE_BYREF);

            if (category < ELEMENT_TYPE_STRING)
            {
                if (!param.is_in())
                {
                    out.write('&');
                }

                out.write(param.name);
            }
            else if (category == ELEMENT_TYPE_SZARRAY)
            {
                ++signature.data;

                if (param.is_in())
                {
                    out.write("%.size(), get_abi(%)",
                        param.name,
                        param.name);
                }
                else if (by_ref || is_return)
                {
                    out.write("impl::put_size_abi(%), put_abi(%)",
                        param.name,
                        param.name);
                }
                else
                {
                    out.write("%.size(), get_abi(%)",
                        param.name,
                        param.name);
                }
            }
            else
            {
                if (param.is_in())
                {
                    out.write("get_abi(%)", param.name);
                }
                else
                {
                    out.write("put_abi(%)", param.name);
                }
            }
        }

        void write_abi_args(output& out, meta::method const& method)
        {
            bool first = true;

            for (meta::param const& param : method.params)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    out.write(", ");
                }

                write_abi_arg(out, param);
            }

            if (method.has_return_type())
            {
                if (!first)
                {
                    out.write(", ");
                }

                write_abi_arg(out, method.return_type, true);
            }
        }

        void write_produce_arg(output& out, meta::param const& param)
        {
            meta::signature signature = param.signature;
            CorElementType category = signature.get_category();
            bool by_ref{};

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                ++signature.data;
                category = signature.get_category();
            }

            WINRT_ASSERT(category != ELEMENT_TYPE_BYREF);

            if (category < ELEMENT_TYPE_STRING)
            {
                if (!param.is_in())
                {
                    out.write('*');
                }

                out.write(param.name);
            }
            else if (category == ELEMENT_TYPE_SZARRAY)
            {
                ++signature.data;

                std::string param_type = signature.get_name();

                if (param.is_in())
                {
                    out.write("array_view<@ const>(reinterpret_cast<@ const *>(%), reinterpret_cast<@ const *>(%) + __%Size)",
                        param_type,
                        param_type,
                        param.name,
                        param_type,
                        param.name,
                        param.name);
                }
                else if (by_ref)
                {
                    out.write("detach_abi<@>(__%Size, %)",
                        param_type,
                        param.name,
                        param.name);
                }
                else
                {
                    out.write("array_view<@>(reinterpret_cast<@*>(%), reinterpret_cast<@*>(%) + __%Size)",
                        param_type,
                        param_type,
                        param.name,
                        param_type,
                        param.name,
                        param.name);
                }
            }
            else
            {
                if (param.is_in())
                {
                    out.write("*reinterpret_cast<@ const*>(&%)",
                        signature.get_name(),
                        param.name);
                }
                else
                {
                    if (param.is_optional_out)
                    {
                        out.write("__local_%", param.name);
                    }
                    else
                    {
                        out.write("*reinterpret_cast<@*>(%)",
                            signature.get_name(),
                            param.name);
                    }
                }
            }
        }

        void write_produce_args(output& out, meta::method const& method)
        {
            bool first = true;

            for (meta::param const& param : method.params)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    out.write(", ");
                }

                write_produce_arg(out, param);
            }
        }

        void write_params(output& out, meta::method const& method, std::vector<std::string> const& generic_params)
        {
            bool first = true;

            for (meta::param const& param : method.params)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    out.write(", ");
                }

                write_param(out, method, param, generic_params);
            }
        }

        void write_component_params(output& out, meta::method const& method, std::vector<std::string> const& generic_params)
        {
            bool first = true;

            for (meta::param const& param : method.params)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    out.write(", ");
                }

                write_component_param(out, param, generic_params);
            }
        }

        void write_args(output& out, meta::method const& method)
        {
            bool first = true;

            for (meta::param const& param : method.params)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    out.write(", ");
                }

                out.write(param.name);
            }
        }

        void write_interface_method_declarations(output& out, meta::type const& type)
        {
            for (meta::method const& method : type.token.get_methods())
            {
                std::string method_name = method.get_name();

                out.write("    %@ %(%) const;\n",
                    bind_output(write_deprecated, method.token),
                    method.return_type.signature.get_name(),
                    method_name,
                    bind_output(write_params, method, empty_generic_params));

                if (is_event_method(method))
                {
                    out.write(strings::write_interface_event_declaration,
                        method_name,
                        type.full_name(),
                        bind_output(write_deprecated, method.token),
                        method_name,
                        method_name,
                        bind_output(write_params, method, empty_generic_params));
                }
            }
        }

        void write_interface_abi(output& out, meta::type const& type)
        {
            out.write(strings::write_interface_abi,
                type.full_name(),
                bind_output(write_interface_abi_methods, type.token));
        }

        void write_delegate_abi(output& out, meta::type const& type)
        {
            out.write(strings::write_delegate_abi,
                type.full_name(),
                bind_output(write_delegate_abi_method, type.token));
        }

        void write_interface_consume(output& out, meta::type const& type)
        {
            out.write(strings::write_interface_consume,
                get_impl_name(type.full_name()),
                bind_output(write_interface_method_declarations, type),
                type.full_name(),
                get_impl_name(type.full_name()));
        }

        void write_optional_out_wrappers(output& out, meta::method const& method)
        {
            for (meta::param const& param : method.params)
            {
                if (param.is_optional_out)
                {
                    out.write("\n            @ __local_%;", param.signature.get_name(), param.name);
                }
            }
        }

        void write_interface_produce_upcall(output& out, meta::method const& method)
        {
            if (!method.has_return_type())
            {
                out.write("this->shim().%(%)",
                    method.get_name(),
                    bind_output(write_produce_args, method));

                return;
            }

            if (method.return_type.signature.get_category() == ELEMENT_TYPE_SZARRAY)
            {
                out.write("std::tie(*__%Size, *%) = detach_abi(this->shim().%(%))",
                    method.return_type.name,
                    method.return_type.name,
                    method.get_name(),
                    bind_output(write_produce_args, method));
            }
            else
            {
                out.write("*% = detach_abi(this->shim().%(%))",
                    method.return_type.name,
                    method.get_name(),
                    bind_output(write_produce_args, method));
            }
        }

        void write_optional_out_results(output& out, meta::method const& method)
        {
            for (meta::param const& param : method.params)
            {
                if (param.is_optional_out)
                {
                    out.write("\n            if (%) *% = detach_abi(__local_%);", param.name, param.name, param.name);
                }
            }
        }

        void write_produce_cleanup_param(output& out, meta::param const& param, bool is_return = false)
        {
            meta::signature signature = param.signature;
            CorElementType category = signature.get_category();
            bool by_ref{};

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                ++signature.data;
                category = signature.get_category();
            }

            if (category < ELEMENT_TYPE_STRING || category == ELEMENT_TYPE_VALUETYPE)
            {
                return;
            }

            if (!by_ref && !is_return)
            {
                return;
            }

            if (category < ELEMENT_TYPE_STRING ||
                category == ELEMENT_TYPE_VALUETYPE)
            {
                out.write("\n            *% = {};", param.name);
            }
            else if (category == ELEMENT_TYPE_SZARRAY)
            {
                out.write("\n            *__%Size = 0;", param.name);
                out.write("\n            *% = nullptr;", param.name);
            }
            else
            {
                if (param.is_optional_out)
                {
                    out.write("\n            if (%) *% = nullptr;", param.name, param.name);
                }
                else
                {
                    out.write("\n            *% = nullptr;", param.name);
                }
            }
        }

        void write_produce_cleanup(output& out, meta::method const& method)
        {
            for (meta::param const& param : method.params)
            {
                if (param.is_in())
                {
                    continue;
                }

                write_produce_cleanup_param(out, param);
            }

            if (method.has_return_type())
            {
                write_produce_cleanup_param(out, method.return_type, true);
            }
        }

        void write_interface_produce_methods(output& out, meta::type const& type)
        {
            bool is_composable_factory = false;
            std::string runtimeclass_name;
            if (type.token.get_attribute_string(L"Windows.Foundation.Metadata.ExclusiveToAttribute", runtimeclass_name))
            {
                auto match_type = [&type](meta::composable_attribute const& attribute)
                {
                    return attribute.type->token == type.token;
                };

                std::vector<meta::composable_attribute> const& attributes = meta::find_type(runtimeclass_name)->token.get_composable_attributes();
                is_composable_factory = std::any_of(attributes.begin(), attributes.end(), match_type);
            }

            for (meta::method method : type.token.get_methods())
            {
                if (is_composable_factory)
                {
                    WINRT_ASSERT(method.params.size() >= 2);
                    method.params[method.params.size() - 1].is_optional_out = true;
                }
                out.write(strings::write_interface_produce_method,
                    method.get_abi_name(),
                    bind_output(write_abi_params, method),
                    bind_output(write_optional_out_wrappers, method),
                    bind_output(write_interface_produce_upcall, method),
                    bind_output(write_optional_out_results, method),
                    bind_output(write_produce_cleanup, method));
            }
        }

        void write_interface_produce(output& out, meta::type const& type)
        {
            out.write(strings::write_interface_produce,
                type.full_name(),
                type.full_name(),
                bind_output(write_interface_produce_methods, type));
        }

        void write_interface_require(output& out, meta::type const& type)
        {
            std::vector<meta::required> required = type.token.get_interface_required();

            if (required.empty())
            {
                return;
            }

            out.write(",\n    impl::require<%", type.name());

            for (meta::required const& r : required)
            {
                out.write(", @", r.name);
            }

            out.write('>');
        }

        void write_class_require(output& out, meta::type const& type)
        {
            std::vector<meta::required> required = type.token.get_class_required_excluding_default();

            if (required.empty())
            {
                return;
            }

            out.write(",\n    impl::require<%", type.name());

            for (meta::required const& r : required)
            {
                out.write(", @", r.name);
            }

            out.write('>');
        }

        void write_class_base(output& out, meta::type const& type)
        {
            meta::token base = type.token.get_base();

            if (!base)
            {
                return;
            }

            out.write(",\n    impl::base<%, @",
                type.name(),
                base.get_name());

            for (meta::token next = base.get_base(); next; next = next.get_base())
            {
                out.write(", @", next.get_name());
            }

            out.write('>');
        }

        void write_interface_usings(output& out, meta::type const& type)
        {
            for (meta::using_pair const& using_pair : type.token.get_interface_usings())
            {
                out.write("    using impl::consume_t<%, @>::%;\n",
                    type.name(),
                    using_pair.interface_name,
                    using_pair.method_name);
            }
        }

        void write_class_usings(output& out, meta::type const& type, meta::token default_interface)
        {
            std::string default_name = default_interface.get_name();

            for (meta::using_pair const& using_pair : type.token.get_class_usings())
            {
                if (using_pair.interface_name.empty())
                {
                    out.write("    using @::%;\n",
                        default_name,
                        using_pair.method_name);
                }
                else
                {
                    out.write("    using impl::consume_t<%, @>::%;\n",
                        type.name(),
                        using_pair.interface_name,
                        using_pair.method_name);
                }

            }
        }

        void write_interface_definition(output& out, meta::type const& type)
        {
            out.write(strings::write_interface_definition,
                bind_output(write_deprecated, type.token),
                type.name(),
                type.name(),
                bind_output(write_interface_require, type),
                type.name(),
                bind_output(write_interface_usings, type));
        }

        void write_delegate_definition(output& out, meta::type const& type)
        {
            meta::method method = type.token.get_delegate();

            out.write(strings::write_delegate_definition,
                bind_output(write_deprecated, type.token),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                method.return_type.signature.get_name(),
                bind_output(write_params, method, empty_generic_params));
        }

        void write_delegate_call_handler(output& out, meta::method const& method)
        {
            if (!method.has_return_type())
            {
                out.write("(*this)(%)", bind_output(write_produce_args, method));
                return;
            }

            if (method.return_type.signature.get_category() == ELEMENT_TYPE_SZARRAY)
            {
                out.write("std::tie(*__%Size, *%) = detach_abi((*this)(%))",
                    method.return_type.name,
                    method.return_type.name,
                    bind_output(write_produce_args, method));
            }
            else
            {
                out.write("*% = detach_abi((*this)(%))",
                    method.return_type.name,
                    bind_output(write_produce_args, method));
            }
        }

        void write_delegate_produce(output& out, meta::type const& type)
        {
            meta::method method = type.token.get_delegate();

            out.write(strings::write_delegate_produce,
                type.full_name(),
                type.full_name(),
                type.full_name(),
                bind_output(write_abi_params, method),
                bind_output(write_delegate_call_handler, method),
                bind_output(write_produce_cleanup, method));
        }

        void write_shim_pre(output& out, meta::method const& method)
        {
            if (!method.has_return_type())
            {
                return;
            }

            meta::signature signature = method.return_type.signature;
            CorElementType const category = CorSigUncompressElementType(signature.data);

            if (category < ELEMENT_TYPE_PTR ||
                category == ELEMENT_TYPE_VALUETYPE)
            {
                out.write("\n    @ %{};",
                    method.return_type.signature.get_name(),
                    method.return_type.name);
            }
            else if (category == ELEMENT_TYPE_SZARRAY)
            {
                out.write("\n    com_array<@> %;",
                    signature.get_name(),
                    method.return_type.name);
            }
            else
            {
                out.write("\n    @ %{ nullptr };",
                    method.return_type.signature.get_name(),
                    method.return_type.name);
            }
        }

        void write_shim_post(output& out, meta::method const& method)
        {
            if (method.has_return_type())
            {
                out.write("\n    return %;", method.return_type.name);
            }
        }

        void write_shim_body(output& out, meta::type const& type, meta::method const& method)
        {
            out.write(strings::write_shim_body,
                bind_output(write_shim_pre, method),
                type.full_name(),
                method.get_abi_name(),
                bind_output(write_abi_args, method),
                bind_output(write_shim_post, method));
        }

        void write_delegate_member_definition(output& out, meta::type const& type)
        {
            meta::method method = type.token.get_delegate();
            char const* const conditional_return = method.has_return_type() ? "return " : "";

            out.write(strings::write_delegate_member_definition,
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                conditional_return,
                type.name(),
                type.name(),
                type.name(),
                conditional_return,
                method.return_type.signature.get_name(),
                type.name(),
                bind_output(write_params, method, empty_generic_params),
                bind_output(write_shim_pre, method),
                type.name(),
                bind_output(write_abi_args, method),
                bind_output(write_shim_post, method));
        }

        void write_default_constructor_definition(output& out, meta::type const& type)
        {
            out.write(strings::write_default_constructor_definition,
                type.name(),
                type.name(),
                type.name(),
                type.name());
        }

        void write_constructor_definitions(output& out, meta::type const& type, meta::type const& factory)
        {
            for (meta::method const& method : factory.token.get_methods())
            {
                out.write(strings::write_constructor_definition,
                    type.name(),
                    type.name(),
                    bind_output(write_params, method, empty_generic_params),
                    type.name(),
                    type.name(),
                    factory.full_name(),
                    method.get_name(),
                    bind_output(write_args, method));
            }
        }

        std::tuple<std::string, std::string> composable_factory_method_to_constructor(meta::method& method)
        {
            WINRT_ASSERT(method.params.size() >= 2);
            std::string inner_name{ std::move(method.params.back().name) };
            method.params.pop_back();
            std::string outer_name{ std::move(method.params.back().name) };
            method.params.pop_back();
            return { std::move(outer_name), std::move(inner_name) };
        }

        void write_composable_constructor_definitions(output& out, meta::type const& type, meta::type const& factory)
        {
            for (meta::method const& method : factory.token.get_methods())
            {
                meta::method ctor = method;
                std::string outer_name, inner_name;
                std::tie(outer_name, inner_name) = composable_factory_method_to_constructor(ctor);

                out.write(strings::write_composable_constructor_definition,
                    type.name(),
                    type.name(),
                    bind_output(write_params, ctor, empty_generic_params),
                    outer_name,
                    inner_name,
                    type.name(),
                    factory.full_name(),
                    method.get_name(),
                    bind_output(write_args, method));
            }
        }

        void write_static_definitions(output& out, meta::type const& type, meta::type const& factory)
        {
            for (meta::method const& method : factory.token.get_methods())
            {
                std::string const method_name = method.get_name();

                out.write(strings::write_static_definition,
                    method.return_type.signature.get_name(),
                    type.name(),
                    method_name,
                    bind_output(write_params, method, empty_generic_params),
                    method.has_return_type() ? "return " : "",
                    type.name(),
                    factory.full_name(),
                    method_name,
                    bind_output(write_args, method));

                if (is_event_method(method))
                {
                    out.write(strings::write_static_event_definition,
                        factory.full_name(),
                        type.name(),
                        method_name,
                        bind_output(write_params, method, empty_generic_params),
                        type.name(),
                        factory.full_name(),
                        factory.full_name(),
                        method_name,
                        method_name,
                        bind_output(write_args, method));
                }
            }
        }

        void write_class_member_definitions(output& out, meta::type const& type)
        {
            for (meta::factory_attribute const& attribute : type.token.get_factory_attributes())
            {
                if (!attribute.activatable)
                {
                    continue;
                }

                if (attribute.type)
                {
                    write_constructor_definitions(out, type, *attribute.type);
                }
                else
                {
                    write_default_constructor_definition(out, type);
                }
            }

            for (meta::composable_attribute const& attribute : type.token.get_composable_attributes())
            {
                if (!attribute.is_public())
                {
                    continue;
                }

                write_composable_constructor_definitions(out, type, *attribute.type);
            }

            for (meta::factory_attribute const& attribute : type.token.get_factory_attributes())
            {
                if (attribute.activatable)
                {
                    continue;
                }

                write_static_definitions(out, type, *attribute.type);
            }
        }

        void write_constructor_declarations(output& out, meta::type const& type)
        {
            for (meta::factory_attribute const& attribute : type.token.get_factory_attributes())
            {
                if (!attribute.activatable)
                {
                    continue;
                }

                if (attribute.type)
                {
                    for (meta::method const& method : attribute.type->token.get_methods())
                    {
                        out.write("    %%(%);\n",
                            bind_output(write_deprecated, method.token),
                            type.name(),
                            bind_output(write_params, method, empty_generic_params));
                    }
                }
                else
                {
                    out.write("    %();\n", type.name());
                }
            }

            for (meta::composable_attribute const& attribute : type.token.get_composable_attributes())
            {
                if (!attribute.is_public())
                {
                    continue;
                }

                for (meta::method method : attribute.type->token.get_methods())
                {
                    composable_factory_method_to_constructor(method);

                    out.write("    %%(%);\n",
                        bind_output(write_deprecated, method.token),
                        type.name(),
                        bind_output(write_params, method, empty_generic_params));
                }
            }
        }

        void write_static_declarations(output& out, meta::type const& type)
        {
            for (meta::factory_attribute const& attribute : type.token.get_factory_attributes())
            {
                if (attribute.activatable)
                {
                    continue;
                }

                for (meta::method const& method : attribute.type->token.get_methods())
                {
                    std::string const method_name = method.get_name();

                    out.write("    %static @ %(%);\n",
                        bind_output(write_deprecated, method.token),
                        method.return_type.signature.get_name(),
                        method_name,
                        bind_output(write_params, method, empty_generic_params));

                    if (is_event_method(method))
                    {
                        out.write(strings::write_static_event_declaration,
                            method_name,
                            attribute.type->full_name(),
                            bind_output(write_deprecated, method.token),
                            method_name,
                            method_name,
                            bind_output(write_params, method, empty_generic_params));
                    }
                }
            }
        }

        void write_class_definition(output& out, meta::type const& type)
        {
            meta::token default_interface = type.token.get_default();

            if (default_interface)
            {
                out.write(strings::write_class_definition,
                    bind_output(write_deprecated, type.token),
                    type.name(),
                    default_interface.get_name(),
                    bind_output(write_class_base, type),
                    bind_output(write_class_require, type),
                    type.name(),
                    bind_output(write_constructor_declarations, type),
                    bind_output(write_class_usings, type, default_interface),
                    bind_output(write_static_declarations, type));
            }
            else
            {
                out.write(strings::write_static_class_definition,
                    bind_output(write_deprecated, type.token),
                    type.name(),
                    type.name(),
                    bind_output(write_static_declarations, type));
            }
        }

        void write_struct_fields(output& out, meta::type const& type)
        {
            for (meta::field const& field : type.token.get_fields())
            {
                out.write("    @ %;\n",
                    field.type.get_name(),
                    field.name);
            }
        }

        void write_struct_definition(output& out, meta::type const& type)
        {
            out.write(strings::write_struct_definition,
                bind_output(write_deprecated, type.token),
                type.name(),
                bind_output(write_struct_fields, type));
        }

        void write_shims(output& out, meta::type const& type)
        {
            for (meta::method const& method : type.token.get_methods())
            {
                std::string const method_name = method.get_name();

                out.write("\ntemplate <typename D> @ consume_%<D>::%(%) const\n",
                    method.return_type.signature.get_name(),
                    get_impl_name(type.full_name()),
                    method_name,
                    bind_output(write_params, method, empty_generic_params));

                write_shim_body(out, type, method);

                if (is_event_method(method))
                {
                    out.write(strings::write_interface_event_definition,
                        type.full_name(),
                        get_impl_name(type.full_name()),
                        method_name,
                        bind_output(write_params, method, empty_generic_params),
                        type.full_name(),
                        type.full_name(),
                        method_name,
                        method_name,
                        bind_output(write_args, method));
                }
            }
        }

        std::string get_simple_name(meta::token const token)
        {
            std::string value = token.get_name();

            size_t position = value.rfind('.') + 1;

            if (position == std::string::npos)
            {
                return value;
            }

            return value.substr(position);
        }

        void write_interface_override_method_definitions(output& out, meta::token const token)
        {
            for (meta::method const& method : token.get_methods())
            {
                std::string const simple_name = get_simple_name(token);
                std::string const method_name = method.get_name();

                out.write(strings::write_interface_override_method_definition,
                    method.return_type.signature.get_name(),
                    simple_name,
                    method_name,
                    bind_output(write_params, method, empty_generic_params),
                    simple_name,
                    method_name,
                    bind_output(write_args, method));
            }
        }

        void write_interface_override_method_declarations(output& out, meta::token const token)
        {
            for (meta::method const& method : token.get_methods())
            {
                out.write("    @ %(%) const;\n",
                    method.return_type.signature.get_name(),
                    method.get_name(),
                    bind_output(write_params, method, empty_generic_params));
            }
        }

        void write_interface_override(output& out, meta::token const token)
        {
            std::string simple_name = get_simple_name(token);

            out.write(strings::write_interface_override,
                simple_name,
                simple_name,
                token.get_name(),
                bind_output(write_interface_override_method_declarations, token));
        }

        void write_class_override_constructors(output& out, meta::token const token, std::string_view ctor_name)
        {
            if (!token)
            {
                return;
            }

            for (meta::composable_attribute const& attribute : token.get_composable_attributes())
            {
                for (meta::method method : attribute.type->token.get_methods())
                {
                    composable_factory_method_to_constructor(method);
                    const char* separator = method.params.empty() ? "" : ", ";

                    out.write(strings::write_class_override_constructor,
                        ctor_name,
                        bind_output(write_params, method, empty_generic_params),
                        token.get_name(),
                        attribute.type->full_name(),
                        method.get_name(),
                        bind_output(write_args, method),
                        separator);
                }
            }
        }

        bool is_composable(meta::token const token)
        {
            return !token.get_composable_attributes().empty();
        }

        bool has_composable_constructor(meta::token const token)
        {
            for (meta::composable_attribute const& attribute : token.get_composable_attributes())
            {
                generator<meta::method> methods = attribute.type->token.get_methods();

                if (methods.begin() != methods.end())
                {
                    return true;
                }
            }

            return false;
        }

        std::vector<meta::token> get_component_implemented_override_interfaces(meta::type const& type, bool ignore_self = false)
        {
            std::vector<meta::token> override_interfaces;
            for (meta::type const* current = &type; current; current = current->token.get_base_type())
            {
                if (current->is_reference || (!ignore_self && current == &type))
                {
                    for (meta::token t : current->token.get_direct_override_interfaces())
                    {
                        override_interfaces.push_back(t);
                    }
                }
            }
            return override_interfaces;
        }

        void write_override_fallbacks(output& out, std::vector<meta::token> const& tokens)
        {
            bool first = true;

            for (meta::token const token : tokens)
            {
                if (first)
                {
                    first = false;
                    char const* str = R"xyz(,
    @T<D>)xyz";
                    out.write(str, token.get_name());
                }
                else
                {
                    out.write(", @T<D>", token.get_name());
                }
            }
        }

        void write_class_override(output& out, meta::type const& type)
        {
            if (!has_composable_constructor(type.token))
            {
                return;
            }

            std::vector<meta::token> const override_interfaces = type.token.get_all_override_interfaces();

            std::vector<meta::required> required_interfaces;

            for (meta::required required : type.token.get_class_required())
            {
                required.token = required.token.get_definition();

                if (std::find(override_interfaces.begin(), override_interfaces.end(), required.token) == override_interfaces.end())
                {
                    required_interfaces.push_back(required);
                }
            }

            auto comma_names = [](const std::vector<meta::token>& names)
            {
                std::string result;

                for (meta::token const token : names)
                {
                    result += ", ";
                    result += token.get_name();
                }

                return result;
            };

            auto overrides_names = [&comma_names](const std::vector<meta::token>& names)
            {
                if (names.empty())
                {
                    return std::string(", Windows::Foundation::IInspectable");
                }
                else
                {
                    return comma_names(names);
                }
            };

            auto require_names = [&comma_names](const std::vector<meta::required>& names)
            {
                std::string result;

                for (const meta::required& required : names)
                {
                    result += ", ";
                    result += required.name;
                }

                return result;
            };

            std::string simple_name = get_simple_name(type.token);

            out.write(strings::write_class_override,
                simple_name,
                overrides_names(override_interfaces),
                require_names(required_interfaces),
                bind_output(write_override_fallbacks, override_interfaces),
                simple_name,
                bind_output(write_class_override_constructors, type.token, std::string(type.name()) + "T"));
        }

        void write_category_field_types(output& out, std::string_view category, meta::type const& type)
        {
            bool first = true;
            out.write(category);
            out.write("<");

            for (meta::field const& field : type.token.get_fields())
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    out.write(",");
                }

                out.write("@", field.type.get_name());
            }

            out.write(">");
        }

        void write_edit_warning_header(output& out)
        {
            out.write(strings::write_edit_warning_header, CPPWINRT_VERSION_STRING);
        }

        void write_component_class_override_dispatch_base(output& out, meta::type const& type)
        {
            std::vector<meta::token> overrides = type.token.get_all_override_interfaces();
            if (overrides.empty())
            {
                return;
            }

            auto comma_names = [](std::vector<meta::token> const& tokens)
            {
                std::string result;
                for (meta::token const token : tokens)
                {
                    result += ", ";
                    result += token.get_name();
                }
                return result;
            };

            out.write(strings::write_component_class_override_dispatch_base,
                comma_names(overrides));
        }

        void write_component_instance_interfaces(output& out, meta::type const& type)
        {
            for (meta::required required : type.token.get_component_class_required())
            {
                out.write(", @", required.name);
            }

            if (is_composable(type.token))
            {
                out.write(", composable");
            }
            meta::type const* base_type = type.token.get_base_type();
            if (base_type && base_type->is_reference && is_composable(base_type->token))
            {
                out.write(", composing");
            }
        }

        void write_component_factory_interfaces(output& out, meta::type const& type)
        {
            for (meta::factory_attribute attribute : type.token.get_factory_attributes())
            {
                if (!attribute.type) // IActivationFactory
                {
                    continue;
                }

                out.write(", @", attribute.type->full_name());
            }

            for (meta::composable_attribute const& attribute : type.token.get_composable_attributes())
            {
                out.write(", @", attribute.type->full_name());
            }
        }

        void write_component_factory_forwarding_constructors(output& out, meta::type const& type, meta::token const factory)
        {
            meta::token default_interface = type.token.get_default();

            if (!default_interface)
            {
                return;
            }

            for (meta::method const& method : factory.get_methods())
            {
                out.write(strings::write_component_factory_forwarding_constructor,
                    default_interface.get_name(),
                    method.get_name(),
                    bind_output(write_component_params, method, empty_generic_params),
                    bind_output(write_args, method));
            }
        }

        void write_component_factory_forwarding_composables(output& out, meta::token const token, meta::token const factory)
        {
            meta::token default_interface = token.get_default();

            if (!default_interface)
            {
                return;
            }

            default_interface = default_interface.get_definition();

            for (meta::method const& method : factory.get_methods())
            {
                out.write(strings::write_component_factory_forwarding_composable,
                    default_interface.get_name(),
                    method.get_name(),
                    bind_output(write_component_params, method, empty_generic_params),
                    default_interface.get_name(),
                    bind_output(write_args, method));
            }
        }
        void write_component_factory_forwarding_statics(output& out, meta::token const factory)
        {
            for (meta::method const& method : factory.get_methods())
            {
                std::string const method_name = method.get_name();

                out.write(strings::write_component_factory_forwarding_static,
                    method.return_type.signature.get_name(),
                    method_name,
                    bind_output(write_component_params, method, empty_generic_params),
                    method.has_return_type() ? "return " : "",
                    method_name,
                    bind_output(write_args, method));
            }
        }

        void write_component_factory_forwarding_methods(output& out, meta::type const& type)
        {
            std::vector<meta::factory_attribute> factory_attributes = type.token.get_factory_attributes();

            bool default_activation{};

            for (meta::factory_attribute const& attribute : factory_attributes)
            {
                if (attribute.activatable && !attribute.type)
                {
                    default_activation = true;
                }
            }

            if (default_activation)
            {
                out.write(strings::write_component_factory_activate_instance);
            }
            else
            {
                out.write(strings::write_component_factory_activate_instance_not_implemented);
            }

            for (meta::factory_attribute const& attribute : factory_attributes)
            {
                if (attribute.activatable)
                {
                    if (!attribute.type)
                    {
                        continue;
                    }

                    write_component_factory_forwarding_constructors(out, type, attribute.type->token);
                }
            }

            for (meta::composable_attribute const& attribute : type.token.get_composable_attributes())
            {
                write_component_factory_forwarding_composables(out, type.token, attribute.type->token);
            }

            for (meta::factory_attribute const& attribute : factory_attributes)
            {
                if (!attribute.activatable)
                {
                    write_component_factory_forwarding_statics(out, attribute.type->token);
                }
            }
        }

        void write_component_class_base(output& out, meta::type const& type)
        {
            WINRT_ASSERT(type.token.get_default());
            meta::token inner_type{};
            std::vector<meta::token> fallback_overrides;

            meta::type const* base_type = type.token.get_base_type();
            if (base_type)
            {
                fallback_overrides = get_component_implemented_override_interfaces(*base_type, true);
                if (base_type->is_reference)
                {
                    inner_type = base_type->token;
                }
            }

            std::string module_lock;
            if (!base_type || base_type->is_reference)
            {
                module_lock = "impl::module_lock, ";
            }

            out.write(strings::write_component_class_base,
                type.name(),
                module_lock,
                bind_output(write_component_instance_interfaces, type),
                bind_output(write_override_fallbacks, fallback_overrides),
                type.full_name(),
                type.full_name(),
                bind_output(write_class_override_constructors, inner_type, std::string(type.name()) + "Base"),
                bind_output(write_component_class_override_dispatch_base, type));
        }

        void write_component_produce_override_dispatch_methods(output& out, meta::token const token)
        {
            for (meta::method const& method : token.get_methods())
            {
                std::string const method_name = method.get_name();

                out.write(strings::write_component_produce_override_dispatch_method,
                    method.return_type.signature.get_name(),
                    method_name,
                    bind_output(write_component_params, method, empty_generic_params),
                    token.get_name(),
                    method_name,
                    bind_output(write_args, method),
                    method_name,
                    bind_output(write_args, method));
            }
        }

        void write_component_produce_override_dispatch(output& out, std::vector<meta::type const*> const& types)
        {
            std::vector<meta::token> override_interfaces;

            for (meta::type const* type : types)
            {
                std::vector<meta::token> current = type->token.get_all_override_interfaces();
                override_interfaces.insert(override_interfaces.end(), current.begin(), current.end());
            }

            std::sort(override_interfaces.begin(), override_interfaces.end());
            override_interfaces.erase(std::unique(override_interfaces.begin(), override_interfaces.end()), override_interfaces.end());

            for (meta::token const override_interface : override_interfaces)
            {
                std::string override_interface_name = override_interface.get_name();

                out.write(strings::write_component_produce_override_dispatch,
                    override_interface_name,
                    override_interface_name,
                    bind_output(write_component_produce_override_dispatch_methods, override_interface));
            }
        }

        void write_guid(output& out, meta::type const& type)
        {
            out.write("template <> struct guid<@>{ static constexpr GUID value{ % }; };\n",
                type.full_name(),
                type.token.get_guid("0x%08X,0x%04X,0x%04X,{ 0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X }"));
        }

        void write_warning(output& out, char const* const format)
        {
            out.write(format, CPPWINRT_VERSION_STRING);
        }

        void write_include_test(output& out, meta::namespace_types const& types)
        {
            for (meta::type const& type : meta::get_projected_types(types.interfaces))
            {
                out.write("    @{};\n", type.full_name());
                out.write("    static_assert(sizeof(void*) == sizeof(@));\n", type.full_name());
            }

            for (meta::type const& type : meta::get_projected_types(types.classes))
            {
                if (type.token.get_default())
                {
                    out.write("    @{ nullptr };\n", type.full_name());
                    out.write("    static_assert(sizeof(void*) == sizeof(@));\n", type.full_name());
                }
                else
                {
                    out.write("    static_assert(1 == sizeof(@));\n", type.full_name());

                }
            }

            for (meta::type const& type : meta::get_projected_types(types.enums))
            {
                out.write("    @{};\n", type.full_name());
            }

            for (meta::type const& type : meta::get_projected_types(types.structs))
            {
                out.write("    @{};\n", type.full_name());
            }

            for (meta::type const& type : meta::get_projected_types(types.delegates))
            {
                meta::method method = type.token.get_delegate();

                if (method.has_return_type())
                {
                    out.write("    @{ [](auto&&...){ return @{}; } };\n",
                        type.full_name(),
                        method.return_type.signature.get_name());
                }
                else
                {
                    out.write("    @{ [](auto&&...){} };\n", type.full_name());
                }

                out.write("    static_assert(sizeof(void*) == sizeof(@));\n", type.full_name());
            }
        }

        void write_include_tests()
        {
            meta::index_type const& index = meta::get_index();

            for (meta::index_pair const& ns : index)
            {
                output out;

                out.write(strings::write_include_tests,
                    ns.first,
                    bind_output(write_include_test, ns.second));

                path p = settings::output;
                p /= "tests";
                p /= ns.first;
                p += ".cpp";

                out.save_as(p.string());
            }
        }

        void write_test_includes(output& out)
        {
            meta::index_type const& index = meta::get_index();

            for (meta::index_pair const& ns : index)
            {
                out.write("#include \"winrt/%.h\"\n", ns.first);
            }
        }

        void write_consume_test_params(output& out, meta::method const& method, std::vector<std::string> const& generic_params)
        {
            bool first = true;

            for (meta::param const& param : method.params)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    out.write(", ");
                }

                out.write("arg<%>()",
                    bind_output(write_param_type, method, param, generic_params));
            }
        }

        void write_consume_test_function_required_methods(output& out, meta::type const& type, meta::required const& required)
        {
            for (meta::method const& method : required.token.get_methods())
            {
                std::string const method_name = method.get_name();

                if (method_name == "Style" && type.name() == "MapControl")
                {
                    continue;
                }

                out.write("    o.%(%);\n",
                    method_name,
                    bind_output(write_consume_test_params, method, required.generic_params));
            }
        }

        void write_consume_test_function_static_methods(output& out, meta::type const& type, meta::type const& factory)
        {
            for (meta::method const& method : factory.token.get_methods())
            {
                out.write("    @::%(%);\n",
                    type.full_name(),
                    method.get_name(),
                    bind_output(write_consume_test_params, method, empty_generic_params));
            }
        }

        void write_consume_test_function_interface_methods(output& out, meta::type const& type)
        {
            write_consume_test_function_required_methods(out, type, { std::string(type.full_name()), type.token,{} });

            for (meta::required const& required : type.token.get_interface_required())
            {
                out.write("    // @\n", required.name);
                write_consume_test_function_required_methods(out, type, required);
            }
        }

        void write_consume_test_function_class_methods(output& out, meta::type const& type)
        {
            for (meta::required const& required : type.token.get_class_required())
            {
                out.write("    // @\n", required.name);
                write_consume_test_function_required_methods(out, type, required);
            }

            for (meta::factory_attribute const& attribute : type.token.get_factory_attributes())
            {
                if (attribute.activatable)
                {
                    continue;
                }

                out.write("    // @\n", attribute.type->full_name());
                write_consume_test_function_static_methods(out, type, *attribute.type);
            }
        }

        void write_consume_test_functions(output& out)
        {
            meta::index_type const& index = meta::get_index();

            for (meta::index_pair const& ns : index)
            {
                for (meta::type const& type : meta::get_projected_types(ns.second.interfaces))
                {
                    out.write("\nvoid %()\n{\n    @ o{ nullptr };\n",
                        get_impl_name(type.full_name()),
                        type.full_name());

                    write_consume_test_function_interface_methods(out, type);
                    out.write("}\n");
                }

                for (meta::type const& type : meta::get_projected_types(ns.second.classes))
                {
                    out.write("\nvoid %()\n{\n", get_impl_name(type.full_name()));

                    if (type.token.get_default())
                    {
                        out.write("    @ o{ nullptr };\n", type.full_name());
                    }

                    write_consume_test_function_class_methods(out, type);
                    out.write("}\n");
                }
            }
        }

        void write_produce_test_interface_methods(output& out, meta::type const& type)
        {
            for (meta::method const& method : type.token.get_methods())
            {
                out.write("\n    @ %(%)\n    {\n        throw hresult_not_implemented();\n    }\n",
                    method.return_type.signature.get_name(),
                    method.get_name(),
                    bind_output(write_component_params, method, empty_generic_params));
            }
        }

        void write_produce_test_interfaces(output& out)
        {
            meta::index_type const& index = meta::get_index();

            for (meta::index_pair const& ns : index)
            {
                for (meta::type const& type : meta::get_projected_types(ns.second.interfaces))
                {
                    if (type.full_name() == "Windows.Devices.Haptics.IKnownSimpleHapticsControllerWaveformsStatics" ||
                        type.full_name() == "Windows.Media.Audio.ILimiterEffectDefinition")
                    {
                        // TODO: This interface has a member called 'Release' which causes problems with implements<...>
                        continue;
                    }

                    out.write(strings::write_produce_test_interface,
                        get_impl_name(type.full_name()),
                        get_impl_name(type.full_name()),
                        type.full_name(),
                        bind_output(write_produce_test_interface_methods, type));
                }
            }
        }

        void write_consume_tests()
        {
            output out;

            out.write(strings::write_consume_tests,
                bind_output(write_test_includes),
                bind_output(write_consume_test_functions));

            path p = settings::output;
            p /= "tests/consume.cpp";

            out.save_as(p.string());
        }

        void write_produce_tests()
        {
            output out;

            out.write(strings::write_produce_tests,
                bind_output(write_test_includes),
                bind_output(write_produce_test_interfaces));

            path p = settings::output;
            p /= "tests/produce.cpp";

            out.save_as(p.string());
        }

        std::string_view get_relative_component_name(meta::type const& type)
        {
            if (!settings::component_name.empty() && starts_with(type.full_name(), settings::component_name))
            {
                return type.full_name().substr(settings::component_name.size() + 1);
            }
            else
            {
                return type.full_name();
            }
        }

        std::string get_component_filename(meta::type const& type)
        {
            path filename = settings::output;
            filename /= std::string(get_relative_component_name(type));
            return filename.string();
        }
    }

    void write_projection(output& out)
    {
        meta::index_type const& complete_index = meta::get_index();

        write_edit_warning_header(out);
        out.write("#include \"winrt/base.h\"\n");

        std::vector<std::reference_wrapper<const meta::index_pair>> unfiltered_index;
        std::vector<reference_writer> ref_writers;
        for (meta::index_pair const& ns : complete_index)
        {
            auto classes = get_projected_types(ns.second.classes);
            if(classes.begin() != classes.end())
            {
                unfiltered_index.push_back(std::ref(ns));
            }
        }

        write_winrt_namespace_begin(out);
        for (meta::index_pair const& ns : unfiltered_index)
        {
            out.write_namespace(ns.first);
            write_forwards(out, ns.second);
        }
        out.write_namespace("impl");
        out.write("\n");

        for (meta::index_pair const& ns : unfiltered_index)
        {
            write_categories(out, ns.second);
            write_names(out, ns.second);
            write_guids(out, ns.second);
            write_default_interfaces(out, ns.second);
            write_struct_abi(out, ns.second);
            write_consume(out, ns.second);
        }

        // This is separate from the previous set because the ABI virtual functions need the
        // size of the handful of structs that have a distinct ABI shape since structs are
        // passed by value.
        for (meta::index_pair const& ns : unfiltered_index)
        {
            write_abi(out, ns.second);
        }

        for (meta::index_pair const& ns : unfiltered_index)
        {
            out.write_namespace(ns.first);
            write_interface_definitions(out, ns.second);
            write_delegate_definitions(out, ns.second);
            write_struct_definitions(out, ns.second);
        }

        // This is separate from the previous set because a base class must be defined before use
        // and we must therefore define the default interfaces before the runtime classes are defined.
        for (meta::index_pair const& ns : unfiltered_index)
        {
            out.write_namespace(ns.first);
            write_class_definitions(out, ns.second);
            write_interface_overrides(out, ns.second);
        }

        out.write_namespace("impl");

        for (meta::index_pair const& ns : unfiltered_index)
        {
            write_interface_member_definitions(out, ns.second);
            write_delegate_produce(out, ns.second);
            write_produce(out, ns.second);
        }

        for (meta::index_pair const& ns : unfiltered_index)
        {
            out.write_namespace(ns.first);
            write_class_member_definitions(out, ns.second);
            write_delegate_member_definitions(out, ns.second);
            write_interface_override_methods(out, ns.second);
            write_class_overrides(out, ns.second);
        }

        write_winrt_namespace_end(out);

        out.write_namespace("std");
        for (meta::index_pair const& ns : unfiltered_index)
        {
            write_std_hashes(out, ns.second);
        }
        out.write_namespace();
    }

    void write_logo(output& out)
    {
        time_t t{ time(nullptr) };
        tm tm{};
        localtime_s(&tm, &t);
        out.write(strings::write_logo, CPPWINRT_VERSION_STRING, 1900 + tm.tm_year);
    }

    void write_winrt_namespace_begin(output& out)
    {
        out.write("\nnamespace winrt {\n");
    }

    void write_winrt_namespace_end(output& out)
    {
        out.write_namespace();
        out.write("\n}\n");
    }

    void write_warning_push(output& out)
    {
        out.write("\nWINRT_WARNING_PUSH\n");
    }

    void write_warning_pop(output& out)
    {
        out.write("\nWINRT_WARNING_POP\n");
    }

    void write_base_header(output& out)
    {
        write_logo(out);
        out.write(strings::base_warnings);
        write_warning_push(out);

        out.write(strings::base_dependencies);
        out.write(strings::base_macros);

        write_winrt_namespace_begin(out);

        out.write(strings::base_meta);
        out.write(strings::base_constexpr_string);
        out.write(strings::base_handle);
        out.write(strings::base_com_ptr);
        out.write(strings::base_string);
        out.write(strings::base_string_hstring);
        out.write(strings::base_string_operators);
        out.write(strings::base_string_input);
        out.write(strings::base_constexpr_guid);
        out.write(strings::base_constexpr_sha1);
        out.write(strings::base_constexpr_traits);
        out.write(strings::base_error);
        out.write(strings::base_lock);
        out.write(strings::base_windows);
        out.write(strings::base_array);
        out.write(strings::base_weak);
        out.write(strings::base_agile);
        out.write(strings::base_event_consume);
        out.write(strings::base_event_produce);
        out.write(strings::base_implements);
        out.write(strings::base_composable);
        out.write(strings::base_activation);
        out.write(strings::base_delegate);

        out.write(strings::base_collections_consume);
        out.write(strings::base_collections_produce);

        out.write(strings::base_collections_input);
        out.write(strings::base_collections_input_iterable);
        out.write(strings::base_collections_input_vector_view);
        out.write(strings::base_collections_input_map_view);
        out.write(strings::base_collections_input_vector);
        out.write(strings::base_collections_input_map);
        out.write(strings::base_collections_vector);
        out.write(strings::base_collections_map);

        out.write(strings::base_reference);
        out.write(strings::base_foundation);
        out.write(strings::base_chrono);
        out.write(strings::base_async_consume);
        out.write(strings::base_async_produce);
        out.write(strings::base_await_consume);
        out.write(strings::base_await_produce);

        write_winrt_namespace_end(out);
        out.write(strings::base_std_hash);

        out.write("\n#ifdef WINRT_ASYNC\n");
        out.write_namespace("std::experimental");
        out.write(strings::base_std_fire_and_forget);
        out.write(strings::base_std_async_action);
        out.write(strings::base_std_async_action_with_progress);
        out.write(strings::base_std_async_operation);
        out.write(strings::base_std_async_operation_with_progress);
        out.write_namespace();
        out.write("\n#endif\n");

        out.write(strings::base_natvis);

        write_warning_pop(out);
    }

    void write_names(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.interfaces, types.classes, types.enums, types.structs, types.delegates))
        {
            out.write("template <> struct name<@>{ static constexpr auto & value{ L\"%\" }; };\n",
                type.full_name(),
                type.full_name());
        }
    }

    void write_categories(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.interfaces))
        {
            out.write("template <> struct category<@>{ using type = interface_category; };\n", type.full_name());
        }

        for (meta::type const& type : get_projected_types(types.classes))
        {
            out.write("template <> struct category<@>{ using type = class_category; };\n", type.full_name());
        }

        for (meta::type const& type : get_projected_types(types.enums))
        {
            out.write("template <> struct category<@>{ using type = enum_category; };\n", type.full_name());
        }

        for (meta::type const& type : get_projected_types(types.structs))
        {
            out.write("template <> struct category<@>{ using type = %; };\n",
                type.full_name(),
                bind_output(write_category_field_types, "struct_category", type));
        }

        for (meta::type const& type : get_projected_types(types.delegates))
        {
            out.write("template <> struct category<@>{ using type = delegate_category; };\n", type.full_name());
        }
    }

    void write_guids(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.interfaces, types.delegates))
        {
            write_guid(out, type);
        }
    }

    void write_forwards(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.enums))
        {
            write_enum(out, type);
        }

        bool first = true;

        for (meta::type const& type : get_projected_types(types.interfaces, types.classes, types.structs, types.delegates))
        {
            if (first)
            {
                first = false;
                out.write("\n");
            }

            out.write("struct %;\n", type.name());
        }
    }

    void write_default_interfaces(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.classes))
        {
            write_default_interface(out, type);
        }
    }

    void write_abi(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.interfaces))
        {
            write_interface_abi(out, type);
        }

        for (meta::type const& type : get_projected_types(types.delegates))
        {
            write_delegate_abi(out, type);
        }
    }

    bool write_struct_abi(output& out, meta::namespace_types const& types)
    {
        bool struct_written = false;

        for (meta::type const& type : get_projected_types(types.structs))
        {
            if (write_struct_abi(out, type))
            {
                struct_written = true;
            }
        }

        return struct_written;
    }

    void write_consume(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.interfaces))
        {
            write_interface_consume(out, type);
        }
    }

    void write_produce(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.interfaces))
        {
            write_interface_produce(out, type);
        }
    }

    void write_interface_definitions(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.interfaces))
        {
            write_interface_definition(out, type);
        }
    }

    void write_delegate_definitions(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.delegates))
        {
            write_delegate_definition(out, type);
        }
    }

    void write_class_definitions(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.classes))
        {
            write_class_definition(out, type);
        }
    }

    void write_params_test(output& out, meta::method const& method, std::vector<std::string> const& generic_params)
    {
        bool first = true;

        for (meta::param const& param : method.params)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                out.write(", ");
            }

            out.write("arg<%>()",
                bind_output(write_param_type, method, param, generic_params));
        }
    }

    void write_interface_consume_test(output& out, std::string_view class_name, meta::required const& required)
    {
        out.write(R"(
    // %)",
            required.name);

        for (meta::method const& method : required.token.get_methods())
        {
            std::string method_name = method.get_name();

            out.write(R"(
    { %o.%%(%); })",
                [&](output& out)
	            {
	                if (method.has_return_type())
	                {
	                    out.write("@ r = ", method.return_type.signature.get_name(required.generic_params));
	                }
	            },
                // Special case: Windows.UI.Xaml.Controls.Maps.MapControl inherits two Style overloads with same arity.
                // Add explicit interface cast to disambiguate.
                [&](output& out)
	            {
	                if ((method_name == "Style") && (class_name == "MapControl"))
	                {
	                    out.write("as<@>().", required.name);
	                }
	            },
                method_name,
                bind_output(write_params_test, method, required.generic_params));
        }
    }

    void write_static_test(output& out, meta::type const& factory)
    {
        for (meta::method const& method : factory.token.get_methods())
        {
            std::string const method_name = method.get_name();

            out.write(R"(
    { %s.%(%); })",
                [&](output& out)
                {
                    if (method.has_return_type())
                    {
                        out.write("@ r = ", method.return_type.signature.get_name());
                    }
                },
                method_name,
                bind_output(write_params_test, method, empty_generic_params));

            if (is_event_method(method))
            {
                out.write(R"(
    { @::%_revoker r = s.%(auto_revoke, %); })",
                    factory.full_name(),
                    method_name,
                    method_name,
                    bind_output(write_params_test, method, empty_generic_params));
            }
        }
    }

    void write_class_test(output& out,
        std::string const& namespace_name,
        meta::type const& type)
    {
        meta::token default_interface = type.token.get_default();

        if (default_interface)
        {
            out.write(
                R"({
    @::% o{nullptr};%
})",
				namespace_name,
				type.name(),
				[&](output& out)
            {

                // TODO: the test code doesn't currently support referring to type params from other namespaces. For now just emitting
                // tests for default interface until we figure out what to test here.

                write_interface_consume_test(out, type.name(), { default_interface.get_name(), default_interface, default_interface.get_generic_params() });

                //for (meta::required const& required : type.token.get_class_required())
                //{
                //    write_interface_test(out, type.name(), required);
                //}
            });
        }
        else
        {
            for (meta::factory_attribute const& attribute : type.token.get_factory_attributes())
            {
                auto& factory = *attribute.type;
                out.write(
                R"({
    @ s{nullptr};%
})",
                factory.full_name(),
                bind_output(write_static_test, factory));
            }
        }
    }

    void write_interface_produce_test(output& out, meta::type const& type)
    {
        // todo: ignore generics for testing until requireds are working
        if (!type.token.is_type_def())
        {
            return;
        }

        std::string_view interface_name = type.full_name();
        out.write(
            R"(
{ struct s : implements<s, @> {
%}; })",
            interface_name,
            bind_output(write_interface_method_declarations, type));
    }

    void write_namespace_test(output& out,
        std::string const& namespace_name,
        meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.classes))
        {
            write_class_test(out, namespace_name, type);
        }

        for (meta::type const& type : get_projected_types(types.interfaces))
        {
            write_interface_produce_test(out, type);
        }
    }

    void write_test(output& out,
        std::string const& namespace_name,
        meta::namespace_types const& types)
    {
        out.write(
            R"(#include "pch.h"
#include "winrt/%.h"

void t()
{
%
})",
            namespace_name,
			bind_output(write_namespace_test, namespace_name, types));
    }

    void write_tests()
    {
        path p = settings::output;
        p /= "tests";
        create_directories(p);

        write_include_tests();
        write_consume_tests();
        write_produce_tests();
    }

    void write_struct_definitions(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.structs))
        {
            write_struct_definition(out, type);
        }
    }

    void write_interface_member_definitions(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.interfaces))
        {
            write_shims(out, type);
        }
    }

    void write_class_member_definitions(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.classes))
        {
            write_class_member_definitions(out, type);
        }
    }

    void write_interface_overrides(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.classes))
        {
            for (meta::token const token : type.token.get_direct_override_interfaces())
            {
                write_interface_override(out, token);
            }
        }
    }

    void write_interface_override_methods(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.classes))
        {
            for (meta::token const token : type.token.get_direct_override_interfaces())
            {
                write_interface_override_method_definitions(out, token);
            }
        }
    }

    void write_class_overrides(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.classes))
        {
            write_class_override(out, type);
        }
    }

    void write_std_hashes(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.interfaces, types.classes))
        {
            out.write(strings::write_std_hash,
                "",
                type.full_name(),
                type.full_name());
        }
    }

    void write_delegate_produce(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.delegates))
        {
            write_delegate_produce(out, type);
        }
    }

    void write_delegate_member_definitions(output& out, meta::namespace_types const& types)
    {
        for (meta::type const& type : get_projected_types(types.delegates))
        {
            write_delegate_member_definition(out, type);
        }
    }

    void write_include(output& out, std::string const& include)
    {
        out.write("#include \"");
        out.write(include);
        out.write("\"\n");
    }

    void write_component_header(std::vector<meta::type const*> const& types)
    {
        output out;
        write_warning(out, strings::write_edit_warning_header);

        if (!settings::component_name.empty())
        {
            out.write("\n#include \"%.h\"\n", settings::component_name);
        }

        write_winrt_namespace_begin(out);

        out.write_namespace("impl");
        out.write(strings::write_component_lock_declaration);
        write_component_produce_override_dispatch(out, types);

        write_winrt_namespace_end(out);

        path filename = settings::output;
        filename /= "module.h";
        out.save_as(filename.string());
    }

    void write_component_class_includes(output& out, std::vector<meta::type const*> const& types)
    {
        for (meta::type const* type : types)
        {
            out.write("#include \"%.h\"\n", get_relative_component_name(*type));
        }
    }

    void write_component_class_activations(output& out, std::vector<meta::type const*> const& types)
    {
        for (meta::type const* type : types)
        {
            out.write(strings::write_component_class_activation,
                type->full_name(),
                type->name_space(),
                type->name());
        }
    }

    void write_component_source(std::vector<meta::type const*> const& types)
    {
        output out;
        write_warning(out, strings::write_edit_warning_source);

        if (types.empty())
        {
            out.write(strings::write_component_source_empty);
        }
        else
        {
            out.write(strings::write_component_source,
                bind_output(write_component_class_includes, types),
                bind_output(write_component_class_activations, types));
        }

        path filename = settings::output;
        filename /= "module.cpp";
        out.save_as(filename.string());
    }

    void write_component_class_constructor_declarations(output& out, meta::type const& type, meta::token const factory)
    {
        for (meta::method const& method : factory.get_methods())
        {
            out.write("        %(%);\n",
                type.name(),
                bind_output(write_component_params, method, empty_generic_params));
        }
    }

    void write_component_class_static_declarations(output& out, meta::token const factory)
    {
        for (meta::method const& method : factory.get_methods())
        {
            out.write("        static @ %(%);\n",
                method.return_type.signature.get_name(),
                method.get_name(),
                bind_output(write_component_params, method, empty_generic_params));
        }
    }

    bool has_statics(std::vector<meta::factory_attribute> const& factory_attributes)
    {
        for (meta::factory_attribute const& attribute : factory_attributes)
        {
            if (!attribute.activatable)
            {
                return true;
            }
        }

        return false;
    }

    void write_component_class_member_declarations(output& out, meta::type const& type)
    {
        std::vector<meta::factory_attribute> factory_attributes = type.token.get_factory_attributes();
        bool default_activation{};

        for (meta::factory_attribute const& attribute : factory_attributes)
        {
            if (attribute.activatable && !attribute.type)
            {
                default_activation = true;
            }
        }

        std::vector<meta::composable_attribute> composable_attributes = type.token.get_composable_attributes();
        for (meta::composable_attribute const& attribute : composable_attributes)
        {
            for (const auto& method : attribute.type->token.get_methods())
            {
                if (method.params.size() == 2)
                {
                    default_activation = true;
                }
            }
        }

        if (default_activation)
        {
            out.write("        %() = default;\n", type.name());
        }
        else
        {
            out.write("        %() = delete;\n", type.name());
        }

        for (meta::factory_attribute const& attribute : factory_attributes)
        {
            if (attribute.activatable)
            {
                if (!attribute.type)
                {
                    continue;
                }

                write_component_class_constructor_declarations(out, type, attribute.type->token);
            }
        }

        std::vector<meta::required> interfaces = type.token.get_component_class_required();

        if (!interfaces.empty())
        {
            out.write("\n");
        }

        for (meta::required const& required : interfaces)
        {
            for (meta::method const& method : required.token.get_methods())
            {
                out.write("        @ %(%);\n",
                    method.return_type.signature.get_name(required.generic_params),
                    method.get_name(),
                    bind_output(write_component_params, method, required.generic_params));
            }
        }

        if (has_statics(factory_attributes))
        {
            out.write("\n");

            for (meta::factory_attribute const& attribute : factory_attributes)
            {
                if (!attribute.activatable)
                {
                    write_component_class_static_declarations(out, attribute.type->token);
                }
            }
        }
    }

    void write_component_class_constructor_definitions(output& out, meta::type const& type, meta::token const factory)
    {
        for (meta::method const& method : factory.get_methods())
        {
            out.write(strings::write_component_class_constructor_definition,
                type.name(),
                type.name(),
                bind_output(write_component_params, method, empty_generic_params));
        }
    }

    void write_component_class_static_definitions(output& out, meta::type const& type, meta::token const factory)
    {
        for (meta::method const& method : factory.get_methods())
        {
            out.write(strings::write_component_class_static_definition,
                method.return_type.signature.get_name(),
                type.name(),
                method.get_name(),
                bind_output(write_component_params, method, empty_generic_params));
        }
    }

    void write_component_class_member_definitions(output& out, meta::type const& type)
    {
        for (meta::factory_attribute const attribute : type.token.get_factory_attributes())
        {
            if (attribute.activatable)
            {
                if (!attribute.type)
                {
                    continue;
                }

                write_component_class_constructor_definitions(out, type, attribute.type->token);
            }
        }

        std::vector<meta::required> interfaces = type.token.get_component_class_required();

        for (meta::required const& required : interfaces)
        {
            for (meta::method const& method : required.token.get_methods())
            {
                out.write(strings::write_component_interface_method_definition,
                    method.return_type.signature.get_name(required.generic_params),
                    type.name(),
                    method.get_name(),
                    bind_output(write_component_params, method, required.generic_params));
            }
        }

        for (meta::factory_attribute const attribute : type.token.get_factory_attributes())
        {
            if (!attribute.activatable)
            {
                write_component_class_static_definitions(out, type, attribute.type->token);
            }
        }
    }

    void write_component_class_generated_header(meta::type const& type)
    {
        std::string const filename = get_component_filename(type) + ".g.h";

        output out;
        write_warning(out, strings::write_edit_warning_header);
        out.write("\n#include \"module.h\"\n");
        write_winrt_namespace_begin(out);
        bool const static_class = type.token.is_static();

        if (!static_class)
        {
            out.write_namespace(std::string(type.name_space()) + ".implementation");
            write_component_class_base(out, type);
        }

        out.write_namespace(std::string(type.name_space()) + ".factory_implementation");

        out.write(strings::write_component_class_factory_base,
            type.name(),
            bind_output(write_component_factory_interfaces, type),
            type.full_name(),
            bind_output(write_component_factory_forwarding_methods, type));

        write_winrt_namespace_end(out);

        if (!static_class)
        {
            std::string upper(type.name());
            std::transform(upper.begin(), upper.end(), upper.begin(), [](char c) {return (char)::toupper(c); });

            out.write(strings::write_component_class_xaml_shim,
                upper,
                get_relative_component_name(type),
                get_relative_component_name(type),
                type.name_space(),
                type.name(),
                type.name());
        }

        out.save_as(filename);
    }

    void write_component_class_header(meta::type const& type)
    {
        std::string const filename = get_component_filename(type) + ".h";

        if (!settings::overwrite && exists(filename))
        {
            return;
        }

        output out;

        bool const static_class = type.token.is_static();

        if (static_class)
        {
            out.write(strings::write_component_static_class_header,
                get_relative_component_name(type),
                type.name_space(),
                type.name(),
                bind_output(write_component_class_member_declarations, type),
                type.name_space(),
                type.name(),
                type.name(),
                type.name(),
                type.name());
        }
        else
        {
            std::string base_name;
            meta::type const* base_type = type.token.get_base_type();
            if (base_type && !base_type->is_reference)
            {
                base_name = ", ";
                base_name += base_type->name_space();
                base_name += "::implementation::";
                base_name += base_type->name();
            }

            out.write(strings::write_component_class_header,
                get_relative_component_name(type),
                type.name_space(),
                type.name(),
                type.name(),
                type.name(),
                base_name,
                bind_output(write_component_class_member_declarations, type),
                type.name_space(),
                type.name(),
                type.name(),
                type.name(),
                type.name());
        }

        out.save_as(filename);
    }

    void write_component_class_source(meta::type const& type)
    {
        std::string const filename = get_component_filename(type) + ".cpp";

        if (!settings::overwrite && exists(filename))
        {
            return;
        }

        output out;

        out.write(strings::write_component_class_source,
            get_relative_component_name(type),
            type.name_space(),
            bind_output(write_component_class_member_definitions, type));

        out.save_as(filename);
    }

    char const* get_natvis_property_field(CorElementType category)
    {
        switch (category)
        {
        case ELEMENT_TYPE_BOOLEAN: return "b";
        case ELEMENT_TYPE_CHAR: return "c";
        case ELEMENT_TYPE_I1: return "i1";
        case ELEMENT_TYPE_I2: return "i2";
        case ELEMENT_TYPE_I4: return "i4";
        case ELEMENT_TYPE_I8: return "i8";
        case ELEMENT_TYPE_U1: return "u1";
        case ELEMENT_TYPE_U2: return "u2";
        case ELEMENT_TYPE_U4: return "u4";
        case ELEMENT_TYPE_U8: return "u8";
        case ELEMENT_TYPE_R4: return "r4";
        case ELEMENT_TYPE_R8: return "r8";
        case ELEMENT_TYPE_STRING: return "s";
        case ELEMENT_TYPE_VALUETYPE: return "v";
        }
        return{};
    }

    using natvis_properties = std::vector<std::tuple<std::string, std::string, int32_t, char const*>>;

    auto enum_natvis_interfaces(meta::type const& type)
    {
        std::map<std::string, natvis_properties> natvis_interfaces;
        bool is_stringable{};

        for (meta::required const& required : type.token.get_class_required())
        {
            natvis_properties natvis_properties;
            int32_t property_index = -1;

            for (meta::method const& method : required.token.get_methods())
            {
                property_index++;

                if (!is_get_accessor(method))
                {
                    continue;
                }

                meta::param const& param = method.return_type;
                meta::signature const signature = param.signature;
                CorElementType category = signature.get_category();
                char const* property_field = get_natvis_property_field(category);

                if (!property_field)
                {
                    continue;
                }

                std::string property_cast;
                if (category == ELEMENT_TYPE_VALUETYPE)
                {
                    meta::token property_token = signature.get_token();
                    std::string property_typename = property_token.get_name();
                    property_cast = "*(winrt::" + property_typename + "*)";
                }

                natvis_properties.push_back({ method.get_name(), property_cast, property_index, property_field });
            }

            meta::token required_type_def = required.token.get_definition();
            
            static const std::string_view IID_IStringable = "96369F54-8EB6-48F0-ABCE-C1B211E627C3";
            std::string iid = required_type_def.get_guid("%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X");

            if (!natvis_properties.empty())
            {
                natvis_interfaces[iid] = std::move(natvis_properties);
            }
            else if (iid == IID_IStringable)
            {
                is_stringable = true;
            }
        }

        return std::make_pair(natvis_interfaces, is_stringable);
    }

    void write_natvis_properties(output& out, std::map<std::string, natvis_properties> natvis_interfaces)
    {
        for (auto& natvis_interface : natvis_interfaces)
        {
            for (auto& natvis_property : natvis_interface.second)
            {
                std::string name;
                std::string cast;
                int32_t index;
                char const* type;
                std::tie(name, cast, index, type) = natvis_property;
                out.write(R"(
        <Item Name="[%]">@WINRT_get_val(this,L"{%}",%).%</Item>)",
                    name, cast, natvis_interface.first, index, type);
            }
        }
    }

    void write_natvis_classes(output& out)
    {
        meta::index_type const& index = meta::get_index();

        for (meta::index_pair const& ns : index)
        for (meta::type const& type : get_projected_types(ns.second.classes))
        {
            auto interfaces = enum_natvis_interfaces(type);

            if (!interfaces.first.empty())
            {
                    out.write(R"(
<Type Name="winrt::@">
    <DisplayString>%</DisplayString>  
    <Expand>%
    </Expand>
</Type>
)",
                    type.full_name(),
                    interfaces.second ? R"({WINRT_get_val(this,L"{96369F54-8EB6-48F0-ABCE-C1B211E627C3}",0).s})" : "(expand to display properties)",
                    bind_output(write_natvis_properties, interfaces.first));
            }
        }
    }

    void write_natvis(output& out)
    {
        out.write(strings::write_natvis, bind_output(write_natvis_classes));
    }

    // todo: generate as much WF/WFC code as possible (e.g., generics) from metadata.
    void write_namespace_special(output& out, std::string const& namespace_name)
    {
        if (namespace_name == "Windows.Foundation")
        {
            out.write(strings::base_reference_produce);

            static const struct
            {
                char const* params;
                char const* name;
            }

            generic_interfaces[] =
            {
                { "", "Windows::Foundation::IUnknown" },
                { "", "Windows::Foundation::IInspectable" },
                { "", "Windows::Foundation::IActivationFactory" },
                { "", "Windows::Foundation::IAsyncInfo" },
                { "", "Windows::Foundation::IAsyncAction" },
                { "typename TProgress", "Windows::Foundation::IAsyncActionWithProgress<TProgress>" },
                { "typename TResult", "Windows::Foundation::IAsyncOperation<TResult>" },
                { "typename TResult, typename TProgress", "Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>" },
                { "", "Windows::Foundation::AsyncActionCompletedHandler" },
                { "typename TProgress", "Windows::Foundation::AsyncActionProgressHandler<TProgress>" },
                { "typename TProgress", "Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>" },
                { "typename TResult", "Windows::Foundation::AsyncOperationCompletedHandler<TResult>" },
                { "typename TResult, typename TProgress", "Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>" },
                { "typename TResult, typename TProgress", "Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>" },
                { "typename T", "Windows::Foundation::IReference<T>" },
                { "typename T", "Windows::Foundation::EventHandler<T>" },
                { "typename TSender, typename TArgs", "Windows::Foundation::TypedEventHandler<TSender, TArgs>" },
            };

            out.write_namespace("std");

            for (auto& generic : generic_interfaces)
            {
                out.write(strings::write_std_hash,
                    generic.params,
                    generic.name,
                    generic.name);
            }

            out.write_namespace();
        }

        if (namespace_name == "Windows.Foundation.Collections")
        {
            static const struct
            {
                char const* params;
                char const* name;
            }

            generic_interfaces[] =
            {
                { "typename T", "Windows::Foundation::Collections::IIterator<T>" },
                { "typename T", "Windows::Foundation::Collections::IIterable<T>" },
                { "typename T", "Windows::Foundation::Collections::IVectorView<T>" },
                { "typename T", "Windows::Foundation::Collections::IVector<T>" },
                { "typename T", "Windows::Foundation::Collections::IObservableVector<T>" },
                { "typename T", "Windows::Foundation::Collections::VectorChangedEventHandler<T>" },
                { "", "Windows::Foundation::Collections::IVectorChangedEventArgs" },
                { "typename K, typename V", "Windows::Foundation::Collections::IKeyValuePair<K, V>" },
                { "typename K, typename V", "Windows::Foundation::Collections::IMapView<K, V>" },
                { "typename K, typename V", "Windows::Foundation::Collections::IMap<K, V>" },
                { "typename K, typename V", "Windows::Foundation::Collections::IObservableMap<K, V>" },
                { "typename K, typename V", "Windows::Foundation::Collections::MapChangedEventHandler<K, V>" },
                { "typename K", "Windows::Foundation::Collections::IMapChangedEventArgs<K>" },
            };

            out.write_namespace("std");

            for (auto& generic : generic_interfaces)
            {
                out.write(strings::write_std_hash,
                    generic.params,
                    generic.name,
                    generic.name);
            }

            out.write_namespace();
        }
    }
}
