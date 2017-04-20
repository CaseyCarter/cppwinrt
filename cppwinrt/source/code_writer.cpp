#include "pch.h"
#include "code_writer.h"
#include "version.h"
#include "strings.h"
#include "settings.h"

using namespace std::experimental::filesystem;

namespace cppwinrt
{
    namespace
    {
        std::string_view get_method_name(std::string_view name)
        {
            size_t const pos = name.find('_');

            if (pos == std::string_view::npos)
            {
                return name;
            }
            else
            {
                return name.substr(pos + 1);
            }
        }

        void write_impl_name(output& out, std::string_view code_name)
        {
            for (std::string_view::iterator c = code_name.begin(); c != code_name.end(); ++c)
            {
                if (*c == ':')
                {
                    ++c;
                    out.write('_');
                }
                else
                {
                    out.write(*c);
                }
            }
        }

        void write_type_name(output& out, meta::token token, PCCOR_SIGNATURE signature)
        {
            out.write(token.get_type_name_cursor(signature));
        }

        void write_generic_type_name(output& out, meta::token token, PCCOR_SIGNATURE& signature)
        {
            out.write(token.get_generic_type_name(signature));
        }

        void write_abi_type_name(output& out, meta::token token, PCCOR_SIGNATURE signature)
        {
            CorElementType category = CorSigUncompressElementType(signature);

            switch (category)
            {
            case ELEMENT_TYPE_BOOLEAN:     out.write("bool"); return;
            case ELEMENT_TYPE_CHAR:        out.write("wchar_t"); return;
            case ELEMENT_TYPE_I1:          out.write("int8_t"); return;
            case ELEMENT_TYPE_U1:          out.write("uint8_t"); return;
            case ELEMENT_TYPE_I2:          out.write("int16_t"); return;
            case ELEMENT_TYPE_U2:          out.write("uint16_t"); return;
            case ELEMENT_TYPE_I4:          out.write("int32_t"); return;
            case ELEMENT_TYPE_U4:          out.write("uint32_t"); return;
            case ELEMENT_TYPE_I8:          out.write("int64_t"); return;
            case ELEMENT_TYPE_U8:          out.write("uint64_t"); return;
            case ELEMENT_TYPE_R4:          out.write("float"); return;
            case ELEMENT_TYPE_R8:          out.write("double"); return;
            case ELEMENT_TYPE_STRING:      out.write("HSTRING"); return;
            case ELEMENT_TYPE_GENERICINST:
            case ELEMENT_TYPE_CLASS:
            case ELEMENT_TYPE_OBJECT:      out.write("::IUnknown*"); return;
            case ELEMENT_TYPE_VALUETYPE:
            {
                meta::token param_type{ CorSigUncompressToken(signature), token.db() };
                out.write("abi_t<");
                out.write(param_type.get_name());
                out.write(">");
                return;
            }
            };

            WINRT_ASSERT(false);
        }

        void write_deprecated(output& out, meta::token token)
        {
            std::pair<bool, std::string_view> const pair = token.get_string(L"Windows.Foundation.Metadata.DeprecatedAttribute");

            if (pair.first)
            {
                out.write(strings::write_deprecated, pair.second);
            }
        }

        void write_enumerators(output& out, meta::token token)
        {
            for (meta::enumerator const& enumerator : token.enum_enumerators())
            {
                out.write(strings::write_enumerator,
                    enumerator.name,
                    bind_output(write_deprecated, enumerator.token),
                    enumerator.value);
            }
        }

        void write_enumerators_flag(output& out, meta::token token)
        {
            for (meta::enumerator const& enumerator : token.enum_enumerators())
            {
                out.write(strings::write_enumerator,
                    enumerator.name,
                    bind_output(write_deprecated, enumerator.token),
                    static_cast<uint32_t>(enumerator.value));
            }
        }

        void write_enumeration(output& out, meta::type const& type)
        {
            out.write(strings::write_enumeration,
                bind_output(write_deprecated, type.token()),
                type.name(),
                bind_output(write_enumerators, type.token()));
        }

        void write_enumeration_flag(output& out, meta::type const& type)
        {
            out.write(strings::write_enumeration_flag,
                bind_output(write_deprecated, type.token()),
                type.name(),
                bind_output(write_enumerators_flag, type.token()),
                type.name());
        }

        void write_enum(output& out, meta::type const& type)
        {
            if (type.token().has_attribute(L"System.FlagsAttribute"))
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
            meta::token default_interface = type.token().find_default_interface();

            if (default_interface)
            {
                out.write(strings::write_default_interface,
                    type.full_name(),
                    default_interface.get_name());
            }
        }

        bool is_complex_struct(std::vector<meta::field> const & fields)
        {
            for (meta::field const& field : fields)
            {
                CorElementType const category = static_cast<CorElementType>(*field.signature);

                if (category == ELEMENT_TYPE_STRING || category == ELEMENT_TYPE_GENERICINST)
                {
                    return true;
                }
            }

            return false;
        }

        void write_struct_abi_fields(output& out, meta::token token, std::vector<meta::field> const& fields)
        {
            for (meta::field const& field : fields)
            {
                out.write("    % %;\n",
                    bind_output(write_abi_type_name, token, field.signature),
                    field.name);
            }
        }

        bool write_struct_abi(output& out, meta::type const& type)
        {
            WINRT_ASSERT(type.is_struct());

            std::vector<meta::field> fields;

            for (meta::field const& field : type.token().enum_fields())
            {
                fields.push_back(field);
            }

            if (!is_complex_struct(fields))
            {
                return false;
            }

            out.write(strings::write_struct_abi,
                type.full_name(),
                bind_output(write_struct_abi_fields, type.token(), fields));

            return true;
        }

        void write_abi_method_name(output& out, meta::method const& method)
        {
            std::pair<bool, std::string_view> const overload = method.token.get_string(L"Windows.Foundation.Metadata.OverloadAttribute");

            if (overload.first)
            {
                out.write(overload.second);
            }
            else
            {
                out.write(method.name);
            }
        }

