#include "pch.h"
#include "winmd_reader.h"

using namespace std::experimental::filesystem;

namespace cppwinrt::meta
{
    namespace
    {
        class database
        {
            winrt::com_ptr<IMetaDataImport2> m_db;
            mdToken m_system_class{};
            mdToken m_system_enum{};
            mdToken m_system_struct{};
            mdToken m_system_delegate{};
            mdToken m_system_attribute{};

        public:

            database(database const&) = delete;
            database& operator=(database const&) = delete;
            database(database&&) = default;
            database& operator=(database&&) = default;
            explicit database(winrt::com_ptr<IMetaDataImport2>&& db);

            generator<type> enum_types(bool foundation) const;
        };

        static std::wstring_view const activatable_attribute{ L"Windows.Foundation.Metadata.ActivatableAttribute" };
        static std::wstring_view const static_attribute{ L"Windows.Foundation.Metadata.StaticAttribute" };

        winrt::com_ptr<IMetaDataDispenser> get_dispenser()
        {
            winrt::com_ptr<IMetaDataDispenser> dispenser;

            winrt::check_hresult(MetaDataGetDispenser(CLSID_CorMetaDataDispenser,
                IID_IMetaDataDispenser,
                reinterpret_cast<void**>(put_abi(dispenser))));

            return dispenser;
        }

        struct enum_handle
        {
            IMetaDataImport2* db{};
            HCORENUM value{};

            operator HCORENUM*() noexcept
            {
                return &value;
            }

            ~enum_handle() noexcept
            {
                if (value)
                {
                    db->CloseEnum(value);
                }
            }
        };

        mdToken get_mscorlib(IMetaDataImport2* db)
        {
            enum_handle eh{ db };
            std::array<mdToken, max_token_count> token_buffer;
            ULONG actual_token_count{};
            std::array<wchar_t, max_name_size> name_buffer;
            ULONG actual_name_size{};
            winrt::com_ptr<IMetaDataAssemblyImport> assembly;

            winrt::check_hresult(db->QueryInterface(IID_IMetaDataAssemblyImport,
                reinterpret_cast<void**>(put_abi(assembly))));

            while (S_OK == assembly->EnumAssemblyRefs(eh,
                token_buffer.data(),
                max_token_count,
                &actual_token_count))
            {
                for (ULONG i = 0; i != actual_token_count; ++i)
                {
                    winrt::check_hresult(assembly->GetAssemblyRefProps(token_buffer[i],
                        nullptr,
                        nullptr,
                        name_buffer.data(),
                        max_name_size,
                        &actual_name_size,
                        nullptr,
                        nullptr,
                        nullptr,
                        nullptr));

                    if (0 == wcscmp(name_buffer.data(), L"mscorlib"))
                    {
                        return token_buffer[i];
                    }
                }
            }

            WINRT_ASSERT(false);
            return 0;
        }

        mdToken find_system_type(winrt::com_ptr<IMetaDataImport2> const& db, mdToken mscorlib, wchar_t const* const name) noexcept
        {
            mdToken token{};
            db->FindTypeRef(mscorlib, name, &token);
            return token;
        }

        generator<std::string_view> enum_foundation_types()
        {
            co_yield "Windows.Foundation.Collections.IIterable`1";
            co_yield "Windows.Foundation.Collections.IIterator`1";
            co_yield "Windows.Foundation.Collections.IVectorView`1";
            co_yield "Windows.Foundation.Collections.IVector`1";
            co_yield "Windows.Foundation.Collections.IKeyValuePair`2";
            co_yield "Windows.Foundation.Collections.IMap`2";
            co_yield "Windows.Foundation.Collections.IMapView`2";
            co_yield "Windows.Foundation.Collections.IObservableVector`1";
            co_yield "Windows.Foundation.Collections.IMapChangedEventArgs`1";
            co_yield "Windows.Foundation.Collections.IObservableMap`2";

            co_yield "Windows.Foundation.IAsyncOperationWithProgress`2";
            co_yield "Windows.Foundation.IAsyncOperation`1";
            co_yield "Windows.Foundation.IAsyncActionWithProgress`1";
            co_yield "Windows.Foundation.IReference`1";
            co_yield "Windows.Foundation.IReferenceArray`1";

            co_yield "Windows.Foundation.AsyncOperationWithProgressCompletedHandler`2";
            co_yield "Windows.Foundation.AsyncOperationCompletedHandler`1";
            co_yield "Windows.Foundation.AsyncOperationProgressHandler`2";
            co_yield "Windows.Foundation.AsyncActionWithProgressCompletedHandler`1";
            co_yield "Windows.Foundation.AsyncActionProgressHandler`1";
            co_yield "Windows.Foundation.AsyncActionCompletedHandler";
            co_yield "Windows.Foundation.TypedEventHandler`2";
            co_yield "Windows.Foundation.EventHandler`1";

            co_yield "Windows.Foundation.IAsyncInfo";
            co_yield "Windows.Foundation.IAsyncAction";

            co_yield "Windows.Foundation.AsyncStatus";
            co_yield "Windows.Foundation.DateTime";
            co_yield "Windows.Foundation.TimeSpan";
            co_yield "Windows.Foundation.Point";
            co_yield "Windows.Foundation.Size";
            co_yield "Windows.Foundation.Rect";
            co_yield "Windows.Foundation.HResult";
            co_yield "Windows.Foundation.EventRegistrationToken";

            co_yield "Windows.Foundation.Collections.CollectionChange";
            co_yield "Windows.Foundation.Collections.VectorChangedEventHandler`1";
            co_yield "Windows.Foundation.Collections.MapChangedEventHandler`2";
            co_yield "Windows.Foundation.Collections.IVectorChangedEventArgs";
        }

