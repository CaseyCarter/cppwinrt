
namespace ABI::Windows::Foundation
{
    struct IPropertyValue;
    struct IPropertyValueStatics;
}

namespace Windows::Foundation
{
    struct IPropertyValue;
    struct IPropertyValueStatics;
    struct PropertyValue;

    enum class PropertyType
    {
        Empty = 0,
        UInt8 = 1,
        Int16 = 2,
        UInt16 = 3,
        Int32 = 4,
        UInt32 = 5,
        Int64 = 6,
        UInt64 = 7,
        Single = 8,
        Double = 9,
        Char16 = 10,
        Boolean = 11,
        String = 12,
        Inspectable = 13,
        DateTime = 14,
        TimeSpan = 15,
        Guid = 16,
        Point = 17,
        Size = 18,
        Rect = 19,
        OtherType = 20,
        UInt8Array = 1025,
        Int16Array = 1026,
        UInt16Array = 1027,
        Int32Array = 1028,
        UInt32Array = 1029,
        Int64Array = 1030,
        UInt64Array = 1031,
        SingleArray = 1032,
        DoubleArray = 1033,
        Char16Array = 1034,
        BooleanArray = 1035,
        StringArray = 1036,
        InspectableArray = 1037,
        DateTimeArray = 1038,
        TimeSpanArray = 1039,
        GuidArray = 1040,
        PointArray = 1041,
        SizeArray = 1042,
        RectArray = 1043,
        OtherTypeArray = 1044,
    };
}

