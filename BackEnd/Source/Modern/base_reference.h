
namespace Windows::Foundation {

template <typename T> struct IReference;

}

namespace ABI::Windows::Foundation {

template <typename T> struct IReference : impl::not_specialized<IReference<T>> {};

template <typename T>
struct __declspec(novtable) impl_IReference : IInspectable
{
    virtual HRESULT __stdcall get_Value(arg_out<T> value) = 0;
};

}

namespace Windows::Foundation {

template <typename D, typename T> struct WINRT_EBO impl_IReference
{
    T Value() const
    {
        T result{};
        check_hresult((*(abi<IReference<T>> **)&static_cast<const IReference<T> &>(static_cast<const D &>(*this)))->get_Value(put_abi(result)));
        return result;
    }
};

}

namespace impl {

template <typename T> struct traits<Windows::Foundation::IReference<T>>
{
    using abi = ABI::Windows::Foundation::IReference<abi<T>>;
    template <typename D> using consume = Windows::Foundation::impl_IReference<D, T>;
};

template <typename D, typename T>
struct produce<D, Windows::Foundation::IReference<T>> : produce_base<D, Windows::Foundation::IReference<T>>
{
    HRESULT __stdcall get_Value(abi_arg_out<T> value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            clear_abi(value);
            return to_hresult();
        }
    }
};

template <typename T>
struct reference : implements<reference<T>, Windows::Foundation::IReference<T>, Windows::Foundation::IPropertyValue>
{
    reference(T const & value)
    {
        m_value = value;
    }

    T Value() const
    {
        return m_value;
    }

    Windows::Foundation::PropertyType Type() { throw hresult_not_implemented(); }
    bool IsNumericScalar() { throw hresult_not_implemented(); }
    uint8_t GetUInt8() { throw hresult_not_implemented(); }
    int16_t GetInt16() { throw hresult_not_implemented(); }
    uint16_t GetUInt16() { throw hresult_not_implemented(); }
    int32_t GetInt32() { throw hresult_not_implemented(); }
    uint32_t GetUInt32() { throw hresult_not_implemented(); }
    int64_t GetInt64() { throw hresult_not_implemented(); }
    uint64_t GetUInt64() { throw hresult_not_implemented(); }
    float GetSingle() { throw hresult_not_implemented(); }
    double GetDouble() { throw hresult_not_implemented(); }
    wchar_t GetChar16() { throw hresult_not_implemented(); }
    bool GetBoolean() { throw hresult_not_implemented(); }
    hstring GetString() { throw hresult_not_implemented(); }
    GUID GetGuid() { throw hresult_not_implemented(); }
    Windows::Foundation::DateTime GetDateTime() { throw hresult_not_implemented(); }
    Windows::Foundation::TimeSpan GetTimeSpan() { throw hresult_not_implemented(); }
    Windows::Foundation::Point GetPoint() { throw hresult_not_implemented(); }
    Windows::Foundation::Size GetSize() { throw hresult_not_implemented(); }
    Windows::Foundation::Rect GetRect() { throw hresult_not_implemented(); }
    void GetUInt8Array(com_array<uint8_t> &) { throw hresult_not_implemented(); }
    void GetInt16Array(com_array<int16_t> &) { throw hresult_not_implemented(); }
    void GetUInt16Array(com_array<uint16_t> &) { throw hresult_not_implemented(); }
    void GetInt32Array(com_array<int32_t> &) { throw hresult_not_implemented(); }
    void GetUInt32Array(com_array<uint32_t> &) { throw hresult_not_implemented(); }
    void GetInt64Array(com_array<int64_t> &) { throw hresult_not_implemented(); }
    void GetUInt64Array(com_array<uint64_t> &) { throw hresult_not_implemented(); }
    void GetSingleArray(com_array<float> &) { throw hresult_not_implemented(); }
    void GetDoubleArray(com_array<double> &) { throw hresult_not_implemented(); }
    void GetChar16Array(com_array<wchar_t> &) { throw hresult_not_implemented(); }
    void GetBooleanArray(com_array<bool> &) { throw hresult_not_implemented(); }
    void GetStringArray(com_array<hstring> &) { throw hresult_not_implemented(); }
    void GetInspectableArray(com_array<Windows::Foundation::IInspectable> &) { throw hresult_not_implemented(); }
    void GetGuidArray(com_array<GUID> &) { throw hresult_not_implemented(); }
    void GetDateTimeArray(com_array<Windows::Foundation::DateTime> &) { throw hresult_not_implemented(); }
    void GetTimeSpanArray(com_array<Windows::Foundation::TimeSpan> &) { throw hresult_not_implemented(); }
    void GetPointArray(com_array<Windows::Foundation::Point> &) { throw hresult_not_implemented(); }
    void GetSizeArray(com_array<Windows::Foundation::Size> &) { throw hresult_not_implemented(); }
    void GetRectArray(com_array<Windows::Foundation::Rect> &) { throw hresult_not_implemented(); }

private:
    T m_value;
};