        generator<std::pair<std::wstring_view, std::string_view>> enum_renamed_types()
        {
            co_yield{ L"System.Guid", "GUID" };
            co_yield{ L"Windows.Foundation.EventRegistrationToken", "event_token" };
            co_yield{ L"Windows.Foundation.HResult", "HRESULT" };

            co_yield{ L"Windows.Foundation.Numerics.Vector2", "Windows::Foundation::Numerics::float2" };
            co_yield{ L"Windows.Foundation.Numerics.Vector3", "Windows::Foundation::Numerics::float3" };
            co_yield{ L"Windows.Foundation.Numerics.Vector4", "Windows::Foundation::Numerics::float4" };
            co_yield{ L"Windows.Foundation.Numerics.Matrix3x2", "Windows::Foundation::Numerics::float3x2" };
            co_yield{ L"Windows.Foundation.Numerics.Matrix4x4", "Windows::Foundation::Numerics::float4x4" };
            co_yield{ L"Windows.Foundation.Numerics.Plane", "Windows::Foundation::Numerics::plane" };
            co_yield{ L"Windows.Foundation.Numerics.Quaternion", "Windows::Foundation::Numerics::quaternion" };
        }

        static winrt::com_ptr<IMetaDataDispenser> m_dispenser{ get_dispenser() };
        static std::vector<std::pair<database, bool>> m_databases;
        static index_type m_index;

        void next_token(PCCOR_SIGNATURE& signature, IMetaDataImport2* db, token_callback callback)
        {
            // Advance the signature pointer by reading the current parameter information. 

            CorElementType category = CorSigUncompressElementType(signature);

            if (category < ELEMENT_TYPE_PTR || category == ELEMENT_TYPE_OBJECT)
            {
                return;
            }

            if (category == ELEMENT_TYPE_BYREF)
            {
                next_token(signature, db, callback);
                return;
            }

            if (category == ELEMENT_TYPE_SZARRAY)
            {
                next_token(signature, db, callback);
                return;
            }

            if (category == ELEMENT_TYPE_VALUETYPE || category == ELEMENT_TYPE_CLASS)
            {
                mdToken token = CorSigUncompressToken(signature);

                if (callback)
                {
                    callback({ token, db });
                }

                return;
            }

            if (category == ELEMENT_TYPE_GENERICINST)
            {
                CorSigUncompressElementType(signature);

                mdToken token = CorSigUncompressToken(signature);

                if (callback)
                {
                    callback({ token, db });
                }
                ULONG count = CorSigUncompressData(signature);

                while (count--)
                {
                    next_token(signature, db, callback);
                }

                return;
            }

            if (category == ELEMENT_TYPE_VAR) // A generic interface type parameter
            {
                CorSigUncompressData(signature); // The index of the type parameter
                return;
            }

            WINRT_ASSERT(false);
        }

        struct name_converter
        {
            void convert(wchar_t const* const buffer, uint32_t const size) noexcept
            {
                m_size = WideCharToMultiByte(CP_UTF8, 0, buffer, size, m_buffer.data(), static_cast<uint32_t>(m_buffer.size()), nullptr, nullptr);
            }

            std::pair<std::string, uint32_t> code_name() const
            {
                std::pair<std::string, uint32_t> result;
                char const* const end = m_buffer.data() + m_size;

                for (char const* c = m_buffer.data(); c != end; ++c)
                {
                    if (*c == '.')
                    {
                        result.second = static_cast<uint32_t>(result.first.size());
                        result.first += "::";
                    }
                    else if (*c == '`')
                    {
                        break;
                    }
                    else
                    {
                        result.first += *c;
                    }
                }

                return result;
            }

            std::string simple_code_name() const
            {
                return code_name().first;
            }

            operator std::string_view() const noexcept
            {
                return { m_buffer.data(), m_size };
            }

        private:

            std::array<char, max_name_size> m_buffer;
            uint32_t m_size{};
        };

        std::string get_method_name(std::string_view name)
        {
            size_t const pos = name.find('_');

            if (pos == std::string_view::npos)
            {
                return std::string(name);
            }
            else
            {
                return std::string(name.substr(pos + 1));
            }
        }

        template<typename T>
        T ReadDataFromBlob(PCCOR_SIGNATURE& data)
        {
            static_assert(std::is_arithmetic_v<T> || std::is_enum_v<T>);
            T result = *reinterpret_cast<const T*>(data);
            data += (std::is_enum_v<T> ? sizeof(int32_t) : sizeof(T));
            return result;
        }

        template<>
        std::string_view ReadDataFromBlob(PCCOR_SIGNATURE& data)
        {
            ULONG string_length = CorSigUncompressData(data);
            std::string_view result{ reinterpret_cast<const char*>(data), string_length };
            data += string_length;
            return result;
        }
    }

    bool is_foundation_type(std::string_view name)
    {
        for (std::string_view type : enum_foundation_types())
        {
            if (type == name)
            {
                return true;
            }
        }

        return false;
    }

    type const* resolve(std::string_view dot_name)
    {
        size_t split = dot_name.find_last_of('.');
        std::string const name_space(dot_name.substr(0, split));
        std::string_view name = dot_name.substr(split + 1);

        for (type const & type : m_index[name_space])
        {
            if (type.name() == name)
            {
                return &type;
            }
        }

        return nullptr;
    }

    void open_database(std::wstring const& filename, bool const foundational)
    {
        winrt::com_ptr<IMetaDataImport2> db;

        winrt::check_hresult(m_dispenser->OpenScope(filename.c_str(),
            ofRead,
            IID_IMetaDataImport2,
            reinterpret_cast<::IUnknown**>(put_abi(db))));

        m_databases.emplace_back(std::move(db), foundational);
    }

