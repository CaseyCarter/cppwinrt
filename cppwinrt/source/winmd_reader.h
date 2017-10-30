#pragma once

#include "helpers.h"

namespace cppwinrt::meta
{
    struct meta_error
    {
        meta_error(std::string_view message) : message(message) {}
        std::string message;
    };

    enum class type_category
    {
        none,

        enum_v,
        struct_v,
        interface_v,
        class_v,
        delegate_v,
    };

    enum composition_access
    {
        protected_v = 1,
        public_v = 2,
    };

    class type;
    struct signature;
    struct field;
    struct param;
    struct method;
    struct token;
    struct enumerator;
    struct required;
    struct factory_attribute;
    struct composable_attribute;

    using token_callback = std::function<void(token)>;

    struct signature
    {
        PCCOR_SIGNATURE data{};
        IMetaDataImport2* db{};

        token get_token() const noexcept;
        std::vector<std::string> get_generic_params(std::vector<std::string> const& generic_params) const;
        std::string get_name() const;
        std::string get_name(std::vector<std::string> const& generic_params) const;
        std::string get_abi_name() const;
        std::pair<uint32_t, uint32_t> get_struct_size(std::pair<uint32_t, uint32_t>* max_alignment) const;
        CorElementType get_category() const;
        signature next(token_callback callback = {}) const;
    };

    struct field
    {
        std::string name;
        signature type;
    };

    struct param
    {
        std::string name;
        uint32_t flags{};
        signature signature;
        bool is_optional_out = false;

        bool is_in() const noexcept;
        bool is_const() const noexcept;
    };

    struct using_pair
    {
        std::string method_name;
        std::string interface_name;
    };

    struct token
    {
        mdToken handle{};
        IMetaDataImport2* db{};

        explicit operator bool() const noexcept;
        bool is_type_def() const noexcept;
        bool is_type_ref() const noexcept;
        bool is_type_spec() const noexcept;
        bool is_method_def() const noexcept;
        bool is_member_ref() const noexcept;
        bool is_method_spec() const noexcept;
        bool is_interface_impl() const noexcept;
        bool is_field_def() const noexcept;
        bool is_param_def() const noexcept;
        bool is_generic_param() const noexcept;
        bool has_attribute(wchar_t const* attribute) const noexcept;
        bool is_default() const noexcept;
        bool is_overridable() const noexcept;
        bool is_api_contract() const noexcept;
        bool is_flags() const noexcept;
        bool is_static() const noexcept;
        bool get_attribute_string(wchar_t const* attribute, std::string& value) const;

        std::string get_name() const;
        std::string get_name(std::vector<std::string> const& generic_params) const;
        signature get_signature() const;
        token get_definition() const;
        type const* get_type() const;
        std::string get_guid(char const* format) const;
        token get_base() const;
        type const* get_base_type() const;
        token get_extends() const;
        token get_default() const;
        method get_delegate(token_callback callback = {}) const;

        generator<method> get_methods(token_callback callback = {}) const;
        generator<std::string> get_method_names() const;
        generator<enumerator> get_enumerators() const;
        std::vector<field> get_fields(token_callback callback = {}) const;
        std::pair<uint32_t, uint32_t> get_struct_size(std::pair<uint32_t, uint32_t>* max_alignment = nullptr) const;

        std::vector<required> get_interface_required() const;
        std::vector<required> get_class_required() const;
        std::vector<required> get_class_required_excluding_default() const;
        std::vector<required> get_component_class_generated_interfaces() const;
        std::vector<required> get_component_class_interfaces() const;
        std::vector<std::string> get_generic_params() const;
        std::vector<factory_attribute> get_factory_attributes() const;
        std::vector<composable_attribute> get_composable_attributes() const;
        std::vector<required> get_direct_override_interfaces() const;
        std::vector<required> get_all_override_interfaces() const;
        std::vector<required> get_all_nonoverride_interfaces() const;
        std::vector<required> get_component_class_override_fallbacks() const;
        std::vector<required> get_component_class_generated_required() const;
        generator<using_pair> get_interface_usings() const;
        generator<using_pair> get_class_usings() const;

        generator<token> EnumInterfaceImpls() const;
        generator<token> EnumCustomAttributes() const;
        generator<token> EnumMembers() const;
        generator<token> EnumParams() const;
        token GetInterfaceImplProps() const;
        generator<token> EnumGenericParams() const;
    };

    bool operator==(token left, token right) noexcept;
    bool operator!=(token left, token right) noexcept;
    bool operator<(token left, token right) noexcept;

    struct factory_attribute
    {
        type const* type{};
        bool activatable{};
    };

    struct composable_attribute
    {
        type const* type{};
        composition_access access{};

        bool is_public() const noexcept;
        bool is_protected() const noexcept;
    };

    struct required
    {
        std::string name;
        token token;
        std::vector<std::string> generic_params;
    };

    bool operator==(required const& left, required const& right) noexcept;
    bool operator!=(required const& left, required const& right) noexcept;
    bool operator<(required const& left, required const& right) noexcept;

    struct method
    {
        token token;
        std::string raw_name;
        uint32_t flags{};
        param return_type;
        std::vector<param> params;

        bool is_special() const noexcept;
        bool has_return_type() const noexcept;
        std::string get_name() const noexcept;
        std::string get_abi_name() const noexcept;
    };

    struct enumerator
    {
        token token;
        std::string name;
        int32_t value{};
    };

    class type
    {
        std::string buffer;
        size_t offset{};

    public:

        type() = default;
        type(type const&) = delete;
        type& operator=(type const&) = delete;
        type(type&&) = default;
        type& operator=(type&&) = default;

        token token;
        bool is_reference{};
        bool is_filtered() const;

        type(std::string&& name, meta::token token, bool reference);
        std::string_view full_name() const noexcept;
        std::string_view name_space() const noexcept;
        std::string_view name() const noexcept;
    };

    struct namespace_types
    {
        std::vector<type> interfaces;
        std::vector<type> classes;
        std::vector<type> enums;
        std::vector<type> structs;
        std::vector<type> delegates;

        bool has_projected_types() const noexcept;
    };

    using index_type = std::map<std::string, namespace_types>;
    using index_pair = index_type::value_type;

    void open_database(std::wstring const& filename, bool is_reference);
    void build_index();
    index_type const& get_index();
    bool is_foundation_type(std::string_view name);
    type const* find_type(std::string_view full_name, type_category* category = nullptr);

    template <typename... Container>
    generator<type> get_projected_types(bool exclude_references, Container const&... container)
    {
        for (type const& type : get_container_values(container...))
        {
            if (type.is_reference && exclude_references)
            {
                continue;
            }

            co_yield type;
        }
    }

    template <typename... Container>
    generator<type> get_projected_types(Container const&... container)
    {
        for (type const& type : get_projected_types(true, container...))
        {
            co_yield type;
        }
    }
}
