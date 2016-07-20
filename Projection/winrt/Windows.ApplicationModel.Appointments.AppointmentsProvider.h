// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.ApplicationModel.Appointments.class.h"
#include "internal\Windows.Foundation.class.h"
#include "internal\Windows.ApplicationModel.Appointments.AppointmentsProvider.class.h"
#include "Windows.ApplicationModel.Appointments.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation> : produce_base<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>
{
    HRESULT __stdcall get_AppointmentInformation(abi_arg_out<Windows::ApplicationModel::Appointments::IAppointment> value) noexcept override
    {
        try
        {
            *value = detach(shim().AppointmentInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourcePackageFamilyName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SourcePackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompleted(abi_arg_in<hstring> itemId) noexcept override
    {
        try
        {
            shim().ReportCompleted(*reinterpret_cast<const hstring *>(&itemId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCanceled() noexcept override
    {
        try
        {
            shim().ReportCanceled();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportError(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().ReportError(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DismissUI() noexcept override
    {
        try
        {
            shim().DismissUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics> : produce_base<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics>
{
    HRESULT __stdcall get_AddAppointment(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AddAppointment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReplaceAppointment(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ReplaceAppointment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoveAppointment(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().RemoveAppointment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShowTimeFrame(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ShowTimeFrame());
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
struct produce<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2> : produce_base<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2>
{
    HRESULT __stdcall get_ShowAppointmentDetails(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ShowAppointmentDetails());
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
struct produce<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation> : produce_base<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>
{
    HRESULT __stdcall get_AppointmentId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AppointmentId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstanceStartDate(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            *value = detach(shim().InstanceStartDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourcePackageFamilyName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SourcePackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompleted() noexcept override
    {
        try
        {
            shim().ReportCompleted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCanceled() noexcept override
    {
        try
        {
            shim().ReportCanceled();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportError(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().ReportError(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DismissUI() noexcept override
    {
        try
        {
            shim().DismissUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation> : produce_base<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>
{
    HRESULT __stdcall get_AppointmentId(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AppointmentId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppointmentInformation(abi_arg_out<Windows::ApplicationModel::Appointments::IAppointment> value) noexcept override
    {
        try
        {
            *value = detach(shim().AppointmentInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstanceStartDate(abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            *value = detach(shim().InstanceStartDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourcePackageFamilyName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SourcePackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompleted(abi_arg_in<hstring> itemId) noexcept override
    {
        try
        {
            shim().ReportCompleted(*reinterpret_cast<const hstring *>(&itemId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCanceled() noexcept override
    {
        try
        {
            shim().ReportCanceled();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportError(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().ReportError(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DismissUI() noexcept override
    {
        try
        {
            shim().DismissUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Appointments::AppointmentsProvider {

template <typename D> hstring impl_IAppointmentsProviderLaunchActionVerbsStatics<D>::AddAppointment() const
{
    hstring value;
    check_hresult(shim()->get_AddAppointment(put(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentsProviderLaunchActionVerbsStatics<D>::ReplaceAppointment() const
{
    hstring value;
    check_hresult(shim()->get_ReplaceAppointment(put(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentsProviderLaunchActionVerbsStatics<D>::RemoveAppointment() const
{
    hstring value;
    check_hresult(shim()->get_RemoveAppointment(put(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentsProviderLaunchActionVerbsStatics<D>::ShowTimeFrame() const
{
    hstring value;
    check_hresult(shim()->get_ShowTimeFrame(put(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentsProviderLaunchActionVerbsStatics2<D>::ShowAppointmentDetails() const
{
    hstring value;
    check_hresult(shim()->get_ShowAppointmentDetails(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::Appointment impl_IAddAppointmentOperation<D>::AppointmentInformation() const
{
    Windows::ApplicationModel::Appointments::Appointment value { nullptr };
    check_hresult(shim()->get_AppointmentInformation(put(value)));
    return value;
}

template <typename D> hstring impl_IAddAppointmentOperation<D>::SourcePackageFamilyName() const
{
    hstring value;
    check_hresult(shim()->get_SourcePackageFamilyName(put(value)));
    return value;
}

template <typename D> void impl_IAddAppointmentOperation<D>::ReportCompleted(hstring_ref itemId) const
{
    check_hresult(shim()->abi_ReportCompleted(get(itemId)));
}

template <typename D> void impl_IAddAppointmentOperation<D>::ReportCanceled() const
{
    check_hresult(shim()->abi_ReportCanceled());
}

template <typename D> void impl_IAddAppointmentOperation<D>::ReportError(hstring_ref value) const
{
    check_hresult(shim()->abi_ReportError(get(value)));
}

template <typename D> void impl_IAddAppointmentOperation<D>::DismissUI() const
{
    check_hresult(shim()->abi_DismissUI());
}

template <typename D> hstring impl_IReplaceAppointmentOperation<D>::AppointmentId() const
{
    hstring value;
    check_hresult(shim()->get_AppointmentId(put(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::Appointment impl_IReplaceAppointmentOperation<D>::AppointmentInformation() const
{
    Windows::ApplicationModel::Appointments::Appointment value { nullptr };
    check_hresult(shim()->get_AppointmentInformation(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IReplaceAppointmentOperation<D>::InstanceStartDate() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(shim()->get_InstanceStartDate(put(value)));
    return value;
}

template <typename D> hstring impl_IReplaceAppointmentOperation<D>::SourcePackageFamilyName() const
{
    hstring value;
    check_hresult(shim()->get_SourcePackageFamilyName(put(value)));
    return value;
}

template <typename D> void impl_IReplaceAppointmentOperation<D>::ReportCompleted(hstring_ref itemId) const
{
    check_hresult(shim()->abi_ReportCompleted(get(itemId)));
}

template <typename D> void impl_IReplaceAppointmentOperation<D>::ReportCanceled() const
{
    check_hresult(shim()->abi_ReportCanceled());
}

template <typename D> void impl_IReplaceAppointmentOperation<D>::ReportError(hstring_ref value) const
{
    check_hresult(shim()->abi_ReportError(get(value)));
}

template <typename D> void impl_IReplaceAppointmentOperation<D>::DismissUI() const
{
    check_hresult(shim()->abi_DismissUI());
}

template <typename D> hstring impl_IRemoveAppointmentOperation<D>::AppointmentId() const
{
    hstring value;
    check_hresult(shim()->get_AppointmentId(put(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IRemoveAppointmentOperation<D>::InstanceStartDate() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(shim()->get_InstanceStartDate(put(value)));
    return value;
}

template <typename D> hstring impl_IRemoveAppointmentOperation<D>::SourcePackageFamilyName() const
{
    hstring value;
    check_hresult(shim()->get_SourcePackageFamilyName(put(value)));
    return value;
}

template <typename D> void impl_IRemoveAppointmentOperation<D>::ReportCompleted() const
{
    check_hresult(shim()->abi_ReportCompleted());
}

template <typename D> void impl_IRemoveAppointmentOperation<D>::ReportCanceled() const
{
    check_hresult(shim()->abi_ReportCanceled());
}

template <typename D> void impl_IRemoveAppointmentOperation<D>::ReportError(hstring_ref value) const
{
    check_hresult(shim()->abi_ReportError(get(value)));
}

template <typename D> void impl_IRemoveAppointmentOperation<D>::DismissUI() const
{
    check_hresult(shim()->abi_DismissUI());
}

inline hstring AppointmentsProviderLaunchActionVerbs::AddAppointment()
{
    return get_activation_factory<AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>().AddAppointment();
}

inline hstring AppointmentsProviderLaunchActionVerbs::ReplaceAppointment()
{
    return get_activation_factory<AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>().ReplaceAppointment();
}

inline hstring AppointmentsProviderLaunchActionVerbs::RemoveAppointment()
{
    return get_activation_factory<AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>().RemoveAppointment();
}

inline hstring AppointmentsProviderLaunchActionVerbs::ShowTimeFrame()
{
    return get_activation_factory<AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>().ShowTimeFrame();
}

inline hstring AppointmentsProviderLaunchActionVerbs::ShowAppointmentDetails()
{
    return get_activation_factory<AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics2>().ShowAppointmentDetails();
}

}

}