    void index_types()
    {
        std::string name_space;

        for (std::pair<database, bool> const& db : m_databases)
        {
            for (meta::type const& type : db.first.enum_types(db.second))
            {
                name_space.clear();

                for (std::string_view::iterator c = type.name_space().begin(); c != type.name_space().end(); ++c)
                {
                    if (*c == ':')
                    {
                        ++c;
                        name_space += '.';
                    }
                    else
                    {
                        name_space += *c;
                    }
                }

                m_index[name_space].push_back(std::move(type));
            }
        }

        for (std::pair<std::string const, std::vector<type>>& pair : m_index)
        {
            std::sort(pair.second.begin(), pair.second.end(), [](type const& left, type const& right)
            {
                return left.full_name() < right.full_name();
            });
        }

        for (std::pair<std::string const, std::vector<type>>& pair : m_index)
        {
            for (type& type : pair.second)
            {
                type.index_base();
            }
        }
    }

    index_type const& get_index()
    {
        return m_index;
    }

    database::database(winrt::com_ptr<IMetaDataImport2>&& db) :
        m_db(std::move(db))
    {
        mdToken mscorlib = get_mscorlib(m_db.get());

        m_system_class = find_system_type(m_db, mscorlib, L"System.Object");
        m_system_enum = find_system_type(m_db, mscorlib, L"System.Enum");
        m_system_struct = find_system_type(m_db, mscorlib, L"System.ValueType");
        m_system_delegate = find_system_type(m_db, mscorlib, L"System.MulticastDelegate");
        m_system_attribute = find_system_type(m_db, mscorlib, L"System.Attribute");
    }

    generator<type> database::enum_types(bool const foundation) const
    {
        enum_handle eh{ m_db.get() };
        std::array<mdToken, max_token_count> token_buffer;
        ULONG actual_token_count{};
        std::array<wchar_t, max_name_size> name_buffer;
        name_converter converter;
        ULONG actual_name_size{};
        DWORD flags{};
        mdToken extends{};

        while (S_OK == m_db->EnumTypeDefs(eh,
            token_buffer.data(),
            max_token_count,
            &actual_token_count))
        {
            for (ULONG i = 0; i != actual_token_count; ++i)
            {
                token token{ token_buffer[i], m_db.get() };

                winrt::check_hresult(m_db->GetTypeDefProps(token.handle(),
                    name_buffer.data(),
                    max_name_size,
                    &actual_name_size,
                    &flags,
                    &extends));

                if (!(flags & tdWindowsRuntime))
                {
                    continue;
                }

                converter.convert(name_buffer.data(), actual_name_size - 1);

                WINRT_ASSERT(converter.simple_code_name() != "Windows.Foundation.Deferral");

                bool local_foundation = foundation;

                if (!local_foundation && is_foundation_type(converter))
                {
                    local_foundation = true;
                }

                if (flags& tdInterface)
                {
                    co_yield type{ token, type_category::interface_v, local_foundation, converter.code_name() };
                }
                else if (extends == m_system_attribute)
                {
                    continue;
                }
                else if (extends == m_system_class)
                {
                    co_yield type{ token, type_category::class_v, local_foundation, converter.code_name() };
                }
                else if (extends == m_system_enum)
                {
                    co_yield type{ token, type_category::enum_v, local_foundation, converter.code_name() };
                }
                else if (extends == m_system_struct)
                {
                    if (token.has_attribute(L"Windows.Foundation.Metadata.ApiContractAttribute"))
                    {
                        continue;
                    }

                    co_yield type{ token, type_category::struct_v, local_foundation, converter.code_name() };
                }
                else if (extends == m_system_delegate)
                {
                    co_yield type{ token, type_category::delegate_v, local_foundation, converter.code_name() };
                }
                else
                {
                    co_yield type{ token, type_category::class_v, local_foundation, converter.code_name(),{ extends, m_db.get() } };
                }
            }
        }
    }

    type::type(meta::token token,
        type_category category,
        bool foundation,
        std::pair<std::string, uint32_t>&& name,
        meta::token base) :
        m_name(std::move(name)),
        m_token(token),
        m_base({ base }),
        m_category(category),
        m_foundation(foundation)
    {
        WINRT_ASSERT(token.is_type_def());
    }

    void type::index_base()
    {
        if (m_base.token)
        {
            m_base.type = &m_base.token.resolve();
            WINRT_ASSERT(m_base.type);
        }
    }

    bool type::is_class() const noexcept
    {
        return m_category == type_category::class_v;
    }

    bool type::is_delegate() const noexcept
    {
        return m_category == type_category::delegate_v;
    }

    bool type::is_enum() const noexcept
    {
        return m_category == type_category::enum_v;
    }

    bool type::is_interface() const noexcept
    {
        return m_category == type_category::interface_v;
    }

    bool type::is_struct() const noexcept
    {
        return m_category == type_category::struct_v;
    }

    bool type::is_foundational() const noexcept
    {
        return m_foundation;
    }

    token type::token() const noexcept
    {
        return m_token;
    }

    type_category type::category() const noexcept
    {
        return m_category;
    }

    std::string_view type::full_name() const noexcept
    {
        return m_name.first;
    }

    std::string_view type::name() const noexcept
    {
        return{ m_name.first.data() + m_name.second + 2, m_name.first.size() - m_name.second - 2 };
    }

    std::string_view type::name_space() const noexcept
    {
        return { m_name.first.data(), m_name.second };
    }

    type const* type::base() const noexcept
    {
        return m_base.type;
    }

    generator<token> token::EnumInterfaceImpls() const
    {
        WINRT_ASSERT(is_type_def());

        enum_handle eh{ m_db };
        std::array<mdToken, max_token_count> buffer;
        ULONG count{};

        while (S_OK == m_db->EnumInterfaceImpls(eh,
            m_handle,
            buffer.data(),
            max_token_count,
            &count))
        {
            for (ULONG i = 0; i != count; ++i)
            {
                co_yield{ buffer[i], m_db };
            }
        }
    }

