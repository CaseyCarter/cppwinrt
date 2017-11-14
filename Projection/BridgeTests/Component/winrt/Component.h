// C++/WinRT v1.0.170906.1
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#include "winrt/base.h"

WINRT_WARNING_PUSH

static_assert(winrt::check_version(CPPWINRT_VERSION, "1.0.170906.1"), "Mismatched component and base headers.");
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Foundation.Collections.h"
#include "winrt/impl/Component.2.h"

namespace winrt::impl {

template <typename D> void consume_Component_IParameters<D>::SetInt32(int32_t value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->SetInt32(value));
}

template <typename D> int32_t consume_Component_IParameters<D>::GetInt32() const
{
    int32_t value{};
    check_hresult(WINRT_SHIM(Component::IParameters)->GetInt32(&value));
    return value;
}

template <typename D> void consume_Component_IParameters<D>::OutInt32(int32_t& value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->OutInt32(&value));
}

template <typename D> void consume_Component_IParameters<D>::SetString(param::hstring const& value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->SetString(get_abi(value)));
}

template <typename D> hstring consume_Component_IParameters<D>::GetString() const
{
    hstring value{};
    check_hresult(WINRT_SHIM(Component::IParameters)->GetString(put_abi(value)));
    return value;
}

template <typename D> void consume_Component_IParameters<D>::OutString(hstring& value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->OutString(put_abi(value)));
}

template <typename D> void consume_Component_IParameters<D>::SetObject(Windows::Foundation::IInspectable const& value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->SetObject(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable consume_Component_IParameters<D>::GetObject() const
{
    Windows::Foundation::IInspectable value{ nullptr };
    check_hresult(WINRT_SHIM(Component::IParameters)->GetObject(put_abi(value)));
    return value;
}

template <typename D> void consume_Component_IParameters<D>::OutObject(Windows::Foundation::IInspectable& value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->OutObject(put_abi(value)));
}

template <typename D> void consume_Component_IParameters<D>::SetInt32Array(array_view<int32_t const> value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->SetInt32Array(value.size(), get_abi(value)));
}

template <typename D> com_array<int32_t> consume_Component_IParameters<D>::GetInt32Array() const
{
    com_array<int32_t> value;
    check_hresult(WINRT_SHIM(Component::IParameters)->GetInt32Array(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> void consume_Component_IParameters<D>::OutInt32Array(com_array<int32_t>& value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->OutInt32Array(impl::put_size_abi(value), put_abi(value)));
}

template <typename D> void consume_Component_IParameters<D>::CopyInt32Array(array_view<int32_t> value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->CopyInt32Array(value.size(), get_abi(value)));
}

template <typename D> void consume_Component_IParameters<D>::SetStringArray(array_view<hstring const> value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->SetStringArray(value.size(), get_abi(value)));
}

template <typename D> com_array<hstring> consume_Component_IParameters<D>::GetStringArray() const
{
    com_array<hstring> value;
    check_hresult(WINRT_SHIM(Component::IParameters)->GetStringArray(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> void consume_Component_IParameters<D>::OutStringArray(com_array<hstring>& value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->OutStringArray(impl::put_size_abi(value), put_abi(value)));
}

template <typename D> void consume_Component_IParameters<D>::CopyStringArray(array_view<hstring> value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->CopyStringArray(value.size(), get_abi(value)));
}

template <typename D> void consume_Component_IParameters<D>::SetObjectArray(array_view<Windows::Foundation::IInspectable const> value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->SetObjectArray(value.size(), get_abi(value)));
}

