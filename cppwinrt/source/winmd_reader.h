#pragma once

#include "helpers.h"

namespace cppwinrt::meta
{
    constexpr uint32_t max_name_size = 300;
    constexpr uint32_t max_token_count = 100;

    struct meta_error
    {
        meta_error(std::wstring_view message) : message(message) {}
        std::wstring message;
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

    template <typename T>
    using generator = std::experimental::generator<T>;

    class token;
    using token_callback = std::function<void(token const &)>;

    struct param;
    struct delegate;
    struct field;
    struct enumerator;
    struct method;
    struct type;

    struct factory_attribute;
    struct composable_attribute;

    struct signature
    {
        PCCOR_SIGNATURE data{};
        IMetaDataImport2* db{};

        // TODO: move token::* methods that works on signatures here since they're not really about the 
        // token but just need the db...
    };

    struct required_type;

    class token
    {
        mdToken m_handle{};
        IMetaDataImport2* m_db{};

        generator<token> EnumInterfaceImpls() const;
        generator<token> EnumCustomAttributes() const;
        generator<token> EnumMembers() const;
        generator<token> EnumParams() const;
        token GetInterfaceImplProps() const;

        generator<param> enum_param_base() const;
        void unpack_type_def_method(PCCOR_SIGNATURE signature, param& return_type, std::vector<param>& params, token_callback callback = {}) const;
        void unpack_type_spec_method(std::vector<meta::signature> const& var_types, PCCOR_SIGNATURE signature, param& return_type, std::vector<param>& params, token_callback callback = {}) const;

    public:

        token() noexcept = default;

        token(mdToken handle,
            IMetaDataImport2* db) noexcept;

        mdToken handle() const noexcept;
        IMetaDataImport2* db() const noexcept;
        explicit operator bool() const noexcept;
        bool is_type_def() const noexcept;
        bool is_type_ref() const noexcept;
        bool is_type_spec() const noexcept;
        bool is_method_def() const noexcept;
        bool is_interface_impl() const noexcept;
        bool is_field_def() const noexcept;

        generator<method> enum_type_def_methods(token_callback callback = {}) const;
        generator<method> enum_type_spec_methods(std::vector<meta::signature>& var_types, token_callback callback = {}) const;

        std::string get_generic_type_name(PCCOR_SIGNATURE& signature, std::vector<meta::signature> const* var_types = nullptr) const;
        std::string get_type_name_cursor(PCCOR_SIGNATURE& signature, std::vector<meta::signature> const* var_types = nullptr) const;
        std::string get_name(bool dotted = false, std::vector<meta::signature> const* var_types = nullptr) const;
        std::string get_simple_name() const;
        token get_abi_token() const;
        bool has_attribute(wchar_t const* const attribute) const noexcept;
        token find_default_interface() const;
        type const& resolve() const;
        type const& resolve_generic() const;
        method get_delegate(token_callback callback = {}) const;
        generator<field> enum_fields(token_callback callback = {}) const;
        generator<enumerator> enum_enumerators() const;
        generator<method> enum_methods(token_callback callback = {}) const;
        generator<std::string> enum_method_names() const;
        std::pair<bool, std::string_view> get_string(wchar_t const* const attribute) const;
        generator<token> enum_required_interfaces(bool const skip_default) const;
        generator<token> enum_override_interfaces() const;
        std::vector<factory_attribute> enum_factory_attributes() const;
        std::vector<composable_attribute> enum_composable_attributes() const;
        generator<std::pair<std::string, std::string>> enum_interface_usings() const;
        std::string get_guid(char const* format = "0x%08X,0x%04X,0x%04X,{ 0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X }") const;
        PCCOR_SIGNATURE get_type_spec() const;
        token get_type_def() const;

        std::vector<required_type> enum_interface_required_types(std::vector<meta::signature> const* var_types) const;
    };

    inline bool operator==(token left, token right) noexcept
    {
        return left.handle() == right.handle() && left.db() == right.db();
    }

    inline bool operator!=(token left, token right) noexcept
    {
        return !(left == right);
    }

    inline bool operator<(token left, token right) noexcept
    {
        return (left.handle() < right.handle() || (!(right.handle() < left.handle()) && left.db() < right.db()));
    }

    struct required_type
    {
        std::string name;
        token type_def;
    };

    inline bool operator==(required_type const& left, required_type const& right) noexcept
    {
        return left.name == right.name;
    }

    inline bool operator!=(required_type const& left, required_type const& right) noexcept
    {
        return !(left == right);
    }

    inline bool operator<(required_type const& left, required_type const& right) noexcept
    {
        return left.name < right.name;
    }

    struct assembly
    {
        token token;
        std::string name;
    };

    struct enumerator
    {
        token token;
        std::string name;
        int32_t value{};
    };

    struct param
    {
        std::string name;
        PCCOR_SIGNATURE signature{};
        bool in{};
    };

    struct field
    {
        std::string name;
        PCCOR_SIGNATURE signature{};
    };

    struct method
    {
        token token;
        std::string name;
        DWORD flags{};
        param return_type;
        std::vector<param> params;

        bool has_return_type() const noexcept
        {
            return static_cast<CorElementType>(*return_type.signature) != ELEMENT_TYPE_VOID;
        }
    };

    struct type
    {
    private:

        union base
        {
            token token;
            type const* type{};
        };

        std::pair<std::string, uint32_t> m_name;
        token m_token;
        base m_base;
        type_category m_category{};
        bool m_foundation{};
        bool m_sealed{};

    public:

        explicit type(meta::token token,
            type_category category,
            bool foundation,
            std::pair<std::string, uint32_t>&& name,
            bool sealed,
            meta::token base = {});

        void index_base();

        bool is_class() const noexcept;
        bool is_delegate() const noexcept;
        bool is_enum() const noexcept;
        bool is_interface() const noexcept;
        bool is_struct() const noexcept;
        bool is_filtered() const noexcept;
        bool is_sealed() const noexcept;

        token token() const noexcept;
        type_category category() const noexcept;
        std::string_view full_name() const noexcept;
        std::string_view name() const noexcept;
        std::string_view name_space() const noexcept;
        type const* base() const noexcept;

        generator<std::tuple<std::string, std::string, bool>> enum_class_usings() const;
        std::vector<required_type> enum_class_required_types() const;
    };

    using index_type = std::map<std::string, std::vector<type>>;
    using index_pair = index_type::value_type;

    void open_database(std::wstring const& filename, bool foundation);
    void index_types();
    index_type const& get_index();
    type const* resolve(std::string_view name);
    bool is_foundation_type(std::string_view name);
    bool is_filtered_type(std::string_view name);

    struct factory_attribute
    {
        token factory;
        bool activatable{};
        static constexpr std::wstring_view activatable_name{ to_string_view(L"Windows.Foundation.Metadata.ActivatableAttribute") };
        static constexpr std::wstring_view static_name{ to_string_view(L"Windows.Foundation.Metadata.StaticAttribute") };
    };

    struct composable_attribute
    {
        token factory;
        enum composition_type
        {
            protected_v = 1,
            public_v = 2,
        } type;
        bool is_public() const noexcept
        {
            return type == composition_type::public_v;
        }
        bool is_protected() const noexcept
        {
            return type == composition_type::protected_v;
        }
        static constexpr std::wstring_view name{ to_string_view(L"Windows.Foundation.Metadata.ComposableAttribute") };
    };
}