    generator<token> token::EnumCustomAttributes() const
    {
        enum_handle eh{ m_db };
        std::array<mdToken, max_token_count> buffer;
        ULONG count{};

        while (S_OK == m_db->EnumCustomAttributes(eh,
            m_handle,
            0, // type
            buffer.data(),
            max_token_count,
            &count))
        {
            for (ULONG i = 0; i != count; ++i)
            {
                co_yield{ buffer[i], m_db };
            }
        }
    }

    generator<token> token::EnumMembers() const
    {
        WINRT_ASSERT(is_type_def());

        enum_handle eh{ m_db };
        std::array<mdToken, max_token_count> buffer;
        ULONG count{};

        while (S_OK == m_db->EnumMembers(eh,
            m_handle,
            buffer.data(),
            max_token_count,
            &count))
        {
            for (ULONG i = 0; i != count; ++i)
            {
                co_yield{ buffer[i], m_db };
            }
        }
    }

    generator<token> token::EnumParams() const
    {
        WINRT_ASSERT(is_method_def());

        enum_handle eh{ m_db };
        std::array<mdToken, max_token_count> buffer;
        ULONG count{};

        while (S_OK == m_db->EnumParams(eh,
            m_handle,
            buffer.data(),
            max_token_count,
            &count))
        {
            for (ULONG i = 0; i != count; ++i)
            {
                co_yield{ buffer[i], m_db };
            }
        }
    }

    token::token(mdToken handle,
        IMetaDataImport2* db) noexcept :
    m_handle(handle),
        m_db(db)
    {
        WINRT_ASSERT(handle);
        WINRT_ASSERT(db);
    }

    mdToken token::handle() const noexcept
    {
        WINRT_ASSERT(m_handle);
        return m_handle;
    }

    IMetaDataImport2* token::db() const noexcept
    {
        WINRT_ASSERT(m_db);
        return m_db;
    }

    token::operator bool() const noexcept
    {
        return m_handle != 0;
    }

    bool token::is_type_def() const noexcept
    {
        return TypeFromToken(m_handle) == mdtTypeDef;
    }

    bool token::is_type_ref() const noexcept
    {
        return TypeFromToken(m_handle) == mdtTypeRef;
    }

    bool token::is_type_spec() const noexcept
    {
        return TypeFromToken(m_handle) == mdtTypeSpec;
    }

    bool token::is_method_def() const noexcept
    {
        return TypeFromToken(m_handle) == mdtMethodDef;
    }

    bool token::is_interface_impl() const noexcept
    {
        return TypeFromToken(m_handle) == mdtInterfaceImpl;
    }

    bool token::is_field_def() const noexcept
    {
        return TypeFromToken(m_handle) == mdtFieldDef;
    }

    std::string token::get_generic_type_name(PCCOR_SIGNATURE& signature) const
    {
        CorSigUncompressElementType(signature);
        meta::token generic_type{ CorSigUncompressToken(signature), db() };
        WINRT_ASSERT(generic_type.is_type_ref());
        std::string name = generic_type.get_name();
        ULONG count = CorSigUncompressData(signature);
        name += '<';
        while (count--)
        {
            name += get_type_name_cursor(signature);
            if (count)
            {
                name += ", ";
            }
        }
        name += '>';
        return name;
    }

    std::string token::get_type_name_cursor(PCCOR_SIGNATURE& signature) const
    {
        CorElementType category = CorSigUncompressElementType(signature);

        switch (category)
        {
        case ELEMENT_TYPE_VOID:        return "void";
        case ELEMENT_TYPE_BOOLEAN:     return "bool";
        case ELEMENT_TYPE_CHAR:        return "wchar_t";
        case ELEMENT_TYPE_I1:          return "int8_t";
        case ELEMENT_TYPE_U1:          return "uint8_t";
        case ELEMENT_TYPE_I2:          return "int16_t";
        case ELEMENT_TYPE_U2:          return "uint16_t";
        case ELEMENT_TYPE_I4:          return "int32_t";
        case ELEMENT_TYPE_U4:          return "uint32_t";
        case ELEMENT_TYPE_I8:          return "int64_t";
        case ELEMENT_TYPE_U8:          return "uint64_t";
        case ELEMENT_TYPE_R4:          return "float";
        case ELEMENT_TYPE_R8:          return "double";
        case ELEMENT_TYPE_STRING:      return "hstring";
        case ELEMENT_TYPE_OBJECT:      return "Windows::Foundation::IInspectable";
        case ELEMENT_TYPE_GENERICINST: return get_generic_type_name(signature);
        case ELEMENT_TYPE_VALUETYPE:
        case ELEMENT_TYPE_CLASS:
        {
            meta::token param_type{ CorSigUncompressToken(signature), db() };
            return param_type.get_name();
        }
        case ELEMENT_TYPE_VAR:
        {
            CorSigUncompressData(signature);
            return get_type_name_cursor(signature);
        }
        }

        WINRT_ASSERT(false);
        return{};
    }

    std::string token::get_name(bool dotted) const
    {
        std::array<wchar_t, max_name_size> name_buffer;
        ULONG actual_name_size{};

        if (is_type_def())
        {
            winrt::check_hresult(m_db->GetTypeDefProps(m_handle,
                name_buffer.data(),
                max_name_size,
                &actual_name_size,
                nullptr,
                nullptr));
        }
        else if (is_type_ref())
        {
            winrt::check_hresult(m_db->GetTypeRefProps(m_handle,
                nullptr,
                name_buffer.data(),
                max_name_size,
                &actual_name_size));
        }
        else
        {
            PCCOR_SIGNATURE signature = get_signature();
            return get_type_name_cursor(signature);
        }

        for (std::pair<std::wstring_view, std::string_view> const& pair : enum_renamed_types())
        {
            if (pair.first == name_buffer.data())
            {
                return std::string(pair.second);
            }
        }

        name_converter converter;
        converter.convert(name_buffer.data(), actual_name_size - 1);

        return dotted ? std::string(converter) : converter.simple_code_name();
    }

