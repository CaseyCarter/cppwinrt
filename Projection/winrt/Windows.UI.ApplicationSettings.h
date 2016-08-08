// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.UI.Popups.3.h"
#include "internal\Windows.Security.Credentials.3.h"
#include "internal\Windows.Foundation.Collections.3.h"
#include "internal\Windows.Foundation.3.h"
#include "internal\Windows.UI.ApplicationSettings.3.h"
#include "Windows.UI.h"
#include "Windows.UI.Popups.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::ApplicationSettings {

template <typename L> CredentialCommandCredentialDeletedHandler::CredentialCommandCredentialDeletedHandler(L lambda) :
    CredentialCommandCredentialDeletedHandler(impl::make_delegate<impl_CredentialCommandCredentialDeletedHandler<L>, CredentialCommandCredentialDeletedHandler>(std::forward<L>(lambda)))
{}

template <typename F> CredentialCommandCredentialDeletedHandler::CredentialCommandCredentialDeletedHandler(F * function) :
    CredentialCommandCredentialDeletedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> CredentialCommandCredentialDeletedHandler::CredentialCommandCredentialDeletedHandler(O * object, M method) :
    CredentialCommandCredentialDeletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void CredentialCommandCredentialDeletedHandler::operator()(const Windows::UI::ApplicationSettings::CredentialCommand & command) const
{
    check_hresult((*this)->abi_Invoke(get(command)));
}

template <typename L> WebAccountCommandInvokedHandler::WebAccountCommandInvokedHandler(L lambda) :
    WebAccountCommandInvokedHandler(impl::make_delegate<impl_WebAccountCommandInvokedHandler<L>, WebAccountCommandInvokedHandler>(std::forward<L>(lambda)))
{}

template <typename F> WebAccountCommandInvokedHandler::WebAccountCommandInvokedHandler(F * function) :
    WebAccountCommandInvokedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> WebAccountCommandInvokedHandler::WebAccountCommandInvokedHandler(O * object, M method) :
    WebAccountCommandInvokedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void WebAccountCommandInvokedHandler::operator()(const Windows::UI::ApplicationSettings::WebAccountCommand & command, const Windows::UI::ApplicationSettings::WebAccountInvokedArgs & args) const
{
    check_hresult((*this)->abi_Invoke(get(command), get(args)));
}

template <typename L> WebAccountProviderCommandInvokedHandler::WebAccountProviderCommandInvokedHandler(L lambda) :
    WebAccountProviderCommandInvokedHandler(impl::make_delegate<impl_WebAccountProviderCommandInvokedHandler<L>, WebAccountProviderCommandInvokedHandler>(std::forward<L>(lambda)))
{}

