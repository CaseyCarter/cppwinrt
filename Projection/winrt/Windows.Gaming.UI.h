// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Gaming.UI.class.h"
#include "internal\Windows.Foundation.class.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Gaming::UI::IGameBarStatics> : produce_base<D, Windows::Gaming::UI::IGameBarStatics>
{
    HRESULT __stdcall add_VisibilityChanged(abi_arg_in<Windows::Foundation::EventHandler<Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().VisibilityChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VisibilityChanged(event_token token) noexcept override
    {
        try
        {
            shim().VisibilityChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_IsInputRedirectedChanged(abi_arg_in<Windows::Foundation::EventHandler<Windows::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            *token = detach(shim().IsInputRedirectedChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_IsInputRedirectedChanged(event_token token) noexcept override
    {
        try
        {
            shim().IsInputRedirectedChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Visible(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().Visible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInputRedirected(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsInputRedirected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Gaming::UI {

template <typename D> event_token impl_IGameBarStatics<D>::VisibilityChanged(const Windows::Foundation::EventHandler<Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_VisibilityChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IGameBarStatics> impl_IGameBarStatics<D>::VisibilityChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IGameBarStatics>(this, &ABI::Windows::Gaming::UI::IGameBarStatics::remove_VisibilityChanged, VisibilityChanged(handler));
}

template <typename D> void impl_IGameBarStatics<D>::VisibilityChanged(event_token token) const
{
    check_hresult(shim()->remove_VisibilityChanged(token));
}

template <typename D> event_token impl_IGameBarStatics<D>::IsInputRedirectedChanged(const Windows::Foundation::EventHandler<Windows::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(shim()->add_IsInputRedirectedChanged(get(handler), &token));
    return token;
}

template <typename D> event_revoker<IGameBarStatics> impl_IGameBarStatics<D>::IsInputRedirectedChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IGameBarStatics>(this, &ABI::Windows::Gaming::UI::IGameBarStatics::remove_IsInputRedirectedChanged, IsInputRedirectedChanged(handler));
}

template <typename D> void impl_IGameBarStatics<D>::IsInputRedirectedChanged(event_token token) const
{
    check_hresult(shim()->remove_IsInputRedirectedChanged(token));
}

template <typename D> bool impl_IGameBarStatics<D>::Visible() const
{
    bool value {};
    check_hresult(shim()->get_Visible(&value));
    return value;
}

template <typename D> bool impl_IGameBarStatics<D>::IsInputRedirected() const
{
    bool value {};
    check_hresult(shim()->get_IsInputRedirected(&value));
    return value;
}

inline event_token GameBar::VisibilityChanged(const Windows::Foundation::EventHandler<Windows::IInspectable> & handler)
{
    return GetActivationFactory<GameBar, IGameBarStatics>().VisibilityChanged(handler);
}

inline factory_event_revoker<IGameBarStatics> GameBar::VisibilityChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::IInspectable> & handler)
{
    auto factory = GetActivationFactory<GameBar, IGameBarStatics>();
    return { factory, &ABI::Windows::Gaming::UI::IGameBarStatics::remove_VisibilityChanged, factory.VisibilityChanged(handler) };
}

inline void GameBar::VisibilityChanged(event_token token)
{
    GetActivationFactory<GameBar, IGameBarStatics>().VisibilityChanged(token);
}

inline event_token GameBar::IsInputRedirectedChanged(const Windows::Foundation::EventHandler<Windows::IInspectable> & handler)
{
    return GetActivationFactory<GameBar, IGameBarStatics>().IsInputRedirectedChanged(handler);
}

inline factory_event_revoker<IGameBarStatics> GameBar::IsInputRedirectedChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::IInspectable> & handler)
{
    auto factory = GetActivationFactory<GameBar, IGameBarStatics>();
    return { factory, &ABI::Windows::Gaming::UI::IGameBarStatics::remove_IsInputRedirectedChanged, factory.IsInputRedirectedChanged(handler) };
}

inline void GameBar::IsInputRedirectedChanged(event_token token)
{
    GetActivationFactory<GameBar, IGameBarStatics>().IsInputRedirectedChanged(token);
}

inline bool GameBar::Visible()
{
    return GetActivationFactory<GameBar, IGameBarStatics>().Visible();
}

inline bool GameBar::IsInputRedirected()
{
    return GetActivationFactory<GameBar, IGameBarStatics>().IsInputRedirected();
}

}

}