    std::string token::get_simple_name() const
    {
        auto result = get_name(true);
        auto pos = result.find_last_of('.');
        if (pos != std::string::npos)
        {
            result.erase(0, pos + 1);
        }
        return result;
    }

    token token::get_abi_token() const
    {
        WINRT_ASSERT(is_type_def() || is_type_ref());
        token abi_token = *this;

        if (is_type_ref())
        {
            abi_token = resolve().token(); // Needed for find_default_interface?
        }

        if (token default_interface = abi_token.find_default_interface())
        {
            abi_token = default_interface;
        }

        return abi_token;
    }

    bool token::has_attribute(wchar_t const* const attribute) const noexcept
    {
        return S_OK == m_db->GetCustomAttributeByName(m_handle,
            attribute,
            nullptr,
            nullptr);
    }

    token token::find_default_interface() const
    {
        for (token impl_token : EnumInterfaceImpls())
        {
            if (!impl_token.has_attribute(L"Windows.Foundation.Metadata.DefaultAttribute"))
            {
                continue;
            }

            mdToken default_interface{};

            winrt::check_hresult(m_db->GetInterfaceImplProps(impl_token.m_handle,
                nullptr,
                &default_interface));

            return { default_interface, m_db };
        }

        return {};
    }

    type const& token::resolve() const
    {
        WINRT_ASSERT(is_type_ref());
        std::array<wchar_t, max_name_size> name_buffer;
        ULONG actual_name_size{};

        winrt::check_hresult(m_db->GetTypeRefProps(m_handle,
            nullptr,
            name_buffer.data(),
            max_name_size,
            &actual_name_size));

        name_converter converter;
        converter.convert(name_buffer.data(), actual_name_size - 1);

        return *meta::resolve(converter);
    }

    type const& token::resolve_generic() const
    {
        WINRT_ASSERT(is_type_spec());

        auto signature = get_signature();
        CorElementType category = CorSigUncompressElementType(signature);

        WINRT_ASSERT(category == ELEMENT_TYPE_GENERICINST);
        CorSigUncompressElementType(signature);
        meta::token generic_type{ CorSigUncompressToken(signature), db() };

        WINRT_ASSERT(generic_type.is_type_ref());
        std::string dot_name = generic_type.get_name(true);
        size_t pos = dot_name.find('`');

        WINRT_ASSERT(pos != std::string_view::npos);
        dot_name = dot_name.substr(0, pos);

        return *meta::resolve(dot_name);
    }

    generator<param> token::enum_param_base() const
    {
        DWORD attribute{};
        std::array<wchar_t, max_name_size> name_buffer;
        ULONG actual_name_size{};
        name_converter converter;

        for (token param_token : EnumParams())
        {
            winrt::check_hresult(m_db->GetParamProps(param_token.m_handle,
                nullptr,
                nullptr,
                name_buffer.data(),
                max_name_size,
                &actual_name_size,
                &attribute,
                nullptr,
                nullptr,
                nullptr));

            converter.convert(name_buffer.data(), actual_name_size - 1);

            co_yield{ std::string(converter), nullptr, (attribute& pdIn) == pdIn };
        }
    }

    void token::unpack_method(PCCOR_SIGNATURE signature, param& return_type, std::vector<param>& params, token_callback callback) const
    {
        WINRT_ASSERT(is_method_def());
        WINRT_ASSERT(signature);

        // If the return type is void then the param enumeration will not include the return type since
        // it is not named. That's why we have to handle this case specially here. Some other return types
        // may also not be named, typically a few (but not all) properties so we might have to produce a 
        // name in those cases for the ABI to use.

        return_type.signature = signature;
        next_token(signature, db(), callback);
        bool first = true;

        if (static_cast<CorElementType>(*return_type.signature) == ELEMENT_TYPE_VOID)
        {
            first = false;
        }

        for (param param_base : enum_param_base())
        {
            if (first)
            {
                first = false;
                return_type.name = std::move(param_base.name);
            }
            else
            {
                param_base.signature = signature;
                params.push_back(std::move(param_base));
                next_token(signature, db(), callback);
            }
        }
    }

    method token::get_delegate(token_callback callback) const
    {
        std::array<wchar_t, max_name_size> name_buffer;
        ULONG actual_name_size{};
        PCCOR_SIGNATURE signature{};

        for (token member_token : EnumMembers())
        {
            WINRT_ASSERT(member_token.is_method_def());

            winrt::check_hresult(m_db->GetMemberProps(member_token.m_handle,
                nullptr,
                name_buffer.data(),
                max_name_size,
                &actual_name_size,
                nullptr,
                &signature,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr));

            if (0 != wcscmp(name_buffer.data(), L"Invoke"))
            {
                continue;
            }

            CorSigUncompressCallingConv(signature); // Skip preamble
            CorSigUncompressData(signature); // Skip param count

            method delegate{member_token};
            delegate.token.unpack_method(signature, delegate.return_type, delegate.params, callback);
            return delegate;
        }

        throw winrt::hresult_out_of_bounds(L"TODO: define invalid metadata exception");
    }

    generator<token> token::enum_required_interfaces(bool const skip_default) const
    {
        if (is_type_spec())
        {
            // todo: implement usings for generics
            //token = token.resolve_generic().token();
            return;
        }

        WINRT_ASSERT(is_type_def());

        for (token impl_token : EnumInterfaceImpls())
        {
            if (skip_default && impl_token.has_attribute(L"Windows.Foundation.Metadata.DefaultAttribute"))
            {
                continue;
            }

            mdToken interface_token_handle{};
            WINRT_ASSERT(impl_token.is_interface_impl());

            winrt::check_hresult(m_db->GetInterfaceImplProps(impl_token.m_handle,
                nullptr,
                &interface_token_handle));

            token interface_token{ interface_token_handle , m_db };

            if (interface_token.is_type_ref())
            {
                interface_token = interface_token.resolve().token();
            }

            co_yield interface_token;

            WINRT_ASSERT(interface_token.is_type_def() || interface_token.is_type_spec());

            if (!interface_token.is_type_def())
            {
                // todo: support recursive enum of generic interfaces
                continue; // generic type spec
            }

            for (token recursive_interface_token : interface_token.enum_required_interfaces(false))
            {
                co_yield recursive_interface_token;
            }
        }
    }