namespace ABI::Windows::Foundation
{
    struct __declspec(uuid("4bd682dd-7554-40e9-9a9b-82654ede7e62")) __declspec(novtable) IPropertyValue : IInspectable
    {
        virtual HRESULT __stdcall get_Type(winrt::Windows::Foundation::PropertyType * value) = 0;
        virtual HRESULT __stdcall get_IsNumericScalar(bool * value) = 0;
        virtual HRESULT __stdcall abi_GetUInt8(uint8_t * value) = 0;
        virtual HRESULT __stdcall abi_GetInt16(int16_t * value) = 0;
        virtual HRESULT __stdcall abi_GetUInt16(uint16_t * value) = 0;
        virtual HRESULT __stdcall abi_GetInt32(int32_t * value) = 0;
        virtual HRESULT __stdcall abi_GetUInt32(uint32_t * value) = 0;
        virtual HRESULT __stdcall abi_GetInt64(int64_t * value) = 0;
        virtual HRESULT __stdcall abi_GetUInt64(uint64_t * value) = 0;
        virtual HRESULT __stdcall abi_GetSingle(float * value) = 0;
        virtual HRESULT __stdcall abi_GetDouble(double * value) = 0;
        virtual HRESULT __stdcall abi_GetChar16(wchar_t * value) = 0;
        virtual HRESULT __stdcall abi_GetBoolean(bool * value) = 0;
        virtual HRESULT __stdcall abi_GetString(hstring * value) = 0;
        virtual HRESULT __stdcall abi_GetGuid(GUID * value) = 0;
        virtual HRESULT __stdcall abi_GetDateTime(Windows::Foundation::DateTime * value) = 0;
        virtual HRESULT __stdcall abi_GetTimeSpan(Windows::Foundation::TimeSpan * value) = 0;
        virtual HRESULT __stdcall abi_GetPoint(Windows::Foundation::Point * value) = 0;
        virtual HRESULT __stdcall abi_GetSize(Windows::Foundation::Size * value) = 0;
        virtual HRESULT __stdcall abi_GetRect(Windows::Foundation::Rect * value) = 0;
        virtual HRESULT __stdcall abi_GetUInt8Array(uint32_t * __valueSize, uint8_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetInt16Array(uint32_t * __valueSize, int16_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetUInt16Array(uint32_t * __valueSize, uint16_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetInt32Array(uint32_t * __valueSize, int32_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetUInt32Array(uint32_t * __valueSize, uint32_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetInt64Array(uint32_t * __valueSize, int64_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetUInt64Array(uint32_t * __valueSize, uint64_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetSingleArray(uint32_t * __valueSize, float ** value) = 0;
        virtual HRESULT __stdcall abi_GetDoubleArray(uint32_t * __valueSize, double ** value) = 0;
        virtual HRESULT __stdcall abi_GetChar16Array(uint32_t * __valueSize, wchar_t ** value) = 0;
        virtual HRESULT __stdcall abi_GetBooleanArray(uint32_t * __valueSize, bool ** value) = 0;
        virtual HRESULT __stdcall abi_GetStringArray(uint32_t * __valueSize, hstring ** value) = 0;
        virtual HRESULT __stdcall abi_GetInspectableArray(uint32_t * __valueSize, IInspectable *** value) = 0;
        virtual HRESULT __stdcall abi_GetGuidArray(uint32_t * __valueSize, GUID ** value) = 0;
        virtual HRESULT __stdcall abi_GetDateTimeArray(uint32_t * __valueSize, Windows::Foundation::DateTime ** value) = 0;
        virtual HRESULT __stdcall abi_GetTimeSpanArray(uint32_t * __valueSize, Windows::Foundation::TimeSpan ** value) = 0;
        virtual HRESULT __stdcall abi_GetPointArray(uint32_t * __valueSize, Windows::Foundation::Point ** value) = 0;
        virtual HRESULT __stdcall abi_GetSizeArray(uint32_t * __valueSize, Windows::Foundation::Size ** value) = 0;
        virtual HRESULT __stdcall abi_GetRectArray(uint32_t * __valueSize, Windows::Foundation::Rect ** value) = 0;
    };

    struct __declspec(uuid("629bdbc8-d932-4ff4-96b9-8d96c5c1e858")) __declspec(novtable) IPropertyValueStatics : IInspectable
    {
        virtual HRESULT __stdcall abi_CreateEmpty(IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt8(uint8_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt16(int16_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt16(uint16_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt32(int32_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt32(uint32_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt64(int64_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt64(uint64_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateSingle(float value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateDouble(double value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateChar16(wchar_t value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateBoolean(bool value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateString(hstring value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInspectable(IInspectable * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateGuid(GUID value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateDateTime(Windows::Foundation::DateTime value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateTimeSpan(Windows::Foundation::TimeSpan value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreatePoint(Windows::Foundation::Point value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateSize(Windows::Foundation::Size value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateRect(Windows::Foundation::Rect value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt8Array(uint32_t __valueSize, uint8_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt16Array(uint32_t __valueSize, int16_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt16Array(uint32_t __valueSize, uint16_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt32Array(uint32_t __valueSize, int32_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt32Array(uint32_t __valueSize, uint32_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInt64Array(uint32_t __valueSize, int64_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateUInt64Array(uint32_t __valueSize, uint64_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateSingleArray(uint32_t __valueSize, float * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateDoubleArray(uint32_t __valueSize, double * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateChar16Array(uint32_t __valueSize, wchar_t * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateBooleanArray(uint32_t __valueSize, bool * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateStringArray(uint32_t __valueSize, hstring * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateInspectableArray(uint32_t __valueSize, IInspectable ** value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateGuidArray(uint32_t __valueSize, GUID * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateDateTimeArray(uint32_t __valueSize, Windows::Foundation::DateTime * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateTimeSpanArray(uint32_t __valueSize, Windows::Foundation::TimeSpan * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreatePointArray(uint32_t __valueSize, Windows::Foundation::Point * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateSizeArray(uint32_t __valueSize, Windows::Foundation::Size * value, IInspectable ** propertyValue) = 0;
        virtual HRESULT __stdcall abi_CreateRectArray(uint32_t __valueSize, Windows::Foundation::Rect * value, IInspectable ** propertyValue) = 0;
    };
}

namespace Windows::Foundation
{
    template <typename D>
    struct WINRT_EBO impl_IPropertyValue
    {
        Windows::Foundation::PropertyType Type() const;
        bool IsNumericScalar() const;
        uint8_t GetUInt8() const;
        int16_t GetInt16() const;
        uint16_t GetUInt16() const;
        int32_t GetInt32() const;
        uint32_t GetUInt32() const;
        int64_t GetInt64() const;
        uint64_t GetUInt64() const;
        float GetSingle() const;
        double GetDouble() const;
        wchar_t GetChar16() const;
        bool GetBoolean() const;
        hstring GetString() const;
        GUID GetGuid() const;
        Windows::Foundation::DateTime GetDateTime() const;
        Windows::Foundation::TimeSpan GetTimeSpan() const;
        Windows::Foundation::Point GetPoint() const;
        Windows::Foundation::Size GetSize() const;
        Windows::Foundation::Rect GetRect() const;
        void GetUInt8Array(com_array<uint8_t> & value) const;
        void GetInt16Array(com_array<int16_t> & value) const;
        void GetUInt16Array(com_array<uint16_t> & value) const;
        void GetInt32Array(com_array<int32_t> & value) const;
        void GetUInt32Array(com_array<uint32_t> & value) const;
        void GetInt64Array(com_array<int64_t> & value) const;
        void GetUInt64Array(com_array<uint64_t> & value) const;
        void GetSingleArray(com_array<float> & value) const;
        void GetDoubleArray(com_array<double> & value) const;
        void GetChar16Array(com_array<wchar_t> & value) const;
        void GetBooleanArray(com_array<bool> & value) const;
        void GetStringArray(com_array<hstring> & value) const;
        void GetInspectableArray(com_array<IInspectable> & value) const;
        void GetGuidArray(com_array<GUID> & value) const;
        void GetDateTimeArray(com_array<Windows::Foundation::DateTime> & value) const;
        void GetTimeSpanArray(com_array<Windows::Foundation::TimeSpan> & value) const;
        void GetPointArray(com_array<Windows::Foundation::Point> & value) const;
        void GetSizeArray(com_array<Windows::Foundation::Size> & value) const;
        void GetRectArray(com_array<Windows::Foundation::Rect> & value) const;
    };

    template <typename D>
    struct WINRT_EBO impl_IPropertyValueStatics
    {
        IInspectable CreateEmpty() const;
        IInspectable CreateUInt8(uint8_t value) const;
        IInspectable CreateInt16(int16_t value) const;
        IInspectable CreateUInt16(uint16_t value) const;
        IInspectable CreateInt32(int32_t value) const;
        IInspectable CreateUInt32(uint32_t value) const;
        IInspectable CreateInt64(int64_t value) const;
        IInspectable CreateUInt64(uint64_t value) const;
        IInspectable CreateSingle(float value) const;
        IInspectable CreateDouble(double value) const;
        IInspectable CreateChar16(wchar_t value) const;
        IInspectable CreateBoolean(bool value) const;
        IInspectable CreateString(hstring_view value) const;
        IInspectable CreateInspectable(const IInspectable & value) const;
        IInspectable CreateGuid(GUID value) const;
        IInspectable CreateDateTime(const Windows::Foundation::DateTime & value) const;
        IInspectable CreateTimeSpan(const Windows::Foundation::TimeSpan & value) const;
        IInspectable CreatePoint(const Windows::Foundation::Point & value) const;
        IInspectable CreateSize(const Windows::Foundation::Size & value) const;
        IInspectable CreateRect(const Windows::Foundation::Rect & value) const;
        IInspectable CreateUInt8Array(array_view<const uint8_t> value) const;
        IInspectable CreateInt16Array(array_view<const int16_t> value) const;
        IInspectable CreateUInt16Array(array_view<const uint16_t> value) const;
        IInspectable CreateInt32Array(array_view<const int32_t> value) const;
        IInspectable CreateUInt32Array(array_view<const uint32_t> value) const;
        IInspectable CreateInt64Array(array_view<const int64_t> value) const;
        IInspectable CreateUInt64Array(array_view<const uint64_t> value) const;
        IInspectable CreateSingleArray(array_view<const float> value) const;
        IInspectable CreateDoubleArray(array_view<const double> value) const;
        IInspectable CreateChar16Array(array_view<const wchar_t> value) const;
        IInspectable CreateBooleanArray(array_view<const bool> value) const;
        IInspectable CreateStringArray(array_view<const hstring> value) const;
        IInspectable CreateInspectableArray(array_view<const IInspectable> value) const;
        IInspectable CreateGuidArray(array_view<const GUID> value) const;
        IInspectable CreateDateTimeArray(array_view<const Windows::Foundation::DateTime> value) const;
        IInspectable CreateTimeSpanArray(array_view<const Windows::Foundation::TimeSpan> value) const;
        IInspectable CreatePointArray(array_view<const Windows::Foundation::Point> value) const;
        IInspectable CreateSizeArray(array_view<const Windows::Foundation::Size> value) const;
        IInspectable CreateRectArray(array_view<const Windows::Foundation::Rect> value) const;
    };
}

namespace impl
{
    template <> struct traits<Windows::Foundation::IPropertyValue>
    {
        using abi = ABI::Windows::Foundation::IPropertyValue;
        template <typename D> using consume = Windows::Foundation::impl_IPropertyValue<D>;
    };

    template <> struct traits<Windows::Foundation::IPropertyValueStatics>
    {
        using abi = ABI::Windows::Foundation::IPropertyValueStatics;
        template <typename D> using consume = Windows::Foundation::impl_IPropertyValueStatics<D>;
    };

    template <> struct traits<Windows::Foundation::PropertyValue>
    {
        static constexpr const wchar_t * name() noexcept { return L"Windows.Foundation.PropertyValue"; }
    };
}

namespace Windows::Foundation
{
    struct IPropertyValue :
        IInspectable,
        impl::consume<IPropertyValue>
    {
        IPropertyValue(std::nullptr_t = nullptr) noexcept {}
    };

    struct IPropertyValueStatics :
        IInspectable,
        impl::consume<IPropertyValueStatics>
    {
        IPropertyValueStatics(std::nullptr_t = nullptr) noexcept {}
    };

    struct PropertyValue
    {
        PropertyValue() = delete;
        static IInspectable CreateEmpty();
        static IInspectable CreateUInt8(uint8_t value);
        static IInspectable CreateInt16(int16_t value);
        static IInspectable CreateUInt16(uint16_t value);
        static IInspectable CreateInt32(int32_t value);
        static IInspectable CreateUInt32(uint32_t value);
        static IInspectable CreateInt64(int64_t value);
        static IInspectable CreateUInt64(uint64_t value);
        static IInspectable CreateSingle(float value);
        static IInspectable CreateDouble(double value);
        static IInspectable CreateChar16(wchar_t value);
        static IInspectable CreateBoolean(bool value);
        static IInspectable CreateString(hstring_view value);
        static IInspectable CreateInspectable(const IInspectable & value);
        static IInspectable CreateGuid(GUID value);
        static IInspectable CreateDateTime(const Windows::Foundation::DateTime & value);
        static IInspectable CreateTimeSpan(const Windows::Foundation::TimeSpan & value);
        static IInspectable CreatePoint(const Windows::Foundation::Point & value);
        static IInspectable CreateSize(const Windows::Foundation::Size & value);
        static IInspectable CreateRect(const Windows::Foundation::Rect & value);
        static IInspectable CreateUInt8Array(array_view<const uint8_t> value);
        static IInspectable CreateInt16Array(array_view<const int16_t> value);
        static IInspectable CreateUInt16Array(array_view<const uint16_t> value);
        static IInspectable CreateInt32Array(array_view<const int32_t> value);
        static IInspectable CreateUInt32Array(array_view<const uint32_t> value);
        static IInspectable CreateInt64Array(array_view<const int64_t> value);
        static IInspectable CreateUInt64Array(array_view<const uint64_t> value);
        static IInspectable CreateSingleArray(array_view<const float> value);
        static IInspectable CreateDoubleArray(array_view<const double> value);
        static IInspectable CreateChar16Array(array_view<const wchar_t> value);
        static IInspectable CreateBooleanArray(array_view<const bool> value);
        static IInspectable CreateStringArray(array_view<const hstring> value);
        static IInspectable CreateInspectableArray(array_view<const IInspectable> value);
        static IInspectable CreateGuidArray(array_view<const GUID> value);
        static IInspectable CreateDateTimeArray(array_view<const Windows::Foundation::DateTime> value);
        static IInspectable CreateTimeSpanArray(array_view<const Windows::Foundation::TimeSpan> value);
        static IInspectable CreatePointArray(array_view<const Windows::Foundation::Point> value);
        static IInspectable CreateSizeArray(array_view<const Windows::Foundation::Size> value);
        static IInspectable CreateRectArray(array_view<const Windows::Foundation::Rect> value);
    };
}

namespace impl
{
    template <typename D>
    struct produce<D, Windows::Foundation::IPropertyValue> : produce_base<D, Windows::Foundation::IPropertyValue>
    {
        HRESULT __stdcall get_Type(Windows::Foundation::PropertyType * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().Type());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall get_IsNumericScalar(bool * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().IsNumericScalar());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt8(uint8_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetUInt8());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt16(int16_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetInt16());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt16(uint16_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetUInt16());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt32(int32_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetInt32());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt32(uint32_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetUInt32());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt64(int64_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetInt64());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt64(uint64_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetUInt64());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetSingle(float * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetSingle());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetDouble(double * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetDouble());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetChar16(wchar_t * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetChar16());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetBoolean(bool * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetBoolean());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetString(abi_arg_out<hstring> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetString());
                return S_OK;
            }
            catch (...)
            {
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetGuid(GUID * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetGuid());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetDateTime(abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetDateTime());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetTimeSpan(abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetTimeSpan());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetPoint(abi_arg_out<Windows::Foundation::Point> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetPoint());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetSize(abi_arg_out<Windows::Foundation::Size> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetSize());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetRect(abi_arg_out<Windows::Foundation::Rect> value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *value = detach_abi(this->shim().GetRect());
                return S_OK;
            }
            catch (...)
            {
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt8Array(uint32_t * __valueSize, abi_arg_out<uint8_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetUInt8Array(detach_abi<uint8_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt16Array(uint32_t * __valueSize, abi_arg_out<int16_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetInt16Array(detach_abi<int16_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt16Array(uint32_t * __valueSize, abi_arg_out<uint16_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetUInt16Array(detach_abi<uint16_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt32Array(uint32_t * __valueSize, abi_arg_out<int32_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetInt32Array(detach_abi<int32_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt32Array(uint32_t * __valueSize, abi_arg_out<uint32_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetUInt32Array(detach_abi<uint32_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInt64Array(uint32_t * __valueSize, abi_arg_out<int64_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetInt64Array(detach_abi<int64_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetUInt64Array(uint32_t * __valueSize, abi_arg_out<uint64_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetUInt64Array(detach_abi<uint64_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetSingleArray(uint32_t * __valueSize, abi_arg_out<float> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetSingleArray(detach_abi<float>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetDoubleArray(uint32_t * __valueSize, abi_arg_out<double> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetDoubleArray(detach_abi<double>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetChar16Array(uint32_t * __valueSize, abi_arg_out<wchar_t> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetChar16Array(detach_abi<wchar_t>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetBooleanArray(uint32_t * __valueSize, abi_arg_out<bool> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetBooleanArray(detach_abi<bool>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetStringArray(uint32_t * __valueSize, abi_arg_out<hstring> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetStringArray(detach_abi<hstring>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetInspectableArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::IInspectable> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetInspectableArray(detach_abi<Windows::Foundation::IInspectable>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetGuidArray(uint32_t * __valueSize, abi_arg_out<GUID> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetGuidArray(detach_abi<GUID>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetDateTimeArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::DateTime> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetDateTimeArray(detach_abi<Windows::Foundation::DateTime>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetTimeSpanArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::TimeSpan> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetTimeSpanArray(detach_abi<Windows::Foundation::TimeSpan>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetPointArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::Point> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetPointArray(detach_abi<Windows::Foundation::Point>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetSizeArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::Size> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetSizeArray(detach_abi<Windows::Foundation::Size>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_GetRectArray(uint32_t * __valueSize, abi_arg_out<Windows::Foundation::Rect> * value) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetRectArray(detach_abi<Windows::Foundation::Rect>(__valueSize, value));
                return S_OK;
            }
            catch (...)
            {
                *__valueSize = 0;
                *value = nullptr;
                return impl::to_hresult();
            }
        }
    };

    template <typename D>
    struct produce<D, Windows::Foundation::IPropertyValueStatics> : produce_base<D, Windows::Foundation::IPropertyValueStatics>
    {
        HRESULT __stdcall abi_CreateEmpty(abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateEmpty());
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt8(uint8_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt8(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt16(int16_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt16(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt16(uint16_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt16(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt32(int32_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt32(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt32(uint32_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt32(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt64(int64_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt64(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt64(uint64_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt64(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateSingle(float value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateSingle(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateDouble(double value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateDouble(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateChar16(wchar_t value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateChar16(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateBoolean(bool value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateBoolean(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateString(abi_arg_in<hstring> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateString(*reinterpret_cast<const hstring *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInspectable(abi_arg_in<Windows::Foundation::IInspectable> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInspectable(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateGuid(GUID value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateGuid(value));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateDateTime(abi_arg_in<Windows::Foundation::DateTime> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateDateTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateTimeSpan(abi_arg_in<Windows::Foundation::TimeSpan> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateTimeSpan(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreatePoint(abi_arg_in<Windows::Foundation::Point> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreatePoint(*reinterpret_cast<const Windows::Foundation::Point *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateSize(abi_arg_in<Windows::Foundation::Size> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateSize(*reinterpret_cast<const Windows::Foundation::Size *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateRect(abi_arg_in<Windows::Foundation::Rect> value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateRect(*reinterpret_cast<const Windows::Foundation::Rect *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt8Array(uint32_t __valueSize, abi_arg_in<uint8_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt8Array(array_view<const uint8_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt16Array(uint32_t __valueSize, abi_arg_in<int16_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt16Array(array_view<const int16_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt16Array(uint32_t __valueSize, abi_arg_in<uint16_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt16Array(array_view<const uint16_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt32Array(uint32_t __valueSize, abi_arg_in<int32_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt32Array(array_view<const int32_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt32Array(uint32_t __valueSize, abi_arg_in<uint32_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt32Array(array_view<const uint32_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInt64Array(uint32_t __valueSize, abi_arg_in<int64_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInt64Array(array_view<const int64_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateUInt64Array(uint32_t __valueSize, abi_arg_in<uint64_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateUInt64Array(array_view<const uint64_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateSingleArray(uint32_t __valueSize, abi_arg_in<float> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateSingleArray(array_view<const float>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateDoubleArray(uint32_t __valueSize, abi_arg_in<double> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateDoubleArray(array_view<const double>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateChar16Array(uint32_t __valueSize, abi_arg_in<wchar_t> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateChar16Array(array_view<const wchar_t>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateBooleanArray(uint32_t __valueSize, abi_arg_in<bool> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateBooleanArray(array_view<const bool>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateStringArray(uint32_t __valueSize, abi_arg_in<hstring> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateStringArray(*reinterpret_cast<const hstring *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *value = nullptr;
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateInspectableArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::IInspectable> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateInspectableArray(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *value = nullptr;
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateGuidArray(uint32_t __valueSize, abi_arg_in<GUID> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateGuidArray(array_view<const GUID>(value, value + __valueSize)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateDateTimeArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::DateTime> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateDateTimeArray(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateTimeSpanArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::TimeSpan> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateTimeSpanArray(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreatePointArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::Point> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreatePointArray(*reinterpret_cast<const Windows::Foundation::Point *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateSizeArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::Size> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateSizeArray(*reinterpret_cast<const Windows::Foundation::Size *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }

        HRESULT __stdcall abi_CreateRectArray(uint32_t __valueSize, abi_arg_in<Windows::Foundation::Rect> * value, abi_arg_out<Windows::Foundation::IInspectable> propertyValue) noexcept override
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *propertyValue = detach_abi(this->shim().CreateRectArray(*reinterpret_cast<const Windows::Foundation::Rect *>(&value)));
                return S_OK;
            }
            catch (...)
            {
                *propertyValue = nullptr;
                return impl::to_hresult();
            }
        }
    };
}

namespace Windows::Foundation
{
    template <typename D> Windows::Foundation::PropertyType impl_IPropertyValue<D>::Type() const
    {
        Windows::Foundation::PropertyType value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->get_Type(&value));
        return value;
    }

    template <typename D> bool impl_IPropertyValue<D>::IsNumericScalar() const
    {
        bool value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->get_IsNumericScalar(&value));
        return value;
    }

    template <typename D> uint8_t impl_IPropertyValue<D>::GetUInt8() const
    {
        uint8_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt8(&value));
        return value;
    }

    template <typename D> int16_t impl_IPropertyValue<D>::GetInt16() const
    {
        int16_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt16(&value));
        return value;
    }

    template <typename D> uint16_t impl_IPropertyValue<D>::GetUInt16() const
    {
        uint16_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt16(&value));
        return value;
    }

    template <typename D> int32_t impl_IPropertyValue<D>::GetInt32() const
    {
        int32_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt32(&value));
        return value;
    }

    template <typename D> uint32_t impl_IPropertyValue<D>::GetUInt32() const
    {
        uint32_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt32(&value));
        return value;
    }

    template <typename D> int64_t impl_IPropertyValue<D>::GetInt64() const
    {
        int64_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt64(&value));
        return value;
    }

    template <typename D> uint64_t impl_IPropertyValue<D>::GetUInt64() const
    {
        uint64_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt64(&value));
        return value;
    }

    template <typename D> float impl_IPropertyValue<D>::GetSingle() const
    {
        float value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetSingle(&value));
        return value;
    }

    template <typename D> double impl_IPropertyValue<D>::GetDouble() const
    {
        double value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetDouble(&value));
        return value;
    }

    template <typename D> wchar_t impl_IPropertyValue<D>::GetChar16() const
    {
        wchar_t value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetChar16(&value));
        return value;
    }

    template <typename D> bool impl_IPropertyValue<D>::GetBoolean() const
    {
        bool value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetBoolean(&value));
        return value;
    }

    template <typename D> hstring impl_IPropertyValue<D>::GetString() const
    {
        hstring value;
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetString(put_abi(value)));
        return value;
    }

    template <typename D> GUID impl_IPropertyValue<D>::GetGuid() const
    {
        GUID value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetGuid(&value));
        return value;
    }

    template <typename D> Windows::Foundation::DateTime impl_IPropertyValue<D>::GetDateTime() const
    {
        Windows::Foundation::DateTime value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetDateTime(put_abi(value)));
        return value;
    }

    template <typename D> Windows::Foundation::TimeSpan impl_IPropertyValue<D>::GetTimeSpan() const
    {
        Windows::Foundation::TimeSpan value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetTimeSpan(put_abi(value)));
        return value;
    }

    template <typename D> Windows::Foundation::Point impl_IPropertyValue<D>::GetPoint() const
    {
        Windows::Foundation::Point value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetPoint(put_abi(value)));
        return value;
    }

    template <typename D> Windows::Foundation::Size impl_IPropertyValue<D>::GetSize() const
    {
        Windows::Foundation::Size value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetSize(put_abi(value)));
        return value;
    }

    template <typename D> Windows::Foundation::Rect impl_IPropertyValue<D>::GetRect() const
    {
        Windows::Foundation::Rect value{};
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetRect(put_abi(value)));
        return value;
    }

    template <typename D> void impl_IPropertyValue<D>::GetUInt8Array(com_array<uint8_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt8Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetInt16Array(com_array<int16_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt16Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetUInt16Array(com_array<uint16_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt16Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetInt32Array(com_array<int32_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt32Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetUInt32Array(com_array<uint32_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt32Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetInt64Array(com_array<int64_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt64Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetUInt64Array(com_array<uint64_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt64Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetSingleArray(com_array<float> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetSingleArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetDoubleArray(com_array<double> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetDoubleArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetChar16Array(com_array<wchar_t> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetChar16Array(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetBooleanArray(com_array<bool> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetBooleanArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetStringArray(com_array<hstring> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetStringArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetInspectableArray(com_array<Windows::Foundation::IInspectable> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInspectableArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetGuidArray(com_array<GUID> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetGuidArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetDateTimeArray(com_array<Windows::Foundation::DateTime> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetDateTimeArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetTimeSpanArray(com_array<Windows::Foundation::TimeSpan> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetTimeSpanArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetPointArray(com_array<Windows::Foundation::Point> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetPointArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetSizeArray(com_array<Windows::Foundation::Size> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetSizeArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> void impl_IPropertyValue<D>::GetRectArray(com_array<Windows::Foundation::Rect> & value) const
    {
        check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetRectArray(impl::put_size_abi(value), put_abi(value)));
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateEmpty() const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateEmpty(put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt8(uint8_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt8(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt16(int16_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt16(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt16(uint16_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt16(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt32(int32_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt32(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt32(uint32_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt32(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt64(int64_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt64(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt64(uint64_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt64(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateSingle(float value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSingle(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateDouble(double value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDouble(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateChar16(wchar_t value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateChar16(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateBoolean(bool value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateBoolean(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateString(hstring_view value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateString(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInspectable(const Windows::Foundation::IInspectable & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInspectable(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateGuid(GUID value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateGuid(value, put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateDateTime(const Windows::Foundation::DateTime & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDateTime(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateTimeSpan(const Windows::Foundation::TimeSpan & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateTimeSpan(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreatePoint(const Windows::Foundation::Point & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreatePoint(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateSize(const Windows::Foundation::Size & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSize(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateRect(const Windows::Foundation::Rect & value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateRect(get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt8Array(array_view<const uint8_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt8Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt16Array(array_view<const int16_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt16Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt16Array(array_view<const uint16_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt16Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt32Array(array_view<const int32_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt32Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt32Array(array_view<const uint32_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt32Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInt64Array(array_view<const int64_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt64Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateUInt64Array(array_view<const uint64_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt64Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateSingleArray(array_view<const float> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSingleArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateDoubleArray(array_view<const double> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDoubleArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateChar16Array(array_view<const wchar_t> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateChar16Array(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateBooleanArray(array_view<const bool> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateBooleanArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateStringArray(array_view<const hstring> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateStringArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateInspectableArray(array_view<const Windows::Foundation::IInspectable> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInspectableArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateGuidArray(array_view<const GUID> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateGuidArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateDateTimeArray(array_view<const Windows::Foundation::DateTime> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDateTimeArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateTimeSpanArray(array_view<const Windows::Foundation::TimeSpan> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateTimeSpanArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreatePointArray(array_view<const Windows::Foundation::Point> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreatePointArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateSizeArray(array_view<const Windows::Foundation::Size> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSizeArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    template <typename D> Windows::Foundation::IInspectable impl_IPropertyValueStatics<D>::CreateRectArray(array_view<const Windows::Foundation::Rect> value) const
    {
        Windows::Foundation::IInspectable propertyValue;
        check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateRectArray(value.size(), get_abi(value), put_abi(propertyValue)));
        return propertyValue;
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateEmpty()
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateEmpty();
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt8(uint8_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt8(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt16(int16_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt16(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt16(uint16_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt16(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt32(int32_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt32(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt32(uint32_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt32(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt64(int64_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt64(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt64(uint64_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt64(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateSingle(float value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSingle(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateDouble(double value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDouble(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateChar16(wchar_t value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateChar16(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateBoolean(bool value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateBoolean(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateString(hstring_view value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateString(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInspectable(const Windows::Foundation::IInspectable & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInspectable(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateGuid(GUID value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateGuid(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateDateTime(const Windows::Foundation::DateTime & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDateTime(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateTimeSpan(const Windows::Foundation::TimeSpan & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateTimeSpan(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreatePoint(const Windows::Foundation::Point & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreatePoint(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateSize(const Windows::Foundation::Size & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSize(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateRect(const Windows::Foundation::Rect & value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateRect(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt8Array(array_view<const uint8_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt8Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt16Array(array_view<const int16_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt16Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt16Array(array_view<const uint16_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt16Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt32Array(array_view<const int32_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt32Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt32Array(array_view<const uint32_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt32Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInt64Array(array_view<const int64_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt64Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateUInt64Array(array_view<const uint64_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt64Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateSingleArray(array_view<const float> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSingleArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateDoubleArray(array_view<const double> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDoubleArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateChar16Array(array_view<const wchar_t> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateChar16Array(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateBooleanArray(array_view<const bool> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateBooleanArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateStringArray(array_view<const hstring> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateStringArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateInspectableArray(array_view<const Windows::Foundation::IInspectable> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInspectableArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateGuidArray(array_view<const GUID> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateGuidArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateDateTimeArray(array_view<const Windows::Foundation::DateTime> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDateTimeArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateTimeSpanArray(array_view<const Windows::Foundation::TimeSpan> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateTimeSpanArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreatePointArray(array_view<const Windows::Foundation::Point> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreatePointArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateSizeArray(array_view<const Windows::Foundation::Size> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSizeArray(value);
    }

    inline Windows::Foundation::IInspectable PropertyValue::CreateRectArray(array_view<const Windows::Foundation::Rect> value)
    {
        return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateRectArray(value);
    }
}
