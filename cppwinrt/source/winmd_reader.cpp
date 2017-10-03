#include "pch.h"
#include "winmd_reader.h"
#include "settings.h"

namespace cppwinrt::meta
{
    namespace
    {
        constexpr uint32_t max_name_size = 300;
        constexpr uint32_t max_token_count = 100;

        struct database
        {
            IMetaDataImport2* db{};
            bool is_reference{};
            mdToken system_enum{};
            mdToken system_struct{};
            mdToken system_delegate{};
            mdToken system_attribute{};

            database(std::wstring const& filename, bool is_reference);
            generator<token> EnumTypeDefs() const noexcept;
        };

        generator<mdToken> EnumAssemblyRefs(IMetaDataAssemblyImport* assembly) noexcept
        {
            HCORENUM eh{};
            std::array<mdToken, max_token_count> buffer;
            ULONG actual{};

            while (S_OK == assembly->EnumAssemblyRefs(&eh, buffer.data(), max_token_count, &actual))
            {
                for (ULONG i = 0; i != actual; ++i)
                {
                    co_yield{ buffer[i] };
                }
            }
        }

        mdToken get_mscorlib(IMetaDataImport2* db)
        {
            IMetaDataAssemblyImport* assembly{};
            winrt::check_hresult(db->QueryInterface(IID_IMetaDataAssemblyImport, reinterpret_cast<void**>(&assembly)));

            std::array<wchar_t, max_name_size> buffer;
            ULONG actual{};

            for (mdToken token : EnumAssemblyRefs(assembly))
            {
                winrt::check_hresult(assembly->GetAssemblyRefProps(
                    token,
                    nullptr,
                    nullptr,
                    buffer.data(),
                    max_name_size,
                    &actual,
                    nullptr,
                    nullptr,
                    nullptr,
                    nullptr));

                if (0 == wcscmp(buffer.data(), L"mscorlib"))
                {
                    return token;
                }
            }

            WINRT_ASSERT(false);
            return {};
        }

        generator<std::pair<std::string_view, std::string_view>> enum_renamed_types()
        {
            co_yield{ "System.Guid", "GUID" };
            co_yield{ "Windows.Foundation.EventRegistrationToken", "event_token" };
            co_yield{ "Windows.Foundation.HResult", "HRESULT" };
            co_yield{ "Windows.Foundation.Numerics.Matrix3x2", "Windows.Foundation.Numerics.float3x2" };
            co_yield{ "Windows.Foundation.Numerics.Matrix4x4", "Windows.Foundation.Numerics.float4x4" };
            co_yield{ "Windows.Foundation.Numerics.Plane", "Windows.Foundation.Numerics.plane" };
            co_yield{ "Windows.Foundation.Numerics.Quaternion", "Windows.Foundation.Numerics.quaternion" };
            co_yield{ "Windows.Foundation.Numerics.Vector2", "Windows.Foundation.Numerics.float2" };
            co_yield{ "Windows.Foundation.Numerics.Vector3", "Windows.Foundation.Numerics.float3" };
            co_yield{ "Windows.Foundation.Numerics.Vector4", "Windows.Foundation.Numerics.float4" };
        }

        generator<std::string_view> get_foundation_types()
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

            co_yield "Windows.Foundation.Collections.CollectionChange";
            co_yield "Windows.Foundation.Collections.VectorChangedEventHandler`1";
            co_yield "Windows.Foundation.Collections.MapChangedEventHandler`2";
            co_yield "Windows.Foundation.Collections.IVectorChangedEventArgs";

            for (std::pair<std::string_view, std::string_view > const& pair : enum_renamed_types())
            {
                co_yield pair.second;
            }
        }

        IMetaDataDispenser* MetaDataGetDispenser()
        {
            IMetaDataDispenser* dispenser{};
            winrt::check_hresult(MetaDataGetDispenser(CLSID_CorMetaDataDispenser, IID_IMetaDataDispenser, reinterpret_cast<void**>(&dispenser)));
            return dispenser;
        }

        static IMetaDataDispenser* dispenser{ MetaDataGetDispenser() };
        static std::vector<database> databases;
        static index_type index;

        void load_index_types()
        {
            std::array<wchar_t, max_name_size> buffer;
            ULONG actual{};
            DWORD flags{};
            mdToken extends{};

            for (database const& database : databases)
            {
                for (token token : database.EnumTypeDefs())
                {
                    winrt::check_hresult(database.db->GetTypeDefProps(
                        token.handle,
                        buffer.data(),
                        max_name_size,
                        &actual,
                        &flags,
                        &extends));

                    if (!(flags & tdWindowsRuntime))
                    {
                        continue;
                    }

                    std::string name = to_string({ buffer.data(), actual - 1 });

                    for (std::pair<std::string_view, std::string_view > const& pair : enum_renamed_types())
                    {
                        if (pair.first == name)
                        {
                            name = std::string(pair.second);
                            break;
                        }
                    }

                    bool const is_reference = database.is_reference || is_foundation_type(name);
                    type type(std::move(name), token, is_reference);

                    if (type.name_space().empty())
                    {
                        continue;
                    }

                    std::string const name_space(type.name_space());

                    if (IsTdInterface(flags))
                    {
                        index[name_space].interfaces.push_back(std::move(type));
                    }
                    else if (extends == database.system_attribute)
                    {
                        continue;
                    }
                    else if (extends == database.system_enum)
                    {
                        index[name_space].enums.push_back(std::move(type));
                    }
                    else if (extends == database.system_struct)
                    {
                        if (token.is_api_contract())
                        {
                            continue;
                        }

                        index[name_space].structs.push_back(std::move(type));
                    }
                    else if (extends == database.system_delegate)
                    {
                        index[name_space].delegates.push_back(std::move(type));
                    }
                    else
                    {
                        index[name_space].classes.push_back(std::move(type));
                    }
                }
            }
        }

        std::string to_method_name(std::string const& name, DWORD flags)
        {
            if (IsMdSpecialName(flags))
            {
                return name.substr(name.find('_') + 1);
            }

            return name;
        }

        std::string read(IMetaDataImport2* db, PCCOR_SIGNATURE& cursor, std::vector<std::string> const& generic_params)
        {
            CorElementType category = CorSigUncompressElementType(cursor);
            bool by_ref{};

            if (category == ELEMENT_TYPE_CMOD_REQD || category == ELEMENT_TYPE_CMOD_OPT)
            {
                // Followed by a type token; typically used to denote a parameter as const via typeref to "IsConst"
                // We'll ignore this as we typically don't care about this from a consumption standpoint
                CorSigUncompressToken(cursor);
                category = CorSigUncompressElementType(cursor);
            }

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                category = CorSigUncompressElementType(cursor);
            }