template <typename T>
struct reference_traits
{
    static Windows::Foundation::IInspectable make(T const & val) { return winrt::make<impl::reference<T>>(val); }
};

template <>
struct reference_traits <uint8_t>
{
    static Windows::Foundation::IInspectable make(uint8_t val) { return Windows::Foundation::PropertyValue::CreateUInt8(val); }
};

template <>
struct reference_traits <uint16_t>
{
    static Windows::Foundation::IInspectable make(uint16_t val) { return Windows::Foundation::PropertyValue::CreateUInt16(val); }
};

template <>
struct reference_traits <int16_t>
{
    static Windows::Foundation::IInspectable make(int16_t val) { return Windows::Foundation::PropertyValue::CreateInt16(val); }
};

template <>
struct reference_traits <uint32_t>
{
    static Windows::Foundation::IInspectable make(uint32_t val) { return Windows::Foundation::PropertyValue::CreateUInt32(val); }
};

template <>
struct reference_traits <int32_t>
{
    static Windows::Foundation::IInspectable make(int32_t val) { return Windows::Foundation::PropertyValue::CreateInt32(val); }
};

template <>
struct reference_traits <uint64_t>
{
    static Windows::Foundation::IInspectable make(uint64_t val) { return Windows::Foundation::PropertyValue::CreateUInt64(val); }
};

template <>
struct reference_traits <int64_t>
{
    static Windows::Foundation::IInspectable make(int64_t val) { return Windows::Foundation::PropertyValue::CreateInt64(val); }
};

template <>
struct reference_traits <float>
{
    static Windows::Foundation::IInspectable make(float val) { return Windows::Foundation::PropertyValue::CreateSingle(val); }
};

template <>
struct reference_traits <double>
{
    static Windows::Foundation::IInspectable make(double val) { return Windows::Foundation::PropertyValue::CreateDouble(val); }
};

template <>
struct reference_traits <wchar_t>
{
    static Windows::Foundation::IInspectable make(wchar_t val) { return Windows::Foundation::PropertyValue::CreateChar16(val); }
};

template <>
struct reference_traits <bool>
{
    static Windows::Foundation::IInspectable make(bool val) { return Windows::Foundation::PropertyValue::CreateBoolean(val); }
};

template <>
struct reference_traits <hstring>
{
    static Windows::Foundation::IInspectable make(hstring const & val) { return Windows::Foundation::PropertyValue::CreateString(val); }
};

template <>
struct reference_traits <hstring_view>
{
    static Windows::Foundation::IInspectable make(hstring_view val) { return Windows::Foundation::PropertyValue::CreateString(val); }
};

template <>
struct reference_traits <Windows::Foundation::IInspectable>
{
    static Windows::Foundation::IInspectable make(Windows::Foundation::IInspectable const & val) { return Windows::Foundation::PropertyValue::CreateInspectable(val); }
};

template <>
struct reference_traits <GUID>
{
    static Windows::Foundation::IInspectable make(GUID const & val) { return Windows::Foundation::PropertyValue::CreateGuid(val); }
};

template <>
struct reference_traits <Windows::Foundation::DateTime>
{
    static Windows::Foundation::IInspectable make(Windows::Foundation::DateTime val) { return Windows::Foundation::PropertyValue::CreateDateTime(val); }
};

template <>
struct reference_traits <Windows::Foundation::TimeSpan>
{
    static Windows::Foundation::IInspectable make(Windows::Foundation::TimeSpan val) { return Windows::Foundation::PropertyValue::CreateTimeSpan(val); }
};

template <>
struct reference_traits  <Windows::Foundation::Point>
{
    static Windows::Foundation::IInspectable make(Windows::Foundation::Point const & val) { return Windows::Foundation::PropertyValue::CreatePoint(val); }
};

template <>
struct reference_traits <Windows::Foundation::Size>
{
    static Windows::Foundation::IInspectable make(Windows::Foundation::Size const & val) { return Windows::Foundation::PropertyValue::CreateSize(val); }
};

template <>
struct reference_traits <Windows::Foundation::Rect>
{
    static Windows::Foundation::IInspectable make(Windows::Foundation::Rect const & val) { return Windows::Foundation::PropertyValue::CreateRect(val); }
};

}

namespace Windows::Foundation {

template <typename T>
struct WINRT_EBO IReference :
    IInspectable,
    impl::consume<IReference<T>>
{
    IReference<T>(std::nullptr_t = nullptr) noexcept {}

    IReference<T>(T const & val)
    {
        this->m_ptr = detach_abi((impl::reference_traits<T>::make(val)).template as<abi<IReference<T>>>());
    }
};

}

template <typename T>
using optional = Windows::Foundation::IReference<T>;