    generator<token> token::enum_override_interfaces() const
    {
        for (token impl_token : EnumInterfaceImpls())
        {
            if (!impl_token.has_attribute(L"Windows.Foundation.Metadata.OverridableAttribute"))
            {
                continue;
            }

            mdToken interface_token_handle{};
            WINRT_ASSERT(impl_token.is_interface_impl());

            winrt::check_hresult(m_db->GetInterfaceImplProps(impl_token.m_handle,
                nullptr,
                &interface_token_handle));

            token interface_token{ interface_token_handle, m_db };

            if (interface_token.is_type_ref())
            {
                interface_token = interface_token.resolve().token();
            }

            co_yield interface_token;
        }
    }

    generator<factory_attribute> token::enum_factory_attributes() const
    {
        for (token attribute_token : EnumCustomAttributes())
        {
            uint8_t const* data{};
            ULONG data_length;
            mdToken attribute{};
            winrt::check_hresult(m_db->GetCustomAttributeProps(attribute_token.m_handle,
                nullptr,
                &attribute,
                reinterpret_cast<void const**>(&data),
                &data_length));
            WINRT_ASSERT(TypeFromToken(attribute) == mdtMemberRef);
            const uint8_t* const data_end = data + data_length;

            PCCOR_SIGNATURE signature;
            ULONG signature_length;

            winrt::check_hresult(m_db->GetMemberRefProps(attribute,
                &attribute,
                nullptr,
                0,
                nullptr,
                &signature,
                &signature_length));
            WINRT_ASSERT(TypeFromToken(attribute) == mdtTypeRef);
            const PCCOR_SIGNATURE signature_end = signature + signature_length;

            factory_attribute result;

            {
                std::array<wchar_t, max_name_size> name_buffer;
                ULONG actual_name_size{};
                winrt::check_hresult(m_db->GetTypeRefProps(attribute,
                    nullptr,
                    name_buffer.data(),
                    max_name_size,
                    &actual_name_size));
                const std::wstring_view name{ name_buffer.data(), actual_name_size - 1 };
                if (name == factory_attribute::activatable_name)
                {
                    result.activatable = true;
                }
                else if (name == factory_attribute::static_name)
                {
                    result.activatable = false;
                }
                else
                {
                    continue;
                }
            }

            const auto prologue = ReadDataFromBlob<uint16_t>(data);
            WINRT_ASSERT(prologue == 0x0001);

            WINRT_ASSERT(*signature == IMAGE_CEE_CS_CALLCONV_HASTHIS);
            CorSigUncompressCallingConv(signature);
            const ULONG param_count = CorSigUncompressData(signature);
            WINRT_ASSERT(param_count <= 3);
            WINRT_ASSERT(*signature == ELEMENT_TYPE_VOID);
            CorSigUncompressElementType(signature);

            for (ULONG param_index = 0; param_index < param_count; ++param_index)
            {
                WINRT_ASSERT(signature <= signature_end);
                WINRT_ASSERT(data <= data_end);

                switch (CorSigUncompressElementType(signature))
                {
                case ELEMENT_TYPE_CLASS:
                {
                    token tk{ CorSigUncompressToken(signature), m_db };
                    WINRT_ASSERT(tk.is_type_ref());
                    WINRT_ASSERT(tk.get_name(true) == "System.Type");
                }
                result.factory = meta::resolve(ReadDataFromBlob<std::string_view>(data))->token();
                break;

                case ELEMENT_TYPE_VALUETYPE:
                {
                    token tk{ CorSigUncompressToken(signature), m_db };
                    WINRT_ASSERT(tk.is_type_ref());
                    WINRT_ASSERT(tk.get_name(true) == "Windows.Foundation.Metadata.Platform");
                }
                result.platform = ReadDataFromBlob<int32_t>(data);
                break;

                case ELEMENT_TYPE_U4:
                    result.version = ReadDataFromBlob<uint32_t>(data);
                    break;

                case ELEMENT_TYPE_STRING:
                    result.contract = ReadDataFromBlob<std::string_view>(data);
                    break;

                default:
                    WINRT_ASSERT(false);
                    break;
                }
            }
            co_yield result;
        }
    }