template <typename F> WebAccountProviderCommandInvokedHandler::WebAccountProviderCommandInvokedHandler(F * function) :
    WebAccountProviderCommandInvokedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> WebAccountProviderCommandInvokedHandler::WebAccountProviderCommandInvokedHandler(O * object, M method) :
    WebAccountProviderCommandInvokedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void WebAccountProviderCommandInvokedHandler::operator()(const Windows::UI::ApplicationSettings::WebAccountProviderCommand & command) const
{
    check_hresult((*this)->abi_Invoke(get(command)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IAccountsSettingsPane> : produce_base<D, Windows::UI::ApplicationSettings::IAccountsSettingsPane>
{
    HRESULT __stdcall add_AccountCommandsRequested(abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::AccountsSettingsPane, Windows::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            *cookie = detach(shim().AccountCommandsRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::AccountsSettingsPane, Windows::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AccountCommandsRequested(event_token cookie) noexcept override
    {
        try
        {
            shim().AccountCommandsRequested(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs> : produce_base<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs>
{
    HRESULT __stdcall get_WebAccountProviderCommands(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountProviderCommand>> value) noexcept override
    {
        try
        {
            *value = detach(shim().WebAccountProviderCommands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WebAccountCommands(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountCommand>> value) noexcept override
    {
        try
        {
            *value = detach(shim().WebAccountCommands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CredentialCommands(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::CredentialCommand>> value) noexcept override
    {
        try
        {
            *value = detach(shim().CredentialCommands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Commands(abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::SettingsCommand>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Commands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeaderText(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().HeaderText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HeaderText(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().HeaderText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(abi_arg_out<Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral> deferral) noexcept override
    {
        try
        {
            *deferral = detach(shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *deferral = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral> : produce_base<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics> : produce_base<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(abi_arg_out<Windows::UI::ApplicationSettings::IAccountsSettingsPane> current) noexcept override
    {
        try
        {
            *current = detach(shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *current = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Show() noexcept override
    {
        try
        {
            shim().Show();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics2> : produce_base<D, Windows::UI::ApplicationSettings::IAccountsSettingsPaneStatics2>
{
    HRESULT __stdcall abi_ShowManageAccountsAsync(abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(shim().ShowManageAccountsAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAddAccountAsync(abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            *asyncInfo = detach(shim().ShowAddAccountAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::ICredentialCommand> : produce_base<D, Windows::UI::ApplicationSettings::ICredentialCommand>
{
    HRESULT __stdcall get_PasswordCredential(abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            *value = detach(shim().PasswordCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CredentialDeleted(abi_arg_out<Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler> value) noexcept override
    {
        try
        {
            *value = detach(shim().CredentialDeleted());
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
struct produce<D, Windows::UI::ApplicationSettings::ICredentialCommandFactory> : produce_base<D, Windows::UI::ApplicationSettings::ICredentialCommandFactory>
{
    HRESULT __stdcall abi_CreateCredentialCommand(abi_arg_in<Windows::Security::Credentials::IPasswordCredential> passwordCredential, abi_arg_out<Windows::UI::ApplicationSettings::ICredentialCommand> instance) noexcept override
    {
        try
        {
            *instance = detach(shim().CreateCredentialCommand(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&passwordCredential)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCredentialCommandWithHandler(abi_arg_in<Windows::Security::Credentials::IPasswordCredential> passwordCredential, abi_arg_in<Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler> deleted, abi_arg_out<Windows::UI::ApplicationSettings::ICredentialCommand> instance) noexcept override
    {
        try
        {
            *instance = detach(shim().CreateCredentialCommandWithHandler(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&passwordCredential), *reinterpret_cast<const Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler *>(&deleted)));
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
struct produce<D, Windows::UI::ApplicationSettings::ISettingsCommandFactory> : produce_base<D, Windows::UI::ApplicationSettings::ISettingsCommandFactory>
{
    HRESULT __stdcall abi_CreateSettingsCommand(abi_arg_in<Windows::IInspectable> settingsCommandId, abi_arg_in<hstring> label, abi_arg_in<Windows::UI::Popups::UICommandInvokedHandler> handler, abi_arg_out<Windows::UI::Popups::IUICommand> instance) noexcept override
    {
        try
        {
            *instance = detach(shim().CreateSettingsCommand(*reinterpret_cast<const Windows::IInspectable *>(&settingsCommandId), *reinterpret_cast<const hstring *>(&label), *reinterpret_cast<const Windows::UI::Popups::UICommandInvokedHandler *>(&handler)));
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
struct produce<D, Windows::UI::ApplicationSettings::ISettingsCommandStatics> : produce_base<D, Windows::UI::ApplicationSettings::ISettingsCommandStatics>
{
    HRESULT __stdcall get_AccountsCommand(abi_arg_out<Windows::UI::Popups::IUICommand> value) noexcept override
    {
        try
        {
            *value = detach(shim().AccountsCommand());
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
struct produce<D, Windows::UI::ApplicationSettings::IWebAccountCommand> : produce_base<D, Windows::UI::ApplicationSettings::IWebAccountCommand>
{
    HRESULT __stdcall get_WebAccount(abi_arg_out<Windows::Security::Credentials::IWebAccount> value) noexcept override
    {
        try
        {
            *value = detach(shim().WebAccount());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Invoked(abi_arg_out<Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler> value) noexcept override
    {
        try
        {
            *value = detach(shim().Invoked());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Actions(Windows::UI::ApplicationSettings::SupportedWebAccountActions * value) noexcept override
    {
        try
        {
            *value = detach(shim().Actions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IWebAccountCommandFactory> : produce_base<D, Windows::UI::ApplicationSettings::IWebAccountCommandFactory>
{
    HRESULT __stdcall abi_CreateWebAccountCommand(abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, abi_arg_in<Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler> invoked, Windows::UI::ApplicationSettings::SupportedWebAccountActions actions, abi_arg_out<Windows::UI::ApplicationSettings::IWebAccountCommand> instance) noexcept override
    {
        try
        {
            *instance = detach(shim().CreateWebAccountCommand(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount), *reinterpret_cast<const Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler *>(&invoked), actions));
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
struct produce<D, Windows::UI::ApplicationSettings::IWebAccountInvokedArgs> : produce_base<D, Windows::UI::ApplicationSettings::IWebAccountInvokedArgs>
{
    HRESULT __stdcall get_Action(Windows::UI::ApplicationSettings::WebAccountAction * action) noexcept override
    {
        try
        {
            *action = detach(shim().Action());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ApplicationSettings::IWebAccountProviderCommand> : produce_base<D, Windows::UI::ApplicationSettings::IWebAccountProviderCommand>
{
    HRESULT __stdcall get_WebAccountProvider(abi_arg_out<Windows::Security::Credentials::IWebAccountProvider> value) noexcept override
    {
        try
        {
            *value = detach(shim().WebAccountProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Invoked(abi_arg_out<Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler> value) noexcept override
    {
        try
        {
            *value = detach(shim().Invoked());
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
struct produce<D, Windows::UI::ApplicationSettings::IWebAccountProviderCommandFactory> : produce_base<D, Windows::UI::ApplicationSettings::IWebAccountProviderCommandFactory>
{
    HRESULT __stdcall abi_CreateWebAccountProviderCommand(abi_arg_in<Windows::Security::Credentials::IWebAccountProvider> webAccountProvider, abi_arg_in<Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler> invoked, abi_arg_out<Windows::UI::ApplicationSettings::IWebAccountProviderCommand> instance) noexcept override
    {
        try
        {
            *instance = detach(shim().CreateWebAccountProviderCommand(*reinterpret_cast<const Windows::Security::Credentials::WebAccountProvider *>(&webAccountProvider), *reinterpret_cast<const Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler *>(&invoked)));
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

namespace Windows::UI::ApplicationSettings {

template <typename D> Windows::UI::ApplicationSettings::SettingsCommand impl_ISettingsCommandFactory<D>::CreateSettingsCommand(const Windows::IInspectable & settingsCommandId, hstring_ref label, const Windows::UI::Popups::UICommandInvokedHandler & handler) const
{
    Windows::UI::ApplicationSettings::SettingsCommand instance { nullptr };
    check_hresult(shim()->abi_CreateSettingsCommand(get(settingsCommandId), get(label), get(handler), put(instance)));
    return instance;
}

template <typename D> Windows::UI::ApplicationSettings::SettingsCommand impl_ISettingsCommandStatics<D>::AccountsCommand() const
{
    Windows::UI::ApplicationSettings::SettingsCommand value { nullptr };
    check_hresult(shim()->get_AccountsCommand(put(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::WebAccountProviderCommand impl_IWebAccountProviderCommandFactory<D>::CreateWebAccountProviderCommand(const Windows::Security::Credentials::WebAccountProvider & webAccountProvider, const Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler & invoked) const
{
    Windows::UI::ApplicationSettings::WebAccountProviderCommand instance { nullptr };
    check_hresult(shim()->abi_CreateWebAccountProviderCommand(get(webAccountProvider), get(invoked), put(instance)));
    return instance;
}

template <typename D> Windows::Security::Credentials::WebAccountProvider impl_IWebAccountProviderCommand<D>::WebAccountProvider() const
{
    Windows::Security::Credentials::WebAccountProvider value { nullptr };
    check_hresult(shim()->get_WebAccountProvider(put(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler impl_IWebAccountProviderCommand<D>::Invoked() const
{
    Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler value {};
    check_hresult(shim()->get_Invoked(put(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::WebAccountAction impl_IWebAccountInvokedArgs<D>::Action() const
{
    Windows::UI::ApplicationSettings::WebAccountAction action {};
    check_hresult(shim()->get_Action(&action));
    return action;
}

template <typename D> Windows::UI::ApplicationSettings::WebAccountCommand impl_IWebAccountCommandFactory<D>::CreateWebAccountCommand(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler & invoked, Windows::UI::ApplicationSettings::SupportedWebAccountActions actions) const
{
    Windows::UI::ApplicationSettings::WebAccountCommand instance { nullptr };
    check_hresult(shim()->abi_CreateWebAccountCommand(get(webAccount), get(invoked), actions, put(instance)));
    return instance;
}

template <typename D> Windows::Security::Credentials::WebAccount impl_IWebAccountCommand<D>::WebAccount() const
{
    Windows::Security::Credentials::WebAccount value { nullptr };
    check_hresult(shim()->get_WebAccount(put(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler impl_IWebAccountCommand<D>::Invoked() const
{
    Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler value {};
    check_hresult(shim()->get_Invoked(put(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::SupportedWebAccountActions impl_IWebAccountCommand<D>::Actions() const
{
    Windows::UI::ApplicationSettings::SupportedWebAccountActions value {};
    check_hresult(shim()->get_Actions(&value));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::CredentialCommand impl_ICredentialCommandFactory<D>::CreateCredentialCommand(const Windows::Security::Credentials::PasswordCredential & passwordCredential) const
{
    Windows::UI::ApplicationSettings::CredentialCommand instance { nullptr };
    check_hresult(shim()->abi_CreateCredentialCommand(get(passwordCredential), put(instance)));
    return instance;
}

template <typename D> Windows::UI::ApplicationSettings::CredentialCommand impl_ICredentialCommandFactory<D>::CreateCredentialCommandWithHandler(const Windows::Security::Credentials::PasswordCredential & passwordCredential, const Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler & deleted) const
{
    Windows::UI::ApplicationSettings::CredentialCommand instance { nullptr };
    check_hresult(shim()->abi_CreateCredentialCommandWithHandler(get(passwordCredential), get(deleted), put(instance)));
    return instance;
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_ICredentialCommand<D>::PasswordCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(shim()->get_PasswordCredential(put(value)));
    return value;
}

template <typename D> Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler impl_ICredentialCommand<D>::CredentialDeleted() const
{
    Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler value {};
    check_hresult(shim()->get_CredentialDeleted(put(value)));
    return value;
}

template <typename D> void impl_IAccountsSettingsPaneEventDeferral<D>::Complete() const
{
    check_hresult(shim()->abi_Complete());
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountProviderCommand> impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::WebAccountProviderCommands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountProviderCommand> value;
    check_hresult(shim()->get_WebAccountProviderCommands(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountCommand> impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::WebAccountCommands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::WebAccountCommand> value;
    check_hresult(shim()->get_WebAccountCommands(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::CredentialCommand> impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::CredentialCommands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::CredentialCommand> value;
    check_hresult(shim()->get_CredentialCommands(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::SettingsCommand> impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::Commands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::ApplicationSettings::SettingsCommand> value;
    check_hresult(shim()->get_Commands(put(value)));
    return value;
}

template <typename D> hstring impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::HeaderText() const
{
    hstring value;
    check_hresult(shim()->get_HeaderText(put(value)));
    return value;
}

template <typename D> void impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::HeaderText(hstring_ref value) const
{
    check_hresult(shim()->put_HeaderText(get(value)));
}

template <typename D> Windows::UI::ApplicationSettings::AccountsSettingsPaneEventDeferral impl_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::GetDeferral() const
{
    Windows::UI::ApplicationSettings::AccountsSettingsPaneEventDeferral deferral { nullptr };
    check_hresult(shim()->abi_GetDeferral(put(deferral)));
    return deferral;
}

template <typename D> Windows::UI::ApplicationSettings::AccountsSettingsPane impl_IAccountsSettingsPaneStatics<D>::GetForCurrentView() const
{
    Windows::UI::ApplicationSettings::AccountsSettingsPane current { nullptr };
    check_hresult(shim()->abi_GetForCurrentView(put(current)));
    return current;
}

template <typename D> void impl_IAccountsSettingsPaneStatics<D>::Show() const
{
    check_hresult(shim()->abi_Show());
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAccountsSettingsPaneStatics2<D>::ShowManageAccountsAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_ShowManageAccountsAsync(put(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAccountsSettingsPaneStatics2<D>::ShowAddAccountAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(shim()->abi_ShowAddAccountAsync(put(asyncInfo)));
    return asyncInfo;
}

template <typename D> event_token impl_IAccountsSettingsPane<D>::AccountCommandsRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::AccountsSettingsPane, Windows::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(shim()->add_AccountCommandsRequested(get(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IAccountsSettingsPane> impl_IAccountsSettingsPane<D>::AccountCommandsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ApplicationSettings::AccountsSettingsPane, Windows::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAccountsSettingsPane>(this, &ABI::Windows::UI::ApplicationSettings::IAccountsSettingsPane::remove_AccountCommandsRequested, AccountCommandsRequested(handler));
}

template <typename D> void impl_IAccountsSettingsPane<D>::AccountCommandsRequested(event_token cookie) const
{
    check_hresult(shim()->remove_AccountCommandsRequested(cookie));
}

inline Windows::UI::ApplicationSettings::AccountsSettingsPane AccountsSettingsPane::GetForCurrentView()
{
    return get_activation_factory<AccountsSettingsPane, IAccountsSettingsPaneStatics>().GetForCurrentView();
}

inline void AccountsSettingsPane::Show()
{
    get_activation_factory<AccountsSettingsPane, IAccountsSettingsPaneStatics>().Show();
}

inline Windows::Foundation::IAsyncAction AccountsSettingsPane::ShowManageAccountsAsync()
{
    return get_activation_factory<AccountsSettingsPane, IAccountsSettingsPaneStatics2>().ShowManageAccountsAsync();
}

inline Windows::Foundation::IAsyncAction AccountsSettingsPane::ShowAddAccountAsync()
{
    return get_activation_factory<AccountsSettingsPane, IAccountsSettingsPaneStatics2>().ShowAddAccountAsync();
}

inline CredentialCommand::CredentialCommand(const Windows::Security::Credentials::PasswordCredential & passwordCredential) :
    CredentialCommand(get_activation_factory<CredentialCommand, ICredentialCommandFactory>().CreateCredentialCommand(passwordCredential))
{}

inline CredentialCommand::CredentialCommand(const Windows::Security::Credentials::PasswordCredential & passwordCredential, const Windows::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler & deleted) :
    CredentialCommand(get_activation_factory<CredentialCommand, ICredentialCommandFactory>().CreateCredentialCommandWithHandler(passwordCredential, deleted))
{}

inline SettingsCommand::SettingsCommand(const Windows::IInspectable & settingsCommandId, hstring_ref label, const Windows::UI::Popups::UICommandInvokedHandler & handler) :
    SettingsCommand(get_activation_factory<SettingsCommand, ISettingsCommandFactory>().CreateSettingsCommand(settingsCommandId, label, handler))
{}

inline Windows::UI::ApplicationSettings::SettingsCommand SettingsCommand::AccountsCommand()
{
    return get_activation_factory<SettingsCommand, ISettingsCommandStatics>().AccountsCommand();
}

inline WebAccountCommand::WebAccountCommand(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::UI::ApplicationSettings::WebAccountCommandInvokedHandler & invoked, Windows::UI::ApplicationSettings::SupportedWebAccountActions actions) :
    WebAccountCommand(get_activation_factory<WebAccountCommand, IWebAccountCommandFactory>().CreateWebAccountCommand(webAccount, invoked, actions))
{}

inline WebAccountProviderCommand::WebAccountProviderCommand(const Windows::Security::Credentials::WebAccountProvider & webAccountProvider, const Windows::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler & invoked) :
    WebAccountProviderCommand(get_activation_factory<WebAccountProviderCommand, IWebAccountProviderCommandFactory>().CreateWebAccountProviderCommand(webAccountProvider, invoked))
{}

}

}