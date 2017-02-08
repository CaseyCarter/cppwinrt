// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "internal/Windows.Foundation.3.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Foundation {

template <typename L> DeferralCompletedHandler::DeferralCompletedHandler(L lambda) :
    DeferralCompletedHandler(impl::make_delegate<impl_DeferralCompletedHandler<L>, DeferralCompletedHandler>(std::forward<L>(lambda)))
{}

template <typename F> DeferralCompletedHandler::DeferralCompletedHandler(F * function) :
    DeferralCompletedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DeferralCompletedHandler::DeferralCompletedHandler(O * object, M method) :
    DeferralCompletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DeferralCompletedHandler::operator()() const
{
    check_hresult((*(abi<DeferralCompletedHandler> **)this)->abi_Invoke());
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Foundation::IClosable> : produce_base<D, Windows::Foundation::IClosable>
{
    HRESULT __stdcall abi_Close() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IDeferral> : produce_base<D, Windows::Foundation::IDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IDeferralFactory> : produce_base<D, Windows::Foundation::IDeferralFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::DeferralCompletedHandler> handler, impl::abi_arg_out<Windows::Foundation::IDeferral> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::DeferralCompletedHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IGetActivationFactory> : produce_base<D, Windows::Foundation::IGetActivationFactory>
{
    HRESULT __stdcall abi_GetActivationFactory(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_out<Windows::IInspectable> factory) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *factory = detach_abi(this->shim().GetActivationFactory(*reinterpret_cast<const hstring *>(&activatableClassId)));
            return S_OK;
        }
        catch (...)
        {
            *factory = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IMemoryBuffer> : produce_base<D, Windows::Foundation::IMemoryBuffer>
{
    HRESULT __stdcall abi_CreateReference(impl::abi_arg_out<Windows::Foundation::IMemoryBufferReference> reference) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *reference = detach_abi(this->shim().CreateReference());
            return S_OK;
        }
        catch (...)
        {
            *reference = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IMemoryBufferFactory> : produce_base<D, Windows::Foundation::IMemoryBufferFactory>
{
    HRESULT __stdcall abi_Create(uint32_t capacity, impl::abi_arg_out<Windows::Foundation::IMemoryBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(capacity));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IMemoryBufferReference> : produce_base<D, Windows::Foundation::IMemoryBufferReference>
{
    HRESULT __stdcall get_Capacity(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Capacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Closed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Closed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Closed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

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

    HRESULT __stdcall abi_GetString(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall abi_GetDateTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
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

    HRESULT __stdcall abi_GetTimeSpan(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
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

    HRESULT __stdcall abi_GetPoint(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
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

    HRESULT __stdcall abi_GetSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
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

    HRESULT __stdcall abi_GetRect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
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

    HRESULT __stdcall abi_GetUInt8Array(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
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

    HRESULT __stdcall abi_GetInt16Array(uint32_t * __valueSize, impl::abi_arg_out<int16_t> * value) noexcept override
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

    HRESULT __stdcall abi_GetUInt16Array(uint32_t * __valueSize, impl::abi_arg_out<uint16_t> * value) noexcept override
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

    HRESULT __stdcall abi_GetInt32Array(uint32_t * __valueSize, impl::abi_arg_out<int32_t> * value) noexcept override
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

    HRESULT __stdcall abi_GetUInt32Array(uint32_t * __valueSize, impl::abi_arg_out<uint32_t> * value) noexcept override
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

    HRESULT __stdcall abi_GetInt64Array(uint32_t * __valueSize, impl::abi_arg_out<int64_t> * value) noexcept override
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

    HRESULT __stdcall abi_GetUInt64Array(uint32_t * __valueSize, impl::abi_arg_out<uint64_t> * value) noexcept override
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

    HRESULT __stdcall abi_GetSingleArray(uint32_t * __valueSize, impl::abi_arg_out<float> * value) noexcept override
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

    HRESULT __stdcall abi_GetDoubleArray(uint32_t * __valueSize, impl::abi_arg_out<double> * value) noexcept override
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

    HRESULT __stdcall abi_GetChar16Array(uint32_t * __valueSize, impl::abi_arg_out<wchar_t> * value) noexcept override
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

    HRESULT __stdcall abi_GetBooleanArray(uint32_t * __valueSize, impl::abi_arg_out<bool> * value) noexcept override
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

    HRESULT __stdcall abi_GetStringArray(uint32_t * __valueSize, impl::abi_arg_out<hstring> * value) noexcept override
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

    HRESULT __stdcall abi_GetInspectableArray(uint32_t * __valueSize, impl::abi_arg_out<Windows::IInspectable> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetInspectableArray(detach_abi<Windows::IInspectable>(__valueSize, value));
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGuidArray(uint32_t * __valueSize, impl::abi_arg_out<GUID> * value) noexcept override
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

    HRESULT __stdcall abi_GetDateTimeArray(uint32_t * __valueSize, impl::abi_arg_out<Windows::Foundation::DateTime> * value) noexcept override
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

    HRESULT __stdcall abi_GetTimeSpanArray(uint32_t * __valueSize, impl::abi_arg_out<Windows::Foundation::TimeSpan> * value) noexcept override
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

    HRESULT __stdcall abi_GetPointArray(uint32_t * __valueSize, impl::abi_arg_out<Windows::Foundation::Point> * value) noexcept override
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

    HRESULT __stdcall abi_GetSizeArray(uint32_t * __valueSize, impl::abi_arg_out<Windows::Foundation::Size> * value) noexcept override
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

    HRESULT __stdcall abi_GetRectArray(uint32_t * __valueSize, impl::abi_arg_out<Windows::Foundation::Rect> * value) noexcept override
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
    HRESULT __stdcall abi_CreateEmpty(impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateUInt8(uint8_t value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateInt16(int16_t value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateUInt16(uint16_t value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateInt32(int32_t value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateUInt32(uint32_t value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateInt64(int64_t value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateUInt64(uint64_t value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateSingle(float value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateDouble(double value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateChar16(wchar_t value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateBoolean(bool value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateString(impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateInspectable(impl::abi_arg_in<Windows::IInspectable> value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_abi(this->shim().CreateInspectable(*reinterpret_cast<const Windows::IInspectable *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *propertyValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateGuid(GUID value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateDateTime(impl::abi_arg_in<Windows::Foundation::DateTime> value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateTimeSpan(impl::abi_arg_in<Windows::Foundation::TimeSpan> value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreatePoint(impl::abi_arg_in<Windows::Foundation::Point> value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateSize(impl::abi_arg_in<Windows::Foundation::Size> value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateRect(impl::abi_arg_in<Windows::Foundation::Rect> value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateUInt8Array(uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateInt16Array(uint32_t __valueSize, impl::abi_arg_in<int16_t> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateUInt16Array(uint32_t __valueSize, impl::abi_arg_in<uint16_t> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateInt32Array(uint32_t __valueSize, impl::abi_arg_in<int32_t> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateUInt32Array(uint32_t __valueSize, impl::abi_arg_in<uint32_t> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateInt64Array(uint32_t __valueSize, impl::abi_arg_in<int64_t> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateUInt64Array(uint32_t __valueSize, impl::abi_arg_in<uint64_t> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateSingleArray(uint32_t __valueSize, impl::abi_arg_in<float> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateDoubleArray(uint32_t __valueSize, impl::abi_arg_in<double> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateChar16Array(uint32_t __valueSize, impl::abi_arg_in<wchar_t> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateBooleanArray(uint32_t __valueSize, impl::abi_arg_in<bool> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateStringArray(uint32_t __valueSize, impl::abi_arg_in<hstring> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateInspectableArray(uint32_t __valueSize, impl::abi_arg_in<Windows::IInspectable> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *propertyValue = detach_abi(this->shim().CreateInspectableArray(*reinterpret_cast<const Windows::IInspectable *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            *propertyValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateGuidArray(uint32_t __valueSize, impl::abi_arg_in<GUID> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateDateTimeArray(uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::DateTime> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateTimeSpanArray(uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::TimeSpan> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreatePointArray(uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Point> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateSizeArray(uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Size> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

    HRESULT __stdcall abi_CreateRectArray(uint32_t __valueSize, impl::abi_arg_in<Windows::Foundation::Rect> * value, impl::abi_arg_out<Windows::IInspectable> propertyValue) noexcept override
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

template <typename D>
struct produce<D, Windows::Foundation::IStringable> : produce_base<D, Windows::Foundation::IStringable>
{
    HRESULT __stdcall abi_ToString(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToString());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IUriEscapeStatics> : produce_base<D, Windows::Foundation::IUriEscapeStatics>
{
    HRESULT __stdcall abi_UnescapeComponent(impl::abi_arg_in<hstring> toUnescape, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnescapeComponent(*reinterpret_cast<const hstring *>(&toUnescape)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EscapeComponent(impl::abi_arg_in<hstring> toEscape, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EscapeComponent(*reinterpret_cast<const hstring *>(&toEscape)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IUriRuntimeClass> : produce_base<D, Windows::Foundation::IUriRuntimeClass>
{
    HRESULT __stdcall get_AbsoluteUri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AbsoluteUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayUri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Domain(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Domain());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Extension(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Extension());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Fragment(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Fragment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Host(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Host());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Password(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Password());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Path(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Path());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Query(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Query());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QueryParsed(impl::abi_arg_out<Windows::Foundation::IWwwFormUrlDecoderRuntimeClass> ppWwwFormUrlDecoder) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppWwwFormUrlDecoder = detach_abi(this->shim().QueryParsed());
            return S_OK;
        }
        catch (...)
        {
            *ppWwwFormUrlDecoder = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawUri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SchemeName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SchemeName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Port(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Port());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Suspicious(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Suspicious());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Equals(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> pUri, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Equals(*reinterpret_cast<const Windows::Foundation::Uri *>(&pUri)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CombineUri(impl::abi_arg_in<hstring> relativeUri, impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CombineUri(*reinterpret_cast<const hstring *>(&relativeUri)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IUriRuntimeClassFactory> : produce_base<D, Windows::Foundation::IUriRuntimeClassFactory>
{
    HRESULT __stdcall abi_CreateUri(impl::abi_arg_in<hstring> uri, impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateUri(*reinterpret_cast<const hstring *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithRelativeUri(impl::abi_arg_in<hstring> baseUri, impl::abi_arg_in<hstring> relativeUri, impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWithRelativeUri(*reinterpret_cast<const hstring *>(&baseUri), *reinterpret_cast<const hstring *>(&relativeUri)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri> : produce_base<D, Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>
{
    HRESULT __stdcall get_AbsoluteCanonicalUri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AbsoluteCanonicalUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayIri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayIri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IWwwFormUrlDecoderEntry> : produce_base<D, Windows::Foundation::IWwwFormUrlDecoderEntry>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IWwwFormUrlDecoderRuntimeClass> : produce_base<D, Windows::Foundation::IWwwFormUrlDecoderRuntimeClass>
{
    HRESULT __stdcall abi_GetFirstValueByName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<hstring> phstrValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *phstrValue = detach_abi(this->shim().GetFirstValueByName(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *phstrValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IWwwFormUrlDecoderRuntimeClassFactory> : produce_base<D, Windows::Foundation::IWwwFormUrlDecoderRuntimeClassFactory>
{
    HRESULT __stdcall abi_CreateWwwFormUrlDecoder(impl::abi_arg_in<hstring> query, impl::abi_arg_out<Windows::Foundation::IWwwFormUrlDecoderRuntimeClass> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWwwFormUrlDecoder(*reinterpret_cast<const hstring *>(&query)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Foundation {

template <typename D> void impl_IClosable<D>::Close() const
{
    check_hresult(WINRT_SHIM(IClosable)->abi_Close());
}

template <typename D> Windows::Foundation::PropertyType impl_IPropertyValue<D>::Type() const
{
    Windows::Foundation::PropertyType value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->get_Type(&value));
    return value;
}

template <typename D> bool impl_IPropertyValue<D>::IsNumericScalar() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->get_IsNumericScalar(&value));
    return value;
}

template <typename D> uint8_t impl_IPropertyValue<D>::GetUInt8() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt8(&value));
    return value;
}

template <typename D> int16_t impl_IPropertyValue<D>::GetInt16() const
{
    int16_t value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt16(&value));
    return value;
}

template <typename D> uint16_t impl_IPropertyValue<D>::GetUInt16() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt16(&value));
    return value;
}

template <typename D> int32_t impl_IPropertyValue<D>::GetInt32() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt32(&value));
    return value;
}

template <typename D> uint32_t impl_IPropertyValue<D>::GetUInt32() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt32(&value));
    return value;
}

template <typename D> int64_t impl_IPropertyValue<D>::GetInt64() const
{
    int64_t value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetInt64(&value));
    return value;
}

template <typename D> uint64_t impl_IPropertyValue<D>::GetUInt64() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetUInt64(&value));
    return value;
}

template <typename D> float impl_IPropertyValue<D>::GetSingle() const
{
    float value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetSingle(&value));
    return value;
}

template <typename D> double impl_IPropertyValue<D>::GetDouble() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetDouble(&value));
    return value;
}

template <typename D> wchar_t impl_IPropertyValue<D>::GetChar16() const
{
    wchar_t value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetChar16(&value));
    return value;
}

template <typename D> bool impl_IPropertyValue<D>::GetBoolean() const
{
    bool value {};
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
    GUID value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetGuid(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IPropertyValue<D>::GetDateTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetDateTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IPropertyValue<D>::GetTimeSpan() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetTimeSpan(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IPropertyValue<D>::GetPoint() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetPoint(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Size impl_IPropertyValue<D>::GetSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IPropertyValue)->abi_GetSize(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IPropertyValue<D>::GetRect() const
{
    Windows::Foundation::Rect value {};
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

template <typename D> void impl_IPropertyValue<D>::GetInspectableArray(com_array<Windows::IInspectable> & value) const
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

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateEmpty() const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateEmpty(put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateUInt8(uint8_t value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt8(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateInt16(int16_t value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt16(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateUInt16(uint16_t value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt16(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateInt32(int32_t value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt32(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateUInt32(uint32_t value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt32(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateInt64(int64_t value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt64(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateUInt64(uint64_t value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt64(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateSingle(float value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSingle(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateDouble(double value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDouble(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateChar16(wchar_t value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateChar16(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateBoolean(bool value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateBoolean(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateString(hstring_view value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateString(get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateInspectable(const Windows::IInspectable & value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInspectable(get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateGuid(GUID value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateGuid(value, put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateDateTime(const Windows::Foundation::DateTime & value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDateTime(get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateTimeSpan(const Windows::Foundation::TimeSpan & value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateTimeSpan(get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreatePoint(const Windows::Foundation::Point & value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreatePoint(get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateSize(const Windows::Foundation::Size & value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSize(get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateRect(const Windows::Foundation::Rect & value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateRect(get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateUInt8Array(array_view<const uint8_t> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt8Array(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateInt16Array(array_view<const int16_t> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt16Array(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateUInt16Array(array_view<const uint16_t> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt16Array(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateInt32Array(array_view<const int32_t> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt32Array(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateUInt32Array(array_view<const uint32_t> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt32Array(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateInt64Array(array_view<const int64_t> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInt64Array(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateUInt64Array(array_view<const uint64_t> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateUInt64Array(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateSingleArray(array_view<const float> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSingleArray(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateDoubleArray(array_view<const double> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDoubleArray(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateChar16Array(array_view<const wchar_t> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateChar16Array(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateBooleanArray(array_view<const bool> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateBooleanArray(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateStringArray(array_view<const hstring> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateStringArray(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateInspectableArray(array_view<const Windows::IInspectable> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateInspectableArray(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateGuidArray(array_view<const GUID> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateGuidArray(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateDateTimeArray(array_view<const Windows::Foundation::DateTime> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateDateTimeArray(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateTimeSpanArray(array_view<const Windows::Foundation::TimeSpan> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateTimeSpanArray(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreatePointArray(array_view<const Windows::Foundation::Point> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreatePointArray(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateSizeArray(array_view<const Windows::Foundation::Size> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateSizeArray(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> Windows::IInspectable impl_IPropertyValueStatics<D>::CreateRectArray(array_view<const Windows::Foundation::Rect> value) const
{
    Windows::IInspectable propertyValue;
    check_hresult(WINRT_SHIM(IPropertyValueStatics)->abi_CreateRectArray(value.size(), get_abi(value), put_abi(propertyValue)));
    return propertyValue;
}

template <typename D> hstring impl_IStringable<D>::ToString() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStringable)->abi_ToString(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IDeferral)->abi_Complete());
}

template <typename D> Windows::Foundation::Deferral impl_IDeferralFactory<D>::Create(const Windows::Foundation::DeferralCompletedHandler & handler) const
{
    Windows::Foundation::Deferral result { nullptr };
    check_hresult(WINRT_SHIM(IDeferralFactory)->abi_Create(get_abi(handler), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::AbsoluteUri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_AbsoluteUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::DisplayUri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_DisplayUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Domain() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Domain(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Extension() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Extension(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Fragment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Fragment(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Host() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Host(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Password() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Password(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Path() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Path(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Query() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Query(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::WwwFormUrlDecoder impl_IUriRuntimeClass<D>::QueryParsed() const
{
    Windows::Foundation::WwwFormUrlDecoder ppWwwFormUrlDecoder { nullptr };
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_QueryParsed(put_abi(ppWwwFormUrlDecoder)));
    return ppWwwFormUrlDecoder;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::RawUri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_RawUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::SchemeName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_SchemeName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::UserName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_UserName(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IUriRuntimeClass<D>::Port() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Port(&value));
    return value;
}

template <typename D> bool impl_IUriRuntimeClass<D>::Suspicious() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Suspicious(&value));
    return value;
}

template <typename D> bool impl_IUriRuntimeClass<D>::Equals(const Windows::Foundation::Uri & pUri) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->abi_Equals(get_abi(pUri), &value));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IUriRuntimeClass<D>::CombineUri(hstring_view relativeUri) const
{
    Windows::Foundation::Uri instance { nullptr };
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->abi_CombineUri(get_abi(relativeUri), put_abi(instance)));
    return instance;
}

template <typename D> hstring impl_IUriRuntimeClassWithAbsoluteCanonicalUri<D>::AbsoluteCanonicalUri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClassWithAbsoluteCanonicalUri)->get_AbsoluteCanonicalUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClassWithAbsoluteCanonicalUri<D>::DisplayIri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClassWithAbsoluteCanonicalUri)->get_DisplayIri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriEscapeStatics<D>::UnescapeComponent(hstring_view toUnescape) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriEscapeStatics)->abi_UnescapeComponent(get_abi(toUnescape), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriEscapeStatics<D>::EscapeComponent(hstring_view toEscape) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriEscapeStatics)->abi_EscapeComponent(get_abi(toEscape), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IUriRuntimeClassFactory<D>::CreateUri(hstring_view uri) const
{
    Windows::Foundation::Uri instance { nullptr };
    check_hresult(WINRT_SHIM(IUriRuntimeClassFactory)->abi_CreateUri(get_abi(uri), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::Uri impl_IUriRuntimeClassFactory<D>::CreateWithRelativeUri(hstring_view baseUri, hstring_view relativeUri) const
{
    Windows::Foundation::Uri instance { nullptr };
    check_hresult(WINRT_SHIM(IUriRuntimeClassFactory)->abi_CreateWithRelativeUri(get_abi(baseUri), get_abi(relativeUri), put_abi(instance)));
    return instance;
}

template <typename D> hstring impl_IWwwFormUrlDecoderEntry<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWwwFormUrlDecoderEntry)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWwwFormUrlDecoderEntry<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWwwFormUrlDecoderEntry)->get_Value(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWwwFormUrlDecoderRuntimeClass<D>::GetFirstValueByName(hstring_view name) const
{
    hstring phstrValue;
    check_hresult(WINRT_SHIM(IWwwFormUrlDecoderRuntimeClass)->abi_GetFirstValueByName(get_abi(name), put_abi(phstrValue)));
    return phstrValue;
}

template <typename D> Windows::Foundation::WwwFormUrlDecoder impl_IWwwFormUrlDecoderRuntimeClassFactory<D>::CreateWwwFormUrlDecoder(hstring_view query) const
{
    Windows::Foundation::WwwFormUrlDecoder instance { nullptr };
    check_hresult(WINRT_SHIM(IWwwFormUrlDecoderRuntimeClassFactory)->abi_CreateWwwFormUrlDecoder(get_abi(query), put_abi(instance)));
    return instance;
}

template <typename D> Windows::IInspectable impl_IGetActivationFactory<D>::GetActivationFactory(hstring_view activatableClassId) const
{
    Windows::IInspectable factory;
    check_hresult(WINRT_SHIM(IGetActivationFactory)->abi_GetActivationFactory(get_abi(activatableClassId), put_abi(factory)));
    return factory;
}

template <typename D> uint32_t impl_IMemoryBufferReference<D>::Capacity() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMemoryBufferReference)->get_Capacity(&value));
    return value;
}

template <typename D> event_token impl_IMemoryBufferReference<D>::Closed(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMemoryBufferReference)->add_Closed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMemoryBufferReference> impl_IMemoryBufferReference<D>::Closed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMemoryBufferReference>(this, &ABI::Windows::Foundation::IMemoryBufferReference::remove_Closed, Closed(handler));
}

template <typename D> void impl_IMemoryBufferReference<D>::Closed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMemoryBufferReference)->remove_Closed(cookie));
}

template <typename D> Windows::Foundation::IMemoryBufferReference impl_IMemoryBuffer<D>::CreateReference() const
{
    Windows::Foundation::IMemoryBufferReference reference;
    check_hresult(WINRT_SHIM(IMemoryBuffer)->abi_CreateReference(put_abi(reference)));
    return reference;
}

template <typename D> Windows::Foundation::MemoryBuffer impl_IMemoryBufferFactory<D>::Create(uint32_t capacity) const
{
    Windows::Foundation::MemoryBuffer value { nullptr };
    check_hresult(WINRT_SHIM(IMemoryBufferFactory)->abi_Create(capacity, put_abi(value)));
    return value;
}

inline Deferral::Deferral(const Windows::Foundation::DeferralCompletedHandler & handler) :
    Deferral(get_activation_factory<Deferral, IDeferralFactory>().Create(handler))
{}

inline MemoryBuffer::MemoryBuffer(uint32_t capacity) :
    MemoryBuffer(get_activation_factory<MemoryBuffer, IMemoryBufferFactory>().Create(capacity))
{}

inline Windows::IInspectable PropertyValue::CreateEmpty()
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateEmpty();
}

inline Windows::IInspectable PropertyValue::CreateUInt8(uint8_t value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt8(value);
}

inline Windows::IInspectable PropertyValue::CreateInt16(int16_t value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt16(value);
}

inline Windows::IInspectable PropertyValue::CreateUInt16(uint16_t value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt16(value);
}

inline Windows::IInspectable PropertyValue::CreateInt32(int32_t value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt32(value);
}

inline Windows::IInspectable PropertyValue::CreateUInt32(uint32_t value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt32(value);
}

inline Windows::IInspectable PropertyValue::CreateInt64(int64_t value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt64(value);
}

inline Windows::IInspectable PropertyValue::CreateUInt64(uint64_t value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt64(value);
}

inline Windows::IInspectable PropertyValue::CreateSingle(float value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSingle(value);
}

inline Windows::IInspectable PropertyValue::CreateDouble(double value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDouble(value);
}

inline Windows::IInspectable PropertyValue::CreateChar16(wchar_t value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateChar16(value);
}

inline Windows::IInspectable PropertyValue::CreateBoolean(bool value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateBoolean(value);
}

inline Windows::IInspectable PropertyValue::CreateString(hstring_view value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateString(value);
}

inline Windows::IInspectable PropertyValue::CreateInspectable(const Windows::IInspectable & value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInspectable(value);
}

inline Windows::IInspectable PropertyValue::CreateGuid(GUID value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateGuid(value);
}

inline Windows::IInspectable PropertyValue::CreateDateTime(const Windows::Foundation::DateTime & value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDateTime(value);
}

inline Windows::IInspectable PropertyValue::CreateTimeSpan(const Windows::Foundation::TimeSpan & value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateTimeSpan(value);
}

inline Windows::IInspectable PropertyValue::CreatePoint(const Windows::Foundation::Point & value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreatePoint(value);
}

inline Windows::IInspectable PropertyValue::CreateSize(const Windows::Foundation::Size & value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSize(value);
}

inline Windows::IInspectable PropertyValue::CreateRect(const Windows::Foundation::Rect & value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateRect(value);
}

inline Windows::IInspectable PropertyValue::CreateUInt8Array(array_view<const uint8_t> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt8Array(value);
}

inline Windows::IInspectable PropertyValue::CreateInt16Array(array_view<const int16_t> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt16Array(value);
}

inline Windows::IInspectable PropertyValue::CreateUInt16Array(array_view<const uint16_t> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt16Array(value);
}

inline Windows::IInspectable PropertyValue::CreateInt32Array(array_view<const int32_t> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt32Array(value);
}

inline Windows::IInspectable PropertyValue::CreateUInt32Array(array_view<const uint32_t> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt32Array(value);
}

inline Windows::IInspectable PropertyValue::CreateInt64Array(array_view<const int64_t> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInt64Array(value);
}

inline Windows::IInspectable PropertyValue::CreateUInt64Array(array_view<const uint64_t> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateUInt64Array(value);
}

inline Windows::IInspectable PropertyValue::CreateSingleArray(array_view<const float> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSingleArray(value);
}

inline Windows::IInspectable PropertyValue::CreateDoubleArray(array_view<const double> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDoubleArray(value);
}

inline Windows::IInspectable PropertyValue::CreateChar16Array(array_view<const wchar_t> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateChar16Array(value);
}

inline Windows::IInspectable PropertyValue::CreateBooleanArray(array_view<const bool> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateBooleanArray(value);
}

inline Windows::IInspectable PropertyValue::CreateStringArray(array_view<const hstring> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateStringArray(value);
}

inline Windows::IInspectable PropertyValue::CreateInspectableArray(array_view<const Windows::IInspectable> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateInspectableArray(value);
}

inline Windows::IInspectable PropertyValue::CreateGuidArray(array_view<const GUID> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateGuidArray(value);
}

inline Windows::IInspectable PropertyValue::CreateDateTimeArray(array_view<const Windows::Foundation::DateTime> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateDateTimeArray(value);
}

inline Windows::IInspectable PropertyValue::CreateTimeSpanArray(array_view<const Windows::Foundation::TimeSpan> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateTimeSpanArray(value);
}

inline Windows::IInspectable PropertyValue::CreatePointArray(array_view<const Windows::Foundation::Point> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreatePointArray(value);
}

inline Windows::IInspectable PropertyValue::CreateSizeArray(array_view<const Windows::Foundation::Size> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateSizeArray(value);
}

inline Windows::IInspectable PropertyValue::CreateRectArray(array_view<const Windows::Foundation::Rect> value)
{
    return get_activation_factory<PropertyValue, IPropertyValueStatics>().CreateRectArray(value);
}

inline Uri::Uri(hstring_view uri) :
    Uri(get_activation_factory<Uri, IUriRuntimeClassFactory>().CreateUri(uri))
{}

inline Uri::Uri(hstring_view baseUri, hstring_view relativeUri) :
    Uri(get_activation_factory<Uri, IUriRuntimeClassFactory>().CreateWithRelativeUri(baseUri, relativeUri))
{}

inline hstring Uri::UnescapeComponent(hstring_view toUnescape)
{
    return get_activation_factory<Uri, IUriEscapeStatics>().UnescapeComponent(toUnescape);
}

inline hstring Uri::EscapeComponent(hstring_view toEscape)
{
    return get_activation_factory<Uri, IUriEscapeStatics>().EscapeComponent(toEscape);
}

inline WwwFormUrlDecoder::WwwFormUrlDecoder(hstring_view query) :
    WwwFormUrlDecoder(get_activation_factory<WwwFormUrlDecoder, IWwwFormUrlDecoderRuntimeClassFactory>().CreateWwwFormUrlDecoder(query))
{}

}

}