        void write_abi_param(output& out, meta::token token, meta::param const& param, bool is_return = false)
        {
            PCCOR_SIGNATURE signature = param.signature;
            CorElementType category = static_cast<CorElementType>(*signature);
            bool by_ref{};

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                ++signature;
                category = static_cast<CorElementType>(*signature);
            }

            WINRT_ASSERT(category != ELEMENT_TYPE_BYREF);

            if (category != ELEMENT_TYPE_SZARRAY)
            {
                write_abi_type_name(out, token, signature);

                if (!param.in)
                {
                    out.write('*');
                }
            }
            else
            {
                ++signature;

                if (param.in)
                {
                    out.write("uint32_t __%Size, %*",
                        param.name,
                        bind_output(write_abi_type_name, token, signature));
                }
                else if (by_ref || is_return)
                {
                    out.write("uint32_t* __%Size, %**",
                        param.name,
                        bind_output(write_abi_type_name, token, signature));
                }
                else
                {
                    out.write("uint32_t __%Size, %*",
                        param.name,
                        bind_output(write_abi_type_name, token, signature));
                }
            }

            out.write(" %", param.name);
        }

        void write_param_type(output& out, meta::token token, meta::param const& param)
        {
            PCCOR_SIGNATURE signature = param.signature;
            CorElementType category = static_cast<CorElementType>(*signature);
            bool by_ref{};

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                ++signature;
                category = static_cast<CorElementType>(*signature);
            }

            WINRT_ASSERT(category != ELEMENT_TYPE_BYREF);