template <typename D> com_array<Windows::Foundation::IInspectable> consume_Component_IParameters<D>::GetObjectArray() const
{
    com_array<Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(Component::IParameters)->GetObjectArray(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> void consume_Component_IParameters<D>::OutObjectArray(com_array<Windows::Foundation::IInspectable>& value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->OutObjectArray(impl::put_size_abi(value), put_abi(value)));
}

template <typename D> void consume_Component_IParameters<D>::CopyObjectArray(array_view<Windows::Foundation::IInspectable> value) const
{
    check_hresult(WINRT_SHIM(Component::IParameters)->CopyObjectArray(value.size(), get_abi(value)));
}

template <typename D>
struct produce<D, Component::IParameters> : produce_base<D, Component::IParameters>
{
    HRESULT __stdcall SetInt32(int32_t value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInt32(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall GetInt32(int32_t* value) noexcept final
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

    HRESULT __stdcall OutInt32(int32_t* value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutInt32(*value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall SetString(HSTRING value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetString(*reinterpret_cast<hstring const*>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall GetString(HSTRING* value) noexcept final
    {
        try
        {
            *value = nullptr;
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetString());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall OutString(HSTRING* value) noexcept final
    {
        try
        {
            *value = nullptr;
            typename D::abi_guard guard(this->shim());
            this->shim().OutString(*reinterpret_cast<hstring*>(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall SetObject(void* value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetObject(*reinterpret_cast<Windows::Foundation::IInspectable const*>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall GetObject(void** value) noexcept final
    {
        try
        {
            *value = nullptr;
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetObject());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall OutObject(void** value) noexcept final
    {
        try
        {
            *value = nullptr;
            typename D::abi_guard guard(this->shim());
            this->shim().OutObject(*reinterpret_cast<Windows::Foundation::IInspectable*>(value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall SetInt32Array(uint32_t __valueSize, int32_t* value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInt32Array(array_view<int32_t const>(reinterpret_cast<int32_t const *>(value), reinterpret_cast<int32_t const *>(value) + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall GetInt32Array(uint32_t* __valueSize, int32_t** value) noexcept final
    {
        try
        {
            *__valueSize = 0;
            *value = nullptr;
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().GetInt32Array());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall OutInt32Array(uint32_t* __valueSize, int32_t** value) noexcept final
    {
        try
        {
            *__valueSize = 0;
            *value = nullptr;
            typename D::abi_guard guard(this->shim());
            this->shim().OutInt32Array(detach_abi<int32_t>(__valueSize, value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall CopyInt32Array(uint32_t __valueSize, int32_t* value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyInt32Array(array_view<int32_t>(reinterpret_cast<int32_t*>(value), reinterpret_cast<int32_t*>(value) + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall SetStringArray(uint32_t __valueSize, HSTRING* value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetStringArray(array_view<hstring const>(reinterpret_cast<hstring const *>(value), reinterpret_cast<hstring const *>(value) + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall GetStringArray(uint32_t* __valueSize, HSTRING** value) noexcept final
    {
        try
        {
            *__valueSize = 0;
            *value = nullptr;
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().GetStringArray());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall OutStringArray(uint32_t* __valueSize, HSTRING** value) noexcept final
    {
        try
        {
            *__valueSize = 0;
            *value = nullptr;
            typename D::abi_guard guard(this->shim());
            this->shim().OutStringArray(detach_abi<hstring>(__valueSize, value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall CopyStringArray(uint32_t __valueSize, HSTRING* value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyStringArray(array_view<hstring>(reinterpret_cast<hstring*>(value), reinterpret_cast<hstring*>(value) + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall SetObjectArray(uint32_t __valueSize, void** value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetObjectArray(array_view<Windows::Foundation::IInspectable const>(reinterpret_cast<Windows::Foundation::IInspectable const *>(value), reinterpret_cast<Windows::Foundation::IInspectable const *>(value) + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall GetObjectArray(uint32_t* __valueSize, void*** value) noexcept final
    {
        try
        {
            *__valueSize = 0;
            *value = nullptr;
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().GetObjectArray());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall OutObjectArray(uint32_t* __valueSize, void*** value) noexcept final
    {
        try
        {
            *__valueSize = 0;
            *value = nullptr;
            typename D::abi_guard guard(this->shim());
            this->shim().OutObjectArray(detach_abi<Windows::Foundation::IInspectable>(__valueSize, value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall CopyObjectArray(uint32_t __valueSize, void** value) noexcept final
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyObjectArray(array_view<Windows::Foundation::IInspectable>(reinterpret_cast<Windows::Foundation::IInspectable*>(value), reinterpret_cast<Windows::Foundation::IInspectable*>(value) + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

WINRT_EXPORT namespace winrt::Component {

inline Parameters::Parameters() :
    Parameters(activate_instance<Parameters>())
{}

}

WINRT_EXPORT namespace std {

template<> struct hash<winrt::Component::IParameters> : 
    winrt::impl::impl_hash_unknown<winrt::Component::IParameters> {};

template<> struct hash<winrt::Component::Parameters> : 
    winrt::impl::impl_hash_unknown<winrt::Component::Parameters> {};

}

WINRT_WARNING_POP