    generator<composable_attribute> token::enum_composable_attributes() const
    {
        for (token attribute_token : EnumCustomAttributes())
        {
            uint8_t const* data{};
            ULONG data_length;
            mdToken attribute{};
            winrt::check_hresult(m_db->GetCustomAttributeProps(attribute_token.m_handle,
                nullptr,
                &attribute,
                reinterpret_cast<void const**>(&data),
                &data_length));
            WINRT_ASSERT(TypeFromToken(attribute) == mdtMemberRef);
            const uint8_t* const data_end = data + data_length;

            PCCOR_SIGNATURE signature;
            ULONG signature_length;

            winrt::check_hresult(m_db->GetMemberRefProps(attribute,
                &attribute,
                nullptr,
                0,
                nullptr,
                &signature,
                &signature_length));
            WINRT_ASSERT(TypeFromToken(attribute) == mdtTypeRef);
            const PCCOR_SIGNATURE signature_end = signature + signature_length;

            {
                std::array<wchar_t, max_name_size> name_buffer;
                ULONG actual_name_size{};
                winrt::check_hresult(m_db->GetTypeRefProps(attribute,
                    nullptr,
                    name_buffer.data(),
                    max_name_size,
                    &actual_name_size));
                if (composable_attribute::name != std::wstring_view{ name_buffer.data(), actual_name_size - 1 })
                {
                    continue;
                }
            }

            const auto prologue = ReadDataFromBlob<uint16_t>(data);
            WINRT_ASSERT(prologue == 0x0001);

            WINRT_ASSERT(*signature == IMAGE_CEE_CS_CALLCONV_HASTHIS);
            CorSigUncompressCallingConv(signature);
            const ULONG param_count = CorSigUncompressData(signature);
            WINRT_ASSERT(param_count == 3 || param_count == 4);
            WINRT_ASSERT(*signature == ELEMENT_TYPE_VOID);
            CorSigUncompressElementType(signature);

            composable_attribute result;

            // First parameter should always be System.Type
            CorElementType category = CorSigUncompressElementType(signature);
            WINRT_ASSERT(category == ELEMENT_TYPE_CLASS);
            token tk{ CorSigUncompressToken(signature), m_db };
            WINRT_ASSERT(tk.is_type_ref());
            WINRT_ASSERT(tk.get_name(true) == "System.Type");

            result.factory = meta::resolve(ReadDataFromBlob<std::string_view>(data))->token();

            WINRT_ASSERT(signature <= signature_end);
            WINRT_ASSERT(data <= data_end);

            // Second parameter is always the CompositionType
            category = CorSigUncompressElementType(signature);
            WINRT_ASSERT(category == ELEMENT_TYPE_VALUETYPE);
            tk = token{ CorSigUncompressToken(signature), m_db };
            WINRT_ASSERT(tk.is_type_ref());
            WINRT_ASSERT(tk.get_name(true) == "Windows.Foundation.Metadata.CompositionType");

            result.type = ReadDataFromBlob<composable_attribute::composition_type>(data);
            WINRT_ASSERT(result.type == composable_attribute::composition_type::protected_v ||
                result.type == composable_attribute::composition_type::public_v);

            WINRT_ASSERT(signature <= signature_end);
            WINRT_ASSERT(data <= data_end);

            // Third parameter is always the version
            category = CorSigUncompressElementType(signature);
            WINRT_ASSERT(category == ELEMENT_TYPE_U4);
            result.version = ReadDataFromBlob<uint32_t>(data);

            WINRT_ASSERT(signature <= signature_end);
            WINRT_ASSERT(data <= data_end);

            // There might be a fourth parameter. It's always either the contract or the platform
            if (param_count == 4)
            {
                category = CorSigUncompressElementType(signature);
                if (category == ELEMENT_TYPE_STRING)
                {
                    result.contract = ReadDataFromBlob<std::string_view>(data);
                }
                else if (category == ELEMENT_TYPE_VALUETYPE)
                {
                    tk = token{ CorSigUncompressToken(signature), m_db };
                    WINRT_ASSERT(tk.is_type_ref());
                    WINRT_ASSERT(tk.get_name(true) == "Windows.Foundation.Metadata.Platform");
                    result.platform = ReadDataFromBlob<int32_t>(data);
                }
                else
                {
                    WINRT_ASSERT(false);
                }
            }

            co_yield result;
        }
    }

    generator<std::pair<token, std::string>> token::enum_interface_usings() const
    {
        // TODO: the value should be the full_name rather than the token to support generics
        std::map<std::string, std::vector<token>> usings;

        for (std::string method : enum_method_names())
        {
            usings[get_method_name(method)].push_back(*this);
        }

        for (token token : enum_required_interfaces(false))
        {
            if (token.is_type_spec())
            {
                // todo: enable usings for generics
                //token = token.resolve_generic().token();
                continue;
            }

            for (std::string method : token.enum_method_names())
            {
                usings[get_method_name(method)].push_back(token);
            }
        }

        auto ctor = usings.find(".ctor");
        if (ctor != usings.end())
        {
            usings.erase(ctor);
        }

        for (std::pair<std::string const, std::vector<token>>& pair : usings)
        {
            std::sort(pair.second.begin(), pair.second.end());
            std::vector<token>::iterator end = std::unique(pair.second.begin(), pair.second.end());
            pair.second.erase(end, pair.second.end());

            if (pair.second.size() > 1)
            {
                for (token token : pair.second)
                {
                    co_yield{ token, pair.first };
                }
            }
        }
    }

    void add_usings(meta::token token, std::map<std::string, std::vector<std::pair<meta::token, bool>>>& usings, bool default_interface)
    {
        if (token.is_type_spec())
        {
            // todo: implement usings for generics
            //token = token.resolve_generic().token();
            return;
        }

        WINRT_ASSERT(token.is_type_def());

        for (std::string method : token.enum_method_names())
        {
            usings[std::string(get_method_name(method))].emplace_back(token, default_interface);
        }
    }

    meta::generator<std::tuple<meta::token, std::string, bool>> type::enum_class_usings() const
    {
        // TODO: the value should be the full_name rather than the token to support generics
        std::map<std::string, std::vector<std::pair<meta::token, bool>>> usings;

        meta::token default_interface = token().find_default_interface();

        if (default_interface.is_type_ref())
        {
            default_interface = default_interface.resolve().token();
        }

        add_usings(default_interface, usings, true);

        for (meta::token required : default_interface.enum_required_interfaces(false))
        {
            add_usings(required, usings, true);
        }

        for (meta::token required : token().enum_required_interfaces(true))
        {
            add_usings(required, usings, false);
        }

        for (meta::type const* next = base(); next != nullptr; next = next->base())
        {
            for (meta::token required : next->token().enum_required_interfaces(false))
            {
                add_usings(required, usings, false);
            }
        }

        auto ctor = usings.find(".ctor");
        if (ctor != usings.end())
        {
            usings.erase(ctor);
        }

        for (std::pair<std::string const, std::vector<std::pair<meta::token, bool>>>& pair : usings)
        {
            std::sort(pair.second.begin(), pair.second.end(),
                [](std::pair<meta::token, bool> const& left, std::pair<meta::token, bool> const& right)
            {
                return left.first < right.first;
            });

            std::vector<std::pair<meta::token, bool>>::iterator end = std::unique(pair.second.begin(), pair.second.end(),
                [](std::pair<meta::token, bool> const& left, std::pair<meta::token, bool> const& right)
            {
                return left.first == right.first;
            });

            pair.second.erase(end, pair.second.end());

            if (pair.second.size() > 1)
            {
                for (std::pair<meta::token, bool> required : pair.second)
                {
                    co_yield{ required.first, pair.first, required.second };
                }
            }
        }
    }