            if (category < ELEMENT_TYPE_STRING)
            {
                write_type_name(out, token, signature);

                if (!param.in)
                {
                    out.write('&');
                }
            }
            else if (category == ELEMENT_TYPE_STRING)
            {
                if (param.in)
                {
                    out.write("hstring_view");
                }
                else
                {
                    out.write("hstring&");
                }
            }
            else if (category == ELEMENT_TYPE_SZARRAY)
            {
                ++signature;

                if (param.in)
                {
                    out.write("array_view<% const>",
                        bind_output(write_type_name, token, signature));
                }
                else if (by_ref)
                {
                    out.write("com_array<%>&",
                        bind_output(write_type_name, token, signature));
                }
                else
                {
                    out.write("array_view<%>",
                        bind_output(write_type_name, token, signature));
                }
            }
            else
            {
                write_type_name(out, token, signature);

                if (param.in)
                {
                    out.write(" const");
                }

                out.write('&');
            }
        }

        void write_param(output& out, meta::token token, meta::param const& param)
        {
            write_param_type(out, token, param);
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

                write_abi_param(out, method.token, param);
            }

            if (method.has_return_type())
            {
                if (!first)
                {
                    out.write(", ");
                }

                write_abi_param(out, method.token, method.return_type, true);
            }
        }

        void write_interface_abi_methods(output& out, meta::token token)
        {
            for (meta::method const& method : token.enum_methods())
            {
                out.write(strings::write_interface_abi_method,
                    bind_output(write_abi_method_name, method),
                    bind_output(write_abi_params, method));
            }
        }

        void write_delegate_abi_method(output& out, meta::token token)
        {
            meta::method method = token.get_delegate();

            out.write(strings::write_delegate_abi_method,
                bind_output(write_abi_params, method));
        }

        void write_abi_arg(output& out, meta::param const& param, bool is_return = false)
        {
            PCCOR_SIGNATURE signature = param.signature;
            CorElementType category = static_cast<CorElementType>(*signature);
            bool by_ref{};

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                ++signature;
                category = static_cast<CorElementType>(*signature);
            }

            WINRT_ASSERT(category != ELEMENT_TYPE_BYREF);

            if (category < ELEMENT_TYPE_STRING)
            {
                if (!param.in)
                {
                    out.write('&');
                }

                out.write(param.name);
            }
            else if (category == ELEMENT_TYPE_SZARRAY)
            {
                ++signature;

                if (param.in)
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
                if (param.in)
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

        void write_produce_arg(output& out, meta::method const& method, meta::param const& param)
        {
            PCCOR_SIGNATURE signature = param.signature;
            CorElementType category = static_cast<CorElementType>(*signature);
            bool by_ref{};

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                ++signature;
                category = static_cast<CorElementType>(*signature);
            }

            WINRT_ASSERT(category != ELEMENT_TYPE_BYREF);

            if (category < ELEMENT_TYPE_STRING)
            {
                if (!param.in)
                {
                    out.write('*');
                }

                out.write(param.name);
            }
            else if (category == ELEMENT_TYPE_SZARRAY)
            {
                ++signature;

                std::string param_type = method.token.get_type_name_cursor(signature);

                if (param.in)
                {
                    out.write("array_view<% const>(reinterpret_cast<% const *>(%), reinterpret_cast<% const *>(%) + __%Size)",
                        param_type,
                        param_type,
                        param.name,
                        param_type,
                        param.name,
                        param.name);
                }
                else if (by_ref)
                {
                    out.write("detach_abi<%>(__%Size, %)",
                        param_type,
                        param.name,
                        param.name);
                }
                else
                {
                    out.write("detach_abi<%>(__%Size, %)",
                        param_type,
                        param.name,
                        param.name);
                }
            }
            else
            {
                if (param.in)
                {
                    out.write("*reinterpret_cast<% const*>(&%)",
                        bind_output(write_type_name, method.token, signature),
                        param.name);
                }
                else
                {
                    out.write("*reinterpret_cast<%*>(%)",
                        bind_output(write_type_name, method.token, signature),
                        param.name);
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

                write_produce_arg(out, method, param);
            }
        }

        void write_return_type(output& out, meta::method const& method)
        {
            PCCOR_SIGNATURE signature = method.return_type.signature;
            CorElementType category = CorSigUncompressElementType(signature);

            if (category == ELEMENT_TYPE_SZARRAY)
            {
                out.write("com_array<%>",
                    bind_output(write_type_name, method.token, signature));
            }
            else
            {
                write_type_name(out, method.token, method.return_type.signature);
            }
        }

        void write_params(output& out, meta::method const& method)
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

                write_param(out, method.token, param);
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

        void write_interface_method_declarations(output& out, meta::token token)
        {
            for (meta::method const& method : token.enum_methods())
            {
                out.write(strings::write_interface_method_declaration,
                    bind_output(write_deprecated, method.token),
                    bind_output(write_return_type, method),
                    get_method_name(method.name),
                    bind_output(write_params, method));
            }
        }

        void write_interface_abi(output& out, meta::type const& type)
        {
            out.write(strings::write_interface_abi,
                type.full_name(),
                bind_output(write_interface_abi_methods, type.token()));
        }

        void write_delegate_abi(output& out, meta::type const& type)
        {
            out.write(strings::write_delegate_abi,
                type.full_name(),
                bind_output(write_delegate_abi_method, type.token()));
        }

        void write_interface_consume(output& out, meta::type const& type)
        {
            out.write(strings::write_interface_consume,
                bind_output(write_impl_name, type.full_name()),
                bind_output(write_interface_method_declarations, type.token()),
                type.full_name(),
                bind_output(write_impl_name, type.full_name()));
        }

        void write_interface_produce_upcall(output& out, meta::method const& method)
        {
            if (!method.has_return_type())
            {
                out.write("this->shim().%(%)",
                    get_method_name(method.name),
                    bind_output(write_produce_args, method));

                return;
            }

            // TODO: determine if return param is array... else

            out.write("*% = detach_abi(this->shim().%(%))",
                method.return_type.name,
                get_method_name(method.name),
                bind_output(write_produce_args, method));
        }

        void write_produce_cleanup(output& /*out*/, meta::method const& /*method*/)
        {
            // TODO: clear out params
        }

        void write_interface_produce_methods(output& out, meta::type const& type)
        {
            for (meta::method const& method : type.token().enum_methods())
            {
                out.write(strings::write_interface_produce_method,
                    bind_output(write_abi_method_name, method),
                    bind_output(write_abi_params, method),
                    bind_output(write_interface_produce_upcall, method),
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

        void add_required_interfaces(meta::token token, std::vector<std::string> & unique)
        {
            for (meta::token required : token.enum_required_interfaces(false))
            {
                std::string required_name = required.get_name();

                if (unique.end() == std::find(unique.begin(), unique.end(), required_name))
                {
                    unique.push_back(std::move(required_name));
                }
            }
        }

        void remove_default_required_interfaces(meta::token token, std::vector<std::string> & unique)
        {
            if (token.is_type_spec())
            {
                // TODO: implement usings for generics
                //token = token.resolve_generic().token();
                return;
            }

            std::vector<std::string>::iterator found = std::find(unique.begin(), unique.end(), token.get_name());

            if (found != unique.end())
            {
                unique.erase(found);
            }

            if (token.is_type_ref())
            {
                token = token.resolve().token();
            }

            for (meta::token required : token.enum_required_interfaces(false))
            {
                found = std::find(unique.begin(), unique.end(), required.get_name());

                if (found != unique.end())
                {
                    unique.erase(found);
                }
            }
        }

        void write_require(output& out, meta::type const& type, meta::token default_interface)
        {
            std::vector<std::string> required;
            add_required_interfaces(type.token(), required);

            for (meta::type const* next = type.base(); next != nullptr; next = next->base())
            {
                add_required_interfaces(next->token(), required);
            }

            if (default_interface)
            {
                remove_default_required_interfaces(default_interface, required);
            }

            if (required.empty())
            {
                return;
            }

            out.write(strings::write_require,
                type.name());

            for (std::string const& required_name : required)
            {
                out.write(", ");
                out.write(required_name);
            }

            out.write('>');
        }

        void write_class_base(output& out, meta::type const& type)
        {
            if (!type.base())
            {
                return;
            }

            out.write(strings::write_class_base,
                type.name(),
                type.base()->full_name());

            for (meta::type const* next = type.base()->base(); next != nullptr; next = next->base())
            {
                out.write(", ");
                out.write(next->full_name());
            }

            out.write('>');
        }

        void write_interface_usings(output& out, meta::type const& type)
        {
            for (std::pair<meta::token, std::string> const pair : type.token().enum_interface_usings())
            {
                out.write(strings::write_using,
                    bind_output(write_impl_name, pair.first.get_name()),
                    type.name(),
                    pair.second);
            }
        }

        void write_class_usings(output& out, meta::type const& type, meta::token default_interface)
        {
            for (std::tuple<meta::token, std::string, bool> const pair : type.enum_class_usings())
            {
                out.write(strings::write_using,
                    bind_output(write_impl_name, std::get<0>(pair).get_name()),
                    std::get<2>(pair) ? default_interface.get_name() : type.name(),
                    std::get<1>(pair));
            }
        }

        void write_interface_definition(output& out, meta::type const& type)
        {
            WINRT_ASSERT(type.is_interface());

            out.write(strings::write_interface_definition,
                bind_output(write_deprecated, type.token()),
                type.name(),
                type.name(),
                bind_output(write_require, type, meta::token{}),
                type.name(),
                bind_output(write_interface_usings, type));
        }

        void write_delegate_definition(output& out, meta::type const& type)
        {
            WINRT_ASSERT(type.is_delegate());

            meta::method method = type.token().get_delegate();

            out.write(strings::write_delegate_definition,
                bind_output(write_deprecated, type.token()),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                bind_output(write_return_type, method),
                bind_output(write_params, method));
        }

        void write_delegate_call_handler(output& out, meta::method const& method)
        {
            if (!method.has_return_type())
            {
                out.write("(*this)(%)",
                    bind_output(write_produce_args, method));

                return;
            }

            // TODO: determine if return param is array... else

            out.write("*% = detach_abi((*this)(%))",
                method.return_type.name,
                bind_output(write_produce_args, method));
        }

        void write_delegate_produce(output& out, meta::type const& type)
        {
            WINRT_ASSERT(type.is_delegate());
            meta::method method = type.token().get_delegate();

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

            PCCOR_SIGNATURE signature = method.return_type.signature;
            CorElementType const category = CorSigUncompressElementType(signature);

            if (category < ELEMENT_TYPE_PTR ||
                category == ELEMENT_TYPE_VALUETYPE)
            {
                out.write(strings::write_shim_pre,
                    bind_output(write_type_name, method.token, method.return_type.signature),
                    method.return_type.name);
            }
            else if (category == ELEMENT_TYPE_SZARRAY)
            {
                out.write(strings::write_shim_pre_array,
                    bind_output(write_type_name, method.token, signature),
                    method.return_type.name);
            }
            else
            {
                out.write(strings::write_shim_pre_nullptr,
                    bind_output(write_type_name, method.token, method.return_type.signature),
                    method.return_type.name);
            }
        }

        void write_shim_post(output& out, meta::method const& method)
        {
            if (method.has_return_type())
            {
                out.write(strings::write_shim_post,
                    method.return_type.name);
            }
        }

        void write_shim_body(output& out, meta::type const& type, meta::method const& method)
        {
            WINRT_ASSERT(type.is_interface());

            out.write(strings::write_shim_body,
                bind_output(write_shim_pre, method),
                type.full_name(),
                bind_output(write_abi_method_name, method),
                bind_output(write_abi_args, method),
                bind_output(write_shim_post, method));
        }

        void write_delegate_member_definition(output& out, meta::type const& type)
        {
            WINRT_ASSERT(type.is_delegate());
            meta::method method = type.token().get_delegate();

            out.write(strings::write_delegate_member_definition,
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                type.name(),
                bind_output(write_return_type, method),
                type.name(),
                bind_output(write_params, method),
                bind_output(write_shim_pre, method),
                type.name(),
                bind_output(write_abi_args, method),
                bind_output(write_shim_post, method));
        }

        void write_default_constructor_definition(output& out, meta::type const& type)
        {
            WINRT_ASSERT(type.is_class());

            out.write(strings::write_default_constructor_definition,
                type.name(),
                type.name(),
                type.name(),
                type.name());
        }

        void write_constructor_definitions(output& out, meta::type const& type, meta::token factory)
        {
            for (meta::method const& method : factory.enum_methods())
            {
                out.write(strings::write_constructor_definition,
                    type.name(),
                    type.name(),
                    bind_output(write_params, method),
                    type.name(),
                    type.name(),
                    factory.get_name(),
                    method.name,
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

        void write_composable_constructor_definitions(output& out, meta::type const& type, meta::token factory)
        {
            for (meta::method const& method : factory.enum_methods())
            {
                meta::method ctor = method;
                std::string outer_name, inner_name;
                std::tie(outer_name, inner_name) = composable_factory_method_to_constructor(ctor);
                out.write(strings::write_composable_constructor_definition,
                    type.name(),
                    type.name(),
                    bind_output(write_params, ctor),
                    outer_name,
                    inner_name,
                    type.name(),
                    factory.get_name(),
                    method.name,
                    bind_output(write_args, method));
            }
        }

        void write_static_definitions(output& out, meta::type const& type, meta::token factory)
        {
            for (meta::method const& method : factory.enum_methods())
            {
                out.write(strings::write_static_definition,
                    bind_output(write_return_type, method),
                    type.name(),
                    get_method_name(method.name),
                    bind_output(write_params, method),
                    method.has_return_type() ? "return " : "",
                    type.name(),
                    factory.get_name(),
                    get_method_name(method.name),
                    bind_output(write_args, method));

                // TODO: write event method overload if ABI starts with "add_"...
            }
        }

        meta::generator<meta::token> enum_public_composable_constructor_factories(meta::token const& type)
        {
            for (const auto& attr : type.enum_composable_attributes())
            {
                if (attr.is_public())
                {
                    co_yield attr.factory;
                }
            }
        }

        meta::generator<meta::token> enum_protected_composable_constructor_factories(meta::token const& type)
        {
            for (const auto& attr : type.enum_composable_attributes())
            {
                if (attr.is_protected())
                {
                    co_yield attr.factory;
                }
            }
        }

        meta::generator<meta::token> enum_composable_constructor_factories(meta::token const& type)
        {
            for (const auto& attr : type.enum_composable_attributes())
            {
                co_yield attr.factory;
            }
        }

        meta::generator<meta::token> enum_noncomposable_constructor_factories(meta::token const& type)
        {
            for (const auto& attr : type.enum_factory_attributes())
            {
                if (attr.activatable)
                {
                    co_yield attr.factory;
                }
            }
        }

        meta::generator<meta::token> enum_static_factories(meta::token const& type)
        {
            for (const auto& attr : type.enum_factory_attributes())
            {
                if (!attr.activatable)
                {
                    co_yield attr.factory;
                }
            }
        }

        void write_class_member_definitions(output& out, meta::type const& type)
        {
            WINRT_ASSERT(type.is_class());

            for (const meta::token& factory : enum_noncomposable_constructor_factories(type.token()))
            {
                if (factory)
                {
                    write_constructor_definitions(out, type, factory);
                }
                else
                {
                    write_default_constructor_definition(out, type);
                }
            }

            for (const meta::token& factory : enum_public_composable_constructor_factories(type.token()))
            {
                write_composable_constructor_definitions(out, type, factory);
            }

            for (const meta::token& factory : enum_static_factories(type.token()))
            {
                write_static_definitions(out, type, factory);
            }
        }

        void write_constructor_declarations(output& out, meta::type const& type)
        {
            for (const meta::token& factory : enum_noncomposable_constructor_factories(type.token()))
            {
                if (factory)
                {
                    for (meta::method const& method : factory.enum_methods())
                    {
                        out.write(strings::write_constructor_declaration,
                            bind_output(write_deprecated, method.token),
                            type.name(),
                            bind_output(write_params, method));
                    }
                }
                else
                {
                    out.write(strings::write_default_constructor_declaration,
                        type.name());
                }
            }
            for (const meta::token& factory : enum_public_composable_constructor_factories(type.token()))
            {
                for (meta::method method : factory.enum_methods())
                {
                    composable_factory_method_to_constructor(method);
                    out.write(strings::write_constructor_declaration,
                        bind_output(write_deprecated, method.token),
                        type.name(),
                        bind_output(write_params, method));
                }
            }
        }

        void write_static_declarations(output& out, meta::type const& type)
        {
            for (const meta::token& factory : enum_static_factories(type.token()))
            {
                for (meta::method const& method : factory.enum_methods())
                {
                    out.write(strings::write_static_method_declaration,
                        bind_output(write_deprecated, method.token),
                        bind_output(write_return_type, method),
                        get_method_name(method.name),
                        bind_output(write_params, method));
                }
            }
        }

        void write_class_definition(output& out, meta::type const& type)
        {
            WINRT_ASSERT(type.is_class());

            meta::token default_interface = type.token().find_default_interface();

            if (default_interface)
            {
                out.write(strings::write_class_definition,
                    bind_output(write_deprecated, type.token()),
                    type.name(),
                    default_interface.get_name(),
                    bind_output(write_class_base, type),
                    bind_output(write_require, type, default_interface),
                    type.name(),
                    bind_output(write_constructor_declarations, type),
                    bind_output(write_class_usings, type, default_interface),
                    bind_output(write_static_declarations, type));
            }
            else
            {
                out.write(strings::write_static_class_definition,
                    bind_output(write_deprecated, type.token()),
                    type.name(),
                    type.name(),
                    bind_output(write_static_declarations, type));
            }
        }

        void write_struct_fields(output& out, meta::type const& type)
        {
            for (meta::field const& field : type.token().enum_fields())
            {
                out.write("    % %;\n",
                    bind_output(write_type_name, type.token(), field.signature),
                    field.name);
            }
        }

        void write_struct_definition(output& out, meta::type const& type)
        {
            WINRT_ASSERT(type.is_struct());

            out.write(strings::write_struct_definition,
                bind_output(write_deprecated, type.token()),
                type.name(),
                bind_output(write_struct_fields, type));
        }

        void write_shims(output& out, meta::type const& type)
        {
            WINRT_ASSERT(type.is_interface());

            for (meta::method const& method : type.token().enum_methods())
            {
                out.write(strings::write_shim,
                    bind_output(write_return_type, method),
                    bind_output(write_impl_name, type.full_name()),
                    get_method_name(method.name),
                    bind_output(write_params, method));

                write_shim_body(out, type, method);
            }
        }

        void write_interface_override_method_definitions(output& out, meta::token const& type)
        {
            for (auto const& method : type.enum_methods())
            {
                out.write(strings::write_interface_override_method_definition,
                    bind_output(write_return_type, method),
                    type.get_simple_name(),
                    get_method_name(method.name),
                    bind_output(write_params, method),
                    type.get_simple_name(),
                    get_method_name(method.name),
                    bind_output(write_args, method));
            }
        }

        void write_interface_override_method_declarations(output& out, meta::token const& type)
        {
            for (auto const& method : type.enum_methods())
            {
                out.write(strings::write_interface_override_method_declaration,
                    bind_output(write_return_type, method),
                    get_method_name(method.name),
                    bind_output(write_params, method));
            }
        }

        void write_interface_override(output& out, meta::token const& type)
        {
            out.write(strings::write_interface_override,
                type.get_simple_name(),
                type.get_simple_name(),
                type.get_name(),
                bind_output(write_interface_override_method_declarations, type));
        }

        void write_class_override_constructors(output& out, meta::type const& type)
        {
            for (const meta::token& factory : enum_composable_constructor_factories(type.token()))
            {
                for (meta::method method : factory.enum_methods())
                {
                    composable_factory_method_to_constructor(method);
                    const char* separator = method.params.empty() ? "" : ", ";
                    out.write(strings::write_class_override_constructor,
                        type.name(),
                        bind_output(write_params, method),
                        type.name(),
                        factory.get_simple_name(),
                        method.name,
                        bind_output(write_args, method),
                        separator);
                }
            }
        }

        bool has_composable_constructor(meta::type const& type)
        {
            for (const auto& factory : enum_composable_constructor_factories(type.token()))
            {
                for (const auto& method : factory.enum_methods())
                {
                    method;
                    return true;
                }
            }
            return false;
        }

        void write_class_override(output& out, meta::type const& type)
        {
            if (!has_composable_constructor(type))
            {
                return;
            }
            std::vector<meta::token> override_interfaces;
            for (meta::type const* current = &type; current != nullptr; current = current->base())
            {
                for (meta::token i : current->token().enum_override_interfaces())
                {
                    override_interfaces.push_back(std::move(i));
                }
            }

            std::vector<meta::token> required_interfaces;
            for (meta::type const* current = &type; current != nullptr; current = current->base())
            {
                for (meta::token i : current->token().enum_required_interfaces(false))
                {
                    if (std::find(override_interfaces.begin(), override_interfaces.end(), i) == override_interfaces.end())
                    {
                        required_interfaces.push_back(std::move(i));
                    }
                }
            }

            auto comma_names = [](const std::vector<meta::token>& names)
            {
                std::string result;
                for (const meta::token& token : names)
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

            auto require_names = [&comma_names](const std::vector<meta::token>& names)
            {
                return comma_names(names);
            };

            auto fallbacks = [](const std::vector<meta::token>& names)
            {
                std::string result;
                bool first = true;
                for (const meta::token& token : names)
                {
                    if (first)
                    {
                        result += "\n    ";
                    }
                    first = false;
                    result += ", ";
                    result += token.get_name();
                    result += "T<D>";
                }
                return result;
            };

            for (const auto& attr : type.token().enum_composable_attributes())
            {
                auto name = attr.factory.get_name();
            }

            out.write(strings::write_class_override,
                type.token().get_simple_name(),
                overrides_names(override_interfaces),
                require_names(required_interfaces),
                fallbacks(override_interfaces),
                type.token().get_simple_name(),
                bind_output(write_class_override_constructors, type));
        }

        void write_category_field_types(output& out, std::string const & category, meta::type const& type)
        {
            bool first = true;

            out.write(category);
            out.write("<");

            for (meta::field const& field : type.token().enum_fields())
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    out.write(",");
                }

                write_type_name(out, type.token(), field.signature);
            }

            out.write(">");
        }

        bool has_module_type(meta::index_pair const& ns)
        {
            for (meta::type const& type : ns.second)
            {
                if (!type.is_foundational())
                {
                    return true;
                }
            }

            return false;
        }

        void write_edit_warning_header(output& out)
        {
            out.write(strings::write_edit_warning_header,
                CPPWINRT_VERSION_STRING);
        }
    }

    void write_projection(output& out)
    {
        meta::index_type const& index = meta::get_index();

        write_edit_warning_header(out);
        write_winrt_namespace_begin(out);

        for (meta::index_pair const& ns : index)
        {
            if (!has_module_type(ns))
            {
                continue;
            }

            out.write_namespace(ns.first);
            write_forwards(out, ns.second);
        }

        out.write_namespace("impl");
        out.write("\n");

        for (meta::index_pair const& ns : index)
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
        for (meta::index_pair const& ns : index)
        {
            write_abi(out, ns.second);
        }

        for (meta::index_pair const& ns : index)
        {
            if (!has_module_type(ns))
            {
                continue;
            }

            out.write_namespace(ns.first);
            write_interface_definitions(out, ns.second);
            write_delegate_definitions(out, ns.second);
            write_struct_definitions(out, ns.second);
        }

        // This is separate from the previous set because a base class must be defined before use
        // and we must therefore define the default interfaces before the runtime classes are defined.
        for (meta::index_pair const& ns : index)
        {
            if (!has_module_type(ns))
            {
                continue;
            }

            out.write_namespace(ns.first);
            write_class_definitions(out, ns.second);
        }

        out.write_namespace("impl");

        for (meta::index_pair const& ns : index)
        {
            write_interface_member_definitions(out, ns.second);
            write_delegate_produce(out, ns.second);
            write_produce(out, ns.second);
        }

        for (meta::index_pair const& ns : index)
        {
            if (!has_module_type(ns))
            {
                continue;
            }
            out.write_namespace(ns.first);
            write_interface_overrides(out, ns.second);
        }

        for (meta::index_pair const& ns : index)
        {
            if (!has_module_type(ns))
            {
                continue;
            }
            out.write_namespace(ns.first);
            write_class_overrides(out, ns.second);
        }

        for (meta::index_pair const& ns : index)
        {
            if (!has_module_type(ns))
            {
                continue;
            }

            out.write_namespace(ns.first);
            write_class_member_definitions(out, ns.second);
            write_delegate_member_definitions(out, ns.second);
        }

        write_winrt_namespace_end(out);
    }

    void write_dot_name(output& out, std::string_view code_name)
    {
        for (std::string_view::iterator c = code_name.begin(); c != code_name.end(); ++c)
        {
            if (*c == ':')
            {
                ++c;
                out.write('.');
            }
            else
            {
                out.write(*c);
            }
        }
    }

    void write_logo(output& out)
    {
        time_t t{ time(nullptr) };
        tm tm{};
        localtime_s(&tm, &t);

        out.write(strings::write_logo, CPPWINRT_VERSION_STRING, 1900 + tm.tm_year);
    }

    void write_warning(output& out, char const* const format)
    {
        out.write(format, CPPWINRT_VERSION_STRING);
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
        out.write(strings::base_string_hstring_ref);
        out.write(strings::base_string_operators);
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
        out.write(strings::base_collections_vector);
        out.write(strings::base_collections_map);

        out.write(strings::base_foundation);
        out.write(strings::base_chrono);
        out.write(strings::base_async_consume);
        out.write(strings::base_async_produce);
        out.write(strings::base_await_consume);
        out.write(strings::base_await_produce);
        out.write(strings::base_reference);

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

        write_warning_pop(out);
    }

    void write_names(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            out.write(strings::write_name,
                type.full_name(),
                bind_output(write_dot_name, type.full_name()));
        }
    }

    void write_categories(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_struct())
            {
                out.write(strings::write_category,
                    type.full_name(),
                    bind_output(write_category_field_types, "struct_category", type));

                continue;
            }

            std::string_view category;

            if (type.is_class())
            {
                category = "class_category";
            }
            else if (type.is_interface())
            {
                category = "interface_category";
            }
            else if (type.is_delegate())
            {
                category = "delegate_category";
            }
            else if (type.is_enum())
            {
                category = "enum_category";
            }
            else
            {
                WINRT_ASSERT(false);
            }

            out.write(strings::write_category,
                type.full_name(),
                category);
        }
    }

    void write_guids(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_interface() || type.is_delegate())
            {
                out.write(strings::write_guid,
                    type.full_name(),
                    type.token().get_guid());
            }
        }
    }

    void write_forwards(output& out, std::vector<meta::type> const& types)
    {
        bool first = true;

        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_enum())
            {
                write_enum(out, type);
            }
            else
            {
                if (first)
                {
                    first = false;
                    out.write("\n");
                }

                out.write("struct %;\n", type.name());
            }
        }
    }

    void write_default_interfaces(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_class())
            {
                write_default_interface(out, type);
            }
        }
    }

    void write_abi(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_interface())
            {
                write_interface_abi(out, type);
            }
            else if (type.is_delegate())
            {
                write_delegate_abi(out, type);
            }
        }
    }

    bool write_struct_abi(output& out, std::vector<meta::type> const& types)
    {
        bool struct_written = false;

        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_struct())
            {
                if (write_struct_abi(out, type))
                {
                    struct_written = true;
                }
            }
        }

        return struct_written;
    }

    void write_consume(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_interface())
            {
                write_interface_consume(out, type);
            }
        }
    }

    void write_produce(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_interface())
            {
                write_interface_produce(out, type);
            }
        }
    }

    void write_interface_definitions(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_interface())
            {
                write_interface_definition(out, type);
            }
        }
    }

    void write_delegate_definitions(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_delegate())
            {
                write_delegate_definition(out, type);
            }
        }
    }

    void write_class_definitions(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_class())
            {
                write_class_definition(out, type);
            }
        }
    }

    void write_params_test(output& out, meta::method const& method)
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
                bind_output(write_param_type, method.token, param));
        }
    }

    void write_interface_test(output& out, std::string_view class_name, meta::token const& token)
    {
        // todo: ignore generics for testing until requireds are working
        if (!token.is_type_def())
        {
            return;
        }
        auto interface_name = token.get_name();
        out.write(R"(
    // %)",
            interface_name);
        for (meta::method const& method : token.enum_methods())
        {
            auto method_name = get_method_name(method.name);

            out.write(R"(
    { %o.%%(%); })",
                [&](output& out)
            {
                if (method.has_return_type())
                {
                    out.write("% r = ",
                        bind_output(write_return_type, method));
                }
            },
                // Special case: Windows.UI.Xaml.Controls.Maps.MapControl inherits two Style overloads with same arity.
                // Add explicit interface cast to disambiguate.
                [&](output& out)
            {
                if ((method_name == "Style") && (class_name == "MapControl"))
                {
                    out.write("as<%>().", interface_name);
                }
            },
                method_name,
                bind_output(write_params_test, method));
        }
    }

    void write_class_test(output& out,
        std::string const& namespace_name,
        meta::type const& type)
    {
        WINRT_ASSERT(type.is_class());

        meta::token default_interface = type.token().find_default_interface();
        auto class_name = type.name();
        if (default_interface)
        {
            out.write(
                R"({
    %::% o{nullptr};%
})",
namespace_name,
class_name,
[&](output& out)
            {
                for (meta::token const& token : type.token().enum_required_interfaces(false))
                {
                    write_interface_test(out, class_name, token);
                }
            });
        }
        else
        {
            // todo: write static method invocations
            //out.write(strings::write_static_class_definition,
            //    bind_output(write_deprecated, type.token()),
            //    type.name(),
            //    type.name(),
            //    bind_output(write_static_declarations, factories));
        }
    }

    void write_class_tests(output& out,
        std::string const& namespace_name,
        std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_class())
            {
                write_class_test(out, namespace_name, type);
            }
        }
    }

    void write_test(output& out,
        std::string const& namespace_name,
        std::vector<meta::type> const& types)
    {
        std::string code_namespace;
        for (auto& ch : namespace_name)
        {
            if (ch == '.')
            {
                code_namespace += "::";
                continue;
            }
            code_namespace += ch;
        }

        out.write(
            R"(#include "pch.h"
#include "%.h"

void t()
{
%
})",
namespace_name,
bind_output(write_class_tests, code_namespace, types));
    }

    void write_struct_definitions(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_struct())
            {
                write_struct_definition(out, type);
            }
        }
    }

    void write_interface_member_definitions(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_interface())
            {
                write_shims(out, type);
            }
        }
    }

    void write_class_member_definitions(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_class())
            {
                write_class_member_definitions(out, type);
            }
        }
    }

    void write_interface_overrides(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }
            if (type.is_class())
            {
                for (const auto& token : type.token().enum_override_interfaces())
                {
                    write_interface_override(out, token);
                }
            }
        }
    }

    void write_interface_override_methods(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }
            if (type.is_class())
            {
                for (const auto& token : type.token().enum_override_interfaces())
                {
                    write_interface_override_method_definitions(out, token);
                }
            }
        }
    }

    void write_class_overrides(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }
            if (type.is_class())
            {
                write_class_override(out, type);
            }
        }
    }

    void write_delegate_produce(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_delegate())
            {
                write_delegate_produce(out, type);
            }
        }
    }

    void write_delegate_member_definitions(output& out, std::vector<meta::type> const& types)
    {
        for (meta::type const& type : types)
        {
            if (type.is_foundational())
            {
                continue;
            }

            if (type.is_delegate())
            {
                write_delegate_member_definition(out, type);
            }
        }
    }

    void write_include(output& out, std::string const& include)
    {
        out.write("#include \"");
        out.write(include);
        out.write("\"\n");
    }

    std::vector<meta::token> get_module_instance_interfaces(meta::type const& type)
    {
        std::vector<meta::token> interfaces;

        for (meta::token required : type.token().enum_required_interfaces(false))
        {
            interfaces.push_back(required);
        }

        std::sort(interfaces.begin(), interfaces.end());
        interfaces.erase(std::unique(interfaces.begin(), interfaces.end()), interfaces.end());
        return interfaces;
    }

    void write_component_instance_interfaces(output& out, meta::type const& type)
    {
        std::vector<meta::token> interfaces = get_module_instance_interfaces(type);

        for (meta::token required : interfaces)
        {
            out.write(", ");
            out.write(required.get_name());
        }
    }

    void write_component_factory_interfaces(output& out, meta::type const& type)
    {
        for (meta::factory_attribute attribute : type.token().enum_factory_attributes())
        {
            if (!attribute.factory) // IActivationFactory
            {
                continue;
            }

            out.write(", ");
            out.write(attribute.factory.get_name());
        }
    }

    void write_component_factory_forwarding_constructors(output& out, meta::type const& type, meta::token factory)
    {
        meta::token default_interface = type.token().find_default_interface();

        for (meta::method const& method : factory.enum_methods())
        {
            out.write(strings::write_component_factory_forwarding_constructor,
                default_interface.get_name(),
                method.name,
                bind_output(write_params, method),
                bind_output(write_args, method));
        }
    }

    void write_component_factory_forwarding_statics(output& out, meta::token factory)
    {
        for (meta::method const& method : factory.enum_methods())
        {
            out.write(strings::write_component_factory_forwarding_static,
                bind_output(write_return_type, method),
                get_method_name(method.name),
                bind_output(write_params, method),
                method.has_return_type() ? "return " : "",
                get_method_name(method.name),
                bind_output(write_args, method));
        }
    }

    std::vector<meta::factory_attribute> get_module_factory_attributes(meta::token type)
    {
        meta::generator<meta::factory_attribute> enum_factory_attributes = type.enum_factory_attributes();
        return{ enum_factory_attributes.begin(), enum_factory_attributes.end() };
    }

    void write_component_factory_forwarding_methods(output& out, meta::type const& type)
    {
        std::vector<meta::factory_attribute> factory_attributes = get_module_factory_attributes(type.token());

        bool default_activation{};

        for (meta::factory_attribute const& attribute : factory_attributes)
        {
            if (attribute.activatable && !attribute.factory)
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
                if (!attribute.factory)
                {
                    continue;
                }

                write_component_factory_forwarding_constructors(out, type, attribute.factory);
            }
        }

        for (meta::factory_attribute const& attribute : factory_attributes)
        {
            if (!attribute.activatable)
            {
                write_component_factory_forwarding_statics(out, attribute.factory);
            }
        }
    }

    void write_component_header(std::vector<meta::type const*> const& types)
    {
        output out;
        write_warning(out, strings::write_edit_warning_header);

        path projection_path = settings::first_input.filename();
        projection_path.replace_extension(".h");

        out.write("\n#include \"%\"\n",
            projection_path.string());

        write_winrt_namespace_begin(out);

        out.write_namespace("impl");
        out.write(strings::write_component_lock_declaration);

        for (meta::type const* type : types)
        {
            if (!type->is_class())
            {
                continue;
            }

            out.write_namespace(std::string(type->name_space()) + ".implementation");

            out.write(strings::write_component_class_base,
                type->name(),
                bind_output(write_component_instance_interfaces, *type),
                bind_output(write_dot_name, type->full_name()),
                type->name(),
                bind_output(write_component_factory_interfaces, *type),
                bind_output(write_dot_name, type->full_name()),
                bind_output(write_component_factory_forwarding_methods, *type));
        }

        write_winrt_namespace_end(out);

        path filename = settings::output;
        filename /= "module.h";
        out.save_as(filename.string());
    }

    void write_component_class_includes(output& out, std::vector<meta::type const*> const& types)
    {
        for (meta::type const* type : types)
        {
            if (type->is_class())
            {
                out.write("#include \"%.h\"\n",
                    bind_output(write_dot_name, type->name()));
            }
        }
    }

    void write_component_class_activations(output& out, std::vector<meta::type const*> const& types)
    {
        for (meta::type const* type : types)
        {
            if (type->is_class())
            {
                out.write(strings::write_component_class_activation,
                    bind_output(write_dot_name, type->full_name()),
                    type->name_space(),
                    type->name());
            }
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

    void write_component_class_constructor_declarations(output& out, meta::type const& type, meta::token factory)
    {
        for (meta::method const& method : factory.enum_methods())
        {
            out.write("        %(%);\n",
                type.name(),
                bind_output(write_params, method));
        }
    }

    void write_component_class_static_declarations(output& out, meta::token factory)
    {
        for (meta::method const& method : factory.enum_methods())
        {
            out.write("        static % %(%);\n",
                bind_output(write_return_type, method),
                get_method_name(method.name),
                bind_output(write_params, method));
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
        std::vector<meta::factory_attribute> factory_attributes = get_module_factory_attributes(type.token());

        bool default_activation{};

        for (meta::factory_attribute const& attribute : factory_attributes)
        {
            if (attribute.activatable && !attribute.factory)
            {
                default_activation = true;
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
                if (!attribute.factory)
                {
                    continue;
                }

                write_component_class_constructor_declarations(out, type, attribute.factory);
            }
        }

        out.write("\n");

        std::vector<meta::token> interfaces = get_module_instance_interfaces(type);

        for (meta::token required : interfaces)
        {
            // TODO: the required interface may be a typespec, in which case we need to resolve
            // the generic to a typedef and perform the specialization here so that the concrete
            // runtime class has the necessary method stubs for the developer to implement.
            if (required.is_type_spec()) continue;

            for (meta::method const& method : required.enum_methods())
            {
                out.write("        % %(%);\n",
                    bind_output(write_return_type, method),
                    get_method_name(method.name),
                    bind_output(write_params, method));
            }
        }

        if (has_statics(factory_attributes))
        {
            out.write("\n");

            for (meta::factory_attribute const& attribute : factory_attributes)
            {
                if (!attribute.activatable)
                {
                    write_component_class_static_declarations(out, attribute.factory);
                }
            }
        }
    }

    void write_component_class_constructor_definitions(output& out, meta::type const& type, meta::token factory)
    {
        for (meta::method const& method : factory.enum_methods())
        {
            out.write(strings::write_component_class_constructor_definition,
                type.name(),
                type.name(),
                bind_output(write_params, method));
        }
    }

    void write_component_class_static_definitions(output& out, meta::type const& type, meta::token factory)
    {
        for (meta::method const& method : factory.enum_methods())
        {
            out.write(strings::write_component_class_static_definition,
                bind_output(write_return_type, method),
                type.name(),
                get_method_name(method.name),
                bind_output(write_params, method));
        }
    }

    void write_component_class_member_definitions(output& out, meta::type const& type)
    {
        for (meta::factory_attribute const& attribute : type.token().enum_factory_attributes())
        {
            if (attribute.activatable)
            {
                if (!attribute.factory)
                {
                    continue;
                }

                write_component_class_constructor_definitions(out, type, attribute.factory);
            }
        }

        std::vector<meta::token> interfaces = get_module_instance_interfaces(type);

        for (meta::token required : interfaces)
        {
            // TODO: the required interface may be a typespec, in which case we need to resolve
            // the generic to a typedef and perform the specialization here so that the concrete
            // runtime class has the necessary method stubs for the developer to implement.
            if (required.is_type_spec()) continue;

            for (meta::method const& method : required.enum_methods())
            {
                out.write(strings::write_component_interface_method_definition,
                    bind_output(write_return_type, method),
                    type.name(),
                    get_method_name(method.name),
                    bind_output(write_params, method));
            }
        }

        for (meta::factory_attribute const& attribute : type.token().enum_factory_attributes())
        {
            if (!attribute.activatable)
            {
                write_component_class_static_definitions(out, type, attribute.factory);
            }
        }
    }

    void write_component_class_header(meta::type const& type)
    {
        path filename = settings::output;
        filename /= std::string(type.name());
        filename += ".h";

        if (exists(filename))
        {
            return;
        }

        output out;

        out.write(strings::write_component_class_header,
            type.name_space(),
            type.name(),
            type.name(),
            type.name(),
            bind_output(write_component_class_member_declarations, type),
            type.name(),
            type.name(),
            type.name(),
            type.name());

        out.save_as(filename.string());
    }

    void write_component_class_source(meta::type const& type)
    {
        path filename = settings::output;
        filename /= std::string(type.name());
        filename += ".cpp";

        if (exists(filename))
        {
            return;
        }

        output out;

        out.write(strings::write_component_class_source,
            type.name(),
            type.name_space(),
            bind_output(write_component_class_member_definitions, type));

        out.save_as(filename.string());
    }
}
