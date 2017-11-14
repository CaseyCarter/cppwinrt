// C++/WinRT v1.0.170906.1
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

WINRT_EXPORT namespace winrt::Component {

struct IParameters;
struct Parameters;

}

namespace winrt::impl {

template <> struct category<Component::IParameters>{ using type = interface_category; };
template <> struct category<Component::Parameters>{ using type = class_category; };
template <> struct name<Component::IParameters>{ static constexpr auto & value{ L"Component.IParameters" }; };
template <> struct name<Component::Parameters>{ static constexpr auto & value{ L"Component.Parameters" }; };
template <> struct guid<Component::IParameters>{ static constexpr GUID value{ 0x461C8806,0x8BC2,0x4622,{ 0x8E,0xAC,0xB5,0x47,0xC3,0x9F,0x86,0x7E } }; };
template <> struct default_interface<Component::Parameters>{ using type = Component::IParameters; };

template <typename D>
struct consume_Component_IParameters
{
    void SetInt32(int32_t value) const;
    int32_t GetInt32() const;
    void OutInt32(int32_t& value) const;
    void SetString(param::hstring const& value) const;
    hstring GetString() const;
    void OutString(hstring& value) const;
    void SetObject(Windows::Foundation::IInspectable const& value) const;
    Windows::Foundation::IInspectable GetObject() const;
    void OutObject(Windows::Foundation::IInspectable& value) const;
    void SetInt32Array(array_view<int32_t const> value) const;
    com_array<int32_t> GetInt32Array() const;
    void OutInt32Array(com_array<int32_t>& value) const;
    void CopyInt32Array(array_view<int32_t> value) const;
    void SetStringArray(array_view<hstring const> value) const;
    com_array<hstring> GetStringArray() const;
    void OutStringArray(com_array<hstring>& value) const;
    void CopyStringArray(array_view<hstring> value) const;
    void SetObjectArray(array_view<Windows::Foundation::IInspectable const> value) const;
    com_array<Windows::Foundation::IInspectable> GetObjectArray() const;
    void OutObjectArray(com_array<Windows::Foundation::IInspectable>& value) const;
    void CopyObjectArray(array_view<Windows::Foundation::IInspectable> value) const;
};
template <> struct consume<Component::IParameters> { template <typename D> using type = consume_Component_IParameters<D>; };

template <> struct abi<Component::IParameters>{ struct type : IInspectable
{
    virtual HRESULT __stdcall SetInt32(int32_t value) noexcept = 0;
    virtual HRESULT __stdcall GetInt32(int32_t* value) noexcept = 0;
    virtual HRESULT __stdcall OutInt32(int32_t* value) noexcept = 0;
    virtual HRESULT __stdcall SetString(HSTRING value) noexcept = 0;
    virtual HRESULT __stdcall GetString(HSTRING* value) noexcept = 0;
    virtual HRESULT __stdcall OutString(HSTRING* value) noexcept = 0;
    virtual HRESULT __stdcall SetObject(void* value) noexcept = 0;
    virtual HRESULT __stdcall GetObject(void** value) noexcept = 0;
    virtual HRESULT __stdcall OutObject(void** value) noexcept = 0;
    virtual HRESULT __stdcall SetInt32Array(uint32_t __valueSize, int32_t* value) noexcept = 0;
    virtual HRESULT __stdcall GetInt32Array(uint32_t* __valueSize, int32_t** value) noexcept = 0;
    virtual HRESULT __stdcall OutInt32Array(uint32_t* __valueSize, int32_t** value) noexcept = 0;
    virtual HRESULT __stdcall CopyInt32Array(uint32_t __valueSize, int32_t* value) noexcept = 0;
    virtual HRESULT __stdcall SetStringArray(uint32_t __valueSize, HSTRING* value) noexcept = 0;
    virtual HRESULT __stdcall GetStringArray(uint32_t* __valueSize, HSTRING** value) noexcept = 0;
    virtual HRESULT __stdcall OutStringArray(uint32_t* __valueSize, HSTRING** value) noexcept = 0;
    virtual HRESULT __stdcall CopyStringArray(uint32_t __valueSize, HSTRING* value) noexcept = 0;
    virtual HRESULT __stdcall SetObjectArray(uint32_t __valueSize, void** value) noexcept = 0;
    virtual HRESULT __stdcall GetObjectArray(uint32_t* __valueSize, void*** value) noexcept = 0;
    virtual HRESULT __stdcall OutObjectArray(uint32_t* __valueSize, void*** value) noexcept = 0;
    virtual HRESULT __stdcall CopyObjectArray(uint32_t __valueSize, void** value) noexcept = 0;
};};

}