            switch (category)
            {
            case ELEMENT_TYPE_VOID:    return "void";
            case ELEMENT_TYPE_BOOLEAN: return "bool";
            case ELEMENT_TYPE_CHAR:    return "char16_t";
            case ELEMENT_TYPE_I1:      return "int8_t";
            case ELEMENT_TYPE_U1:      return "uint8_t";
            case ELEMENT_TYPE_I2:      return "int16_t";
            case ELEMENT_TYPE_U2:      return "uint16_t";
            case ELEMENT_TYPE_I4:      return "int32_t";
            case ELEMENT_TYPE_U4:      return "uint32_t";
            case ELEMENT_TYPE_I8:      return "int64_t";
            case ELEMENT_TYPE_U8:      return "uint64_t";
            case ELEMENT_TYPE_R4:      return "float";
            case ELEMENT_TYPE_R8:      return "double";
            case ELEMENT_TYPE_I:       return "LONG_PTR";
            case ELEMENT_TYPE_U:       return "ULONG_PTR";
            case ELEMENT_TYPE_STRING:  return "hstring";
            case ELEMENT_TYPE_OBJECT:  return "Windows.Foundation.IInspectable";
            }

            if (category == ELEMENT_TYPE_VALUETYPE || category == ELEMENT_TYPE_CLASS)
            {
                return token{ CorSigUncompressToken(cursor), db }.get_name(generic_params);
            }

            if (category == ELEMENT_TYPE_GENERICINST)
            {
                WINRT_VERIFY_(ELEMENT_TYPE_CLASS, CorSigUncompressElementType(cursor));
                std::string name = token{ CorSigUncompressToken(cursor), db }.get_name();
                name.resize(name.rfind('`'));
                name += '<';
                ULONG count = CorSigUncompressData(cursor);
                name += read(db, cursor, generic_params);

                while (--count)
                {
                    name += ", ";
                    name += read(db, cursor, generic_params);
                }

                name += '>';
                return name;
            }

            if (category == ELEMENT_TYPE_SZARRAY)
            {
                return "com_array<" + read(db, cursor, generic_params) + ">";
            }

            if (category == ELEMENT_TYPE_VAR)
            {
                return generic_params[CorSigUncompressData(cursor)];
            }