    generator<field> token::enum_fields(token_callback callback) const
    {
        std::array<wchar_t, max_name_size> name_buffer;
        ULONG actual_name_size{};
        PCCOR_SIGNATURE signature{};
        name_converter converter;

        for (token member_token : EnumMembers())
        {
            WINRT_ASSERT(member_token.is_field_def());

            winrt::check_hresult(m_db->GetFieldProps(member_token.m_handle,
                nullptr,
                name_buffer.data(),
                max_name_size,
                &actual_name_size,
                nullptr,
                &signature,
                nullptr,
                nullptr,
                nullptr,
                nullptr));

            if (callback)
            {
                auto sig = signature + 1;
                next_token(sig, db(), callback);
            }

            converter.convert(name_buffer.data(), actual_name_size - 1);
            co_yield{ std::string(converter), signature + 1 };
        }
    }

    generator<enumerator> token::enum_enumerators() const
    {
        std::array<wchar_t, max_name_size> name_buffer;
        ULONG actual_name_size{};
        UVCP_CONSTANT enum_value{};
        name_converter converter;

        for (token member_token : EnumMembers())
        {
            WINRT_ASSERT(member_token.is_field_def());

            winrt::check_hresult(m_db->GetFieldProps(member_token.m_handle,
                nullptr,
                name_buffer.data(),
                max_name_size,
                &actual_name_size,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                &enum_value,
                nullptr));

            if (enum_value == nullptr)
            {
                continue;
            }

            converter.convert(name_buffer.data(), actual_name_size - 1);

            co_yield{ member_token, std::string(converter), *static_cast<int32_t const*>(enum_value) };
        }
    }

    generator<method> token::enum_methods(token_callback callback) const
    {
        std::array<wchar_t, max_name_size> name_buffer;
        ULONG actual_name_size{};
        PCCOR_SIGNATURE signature{};
        name_converter converter;

        for (token member_token : EnumMembers())
        {
            WINRT_ASSERT(member_token.is_method_def());

            winrt::check_hresult(m_db->GetMemberProps(member_token.m_handle,
                nullptr,
                name_buffer.data(),
                max_name_size,
                &actual_name_size,
                nullptr,
                &signature,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr));

            converter.convert(name_buffer.data(), actual_name_size - 1);

            CorSigUncompressCallingConv(signature); // Skip preamble
            CorSigUncompressData(signature); // Skip param count

            method method{ member_token, std::string(converter) };
            method.token.unpack_method(signature, method.return_type, method.params, callback);
            co_yield std::move(method);
        }
    }

    generator<std::string> token::enum_method_names() const
    {
        std::array<wchar_t, max_name_size> name_buffer;
        ULONG actual_name_size{};
        name_converter converter;

        for (token member_token : EnumMembers())
        {
            WINRT_ASSERT(member_token.is_method_def());

            winrt::check_hresult(m_db->GetMemberProps(member_token.m_handle,
                nullptr,
                name_buffer.data(),
                max_name_size,
                &actual_name_size,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr));

            converter.convert(name_buffer.data(), actual_name_size - 1);
            co_yield std::string(converter);
        }
    }

    std::pair<bool, std::string_view> token::get_string(wchar_t const* const attribute) const
    {
        void const* data{};
        ULONG size{};

        HRESULT const hr = m_db->GetCustomAttributeByName(m_handle,
            attribute,
            &data,
            &size);

        if (hr != S_OK)
        {
            return{ false,{} };
        }

        PCCOR_SIGNATURE signature = static_cast<PCCOR_SIGNATURE>(data);

        WINRT_ASSERT(*signature == 1);
        ++signature;
        WINRT_ASSERT(*signature == 0);
        ++signature;

        ULONG const count = CorSigUncompressData(signature);
        return { true,{ reinterpret_cast<char const*>(signature), count } };
    }

    std::string token::get_guid() const
    {
        void const* data{};
        ULONG size{};

        winrt::check_hresult(m_db->GetCustomAttributeByName(m_handle,
            L"Windows.Foundation.Metadata.GuidAttribute",
            &data,
            &size));

        GUID const& guid = *reinterpret_cast<GUID const*>(static_cast<uint8_t const*>(data) + 2);

        std::string result(68, '?');

        sprintf_s(result.data(),
            result.size() + 1,
            "0x%08X,0x%04X,0x%04X,{ 0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X,0x%02X }",
            guid.Data1,
            guid.Data2,
            guid.Data3,
            guid.Data4[0],
            guid.Data4[1],
            guid.Data4[2],
            guid.Data4[3],
            guid.Data4[4],
            guid.Data4[5],
            guid.Data4[6],
            guid.Data4[7]);

        return result;
    }

    PCCOR_SIGNATURE token::get_signature() const
    {
        WINRT_ASSERT(is_type_spec());

        PCCOR_SIGNATURE signature{};
        ULONG size{};

        winrt::check_hresult(m_db->GetTypeSpecFromToken(m_handle,
            &signature,
            &size));

        return signature;
    }

}