            WINRT_ASSERT(false);
            return {};
        }

        std::pair<uint32_t, uint32_t> read_size(IMetaDataImport2* db, PCCOR_SIGNATURE& cursor, std::pair<uint32_t, uint32_t>* max_alignment)
        {
            CorElementType category = CorSigUncompressElementType(cursor);
            bool by_ref{};

            if (category == ELEMENT_TYPE_CMOD_REQD || category == ELEMENT_TYPE_CMOD_OPT)
            {
                CorSigUncompressToken(cursor);
                category = CorSigUncompressElementType(cursor);
            }

            if (category == ELEMENT_TYPE_BYREF)
            {
                by_ref = true;
                category = CorSigUncompressElementType(cursor);
            }

            switch (category)
            {
            case ELEMENT_TYPE_BOOLEAN: return { 1, 1 };
            case ELEMENT_TYPE_CHAR:    return { 2, 2 };
            case ELEMENT_TYPE_I1:      return { 1, 1 };
            case ELEMENT_TYPE_U1:      return { 1, 1 };
            case ELEMENT_TYPE_I2:      return { 2, 2 };
            case ELEMENT_TYPE_U2:      return { 2, 2 };
            case ELEMENT_TYPE_I4:      return { 4, 4 };
            case ELEMENT_TYPE_U4:      return { 4, 4 };
            case ELEMENT_TYPE_I8:      return { 8, 8 };
            case ELEMENT_TYPE_U8:      return { 8, 8 };
            case ELEMENT_TYPE_R4:      return { 4, 4 };
            case ELEMENT_TYPE_R8:      return { 8, 8 };
            case ELEMENT_TYPE_STRING:  return { 4, 8 };
            }

            if (category == ELEMENT_TYPE_VALUETYPE)
            {
                return token{ CorSigUncompressToken(cursor), db }.get_struct_size(max_alignment);
            }

            if (category == ELEMENT_TYPE_GENERICINST)
            {
                return { 4, 8 };
            }

            WINRT_ASSERT(false);
            return {};
        }


        enum class interface_filter
        {
            all,
            overridable,
            non_overridable,
            none,
        };

        enum class base_filter
        {
            all,
            reference_only,
            none,
        };

        void append_required(std::vector<required>& values, token derived, std::vector<std::string> const& generic_params, interface_filter filter)
        {
            WINRT_ASSERT(filter != interface_filter::none);
            for (token impl_token : derived.get_definition().EnumInterfaceImpls())
            {
                const bool is_override = impl_token.has_attribute(L"Windows.Foundation.Metadata.OverridableAttribute");
                if (filter == interface_filter::all ||
                    (filter == interface_filter::overridable && is_override) ||
                    (filter == interface_filter::non_overridable && !is_override))
                {
                    const token token = impl_token.GetInterfaceImplProps();

                    if (token.is_type_spec())
                    {
                        if (generic_params.empty())
                        {
                            values.push_back({ token.get_name(generic_params), token, token.get_generic_params() });
                        }
                        else
                        {
                            values.push_back({ token.get_name(generic_params), token, generic_params });
                        }

                        append_required(values, token, token.get_signature().get_generic_params(generic_params), filter);
                    }
                    else
                    {
                        values.push_back({ token.get_name(generic_params), token, generic_params });
                        append_required(values, token, generic_params, filter);
                    }
                }
            }
        }

        void exclude_required(std::vector<required>& values, token default_interface)
        {
            if (!default_interface)
            {
                return;
            }

            std::string name = default_interface.get_name();

            values.erase(std::remove_if(
                values.begin(),
                values.end(),
                [&](required const& value)
                {
                    return value.name == name;
                }),
                values.end());

            std::vector<required> exclude = default_interface.get_interface_required();

            values.erase(std::remove_if(
                values.begin(),
                values.end(),
                [&](required const& value)
                {
                    return exclude.end() != std::find(exclude.begin(), exclude.end(), value);
                }),
                values.end());
        }

        template <typename T>
        void sort_unique(std::vector<T>& values)
        {
            std::sort(values.begin(), values.end());
            values.erase(std::unique(values.begin(), values.end()), values.end());
        }

        std::vector<required> get_class_required_base(token class_token, interface_filter self_interfaces, interface_filter base_interfaces, base_filter base_types)
        {
            std::vector<required> values;
            if (self_interfaces != interface_filter::none)
            {
                append_required(values, class_token, {}, self_interfaces);
            }

            if (base_interfaces != interface_filter::none && base_types != base_filter::none)
            {
                for (type const* base = class_token.get_base_type();
                    base && !(base_types == base_filter::reference_only && !base->is_reference);
                    base = base->token.get_base_type())
                {
                    append_required(values, base->token, {}, base_interfaces);
                }
            }

            sort_unique(values);
            return values;
        }

        std::vector<required> get_class_required_impl(token class_token, interface_filter self_interfaces, interface_filter base_interfaces, base_filter base_types)
        {
            std::vector<required> values = get_class_required_base(class_token, self_interfaces, base_interfaces, base_types);

            if (values.empty())
            {
                return values;
            }

            auto default_interface = class_token.get_default();
            if (!default_interface)
            {
                values.clear();
                return values;
            }
            std::string default_name = default_interface.get_name();

            std::vector<required>::iterator position = std::find_if(values.begin(), values.end(),
                [&](required const& value)
            {
                return value.name == default_name;
            });

            if (position != values.end())
            {
                std::rotate(values.begin(), position, position + 1);
            }
            return values;
        }

        template<typename T>
        T read_blob(PCCOR_SIGNATURE& data)
        {
            static_assert(std::is_arithmetic_v<T> || std::is_enum_v<T>);
            T result = *reinterpret_cast<const T*>(data);
            data += (std::is_enum_v<T> ? sizeof(int32_t) : sizeof(T));
            return result;
        }

        template<>
        std::string read_blob(PCCOR_SIGNATURE& data)
        {
            ULONG string_length = CorSigUncompressData(data);
            std::string result{ reinterpret_cast<const char*>(data), string_length };
            data += string_length;
            return result;
        }

        void sort_index_types()
        {
            auto sort = [](std::vector<type>& vector)
            {
                std::sort(vector.begin(), vector.end(),
                    [](type const& left, type const& right)
                    {
                        return left.name() < right.name();
                    });
            };

            for (index_pair& pair : index)
            {
                sort(pair.second.enums);
                sort(pair.second.structs);
                sort(pair.second.interfaces);
                sort(pair.second.classes);
                sort(pair.second.delegates);
            }
        }

        std::string get_name(token const token)
        {
            WINRT_ASSERT(token.is_type_def() || token.is_type_ref());

            std::array<wchar_t, max_name_size> buffer;
            ULONG actual{};

            if (token.is_type_def())
            {
                winrt::check_hresult(token.db->GetTypeDefProps(
                    token.handle,
                    buffer.data(),
                    max_name_size,
                    &actual,
                    nullptr,
                    nullptr));
            }
            else
            {
                winrt::check_hresult(token.db->GetTypeRefProps(
                    token.handle,
                    nullptr,
                    buffer.data(),
                    max_name_size,
                    &actual));
            }

            std::string result = to_string({ buffer.data(), actual - 1 });

            for (std::pair<std::string_view, std::string_view > const& pair : enum_renamed_types())
            {
                if (pair.first == result)
                {
                    return std::string(pair.second);
                }
            }

            return result;
        }

        void add_override_interfaces(std::vector<token>& interfaces, token token)
        {
            for (meta::token impl_token : token.EnumInterfaceImpls())
            {
                if (!impl_token.has_attribute(L"Windows.Foundation.Metadata.OverridableAttribute"))
                {
                    continue;
                }

                interfaces.push_back(impl_token.GetInterfaceImplProps().get_definition());
            }
        }
    }

    database::database(std::wstring const& filename, bool const is_reference) : is_reference(is_reference)
    {
        winrt::check_hresult(dispenser->OpenScope(
            filename.c_str(),
            ofRead,
            IID_IMetaDataImport2,
            reinterpret_cast<::IUnknown**>(&db)));

        mdToken mscorlib = get_mscorlib(db);

        auto FindTypeRef = [&](wchar_t const* const name) noexcept
        {
            mdToken token{};
            db->FindTypeRef(mscorlib, name, &token);
            return token;
        };

        system_enum = FindTypeRef(L"System.Enum");
        system_struct = FindTypeRef(L"System.ValueType");
        system_delegate = FindTypeRef(L"System.MulticastDelegate");
        system_attribute = FindTypeRef(L"System.Attribute");
    }

    generator<token> database::EnumTypeDefs() const noexcept
    {
        HCORENUM eh{};
        std::array<mdToken, max_token_count> buffer;
        ULONG actual{};

        while (S_OK == db->EnumTypeDefs(&eh, buffer.data(), max_token_count, &actual))
        {
            for (ULONG i = 0; i != actual; ++i)
            {
                co_yield{ buffer[i], db };
            }
        }
    }

    bool namespace_types::has_projected_types() const noexcept
    {
        for (type const& type : get_container_values(interfaces, classes, enums, structs, delegates))
        {
            if (!type.is_reference)
            {
                return true;
            }
        }

        return false;
    }

    void open_database(std::wstring const& filename, bool const is_reference)
    {
        databases.emplace_back(filename, is_reference);
    }

    void build_index()
    {
        WINRT_ASSERT(index.empty());
        load_index_types();
        sort_index_types();
    }

    index_type const& get_index()
    {
        return index;
    }

    bool is_foundation_type(std::string_view name)
    {
        for (std::string_view type : get_foundation_types())
        {
            if (type == name)
            {
                return true;
            }
        }

        return false;
    }

    bool is_meta_struct(std::string_view match)
    {
        if (is_foundation_type(match))
        {
            return false;
        }

        std::string name_space(match.data(), match.rfind('.'));
        match = match.substr(name_space.size() + 1);

        namespace_types const& types = index.at(name_space);

        for (type const& type : types.structs)
        {
            if (type.name() == match)
            {
                return true;
            }
        }

        return false;
    }

    type const* find_type(std::string_view match, type_category* category)
    {
        std::string name_space(match.data(), match.rfind('.'));
        match = match.substr(name_space.size() + 1);
        
        try
        {
            namespace_types const& types = index.at(name_space);

            auto find = [&](std::vector<type> const& vector) -> type const*
            {
                auto result = std::find_if(vector.begin(), vector.end(),
                    [&](type const& type)
                {
                    return type.name() == match;
                });

                if (result != vector.end())
                {
                    return &*result;
                }

                return nullptr;
            };

            if (type const* result = find(types.interfaces))
            {
                if (category)
                {
                    *category = type_category::interface_v;
                }

                return result;
            }

            if (type const* result = find(types.classes))
            {
                if (category)
                {
                    *category = type_category::class_v;
                }

                return result;
            }

            if (type const* result = find(types.enums))
            {
                if (category)
                {
                    *category = type_category::enum_v;
                }

                return result;
            }

            if (type const* result = find(types.structs))
            {
                if (category)
                {
                    *category = type_category::struct_v;
                }

                return result;
            }

            if (type const* result = find(types.delegates))
            {
                if (category)
                {
                    *category = type_category::delegate_v;
                }

                return result;
            }
        }
        catch (std::out_of_range&)
        {
            throw meta_error{ "Unknown namespace: " + name_space };
        }

        throw meta_error{ "Unresolved type: " + std::string(match) };
    }

    std::string signature::get_name() const
    {
        PCCOR_SIGNATURE cursor = data;
        return read(db, cursor, {}); 
    }

    std::string signature::get_name(std::vector<std::string> const& generic_params) const
    {
        PCCOR_SIGNATURE cursor = data;
        return read(db, cursor, generic_params);
    }

    std::vector<std::string> signature::get_generic_params(std::vector<std::string> const& generic_params) const
    {
        PCCOR_SIGNATURE cursor = data;
        WINRT_VERIFY_(ELEMENT_TYPE_GENERICINST, CorSigUncompressElementType(cursor));
        WINRT_VERIFY_(ELEMENT_TYPE_CLASS, CorSigUncompressElementType(cursor));
        CorSigUncompressToken(cursor);
        ULONG count = CorSigUncompressData(cursor);
        std::vector<std::string> values;

        while (count--)
        {
            values.push_back(read(db, cursor, generic_params));
        }

        return values;
    }

    token signature::get_token() const noexcept
    {
        PCCOR_SIGNATURE cursor = data;
        CorElementType category = CorSigUncompressElementType(cursor);
        token result;

        if (category == ELEMENT_TYPE_VALUETYPE || category == ELEMENT_TYPE_CLASS)
        {
            // do nothing
        }
        else if (category == ELEMENT_TYPE_GENERICINST)
        {
            WINRT_VERIFY_(ELEMENT_TYPE_CLASS, CorSigUncompressElementType(cursor));
        }
        else
        {
            WINRT_ASSERT(false);
            return {};
        }

        return token{ CorSigUncompressToken(cursor), db };
    }

    std::string signature::get_abi_name() const
    {
        PCCOR_SIGNATURE cursor = data;
        CorElementType category = CorSigUncompressElementType(cursor);

        if (category == ELEMENT_TYPE_CMOD_REQD || category == ELEMENT_TYPE_CMOD_OPT)
        {
            CorSigUncompressToken(cursor);
            category = CorSigUncompressElementType(cursor);
        }

        if (category == ELEMENT_TYPE_BYREF)
        {
            category = CorSigUncompressElementType(cursor);
        }

        switch (category)
        {
        case ELEMENT_TYPE_BOOLEAN: return "bool";
        case ELEMENT_TYPE_CHAR:    return "char16_t";
        case ELEMENT_TYPE_I1:      return "int8_t";
        case ELEMENT_TYPE_U1:      return "uint8_t";
        case ELEMENT_TYPE_I2:      return "int16_t";
        case ELEMENT_TYPE_U2:      return "uint16_t";
        case ELEMENT_TYPE_I4:      return "int32_t";
        case ELEMENT_TYPE_U4:      return "uint32_t";
        case ELEMENT_TYPE_I8:      return "int64_t";
        case ELEMENT_TYPE_U8:      return "uint64_t";
        case ELEMENT_TYPE_R4:      return "float";
        case ELEMENT_TYPE_R8:      return "double";
        case ELEMENT_TYPE_I:       return "LONG_PTR";
        case ELEMENT_TYPE_U:       return "ULONG_PTR";
        case ELEMENT_TYPE_STRING:  return "HSTRING";
        }

        if (category == ELEMENT_TYPE_CLASS || category == ELEMENT_TYPE_GENERICINST || category == ELEMENT_TYPE_OBJECT)
        {
            return "::IUnknown*";
        }

        WINRT_ASSERT(category == ELEMENT_TYPE_VALUETYPE);

        token token{ CorSigUncompressToken(cursor), db };
        std::string const token_name = token.get_name();

        if (is_meta_struct(token_name))
        {
            std::pair<uint32_t, uint32_t> sizes = token.get_struct_size();

            if (sizes.first == sizes.second)
            {
                return "struct_of<" + std::to_string(sizes.first) + ">";
            }
            else
            {
                return "struct_of<" + std::to_string(sizes.first) + "," + std::to_string(sizes.second) + ">";
            }
        }
        else
        {
            return token_name;
        }
    }

    std::pair<uint32_t, uint32_t> signature::get_struct_size(std::pair<uint32_t, uint32_t>* max_alignment) const
    {
        PCCOR_SIGNATURE cursor = data;
        return read_size(db, cursor, max_alignment);
    }

    CorElementType signature::get_category() const
    {
        return static_cast<CorElementType>(*data);
    }

    signature signature::next(token_callback callback) const 
    {
        signature next{ data, db };

        CorElementType category = CorSigUncompressElementType(next.data);

        if (CorIsPrimitiveType(category) || category == ELEMENT_TYPE_OBJECT)
        {
            return next;
        }

        if (category == ELEMENT_TYPE_BYREF || category == ELEMENT_TYPE_SZARRAY)
        {
            return next.next(callback);
        }

        if (category == ELEMENT_TYPE_VALUETYPE || category == ELEMENT_TYPE_CLASS)
        {
            mdToken token = CorSigUncompressToken(next.data);

            if (callback)
            {
                callback({ token, db });
            }

            return next;
        }

        if (category == ELEMENT_TYPE_GENERICINST)
        {
            CorSigUncompressElementType(next.data);
            mdToken token = CorSigUncompressToken(next.data);

            if (callback)
            {
                callback({ token, db });
            }

            ULONG count = CorSigUncompressData(next.data);

            while (count--)
            {
                next = next.next(callback);
            }

            return next;
        }

        if (category == ELEMENT_TYPE_VAR)
        {
            CorSigUncompressData(next.data);
            return next;
        }

        if (category == ELEMENT_TYPE_CMOD_REQD || category == ELEMENT_TYPE_CMOD_OPT)
        {
            CorSigUncompressToken(next.data);
            return next.next(callback);
        }

        WINRT_ASSERT(false);
        return {};
    }

    bool param::is_in() const noexcept
    {
        return IsPdIn(flags);
    }

    bool param::is_const() const noexcept
    {
        PCCOR_SIGNATURE cursor = signature.data;
        CorElementType category = CorSigUncompressElementType(cursor);
        if (category != ELEMENT_TYPE_CMOD_OPT)
        {
            return false;
        }

        return get_name(token{ CorSigUncompressToken(cursor), signature.db }) == "System.Runtime.CompilerServices.IsConst";
    }

    bool composable_attribute::is_public() const noexcept
    {
        return access == composition_access::public_v;
    }
    bool composable_attribute::is_protected() const noexcept
    {
        return access == composition_access::protected_v;
    }

    token::operator bool() const noexcept
    {
        return handle != 0;
    }

    bool token::is_type_def() const noexcept
    {
        return TypeFromToken(handle) == mdtTypeDef;
    }

    bool token::is_type_ref() const noexcept
    {
        return TypeFromToken(handle) == mdtTypeRef;
    }

    bool token::is_type_spec() const noexcept
    {
        return TypeFromToken(handle) == mdtTypeSpec;
    }

    bool token::is_method_def() const noexcept
    {
        return TypeFromToken(handle) == mdtMethodDef;
    }

    bool token::is_member_ref() const noexcept
    {
        return TypeFromToken(handle) == mdtMemberRef;
    }

    bool token::is_method_spec() const noexcept
    {
        return TypeFromToken(handle) == mdtMethodSpec;
    }

    bool token::is_interface_impl() const noexcept
    {
        return TypeFromToken(handle) == mdtInterfaceImpl;
    }

    bool token::is_field_def() const noexcept
    {
        return TypeFromToken(handle) == mdtFieldDef;
    }

    bool token::is_param_def() const noexcept
    {
        return TypeFromToken(handle) == mdtParamDef;
    }

    bool token::is_generic_param() const noexcept
    {
        return TypeFromToken(handle) == mdtGenericParam;
    }

    generator<token> token::EnumInterfaceImpls() const
    {
        WINRT_ASSERT(is_type_def());
        HCORENUM eh{};
        std::array<mdToken, max_token_count> buffer;
        ULONG actual{};

        while (S_OK == db->EnumInterfaceImpls(&eh, handle, buffer.data(), max_token_count, &actual))
        {
            for (ULONG i = 0; i != actual; ++i)
            {
                co_yield{ buffer[i], db };
            }
        }
    }

    generator<token> token::EnumCustomAttributes() const
    {
        HCORENUM eh{};
        std::array<mdToken, max_token_count> buffer;
        ULONG actual{};

        while (S_OK == db->EnumCustomAttributes(&eh, handle, 0, buffer.data(), max_token_count, &actual))
        {
            for (ULONG i = 0; i != actual; ++i)
            {
                co_yield{ buffer[i], db };
            }
        }
    }

    generator<token> token::EnumMembers() const
    {
        WINRT_ASSERT(is_type_def());
        HCORENUM eh{};
        std::array<mdToken, max_token_count> buffer;
        ULONG actual{};

        while (S_OK == db->EnumMembers(&eh, handle, buffer.data(), max_token_count, &actual))
        {
            for (ULONG i = 0; i != actual; ++i)
            {
                co_yield{ buffer[i], db };
            }
        }
    }

    generator<token> token::EnumParams() const
    {
        WINRT_ASSERT(is_method_def());
        HCORENUM eh{};
        std::array<mdToken, max_token_count> buffer;
        ULONG actual{};

        while (S_OK == db->EnumParams(&eh, handle, buffer.data(), max_token_count, &actual))
        {
            for (ULONG i = 0; i != actual; ++i)
            {
                co_yield{ buffer[i], db };
            }
        }
    }

    token token::GetInterfaceImplProps() const
    {
        WINRT_ASSERT(is_interface_impl());
        mdToken token{};
        winrt::check_hresult(db->GetInterfaceImplProps(handle, nullptr, &token));
        return { token, db };
    }

    std::string token::get_name() const
    {
        WINRT_ASSERT(is_type_def() || is_type_ref() || is_type_spec());

        if (is_type_spec())
        {
            return get_signature().get_name();
        }

        return meta::get_name(*this);
    }

    std::string token::get_name(std::vector<std::string> const& generic_params) const
    {
        WINRT_ASSERT(is_type_def() || is_type_ref() || is_type_spec());

        if (is_type_spec())
        {
            return get_signature().get_name(generic_params);
        }

        std::string value = meta::get_name(*this);
        size_t const tick = value.rfind('`');

        if (tick != std::string::npos)
        {
            value.resize(tick);
            value += '<';
            value += generic_params[0];

            for (size_t i = 1; i != generic_params.size(); ++i)
            {
                value += ", ";
                value += generic_params[i];
            }

            value += '>';
        }

        return value;
    }

    generator<token> token::EnumGenericParams() const
    {
        WINRT_ASSERT(is_type_def());
        HCORENUM eh{};
        std::array<mdToken, max_token_count> buffer;
        ULONG actual{};

        while (S_OK == db->EnumGenericParams(&eh, handle, buffer.data(), max_token_count, &actual))
        {
            for (ULONG i = 0; i != actual; ++i)
            {
                co_yield{ buffer[i], db };
            }
        }
    }

    std::vector<std::string> token::get_generic_params() const
    {
        if (is_type_spec())
        {
            return get_signature().get_generic_params({});
        }

        if (is_type_ref())
        {
            return {};
        }

        std::vector<std::string> generic_params;
        std::array<wchar_t, max_name_size> buffer;
        ULONG actual{};

        for (token param : EnumGenericParams())
        {
            winrt::check_hresult(db->GetGenericParamProps(
                param.handle,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                buffer.data(),
                max_name_size,
                &actual));

            generic_params.push_back(to_string({ buffer.data(), actual - 1 }));
        }

        return generic_params;
    }

    std::vector<factory_attribute> token::get_factory_attributes() const
    {
        std::vector<factory_attribute> factory_attributes;

        for (token attribute_token : EnumCustomAttributes())
        {
            uint8_t const* data{};
            ULONG data_length{};
            token attribute{ 0, db };

            winrt::check_hresult(db->GetCustomAttributeProps(
                attribute_token.handle,
                nullptr,
                &attribute.handle,
                reinterpret_cast<void const**>(&data),
                &data_length));

            WINRT_ASSERT(attribute.is_member_ref());
            const uint8_t* const data_end = data + data_length;

            // TODO: update meta::signature to handle this and simplify this parsing code...
            PCCOR_SIGNATURE signature{};
            ULONG signature_length{};

            winrt::check_hresult(attribute.db->GetMemberRefProps(
                attribute.handle,
                &attribute.handle,
                nullptr,
                0,
                nullptr,
                &signature,
                &signature_length));

            WINRT_ASSERT(attribute.is_type_ref());
            const PCCOR_SIGNATURE signature_end = signature + signature_length;

            bool activatable{};
            type const* factory_type{};

            {
                std::string const name = attribute.get_name();

                if (name == "Windows.Foundation.Metadata.ActivatableAttribute")
                {
                    activatable = true;
                }
                else if (name == "Windows.Foundation.Metadata.StaticAttribute")
                {
                    activatable = false;
                }
                else
                {
                    continue;
                }
            }

            const auto prologue = read_blob<uint16_t>(data);
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
                    token tk{ CorSigUncompressToken(signature), db };
                    WINRT_ASSERT(tk.is_type_ref());
                    WINRT_ASSERT(tk.get_name() == "System.Type");
                }
                factory_type = find_type(read_blob<std::string>(data));
                break;

                case ELEMENT_TYPE_VALUETYPE:
                {
                    token tk{ CorSigUncompressToken(signature), db };
                    WINRT_ASSERT(tk.is_type_ref());
                    WINRT_ASSERT(tk.get_name() == "Windows.Foundation.Metadata.Platform");
                }
                read_blob<int32_t>(data);
                break;

                case ELEMENT_TYPE_U4:
                    read_blob<uint32_t>(data);
                    break;

                case ELEMENT_TYPE_STRING:
                    read_blob<std::string>(data);
                    break;

                default:
                    WINRT_ASSERT(false);
                    break;
                }
            }

            factory_attributes.push_back({ factory_type, activatable });
        }

        std::sort(factory_attributes.begin(), factory_attributes.end(),
            [](factory_attribute const& left, factory_attribute const& right)
        {
            std::string_view left_name;
            std::string_view right_name;

            if (left.type)
            {
                left_name = left.type->full_name();
            }

            if (right.type)
            {
                right_name = right.type->full_name();
            }

            return left_name < right_name;
        });

        return factory_attributes;
    }

    std::vector<composable_attribute> token::get_composable_attributes() const
    {
        std::vector<composable_attribute> composable_attributes;

        for (token attribute_token : EnumCustomAttributes())
        {
            uint8_t const* data{};
            ULONG data_length{};
            token attribute{ 0, db };

            winrt::check_hresult(db->GetCustomAttributeProps(
                attribute_token.handle,
                nullptr,
                &attribute.handle,
                reinterpret_cast<void const**>(&data),
                &data_length));

            WINRT_ASSERT(attribute.is_member_ref());
            const uint8_t* const data_end = data + data_length;

            // TODO: update meta::signature to handle this and simplify this parsing code...
            PCCOR_SIGNATURE signature{};
            ULONG signature_length{};

            winrt::check_hresult(attribute.db->GetMemberRefProps(
                attribute.handle,
                &attribute.handle,
                nullptr,
                0,
                nullptr,
                &signature,
                &signature_length));

            WINRT_ASSERT(attribute.is_type_ref());
            const PCCOR_SIGNATURE signature_end = signature + signature_length;

            if (attribute.get_name() != "Windows.Foundation.Metadata.ComposableAttribute")
            {
                continue;
            }

            const auto prologue = read_blob<uint16_t>(data);
            WINRT_ASSERT(prologue == 0x0001);

            WINRT_ASSERT(*signature == IMAGE_CEE_CS_CALLCONV_HASTHIS);
            CorSigUncompressCallingConv(signature);
            const ULONG param_count = CorSigUncompressData(signature);
            WINRT_ASSERT(param_count == 3 || param_count == 4);
            WINRT_ASSERT(*signature == ELEMENT_TYPE_VOID);
            CorSigUncompressElementType(signature);

            // First parameter should always be System.Type
            CorElementType category = CorSigUncompressElementType(signature);
            WINRT_ASSERT(category == ELEMENT_TYPE_CLASS);
            token tk{ CorSigUncompressToken(signature), db };
            WINRT_ASSERT(tk.is_type_ref());
            WINRT_ASSERT(tk.get_name() == "System.Type");

            type const* factory_type = find_type(read_blob<std::string>(data));

            WINRT_ASSERT(signature <= signature_end);
            WINRT_ASSERT(data <= data_end);

            // Second parameter is always the CompositionType
            category = CorSigUncompressElementType(signature);
            WINRT_ASSERT(category == ELEMENT_TYPE_VALUETYPE);
            tk = token{ CorSigUncompressToken(signature), db };
            WINRT_ASSERT(tk.is_type_ref());
            WINRT_ASSERT(tk.get_name() == "Windows.Foundation.Metadata.CompositionType");

            composition_access access = read_blob<composition_access>(data);
            WINRT_ASSERT(access == composition_access::protected_v || access == composition_access::public_v);

            WINRT_ASSERT(signature <= signature_end);
            WINRT_ASSERT(data <= data_end);

            // Third parameter is always the version
            category = CorSigUncompressElementType(signature);
            WINRT_ASSERT(category == ELEMENT_TYPE_U4);
            read_blob<uint32_t>(data);

            WINRT_ASSERT(signature <= signature_end);
            WINRT_ASSERT(data <= data_end);

            // There might be a fourth parameter. It's always either the contract or the platform
            if (param_count == 4)
            {
                category = CorSigUncompressElementType(signature);
                if (category == ELEMENT_TYPE_STRING)
                {
                    read_blob<std::string>(data);
                }
                else if (category == ELEMENT_TYPE_VALUETYPE)
                {
                    tk = token{ CorSigUncompressToken(signature), db };
                    WINRT_ASSERT(tk.is_type_ref());
                    WINRT_ASSERT(tk.get_name() == "Windows.Foundation.Metadata.Platform");
                    read_blob<int32_t>(data);
                }
                else
                {
                    WINRT_ASSERT(false);
                }
            }

            composable_attributes.push_back({ factory_type, access });
        }

        return composable_attributes;
    }

    std::vector<required> token::get_direct_override_interfaces() const
    {
        return get_class_required_impl(*this, interface_filter::overridable, interface_filter::none, base_filter::none);
    }

    std::vector<required> token::get_all_override_interfaces() const
    {
        return get_class_required_impl(*this, interface_filter::overridable, interface_filter::overridable, base_filter::all);
    }

    std::vector<required> token::get_all_nonoverride_interfaces() const
    {
        return get_class_required_impl(*this, interface_filter::non_overridable, interface_filter::non_overridable, base_filter::all);
    }

    std::vector<required> token::get_component_class_override_fallbacks() const
    {
        return get_class_required_impl(*this, interface_filter::none, interface_filter::overridable, base_filter::reference_only);
    }

    generator<using_pair> token::get_interface_usings() const
    {
        std::vector<required> required_interfaces = get_interface_required();
        required_interfaces.push_back({ get_name(), *this });
        using using_map = std::map<std::string, std::vector<size_t>>;
        using_map usings;

        for (size_t i = 0; i != required_interfaces.size(); ++i)
        {
            for (std::string const& method : required_interfaces[i].token.get_method_names())
            {
                usings[method].push_back(i);
            }
        }

        for (using_map::value_type& pair : usings)
        {
            std::sort(pair.second.begin(), pair.second.end());
            pair.second.erase(std::unique(pair.second.begin(), pair.second.end()), pair.second.end());

            if (pair.second.size() <= 1)
            {
                continue;
            }

            for (size_t i : pair.second)
            {
                co_yield{ pair.first, required_interfaces[i].name };
            }
        }
    }

    generator<using_pair> token::get_class_usings() const
    {
        token default_interface = get_default();
        std::vector<required> required_interfaces = default_interface.get_interface_required();
        required_interfaces.push_back({ default_interface.get_name(), default_interface });
        using using_map = std::map<std::string, std::vector<size_t>>;
        using_map usings;

        for (size_t i = 0; i != required_interfaces.size(); ++i)
        {
            for (std::string const& method : required_interfaces[i].token.get_method_names())
            {
                usings[method].push_back(UINTPTR_MAX);
            }
        }

        required_interfaces = get_class_required_excluding_default();

        for (size_t i = 0; i != required_interfaces.size(); ++i)
        {
            for (std::string const& method : required_interfaces[i].token.get_method_names())
            {
                usings[method].push_back(i);
            }
        }

        for (using_map::value_type& pair : usings)
        {
            std::sort(pair.second.begin(), pair.second.end());
            pair.second.erase(std::unique(pair.second.begin(), pair.second.end()), pair.second.end());

            if (pair.second.size() <= 1)
            {
                continue;
            }

            for (size_t i : pair.second)
            {
                if (i == UINTPTR_MAX)
                {
                    co_yield{ pair.first, {} };
                }
                else
                {
                    co_yield{ pair.first, required_interfaces[i].name };
                }
            }
        }
    }

    signature token::get_signature() const
    {
        WINRT_ASSERT(is_type_spec());
        PCCOR_SIGNATURE signature{};
        ULONG size{};
        winrt::check_hresult(db->GetTypeSpecFromToken(handle, &signature, &size));
        return { signature, db };
    }

    token token::get_definition() const
    {
        WINRT_ASSERT(is_type_def() || is_type_ref() || is_type_spec());

        if (is_type_def())
        {
            return *this;
        }

        return get_type()->token;
    }

    type const* token::get_type() const
    {
        WINRT_ASSERT(is_type_def() || is_type_ref() || is_type_spec());

        if (is_type_def() || is_type_ref())
        {
            return find_type(get_name());
        }

        return find_type(get_signature().get_token().get_name());
    }

    std::string token::get_guid(char const* format) const
    {
        void const* data{};
        ULONG size{};
        winrt::check_hresult(db->GetCustomAttributeByName(handle, L"Windows.Foundation.Metadata.GuidAttribute", &data, &size));
        GUID const& guid = *reinterpret_cast<GUID const*>(static_cast<uint8_t const*>(data) + 2);

        std::string result(68, '?');

        int count = sprintf_s(result.data(), result.size() + 1,
            format,
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

        result.resize(count);

        return result;
    }

    generator<method> token::get_methods(token_callback callback) const
    {
        token type_def = get_definition();
        std::array<wchar_t, max_name_size> buffer;
        ULONG actual{};
        DWORD flags{};
        signature signature{ nullptr, type_def.db };

        for (token member_token : type_def.EnumMembers())
        {
            WINRT_ASSERT(member_token.is_method_def());

            winrt::check_hresult(member_token.db->GetMemberProps(
                member_token.handle,
                nullptr,
                buffer.data(),
                max_name_size,
                &actual,
                &flags,
                &signature.data,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr));

            WINRT_ASSERT(actual > 0);
            if (0 == wcscmp(buffer.data(), L".ctor"))
            {
                continue;
            }

            CorSigUncompressCallingConv(signature.data);
            CorSigUncompressData(signature.data);

            method method{ member_token, to_string({ buffer.data(), actual - 1 }), flags };
            method.return_type.signature = signature;
            signature = signature.next(callback);
            bool first = static_cast<CorElementType>(*method.return_type.signature.data) != ELEMENT_TYPE_VOID;
            ULONG sequence{};

            for (token param_token : member_token.EnumParams())
            {
                winrt::check_hresult(param_token.db->GetParamProps(
                    param_token.handle,
                    nullptr,
                    &sequence,
                    buffer.data(),
                    max_name_size,
                    &actual,
                    &flags,
                    nullptr,
                    nullptr,
                    nullptr));

                if (first && sequence == 0)
                {
                    first = false;
                    if (actual > 0)
                    {
                        method.return_type.name = to_string({ buffer.data(), actual - 1 });
                    }
                    else
                    {
                        method.return_type.name = "_unnamed_return_";
                    }
                }
                else
                {
                    if (actual > 0)
                    {
                        method.params.push_back({ to_string({ buffer.data(), actual - 1 }), flags, signature });
                    }
                    else
                    {
                        std::array<char, 64> temp;
                        snprintf(temp.data(), temp.size(), "_unnamed_param_%d_", sequence);
                        method.params.push_back({ std::string(temp.data()), flags, signature });
                    }
                    signature = signature.next(callback);
                }
            }

            co_yield method;
        }
    }

    generator<std::string> token::get_method_names() const
    {
        token type_def = get_definition();
        std::array<wchar_t, max_name_size> buffer;
        ULONG actual{};
        DWORD flags{};

        for (token member_token : type_def.EnumMembers())
        {
            WINRT_ASSERT(member_token.is_method_def());

            winrt::check_hresult(member_token.db->GetMemberProps(
                member_token.handle,
                nullptr,
                buffer.data(),
                max_name_size,
                &actual,
                &flags,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr,
                nullptr));

            WINRT_ASSERT(actual > 0);
            co_yield to_method_name(to_string({ buffer.data(), actual - 1 }), flags);
        }
    }

    bool token::has_attribute(wchar_t const* attribute) const noexcept
    {
        return S_OK == db->GetCustomAttributeByName(handle, attribute, nullptr, nullptr);
    }

    bool token::is_default() const noexcept
    {
        return has_attribute(L"Windows.Foundation.Metadata.DefaultAttribute");
    }

    bool token::is_overridable() const noexcept
    {
        return has_attribute(L"Windows.Foundation.Metadata.OverridableAttribute");
    }

    bool token::is_api_contract() const noexcept
    {
        return has_attribute(L"Windows.Foundation.Metadata.ApiContractAttribute");
    }

    bool token::is_flags() const noexcept
    {
        return has_attribute(L"System.FlagsAttribute");
    }

    bool token::is_static() const noexcept
    {
        return !static_cast<bool>(get_default());
    }

    bool token::get_attribute_string(wchar_t const* attribute, std::string& value) const
    {
        void const* data{};
        ULONG size{};
        HRESULT const hr = db->GetCustomAttributeByName(handle, attribute, &data, &size);

        if (hr != S_OK)
        {
            return false;
        }

        PCCOR_SIGNATURE signature = static_cast<PCCOR_SIGNATURE>(data);
        WINRT_ASSERT(*signature == 1);
        ++signature;
        WINRT_ASSERT(*signature == 0);
        ++signature;

        ULONG const count = CorSigUncompressData(signature);
        value.assign(reinterpret_cast<char const*>(signature), count);
        return true;
    }

    generator<enumerator> token::get_enumerators() const
    {
        std::array<wchar_t, max_name_size> buffer;
        ULONG actual{};
        UVCP_CONSTANT enum_value{};

        for (token member_token : EnumMembers())
        {
            WINRT_ASSERT(member_token.is_field_def());

            winrt::check_hresult(member_token.db->GetFieldProps(
                member_token.handle,
                nullptr,
                buffer.data(),
                max_name_size,
                &actual,
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

            co_yield{ member_token, to_string({ buffer.data(), actual - 1 }), *static_cast<int32_t const*>(enum_value) };
        }
    }

    std::vector<field> token::get_fields(token_callback callback) const
    {
        std::vector<field> fields;
        std::array<wchar_t, max_name_size> buffer;
        ULONG actual{};
        signature signature{ nullptr, db };

        for (token member_token : EnumMembers())
        {
            WINRT_ASSERT(member_token.is_field_def());

            winrt::check_hresult(member_token.db->GetFieldProps(member_token.handle,
                nullptr,
                buffer.data(),
                max_name_size,
                &actual,
                nullptr,
                &signature.data,
                nullptr,
                nullptr,
                nullptr,
                nullptr));

            ++signature.data;

            fields.push_back({ to_string({ buffer.data(), actual - 1 }), signature });

            if (callback)
            {
                signature.next(callback);
            }
        }

        return fields;
    }

    uint32_t round_up(uint32_t value, uint32_t multiple)
    {
        if (multiple == 0)
        {
            return value;
        }

        uint32_t remainder = value % multiple;

        if (remainder == 0)
        {
            return value;
        }

        return value + multiple - remainder;
    }

    std::pair<uint32_t, uint32_t> token::get_struct_size(std::pair<uint32_t, uint32_t>* max_alignment) const
    {
        std::string const name = get_name();

        // I don't love this special handling of GUID, but we'll need a larger refactor of GUID type handling
        // to resolve this. This only came up because internal types use GUID parameters whereas public types
        // are not permitted to do so by convention.

        if (name == "GUID")
        {
            if (max_alignment != nullptr)
            {
                *max_alignment = { 4, 4 };
            }

            return { 16, 16 };
        }

        type_category category;
        type const* type = find_type(name, &category);

        if (category == type_category::enum_v)
        {
            return { 4, 4 };
        }

        WINRT_ASSERT(category == type_category::struct_v);

        std::pair<uint32_t, uint32_t> sum;
        std::pair<uint32_t, uint32_t> alignment;

        for (field const& field : type->token.get_fields())
        {
            // Size of next field.
            std::pair<uint32_t, uint32_t> inner_alignment;
            std::pair<uint32_t, uint32_t> const size = field.type.get_struct_size(&inner_alignment);

            // Maximum alignment needed to calculate effective struct alignment.
            if (inner_alignment.first == 0)
            {
                inner_alignment = size;
            }

            alignment.first = std::max(alignment.first, inner_alignment.first);
            alignment.second = std::max(alignment.second, inner_alignment.second);

            // Padding for next field.
            sum.first += (sum.first % inner_alignment.first == 0) ? 0 : (inner_alignment.first - (sum.first % inner_alignment.first));
            sum.second += (sum.second % inner_alignment.second == 0) ? 0 : (inner_alignment.second - (sum.second % inner_alignment.second));

            // Size of field itself
            sum.first += size.first;
            sum.second += size.second;
        }

        sum.first = round_up(sum.first, alignment.first);
        sum.second = round_up(sum.second, alignment.second);

        if (max_alignment != nullptr)
        {
            *max_alignment = alignment;
        }

        return sum;
    }

    std::vector<required> token::get_interface_required() const
    {
        std::vector<required> values;
        append_required(values, *this, get_generic_params(), interface_filter::all);
        sort_unique(values);
        return values;
    }

    std::vector<required> token::get_class_required() const
    {
        return get_class_required_impl(*this, interface_filter::all, interface_filter::all, base_filter::all);
    }

    std::vector<required> token::get_component_class_generated_interfaces() const
    {
        return get_class_required_impl(*this, interface_filter::all, interface_filter::overridable, base_filter::reference_only);
    }

    std::vector<required> token::get_component_class_interfaces() const
    {
        return get_class_required_impl(*this, interface_filter::all, interface_filter::none, base_filter::none);
    }

    std::vector<required> token::get_component_class_generated_required() const
    {
        return get_class_required_impl(*this, interface_filter::none, interface_filter::non_overridable, base_filter::reference_only);
    }

    std::vector<required> token::get_class_required_excluding_default() const
    {
        std::vector<required> values = get_class_required_base(*this, interface_filter::all, interface_filter::all, base_filter::all);

        if (values.empty())
        {
            return values;
        }

        exclude_required(values, get_default());
        return values;
    }

    token token::get_extends() const
    {
        WINRT_ASSERT(is_type_def());
        mdToken extends{};
        winrt::check_hresult(db->GetTypeDefProps(handle, nullptr, 0, nullptr, nullptr, &extends));
        return{ extends, db };
    }

    token token::get_base() const
    {
        token base = get_extends();

        if (base.get_name() == "System.Object")
        {
            return {};
        }

        return base.get_definition();
    }

    type const* token::get_base_type() const
    {
        token base = get_extends();

        if (base.get_name() == "System.Object")
        {
            return nullptr;
        }

        return base.get_type();
    }

    token token::get_default() const
    {
        for (token impl_token : EnumInterfaceImpls())
        {
            if (impl_token.is_default())
            {
                return impl_token.GetInterfaceImplProps();
            }
        }

        return {};
    }

    method token::get_delegate(token_callback callback) const
    {
        return *get_methods(callback).begin();
    }

    bool operator==(token left, token right) noexcept
    {
        WINRT_ASSERT(left.is_type_def());
        return left.handle == right.handle && left.db == right.db;
    }

    bool operator!=(token left, token right) noexcept
    {
        return !(left == right);
    }

    bool operator<(token left, token right) noexcept
    {
        WINRT_ASSERT(left.is_type_def());
        return (left.handle < right.handle || (!(right.handle < left.handle) && left.db < right.db));
    }

    bool operator==(required const& left, required const& right) noexcept
    {
        return left.name == right.name;
    }

    bool operator!=(required const& left, required const& right) noexcept
    {
        return !(left == right);
    }

    bool operator<(required const& left, required const& right) noexcept
    {
        return left.name < right.name;
    }

    bool method::is_special() const noexcept
    {
        return IsMdSpecialName(flags);
    }

    bool method::has_return_type() const noexcept
    {
        return static_cast<CorElementType>(*return_type.signature.data) != ELEMENT_TYPE_VOID;
    }

    std::string method::get_name() const noexcept
    {
        return to_method_name(raw_name, flags);
    }

    std::string method::get_abi_name() const noexcept
    {
        std::string value;

        if (token.get_attribute_string(L"Windows.Foundation.Metadata.OverloadAttribute", value))
        {
            return value;
        }

        return raw_name;
    }

    bool type::is_filtered() const
    {
        if (settings::filters.empty())
        {
            return !is_reference;
        }

        for (std::string const& match : settings::filters)
        {
            if (starts_with(full_name(), match))
            {
                return true;
            }
        }

        return false;
    }

    type::type(std::string&& name, meta::token token, bool const reference) :
        buffer(std::move(name)),
        offset(buffer.rfind('.') + 1),
        token(token),
        is_reference(reference)
    {
        if (offset == 0)
        {
            offset = 1;
        }
    }

    std::string_view type::full_name() const noexcept
    {
        return buffer;
    }

    std::string_view type::name_space() const noexcept
    {
        return { buffer.data(), offset - 1 };
    }

    std::string_view type::name() const noexcept
    {
        return { buffer.data() + offset, buffer.size() - offset };
    }
}
