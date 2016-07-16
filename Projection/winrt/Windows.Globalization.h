// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "internal\Windows.Foundation.Collections.class.h"
#include "internal\Windows.Foundation.class.h"
#include "internal\Windows.Globalization.class.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Globalization::IApplicationLanguagesStatics> : produce_base<D, Windows::Globalization::IApplicationLanguagesStatics>
{
    HRESULT __stdcall get_PrimaryLanguageOverride(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().PrimaryLanguageOverride());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PrimaryLanguageOverride(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().PrimaryLanguageOverride(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Languages(abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Languages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManifestLanguages(abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().ManifestLanguages());
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
struct produce<D, Windows::Globalization::ICalendar> : produce_base<D, Windows::Globalization::ICalendar>
{
    HRESULT __stdcall abi_Clone(abi_arg_out<Windows::Globalization::ICalendar> value) noexcept override
    {
        try
        {
            *value = detach(shim().Clone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetToMin() noexcept override
    {
        try
        {
            shim().SetToMin();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetToMax() noexcept override
    {
        try
        {
            shim().SetToMax();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Languages(abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().Languages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumeralSystem(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().NumeralSystem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NumeralSystem(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().NumeralSystem(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCalendarSystem(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().GetCalendarSystem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangeCalendarSystem(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().ChangeCalendarSystem(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClock(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().GetClock());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangeClock(abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            shim().ChangeClock(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDateTime(abi_arg_out<Windows::Foundation::DateTime> result) noexcept override
    {
        try
        {
            *result = detach(shim().GetDateTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDateTime(abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            shim().SetDateTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetToNow() noexcept override
    {
        try
        {
            shim().SetToNow();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstEra(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().FirstEra());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastEra(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LastEra());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfEras(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().NumberOfEras());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Era(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Era());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Era(int32_t value) noexcept override
    {
        try
        {
            shim().Era(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddEras(int32_t eras) noexcept override
    {
        try
        {
            shim().AddEras(eras);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EraAsFullString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().EraAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EraAsString(int32_t idealLength, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().EraAsString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstYearInThisEra(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().FirstYearInThisEra());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastYearInThisEra(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LastYearInThisEra());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfYearsInThisEra(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().NumberOfYearsInThisEra());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Year(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Year());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Year(int32_t value) noexcept override
    {
        try
        {
            shim().Year(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddYears(int32_t years) noexcept override
    {
        try
        {
            shim().AddYears(years);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_YearAsString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().YearAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_YearAsTruncatedString(int32_t remainingDigits, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().YearAsTruncatedString(remainingDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_YearAsPaddedString(int32_t minDigits, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().YearAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstMonthInThisYear(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().FirstMonthInThisYear());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastMonthInThisYear(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LastMonthInThisYear());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfMonthsInThisYear(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().NumberOfMonthsInThisYear());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Month(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Month());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Month(int32_t value) noexcept override
    {
        try
        {
            shim().Month(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddMonths(int32_t months) noexcept override
    {
        try
        {
            shim().AddMonths(months);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsFullString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().MonthAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsString(int32_t idealLength, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().MonthAsString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsFullSoloString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().MonthAsSoloString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsSoloString(int32_t idealLength, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().MonthAsSoloString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsNumericString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().MonthAsNumericString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MonthAsPaddedNumericString(int32_t minDigits, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().MonthAsPaddedNumericString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddWeeks(int32_t weeks) noexcept override
    {
        try
        {
            shim().AddWeeks(weeks);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstDayInThisMonth(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().FirstDayInThisMonth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastDayInThisMonth(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LastDayInThisMonth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfDaysInThisMonth(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().NumberOfDaysInThisMonth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Day(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Day());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Day(int32_t value) noexcept override
    {
        try
        {
            shim().Day(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDays(int32_t days) noexcept override
    {
        try
        {
            shim().AddDays(days);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayAsString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().DayAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayAsPaddedString(int32_t minDigits, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().DayAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DayOfWeek(Windows::Globalization::DayOfWeek * value) noexcept override
    {
        try
        {
            *value = detach(shim().DayOfWeek());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayOfWeekAsFullString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().DayOfWeekAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayOfWeekAsString(int32_t idealLength, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().DayOfWeekAsString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayOfWeekAsFullSoloString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().DayOfWeekAsSoloString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DayOfWeekAsSoloString(int32_t idealLength, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().DayOfWeekAsSoloString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstPeriodInThisDay(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().FirstPeriodInThisDay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastPeriodInThisDay(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LastPeriodInThisDay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfPeriodsInThisDay(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().NumberOfPeriodsInThisDay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Period(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Period());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Period(int32_t value) noexcept override
    {
        try
        {
            shim().Period(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPeriods(int32_t periods) noexcept override
    {
        try
        {
            shim().AddPeriods(periods);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PeriodAsFullString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().PeriodAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PeriodAsString(int32_t idealLength, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().PeriodAsString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstHourInThisPeriod(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().FirstHourInThisPeriod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastHourInThisPeriod(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LastHourInThisPeriod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfHoursInThisPeriod(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().NumberOfHoursInThisPeriod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Hour(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Hour());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Hour(int32_t value) noexcept override
    {
        try
        {
            shim().Hour(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddHours(int32_t hours) noexcept override
    {
        try
        {
            shim().AddHours(hours);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HourAsString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().HourAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HourAsPaddedString(int32_t minDigits, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().HourAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Minute(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Minute());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Minute(int32_t value) noexcept override
    {
        try
        {
            shim().Minute(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddMinutes(int32_t minutes) noexcept override
    {
        try
        {
            shim().AddMinutes(minutes);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MinuteAsString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().MinuteAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MinuteAsPaddedString(int32_t minDigits, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().MinuteAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Second(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Second());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Second(int32_t value) noexcept override
    {
        try
        {
            shim().Second(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddSeconds(int32_t seconds) noexcept override
    {
        try
        {
            shim().AddSeconds(seconds);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SecondAsString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().SecondAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SecondAsPaddedString(int32_t minDigits, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().SecondAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Nanosecond(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().Nanosecond());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Nanosecond(int32_t value) noexcept override
    {
        try
        {
            shim().Nanosecond(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddNanoseconds(int32_t nanoseconds) noexcept override
    {
        try
        {
            shim().AddNanoseconds(nanoseconds);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NanosecondAsString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().NanosecondAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_NanosecondAsPaddedString(int32_t minDigits, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().NanosecondAsPaddedString(minDigits));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Compare(abi_arg_in<Windows::Globalization::ICalendar> other, int32_t * result) noexcept override
    {
        try
        {
            *result = detach(shim().Compare(*reinterpret_cast<const Windows::Globalization::Calendar *>(&other)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CompareDateTime(abi_arg_in<Windows::Foundation::DateTime> other, int32_t * result) noexcept override
    {
        try
        {
            *result = detach(shim().CompareDateTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&other)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyTo(abi_arg_in<Windows::Globalization::ICalendar> other) noexcept override
    {
        try
        {
            shim().CopyTo(*reinterpret_cast<const Windows::Globalization::Calendar *>(&other));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstMinuteInThisHour(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().FirstMinuteInThisHour());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastMinuteInThisHour(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LastMinuteInThisHour());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfMinutesInThisHour(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().NumberOfMinutesInThisHour());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstSecondInThisMinute(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().FirstSecondInThisMinute());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastSecondInThisMinute(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().LastSecondInThisMinute());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfSecondsInThisMinute(int32_t * value) noexcept override
    {
        try
        {
            *value = detach(shim().NumberOfSecondsInThisMinute());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResolvedLanguage(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ResolvedLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDaylightSavingTime(bool * value) noexcept override
    {
        try
        {
            *value = detach(shim().IsDaylightSavingTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::ICalendarFactory> : produce_base<D, Windows::Globalization::ICalendarFactory>
{
    HRESULT __stdcall abi_CreateCalendarDefaultCalendarAndClock(abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, abi_arg_out<Windows::Globalization::ICalendar> result) noexcept override
    {
        try
        {
            *result = detach(shim().CreateCalendarDefaultCalendarAndClock(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCalendar(abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, abi_arg_in<hstring> calendar, abi_arg_in<hstring> clock, abi_arg_out<Windows::Globalization::ICalendar> result) noexcept override
    {
        try
        {
            *result = detach(shim().CreateCalendar(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages), *reinterpret_cast<const hstring *>(&calendar), *reinterpret_cast<const hstring *>(&clock)));
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
struct produce<D, Windows::Globalization::ICalendarFactory2> : produce_base<D, Windows::Globalization::ICalendarFactory2>
{
    HRESULT __stdcall abi_CreateCalendarWithTimeZone(abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> languages, abi_arg_in<hstring> calendar, abi_arg_in<hstring> clock, abi_arg_in<hstring> timeZoneId, abi_arg_out<Windows::Globalization::ICalendar> result) noexcept override
    {
        try
        {
            *result = detach(shim().CreateCalendarWithTimeZone(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&languages), *reinterpret_cast<const hstring *>(&calendar), *reinterpret_cast<const hstring *>(&clock), *reinterpret_cast<const hstring *>(&timeZoneId)));
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
struct produce<D, Windows::Globalization::ICalendarIdentifiersStatics> : produce_base<D, Windows::Globalization::ICalendarIdentifiersStatics>
{
    HRESULT __stdcall get_Gregorian(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Gregorian());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Hebrew(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Hebrew());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Hijri(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Hijri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Japanese(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Japanese());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Julian(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Julian());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Korean(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Korean());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Taiwan(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Taiwan());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thai(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Thai());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UmAlQura(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().UmAlQura());
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
struct produce<D, Windows::Globalization::ICalendarIdentifiersStatics2> : produce_base<D, Windows::Globalization::ICalendarIdentifiersStatics2>
{
    HRESULT __stdcall get_Persian(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Persian());
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
struct produce<D, Windows::Globalization::ICalendarIdentifiersStatics3> : produce_base<D, Windows::Globalization::ICalendarIdentifiersStatics3>
{
    HRESULT __stdcall get_ChineseLunar(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ChineseLunar());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JapaneseLunar(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().JapaneseLunar());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KoreanLunar(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().KoreanLunar());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TaiwanLunar(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TaiwanLunar());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VietnameseLunar(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().VietnameseLunar());
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
struct produce<D, Windows::Globalization::IClockIdentifiersStatics> : produce_base<D, Windows::Globalization::IClockIdentifiersStatics>
{
    HRESULT __stdcall get_TwelveHour(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TwelveHour());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TwentyFourHour(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TwentyFourHour());
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
struct produce<D, Windows::Globalization::ICurrencyIdentifiersStatics> : produce_base<D, Windows::Globalization::ICurrencyIdentifiersStatics>
{
    HRESULT __stdcall get_AED(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AED());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AFN(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AFN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ALL(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ALL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AMD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AMD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ANG(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ANG());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AOA(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AOA());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ARS(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ARS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AUD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AUD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AWG(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AWG());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AZN(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().AZN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BAM(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BAM());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BBD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BBD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BDT(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BDT());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BGN(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BGN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BHD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BHD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BIF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BIF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BMD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BMD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BND(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BND());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BOB(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BOB());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BRL(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BRL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BSD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BSD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BTN(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BTN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BWP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BWP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BYR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BYR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BZD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().BZD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CAD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CAD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CDF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CDF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CHF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CHF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CLP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CLP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CNY(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CNY());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_COP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().COP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CRC(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CRC());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CUP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CUP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CVE(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CVE());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CZK(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CZK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DJF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DJF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DKK(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DKK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DOP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DOP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DZD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DZD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EGP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().EGP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ERN(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ERN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ETB(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ETB());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EUR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().EUR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FJD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().FJD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FKP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().FKP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GBP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().GBP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GEL(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().GEL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GHS(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().GHS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GIP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().GIP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GMD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().GMD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GNF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().GNF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GTQ(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().GTQ());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GYD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().GYD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HKD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().HKD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HNL(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().HNL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HRK(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().HRK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HTG(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().HTG());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HUF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().HUF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IDR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().IDR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ILS(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ILS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_INR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().INR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IQD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().IQD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IRR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().IRR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ISK(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ISK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JMD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().JMD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JOD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().JOD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_JPY(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().JPY());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KES(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().KES());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KGS(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().KGS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KHR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().KHR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KMF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().KMF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KPW(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().KPW());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KRW(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().KRW());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KWD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().KWD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KYD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().KYD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KZT(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().KZT());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LAK(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LAK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LBP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LBP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LKR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LKR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LRD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LRD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LSL(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LSL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LTL(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LTL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LVL(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LVL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LYD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LYD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MAD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MAD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MDL(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MDL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MGA(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MGA());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MKD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MKD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MMK(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MMK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MNT(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MNT());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MOP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MOP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MRO(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MRO());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MUR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MUR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MVR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MVR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MWK(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MWK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MXN(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MXN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MYR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MYR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MZN(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MZN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NAD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().NAD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NGN(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().NGN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NIO(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().NIO());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NOK(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().NOK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NPR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().NPR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NZD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().NZD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OMR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().OMR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PAB(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().PAB());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PEN(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().PEN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PGK(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().PGK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PHP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().PHP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PKR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().PKR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PLN(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().PLN());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PYG(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().PYG());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QAR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().QAR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RON(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().RON());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RSD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().RSD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RUB(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().RUB());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RWF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().RWF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SAR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SAR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SBD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SBD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SCR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SCR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SDG(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SDG());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SEK(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SEK());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SGD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SGD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SHP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SHP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SLL(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SLL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SOS(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SOS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SRD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SRD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_STD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().STD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SYP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SYP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SZL(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().SZL());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_THB(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().THB());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TJS(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TJS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TMT(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TMT());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TND(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TND());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TOP(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TOP());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TRY(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TRY());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TTD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TTD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TWD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TWD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TZS(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TZS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UAH(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().UAH());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UGX(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().UGX());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_USD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().USD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UYU(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().UYU());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UZS(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().UZS());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VEF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().VEF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VND(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().VND());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VUV(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().VUV());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WST(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().WST());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XAF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().XAF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XCD(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().XCD());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XOF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().XOF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XPF(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().XPF());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_XXX(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().XXX());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_YER(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().YER());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZAR(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ZAR());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZMW(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ZMW());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZWL(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ZWL());
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
struct produce<D, Windows::Globalization::IGeographicRegion> : produce_base<D, Windows::Globalization::IGeographicRegion>
{
    HRESULT __stdcall get_Code(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Code());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CodeTwoLetter(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CodeTwoLetter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CodeThreeLetter(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CodeThreeLetter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CodeThreeDigit(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CodeThreeDigit());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NativeName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().NativeName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrenciesInUse(abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().CurrenciesInUse());
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
struct produce<D, Windows::Globalization::IGeographicRegionFactory> : produce_base<D, Windows::Globalization::IGeographicRegionFactory>
{
    HRESULT __stdcall abi_CreateGeographicRegion(abi_arg_in<hstring> geographicRegionCode, abi_arg_out<Windows::Globalization::IGeographicRegion> result) noexcept override
    {
        try
        {
            *result = detach(shim().CreateGeographicRegion(*reinterpret_cast<const hstring *>(&geographicRegionCode)));
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
struct produce<D, Windows::Globalization::IGeographicRegionStatics> : produce_base<D, Windows::Globalization::IGeographicRegionStatics>
{
    HRESULT __stdcall abi_IsSupported(abi_arg_in<hstring> geographicRegionCode, bool * result) noexcept override
    {
        try
        {
            *result = detach(shim().IsSupported(*reinterpret_cast<const hstring *>(&geographicRegionCode)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::ILanguage> : produce_base<D, Windows::Globalization::ILanguage>
{
    HRESULT __stdcall get_LanguageTag(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LanguageTag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NativeName(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().NativeName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Script(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Script());
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
struct produce<D, Windows::Globalization::ILanguageExtensionSubtags> : produce_base<D, Windows::Globalization::ILanguageExtensionSubtags>
{
    HRESULT __stdcall abi_GetExtensionSubtags(abi_arg_in<hstring> singleton, abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            *value = detach(shim().GetExtensionSubtags(*reinterpret_cast<const hstring *>(&singleton)));
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
struct produce<D, Windows::Globalization::ILanguageFactory> : produce_base<D, Windows::Globalization::ILanguageFactory>
{
    HRESULT __stdcall abi_CreateLanguage(abi_arg_in<hstring> languageTag, abi_arg_out<Windows::Globalization::ILanguage> result) noexcept override
    {
        try
        {
            *result = detach(shim().CreateLanguage(*reinterpret_cast<const hstring *>(&languageTag)));
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
struct produce<D, Windows::Globalization::ILanguageStatics> : produce_base<D, Windows::Globalization::ILanguageStatics>
{
    HRESULT __stdcall abi_IsWellFormed(abi_arg_in<hstring> languageTag, bool * result) noexcept override
    {
        try
        {
            *result = detach(shim().IsWellFormed(*reinterpret_cast<const hstring *>(&languageTag)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentInputMethodLanguageTag(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().CurrentInputMethodLanguageTag());
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
struct produce<D, Windows::Globalization::ILanguageStatics2> : produce_base<D, Windows::Globalization::ILanguageStatics2>
{
    HRESULT __stdcall abi_TrySetInputMethodLanguageTag(abi_arg_in<hstring> languageTag, bool * result) noexcept override
    {
        try
        {
            *result = detach(shim().TrySetInputMethodLanguageTag(*reinterpret_cast<const hstring *>(&languageTag)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::INumeralSystemIdentifiersStatics> : produce_base<D, Windows::Globalization::INumeralSystemIdentifiersStatics>
{
    HRESULT __stdcall get_Arab(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Arab());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ArabExt(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ArabExt());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bali(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Bali());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Beng(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Beng());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cham(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Cham());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Deva(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Deva());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FullWide(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().FullWide());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gujr(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Gujr());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Guru(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Guru());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HaniDec(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().HaniDec());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Java(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Java());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kali(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Kali());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Khmr(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Khmr());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Knda(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Knda());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Lana(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Lana());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LanaTham(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().LanaTham());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Laoo(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Laoo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Latn(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Latn());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Lepc(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Lepc());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Limb(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Limb());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mlym(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Mlym());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mong(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Mong());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mtei(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Mtei());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mymr(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Mymr());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MymrShan(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MymrShan());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Nkoo(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Nkoo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Olck(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Olck());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Orya(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Orya());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Saur(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Saur());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Sund(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Sund());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Talu(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Talu());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TamlDec(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().TamlDec());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Telu(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Telu());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thai(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Thai());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tibt(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Tibt());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Vaii(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Vaii());
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
struct produce<D, Windows::Globalization::INumeralSystemIdentifiersStatics2> : produce_base<D, Windows::Globalization::INumeralSystemIdentifiersStatics2>
{
    HRESULT __stdcall get_Brah(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Brah());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Osma(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().Osma());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MathBold(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MathBold());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MathDbl(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MathDbl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MathSans(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MathSans());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MathSanb(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MathSanb());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MathMono(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().MathMono());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZmthBold(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ZmthBold());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZmthDbl(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ZmthDbl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZmthSans(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ZmthSans());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZmthSanb(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ZmthSanb());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZmthMono(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().ZmthMono());
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
struct produce<D, Windows::Globalization::ITimeZoneOnCalendar> : produce_base<D, Windows::Globalization::ITimeZoneOnCalendar>
{
    HRESULT __stdcall abi_GetTimeZone(abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            *value = detach(shim().GetTimeZone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangeTimeZone(abi_arg_in<hstring> timeZoneId) noexcept override
    {
        try
        {
            shim().ChangeTimeZone(*reinterpret_cast<const hstring *>(&timeZoneId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TimeZoneAsFullString(abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().TimeZoneAsString());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TimeZoneAsString(int32_t idealLength, abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            *result = detach(shim().TimeZoneAsString(idealLength));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Globalization {

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Gregorian() const
{
    hstring value;
    check_hresult(shim()->get_Gregorian(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Hebrew() const
{
    hstring value;
    check_hresult(shim()->get_Hebrew(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Hijri() const
{
    hstring value;
    check_hresult(shim()->get_Hijri(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Japanese() const
{
    hstring value;
    check_hresult(shim()->get_Japanese(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Julian() const
{
    hstring value;
    check_hresult(shim()->get_Julian(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Korean() const
{
    hstring value;
    check_hresult(shim()->get_Korean(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Taiwan() const
{
    hstring value;
    check_hresult(shim()->get_Taiwan(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::Thai() const
{
    hstring value;
    check_hresult(shim()->get_Thai(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics<D>::UmAlQura() const
{
    hstring value;
    check_hresult(shim()->get_UmAlQura(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics2<D>::Persian() const
{
    hstring value;
    check_hresult(shim()->get_Persian(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics3<D>::ChineseLunar() const
{
    hstring value;
    check_hresult(shim()->get_ChineseLunar(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics3<D>::JapaneseLunar() const
{
    hstring value;
    check_hresult(shim()->get_JapaneseLunar(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics3<D>::KoreanLunar() const
{
    hstring value;
    check_hresult(shim()->get_KoreanLunar(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics3<D>::TaiwanLunar() const
{
    hstring value;
    check_hresult(shim()->get_TaiwanLunar(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendarIdentifiersStatics3<D>::VietnameseLunar() const
{
    hstring value;
    check_hresult(shim()->get_VietnameseLunar(put(value)));
    return value;
}

template <typename D> hstring impl_IClockIdentifiersStatics<D>::TwelveHour() const
{
    hstring value;
    check_hresult(shim()->get_TwelveHour(put(value)));
    return value;
}

template <typename D> hstring impl_IClockIdentifiersStatics<D>::TwentyFourHour() const
{
    hstring value;
    check_hresult(shim()->get_TwentyFourHour(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Arab() const
{
    hstring value;
    check_hresult(shim()->get_Arab(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::ArabExt() const
{
    hstring value;
    check_hresult(shim()->get_ArabExt(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Bali() const
{
    hstring value;
    check_hresult(shim()->get_Bali(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Beng() const
{
    hstring value;
    check_hresult(shim()->get_Beng(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Cham() const
{
    hstring value;
    check_hresult(shim()->get_Cham(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Deva() const
{
    hstring value;
    check_hresult(shim()->get_Deva(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::FullWide() const
{
    hstring value;
    check_hresult(shim()->get_FullWide(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Gujr() const
{
    hstring value;
    check_hresult(shim()->get_Gujr(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Guru() const
{
    hstring value;
    check_hresult(shim()->get_Guru(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::HaniDec() const
{
    hstring value;
    check_hresult(shim()->get_HaniDec(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Java() const
{
    hstring value;
    check_hresult(shim()->get_Java(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Kali() const
{
    hstring value;
    check_hresult(shim()->get_Kali(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Khmr() const
{
    hstring value;
    check_hresult(shim()->get_Khmr(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Knda() const
{
    hstring value;
    check_hresult(shim()->get_Knda(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Lana() const
{
    hstring value;
    check_hresult(shim()->get_Lana(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::LanaTham() const
{
    hstring value;
    check_hresult(shim()->get_LanaTham(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Laoo() const
{
    hstring value;
    check_hresult(shim()->get_Laoo(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Latn() const
{
    hstring value;
    check_hresult(shim()->get_Latn(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Lepc() const
{
    hstring value;
    check_hresult(shim()->get_Lepc(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Limb() const
{
    hstring value;
    check_hresult(shim()->get_Limb(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Mlym() const
{
    hstring value;
    check_hresult(shim()->get_Mlym(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Mong() const
{
    hstring value;
    check_hresult(shim()->get_Mong(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Mtei() const
{
    hstring value;
    check_hresult(shim()->get_Mtei(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Mymr() const
{
    hstring value;
    check_hresult(shim()->get_Mymr(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::MymrShan() const
{
    hstring value;
    check_hresult(shim()->get_MymrShan(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Nkoo() const
{
    hstring value;
    check_hresult(shim()->get_Nkoo(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Olck() const
{
    hstring value;
    check_hresult(shim()->get_Olck(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Orya() const
{
    hstring value;
    check_hresult(shim()->get_Orya(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Saur() const
{
    hstring value;
    check_hresult(shim()->get_Saur(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Sund() const
{
    hstring value;
    check_hresult(shim()->get_Sund(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Talu() const
{
    hstring value;
    check_hresult(shim()->get_Talu(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::TamlDec() const
{
    hstring value;
    check_hresult(shim()->get_TamlDec(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Telu() const
{
    hstring value;
    check_hresult(shim()->get_Telu(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Thai() const
{
    hstring value;
    check_hresult(shim()->get_Thai(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Tibt() const
{
    hstring value;
    check_hresult(shim()->get_Tibt(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics<D>::Vaii() const
{
    hstring value;
    check_hresult(shim()->get_Vaii(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::Brah() const
{
    hstring value;
    check_hresult(shim()->get_Brah(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::Osma() const
{
    hstring value;
    check_hresult(shim()->get_Osma(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::MathBold() const
{
    hstring value;
    check_hresult(shim()->get_MathBold(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::MathDbl() const
{
    hstring value;
    check_hresult(shim()->get_MathDbl(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::MathSans() const
{
    hstring value;
    check_hresult(shim()->get_MathSans(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::MathSanb() const
{
    hstring value;
    check_hresult(shim()->get_MathSanb(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::MathMono() const
{
    hstring value;
    check_hresult(shim()->get_MathMono(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::ZmthBold() const
{
    hstring value;
    check_hresult(shim()->get_ZmthBold(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::ZmthDbl() const
{
    hstring value;
    check_hresult(shim()->get_ZmthDbl(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::ZmthSans() const
{
    hstring value;
    check_hresult(shim()->get_ZmthSans(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::ZmthSanb() const
{
    hstring value;
    check_hresult(shim()->get_ZmthSanb(put(value)));
    return value;
}

template <typename D> hstring impl_INumeralSystemIdentifiersStatics2<D>::ZmthMono() const
{
    hstring value;
    check_hresult(shim()->get_ZmthMono(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AED() const
{
    hstring value;
    check_hresult(shim()->get_AED(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AFN() const
{
    hstring value;
    check_hresult(shim()->get_AFN(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ALL() const
{
    hstring value;
    check_hresult(shim()->get_ALL(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AMD() const
{
    hstring value;
    check_hresult(shim()->get_AMD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ANG() const
{
    hstring value;
    check_hresult(shim()->get_ANG(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AOA() const
{
    hstring value;
    check_hresult(shim()->get_AOA(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ARS() const
{
    hstring value;
    check_hresult(shim()->get_ARS(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AUD() const
{
    hstring value;
    check_hresult(shim()->get_AUD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AWG() const
{
    hstring value;
    check_hresult(shim()->get_AWG(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::AZN() const
{
    hstring value;
    check_hresult(shim()->get_AZN(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BAM() const
{
    hstring value;
    check_hresult(shim()->get_BAM(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BBD() const
{
    hstring value;
    check_hresult(shim()->get_BBD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BDT() const
{
    hstring value;
    check_hresult(shim()->get_BDT(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BGN() const
{
    hstring value;
    check_hresult(shim()->get_BGN(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BHD() const
{
    hstring value;
    check_hresult(shim()->get_BHD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BIF() const
{
    hstring value;
    check_hresult(shim()->get_BIF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BMD() const
{
    hstring value;
    check_hresult(shim()->get_BMD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BND() const
{
    hstring value;
    check_hresult(shim()->get_BND(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BOB() const
{
    hstring value;
    check_hresult(shim()->get_BOB(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BRL() const
{
    hstring value;
    check_hresult(shim()->get_BRL(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BSD() const
{
    hstring value;
    check_hresult(shim()->get_BSD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BTN() const
{
    hstring value;
    check_hresult(shim()->get_BTN(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BWP() const
{
    hstring value;
    check_hresult(shim()->get_BWP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BYR() const
{
    hstring value;
    check_hresult(shim()->get_BYR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::BZD() const
{
    hstring value;
    check_hresult(shim()->get_BZD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CAD() const
{
    hstring value;
    check_hresult(shim()->get_CAD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CDF() const
{
    hstring value;
    check_hresult(shim()->get_CDF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CHF() const
{
    hstring value;
    check_hresult(shim()->get_CHF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CLP() const
{
    hstring value;
    check_hresult(shim()->get_CLP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CNY() const
{
    hstring value;
    check_hresult(shim()->get_CNY(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::COP() const
{
    hstring value;
    check_hresult(shim()->get_COP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CRC() const
{
    hstring value;
    check_hresult(shim()->get_CRC(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CUP() const
{
    hstring value;
    check_hresult(shim()->get_CUP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CVE() const
{
    hstring value;
    check_hresult(shim()->get_CVE(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::CZK() const
{
    hstring value;
    check_hresult(shim()->get_CZK(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::DJF() const
{
    hstring value;
    check_hresult(shim()->get_DJF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::DKK() const
{
    hstring value;
    check_hresult(shim()->get_DKK(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::DOP() const
{
    hstring value;
    check_hresult(shim()->get_DOP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::DZD() const
{
    hstring value;
    check_hresult(shim()->get_DZD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::EGP() const
{
    hstring value;
    check_hresult(shim()->get_EGP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ERN() const
{
    hstring value;
    check_hresult(shim()->get_ERN(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ETB() const
{
    hstring value;
    check_hresult(shim()->get_ETB(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::EUR() const
{
    hstring value;
    check_hresult(shim()->get_EUR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::FJD() const
{
    hstring value;
    check_hresult(shim()->get_FJD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::FKP() const
{
    hstring value;
    check_hresult(shim()->get_FKP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GBP() const
{
    hstring value;
    check_hresult(shim()->get_GBP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GEL() const
{
    hstring value;
    check_hresult(shim()->get_GEL(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GHS() const
{
    hstring value;
    check_hresult(shim()->get_GHS(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GIP() const
{
    hstring value;
    check_hresult(shim()->get_GIP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GMD() const
{
    hstring value;
    check_hresult(shim()->get_GMD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GNF() const
{
    hstring value;
    check_hresult(shim()->get_GNF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GTQ() const
{
    hstring value;
    check_hresult(shim()->get_GTQ(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::GYD() const
{
    hstring value;
    check_hresult(shim()->get_GYD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::HKD() const
{
    hstring value;
    check_hresult(shim()->get_HKD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::HNL() const
{
    hstring value;
    check_hresult(shim()->get_HNL(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::HRK() const
{
    hstring value;
    check_hresult(shim()->get_HRK(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::HTG() const
{
    hstring value;
    check_hresult(shim()->get_HTG(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::HUF() const
{
    hstring value;
    check_hresult(shim()->get_HUF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::IDR() const
{
    hstring value;
    check_hresult(shim()->get_IDR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ILS() const
{
    hstring value;
    check_hresult(shim()->get_ILS(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::INR() const
{
    hstring value;
    check_hresult(shim()->get_INR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::IQD() const
{
    hstring value;
    check_hresult(shim()->get_IQD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::IRR() const
{
    hstring value;
    check_hresult(shim()->get_IRR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ISK() const
{
    hstring value;
    check_hresult(shim()->get_ISK(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::JMD() const
{
    hstring value;
    check_hresult(shim()->get_JMD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::JOD() const
{
    hstring value;
    check_hresult(shim()->get_JOD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::JPY() const
{
    hstring value;
    check_hresult(shim()->get_JPY(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KES() const
{
    hstring value;
    check_hresult(shim()->get_KES(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KGS() const
{
    hstring value;
    check_hresult(shim()->get_KGS(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KHR() const
{
    hstring value;
    check_hresult(shim()->get_KHR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KMF() const
{
    hstring value;
    check_hresult(shim()->get_KMF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KPW() const
{
    hstring value;
    check_hresult(shim()->get_KPW(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KRW() const
{
    hstring value;
    check_hresult(shim()->get_KRW(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KWD() const
{
    hstring value;
    check_hresult(shim()->get_KWD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KYD() const
{
    hstring value;
    check_hresult(shim()->get_KYD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::KZT() const
{
    hstring value;
    check_hresult(shim()->get_KZT(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LAK() const
{
    hstring value;
    check_hresult(shim()->get_LAK(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LBP() const
{
    hstring value;
    check_hresult(shim()->get_LBP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LKR() const
{
    hstring value;
    check_hresult(shim()->get_LKR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LRD() const
{
    hstring value;
    check_hresult(shim()->get_LRD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LSL() const
{
    hstring value;
    check_hresult(shim()->get_LSL(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LTL() const
{
    hstring value;
    check_hresult(shim()->get_LTL(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LVL() const
{
    hstring value;
    check_hresult(shim()->get_LVL(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::LYD() const
{
    hstring value;
    check_hresult(shim()->get_LYD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MAD() const
{
    hstring value;
    check_hresult(shim()->get_MAD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MDL() const
{
    hstring value;
    check_hresult(shim()->get_MDL(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MGA() const
{
    hstring value;
    check_hresult(shim()->get_MGA(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MKD() const
{
    hstring value;
    check_hresult(shim()->get_MKD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MMK() const
{
    hstring value;
    check_hresult(shim()->get_MMK(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MNT() const
{
    hstring value;
    check_hresult(shim()->get_MNT(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MOP() const
{
    hstring value;
    check_hresult(shim()->get_MOP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MRO() const
{
    hstring value;
    check_hresult(shim()->get_MRO(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MUR() const
{
    hstring value;
    check_hresult(shim()->get_MUR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MVR() const
{
    hstring value;
    check_hresult(shim()->get_MVR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MWK() const
{
    hstring value;
    check_hresult(shim()->get_MWK(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MXN() const
{
    hstring value;
    check_hresult(shim()->get_MXN(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MYR() const
{
    hstring value;
    check_hresult(shim()->get_MYR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::MZN() const
{
    hstring value;
    check_hresult(shim()->get_MZN(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NAD() const
{
    hstring value;
    check_hresult(shim()->get_NAD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NGN() const
{
    hstring value;
    check_hresult(shim()->get_NGN(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NIO() const
{
    hstring value;
    check_hresult(shim()->get_NIO(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NOK() const
{
    hstring value;
    check_hresult(shim()->get_NOK(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NPR() const
{
    hstring value;
    check_hresult(shim()->get_NPR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::NZD() const
{
    hstring value;
    check_hresult(shim()->get_NZD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::OMR() const
{
    hstring value;
    check_hresult(shim()->get_OMR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PAB() const
{
    hstring value;
    check_hresult(shim()->get_PAB(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PEN() const
{
    hstring value;
    check_hresult(shim()->get_PEN(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PGK() const
{
    hstring value;
    check_hresult(shim()->get_PGK(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PHP() const
{
    hstring value;
    check_hresult(shim()->get_PHP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PKR() const
{
    hstring value;
    check_hresult(shim()->get_PKR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PLN() const
{
    hstring value;
    check_hresult(shim()->get_PLN(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::PYG() const
{
    hstring value;
    check_hresult(shim()->get_PYG(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::QAR() const
{
    hstring value;
    check_hresult(shim()->get_QAR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::RON() const
{
    hstring value;
    check_hresult(shim()->get_RON(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::RSD() const
{
    hstring value;
    check_hresult(shim()->get_RSD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::RUB() const
{
    hstring value;
    check_hresult(shim()->get_RUB(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::RWF() const
{
    hstring value;
    check_hresult(shim()->get_RWF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SAR() const
{
    hstring value;
    check_hresult(shim()->get_SAR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SBD() const
{
    hstring value;
    check_hresult(shim()->get_SBD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SCR() const
{
    hstring value;
    check_hresult(shim()->get_SCR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SDG() const
{
    hstring value;
    check_hresult(shim()->get_SDG(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SEK() const
{
    hstring value;
    check_hresult(shim()->get_SEK(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SGD() const
{
    hstring value;
    check_hresult(shim()->get_SGD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SHP() const
{
    hstring value;
    check_hresult(shim()->get_SHP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SLL() const
{
    hstring value;
    check_hresult(shim()->get_SLL(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SOS() const
{
    hstring value;
    check_hresult(shim()->get_SOS(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SRD() const
{
    hstring value;
    check_hresult(shim()->get_SRD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::STD() const
{
    hstring value;
    check_hresult(shim()->get_STD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SYP() const
{
    hstring value;
    check_hresult(shim()->get_SYP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::SZL() const
{
    hstring value;
    check_hresult(shim()->get_SZL(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::THB() const
{
    hstring value;
    check_hresult(shim()->get_THB(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TJS() const
{
    hstring value;
    check_hresult(shim()->get_TJS(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TMT() const
{
    hstring value;
    check_hresult(shim()->get_TMT(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TND() const
{
    hstring value;
    check_hresult(shim()->get_TND(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TOP() const
{
    hstring value;
    check_hresult(shim()->get_TOP(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TRY() const
{
    hstring value;
    check_hresult(shim()->get_TRY(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TTD() const
{
    hstring value;
    check_hresult(shim()->get_TTD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TWD() const
{
    hstring value;
    check_hresult(shim()->get_TWD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::TZS() const
{
    hstring value;
    check_hresult(shim()->get_TZS(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::UAH() const
{
    hstring value;
    check_hresult(shim()->get_UAH(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::UGX() const
{
    hstring value;
    check_hresult(shim()->get_UGX(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::USD() const
{
    hstring value;
    check_hresult(shim()->get_USD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::UYU() const
{
    hstring value;
    check_hresult(shim()->get_UYU(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::UZS() const
{
    hstring value;
    check_hresult(shim()->get_UZS(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::VEF() const
{
    hstring value;
    check_hresult(shim()->get_VEF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::VND() const
{
    hstring value;
    check_hresult(shim()->get_VND(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::VUV() const
{
    hstring value;
    check_hresult(shim()->get_VUV(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::WST() const
{
    hstring value;
    check_hresult(shim()->get_WST(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::XAF() const
{
    hstring value;
    check_hresult(shim()->get_XAF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::XCD() const
{
    hstring value;
    check_hresult(shim()->get_XCD(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::XOF() const
{
    hstring value;
    check_hresult(shim()->get_XOF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::XPF() const
{
    hstring value;
    check_hresult(shim()->get_XPF(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::XXX() const
{
    hstring value;
    check_hresult(shim()->get_XXX(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::YER() const
{
    hstring value;
    check_hresult(shim()->get_YER(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ZAR() const
{
    hstring value;
    check_hresult(shim()->get_ZAR(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ZMW() const
{
    hstring value;
    check_hresult(shim()->get_ZMW(put(value)));
    return value;
}

template <typename D> hstring impl_ICurrencyIdentifiersStatics<D>::ZWL() const
{
    hstring value;
    check_hresult(shim()->get_ZWL(put(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::Code() const
{
    hstring value;
    check_hresult(shim()->get_Code(put(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::CodeTwoLetter() const
{
    hstring value;
    check_hresult(shim()->get_CodeTwoLetter(put(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::CodeThreeLetter() const
{
    hstring value;
    check_hresult(shim()->get_CodeThreeLetter(put(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::CodeThreeDigit() const
{
    hstring value;
    check_hresult(shim()->get_CodeThreeDigit(put(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::DisplayName() const
{
    hstring value;
    check_hresult(shim()->get_DisplayName(put(value)));
    return value;
}

template <typename D> hstring impl_IGeographicRegion<D>::NativeName() const
{
    hstring value;
    check_hresult(shim()->get_NativeName(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IGeographicRegion<D>::CurrenciesInUse() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(shim()->get_CurrenciesInUse(put(value)));
    return value;
}

template <typename D> Windows::Globalization::GeographicRegion impl_IGeographicRegionFactory<D>::CreateGeographicRegion(hstring_ref geographicRegionCode) const
{
    Windows::Globalization::GeographicRegion result { nullptr };
    check_hresult(shim()->abi_CreateGeographicRegion(get(geographicRegionCode), put(result)));
    return result;
}

template <typename D> bool impl_IGeographicRegionStatics<D>::IsSupported(hstring_ref geographicRegionCode) const
{
    bool result {};
    check_hresult(shim()->abi_IsSupported(get(geographicRegionCode), &result));
    return result;
}

template <typename D> hstring impl_ILanguage<D>::LanguageTag() const
{
    hstring value;
    check_hresult(shim()->get_LanguageTag(put(value)));
    return value;
}

template <typename D> hstring impl_ILanguage<D>::DisplayName() const
{
    hstring value;
    check_hresult(shim()->get_DisplayName(put(value)));
    return value;
}

template <typename D> hstring impl_ILanguage<D>::NativeName() const
{
    hstring value;
    check_hresult(shim()->get_NativeName(put(value)));
    return value;
}

template <typename D> hstring impl_ILanguage<D>::Script() const
{
    hstring value;
    check_hresult(shim()->get_Script(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ILanguageExtensionSubtags<D>::GetExtensionSubtags(hstring_ref singleton) const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(shim()->abi_GetExtensionSubtags(get(singleton), put(value)));
    return value;
}

template <typename D> Windows::Globalization::Language impl_ILanguageFactory<D>::CreateLanguage(hstring_ref languageTag) const
{
    Windows::Globalization::Language result { nullptr };
    check_hresult(shim()->abi_CreateLanguage(get(languageTag), put(result)));
    return result;
}

template <typename D> bool impl_ILanguageStatics<D>::IsWellFormed(hstring_ref languageTag) const
{
    bool result {};
    check_hresult(shim()->abi_IsWellFormed(get(languageTag), &result));
    return result;
}

template <typename D> hstring impl_ILanguageStatics<D>::CurrentInputMethodLanguageTag() const
{
    hstring value;
    check_hresult(shim()->get_CurrentInputMethodLanguageTag(put(value)));
    return value;
}

template <typename D> bool impl_ILanguageStatics2<D>::TrySetInputMethodLanguageTag(hstring_ref languageTag) const
{
    bool result {};
    check_hresult(shim()->abi_TrySetInputMethodLanguageTag(get(languageTag), &result));
    return result;
}

template <typename D> Windows::Globalization::Calendar impl_ICalendar<D>::Clone() const
{
    Windows::Globalization::Calendar value { nullptr };
    check_hresult(shim()->abi_Clone(put(value)));
    return value;
}

template <typename D> void impl_ICalendar<D>::SetToMin() const
{
    check_hresult(shim()->abi_SetToMin());
}

template <typename D> void impl_ICalendar<D>::SetToMax() const
{
    check_hresult(shim()->abi_SetToMax());
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ICalendar<D>::Languages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(shim()->get_Languages(put(value)));
    return value;
}

template <typename D> hstring impl_ICalendar<D>::NumeralSystem() const
{
    hstring value;
    check_hresult(shim()->get_NumeralSystem(put(value)));
    return value;
}

template <typename D> void impl_ICalendar<D>::NumeralSystem(hstring_ref value) const
{
    check_hresult(shim()->put_NumeralSystem(get(value)));
}

template <typename D> hstring impl_ICalendar<D>::GetCalendarSystem() const
{
    hstring value;
    check_hresult(shim()->abi_GetCalendarSystem(put(value)));
    return value;
}

template <typename D> void impl_ICalendar<D>::ChangeCalendarSystem(hstring_ref value) const
{
    check_hresult(shim()->abi_ChangeCalendarSystem(get(value)));
}

template <typename D> hstring impl_ICalendar<D>::GetClock() const
{
    hstring value;
    check_hresult(shim()->abi_GetClock(put(value)));
    return value;
}

template <typename D> void impl_ICalendar<D>::ChangeClock(hstring_ref value) const
{
    check_hresult(shim()->abi_ChangeClock(get(value)));
}

template <typename D> Windows::Foundation::DateTime impl_ICalendar<D>::GetDateTime() const
{
    Windows::Foundation::DateTime result {};
    check_hresult(shim()->abi_GetDateTime(put(result)));
    return result;
}

template <typename D> void impl_ICalendar<D>::SetDateTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(shim()->abi_SetDateTime(get(value)));
}

template <typename D> void impl_ICalendar<D>::SetToNow() const
{
    check_hresult(shim()->abi_SetToNow());
}

template <typename D> int32_t impl_ICalendar<D>::FirstEra() const
{
    int32_t value {};
    check_hresult(shim()->get_FirstEra(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastEra() const
{
    int32_t value {};
    check_hresult(shim()->get_LastEra(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfEras() const
{
    int32_t value {};
    check_hresult(shim()->get_NumberOfEras(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Era() const
{
    int32_t value {};
    check_hresult(shim()->get_Era(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Era(int32_t value) const
{
    check_hresult(shim()->put_Era(value));
}

template <typename D> void impl_ICalendar<D>::AddEras(int32_t eras) const
{
    check_hresult(shim()->abi_AddEras(eras));
}

template <typename D> hstring impl_ICalendar<D>::EraAsString() const
{
    hstring result;
    check_hresult(shim()->abi_EraAsFullString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::EraAsString(int32_t idealLength) const
{
    hstring result;
    check_hresult(shim()->abi_EraAsString(idealLength, put(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::FirstYearInThisEra() const
{
    int32_t value {};
    check_hresult(shim()->get_FirstYearInThisEra(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastYearInThisEra() const
{
    int32_t value {};
    check_hresult(shim()->get_LastYearInThisEra(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfYearsInThisEra() const
{
    int32_t value {};
    check_hresult(shim()->get_NumberOfYearsInThisEra(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Year() const
{
    int32_t value {};
    check_hresult(shim()->get_Year(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Year(int32_t value) const
{
    check_hresult(shim()->put_Year(value));
}

template <typename D> void impl_ICalendar<D>::AddYears(int32_t years) const
{
    check_hresult(shim()->abi_AddYears(years));
}

template <typename D> hstring impl_ICalendar<D>::YearAsString() const
{
    hstring result;
    check_hresult(shim()->abi_YearAsString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::YearAsTruncatedString(int32_t remainingDigits) const
{
    hstring result;
    check_hresult(shim()->abi_YearAsTruncatedString(remainingDigits, put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::YearAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(shim()->abi_YearAsPaddedString(minDigits, put(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::FirstMonthInThisYear() const
{
    int32_t value {};
    check_hresult(shim()->get_FirstMonthInThisYear(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastMonthInThisYear() const
{
    int32_t value {};
    check_hresult(shim()->get_LastMonthInThisYear(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfMonthsInThisYear() const
{
    int32_t value {};
    check_hresult(shim()->get_NumberOfMonthsInThisYear(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Month() const
{
    int32_t value {};
    check_hresult(shim()->get_Month(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Month(int32_t value) const
{
    check_hresult(shim()->put_Month(value));
}

template <typename D> void impl_ICalendar<D>::AddMonths(int32_t months) const
{
    check_hresult(shim()->abi_AddMonths(months));
}

template <typename D> hstring impl_ICalendar<D>::MonthAsString() const
{
    hstring result;
    check_hresult(shim()->abi_MonthAsFullString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MonthAsString(int32_t idealLength) const
{
    hstring result;
    check_hresult(shim()->abi_MonthAsString(idealLength, put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MonthAsSoloString() const
{
    hstring result;
    check_hresult(shim()->abi_MonthAsFullSoloString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MonthAsSoloString(int32_t idealLength) const
{
    hstring result;
    check_hresult(shim()->abi_MonthAsSoloString(idealLength, put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MonthAsNumericString() const
{
    hstring result;
    check_hresult(shim()->abi_MonthAsNumericString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MonthAsPaddedNumericString(int32_t minDigits) const
{
    hstring result;
    check_hresult(shim()->abi_MonthAsPaddedNumericString(minDigits, put(result)));
    return result;
}

template <typename D> void impl_ICalendar<D>::AddWeeks(int32_t weeks) const
{
    check_hresult(shim()->abi_AddWeeks(weeks));
}

template <typename D> int32_t impl_ICalendar<D>::FirstDayInThisMonth() const
{
    int32_t value {};
    check_hresult(shim()->get_FirstDayInThisMonth(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastDayInThisMonth() const
{
    int32_t value {};
    check_hresult(shim()->get_LastDayInThisMonth(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfDaysInThisMonth() const
{
    int32_t value {};
    check_hresult(shim()->get_NumberOfDaysInThisMonth(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Day() const
{
    int32_t value {};
    check_hresult(shim()->get_Day(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Day(int32_t value) const
{
    check_hresult(shim()->put_Day(value));
}

template <typename D> void impl_ICalendar<D>::AddDays(int32_t days) const
{
    check_hresult(shim()->abi_AddDays(days));
}

template <typename D> hstring impl_ICalendar<D>::DayAsString() const
{
    hstring result;
    check_hresult(shim()->abi_DayAsString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::DayAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(shim()->abi_DayAsPaddedString(minDigits, put(result)));
    return result;
}

template <typename D> Windows::Globalization::DayOfWeek impl_ICalendar<D>::DayOfWeek() const
{
    Windows::Globalization::DayOfWeek value {};
    check_hresult(shim()->get_DayOfWeek(&value));
    return value;
}

template <typename D> hstring impl_ICalendar<D>::DayOfWeekAsString() const
{
    hstring result;
    check_hresult(shim()->abi_DayOfWeekAsFullString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::DayOfWeekAsString(int32_t idealLength) const
{
    hstring result;
    check_hresult(shim()->abi_DayOfWeekAsString(idealLength, put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::DayOfWeekAsSoloString() const
{
    hstring result;
    check_hresult(shim()->abi_DayOfWeekAsFullSoloString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::DayOfWeekAsSoloString(int32_t idealLength) const
{
    hstring result;
    check_hresult(shim()->abi_DayOfWeekAsSoloString(idealLength, put(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::FirstPeriodInThisDay() const
{
    int32_t value {};
    check_hresult(shim()->get_FirstPeriodInThisDay(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastPeriodInThisDay() const
{
    int32_t value {};
    check_hresult(shim()->get_LastPeriodInThisDay(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfPeriodsInThisDay() const
{
    int32_t value {};
    check_hresult(shim()->get_NumberOfPeriodsInThisDay(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Period() const
{
    int32_t value {};
    check_hresult(shim()->get_Period(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Period(int32_t value) const
{
    check_hresult(shim()->put_Period(value));
}

template <typename D> void impl_ICalendar<D>::AddPeriods(int32_t periods) const
{
    check_hresult(shim()->abi_AddPeriods(periods));
}

template <typename D> hstring impl_ICalendar<D>::PeriodAsString() const
{
    hstring result;
    check_hresult(shim()->abi_PeriodAsFullString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::PeriodAsString(int32_t idealLength) const
{
    hstring result;
    check_hresult(shim()->abi_PeriodAsString(idealLength, put(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::FirstHourInThisPeriod() const
{
    int32_t value {};
    check_hresult(shim()->get_FirstHourInThisPeriod(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastHourInThisPeriod() const
{
    int32_t value {};
    check_hresult(shim()->get_LastHourInThisPeriod(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfHoursInThisPeriod() const
{
    int32_t value {};
    check_hresult(shim()->get_NumberOfHoursInThisPeriod(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::Hour() const
{
    int32_t value {};
    check_hresult(shim()->get_Hour(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Hour(int32_t value) const
{
    check_hresult(shim()->put_Hour(value));
}

template <typename D> void impl_ICalendar<D>::AddHours(int32_t hours) const
{
    check_hresult(shim()->abi_AddHours(hours));
}

template <typename D> hstring impl_ICalendar<D>::HourAsString() const
{
    hstring result;
    check_hresult(shim()->abi_HourAsString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::HourAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(shim()->abi_HourAsPaddedString(minDigits, put(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::Minute() const
{
    int32_t value {};
    check_hresult(shim()->get_Minute(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Minute(int32_t value) const
{
    check_hresult(shim()->put_Minute(value));
}

template <typename D> void impl_ICalendar<D>::AddMinutes(int32_t minutes) const
{
    check_hresult(shim()->abi_AddMinutes(minutes));
}

template <typename D> hstring impl_ICalendar<D>::MinuteAsString() const
{
    hstring result;
    check_hresult(shim()->abi_MinuteAsString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::MinuteAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(shim()->abi_MinuteAsPaddedString(minDigits, put(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::Second() const
{
    int32_t value {};
    check_hresult(shim()->get_Second(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Second(int32_t value) const
{
    check_hresult(shim()->put_Second(value));
}

template <typename D> void impl_ICalendar<D>::AddSeconds(int32_t seconds) const
{
    check_hresult(shim()->abi_AddSeconds(seconds));
}

template <typename D> hstring impl_ICalendar<D>::SecondAsString() const
{
    hstring result;
    check_hresult(shim()->abi_SecondAsString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::SecondAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(shim()->abi_SecondAsPaddedString(minDigits, put(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::Nanosecond() const
{
    int32_t value {};
    check_hresult(shim()->get_Nanosecond(&value));
    return value;
}

template <typename D> void impl_ICalendar<D>::Nanosecond(int32_t value) const
{
    check_hresult(shim()->put_Nanosecond(value));
}

template <typename D> void impl_ICalendar<D>::AddNanoseconds(int32_t nanoseconds) const
{
    check_hresult(shim()->abi_AddNanoseconds(nanoseconds));
}

template <typename D> hstring impl_ICalendar<D>::NanosecondAsString() const
{
    hstring result;
    check_hresult(shim()->abi_NanosecondAsString(put(result)));
    return result;
}

template <typename D> hstring impl_ICalendar<D>::NanosecondAsPaddedString(int32_t minDigits) const
{
    hstring result;
    check_hresult(shim()->abi_NanosecondAsPaddedString(minDigits, put(result)));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::Compare(const Windows::Globalization::Calendar & other) const
{
    int32_t result {};
    check_hresult(shim()->abi_Compare(get(other), &result));
    return result;
}

template <typename D> int32_t impl_ICalendar<D>::CompareDateTime(const Windows::Foundation::DateTime & other) const
{
    int32_t result {};
    check_hresult(shim()->abi_CompareDateTime(get(other), &result));
    return result;
}

template <typename D> void impl_ICalendar<D>::CopyTo(const Windows::Globalization::Calendar & other) const
{
    check_hresult(shim()->abi_CopyTo(get(other)));
}

template <typename D> int32_t impl_ICalendar<D>::FirstMinuteInThisHour() const
{
    int32_t value {};
    check_hresult(shim()->get_FirstMinuteInThisHour(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastMinuteInThisHour() const
{
    int32_t value {};
    check_hresult(shim()->get_LastMinuteInThisHour(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfMinutesInThisHour() const
{
    int32_t value {};
    check_hresult(shim()->get_NumberOfMinutesInThisHour(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::FirstSecondInThisMinute() const
{
    int32_t value {};
    check_hresult(shim()->get_FirstSecondInThisMinute(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::LastSecondInThisMinute() const
{
    int32_t value {};
    check_hresult(shim()->get_LastSecondInThisMinute(&value));
    return value;
}

template <typename D> int32_t impl_ICalendar<D>::NumberOfSecondsInThisMinute() const
{
    int32_t value {};
    check_hresult(shim()->get_NumberOfSecondsInThisMinute(&value));
    return value;
}

template <typename D> hstring impl_ICalendar<D>::ResolvedLanguage() const
{
    hstring value;
    check_hresult(shim()->get_ResolvedLanguage(put(value)));
    return value;
}

template <typename D> bool impl_ICalendar<D>::IsDaylightSavingTime() const
{
    bool value {};
    check_hresult(shim()->get_IsDaylightSavingTime(&value));
    return value;
}

template <typename D> Windows::Globalization::Calendar impl_ICalendarFactory2<D>::CreateCalendarWithTimeZone(const Windows::Foundation::Collections::IIterable<hstring> & languages, hstring_ref calendar, hstring_ref clock, hstring_ref timeZoneId) const
{
    Windows::Globalization::Calendar result { nullptr };
    check_hresult(shim()->abi_CreateCalendarWithTimeZone(get(languages), get(calendar), get(clock), get(timeZoneId), put(result)));
    return result;
}

template <typename D> hstring impl_ITimeZoneOnCalendar<D>::GetTimeZone() const
{
    hstring value;
    check_hresult(shim()->abi_GetTimeZone(put(value)));
    return value;
}

template <typename D> void impl_ITimeZoneOnCalendar<D>::ChangeTimeZone(hstring_ref timeZoneId) const
{
    check_hresult(shim()->abi_ChangeTimeZone(get(timeZoneId)));
}

template <typename D> hstring impl_ITimeZoneOnCalendar<D>::TimeZoneAsString() const
{
    hstring result;
    check_hresult(shim()->abi_TimeZoneAsFullString(put(result)));
    return result;
}

template <typename D> hstring impl_ITimeZoneOnCalendar<D>::TimeZoneAsString(int32_t idealLength) const
{
    hstring result;
    check_hresult(shim()->abi_TimeZoneAsString(idealLength, put(result)));
    return result;
}

template <typename D> Windows::Globalization::Calendar impl_ICalendarFactory<D>::CreateCalendarDefaultCalendarAndClock(const Windows::Foundation::Collections::IIterable<hstring> & languages) const
{
    Windows::Globalization::Calendar result { nullptr };
    check_hresult(shim()->abi_CreateCalendarDefaultCalendarAndClock(get(languages), put(result)));
    return result;
}

template <typename D> Windows::Globalization::Calendar impl_ICalendarFactory<D>::CreateCalendar(const Windows::Foundation::Collections::IIterable<hstring> & languages, hstring_ref calendar, hstring_ref clock) const
{
    Windows::Globalization::Calendar result { nullptr };
    check_hresult(shim()->abi_CreateCalendar(get(languages), get(calendar), get(clock), put(result)));
    return result;
}

template <typename D> hstring impl_IApplicationLanguagesStatics<D>::PrimaryLanguageOverride() const
{
    hstring value;
    check_hresult(shim()->get_PrimaryLanguageOverride(put(value)));
    return value;
}

template <typename D> void impl_IApplicationLanguagesStatics<D>::PrimaryLanguageOverride(hstring_ref value) const
{
    check_hresult(shim()->put_PrimaryLanguageOverride(get(value)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IApplicationLanguagesStatics<D>::Languages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(shim()->get_Languages(put(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IApplicationLanguagesStatics<D>::ManifestLanguages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(shim()->get_ManifestLanguages(put(value)));
    return value;
}

inline hstring ApplicationLanguages::PrimaryLanguageOverride()
{
    return GetActivationFactory<ApplicationLanguages, IApplicationLanguagesStatics>().PrimaryLanguageOverride();
}

inline void ApplicationLanguages::PrimaryLanguageOverride(hstring_ref value)
{
    GetActivationFactory<ApplicationLanguages, IApplicationLanguagesStatics>().PrimaryLanguageOverride(value);
}

inline Windows::Foundation::Collections::IVectorView<hstring> ApplicationLanguages::Languages()
{
    return GetActivationFactory<ApplicationLanguages, IApplicationLanguagesStatics>().Languages();
}

inline Windows::Foundation::Collections::IVectorView<hstring> ApplicationLanguages::ManifestLanguages()
{
    return GetActivationFactory<ApplicationLanguages, IApplicationLanguagesStatics>().ManifestLanguages();
}

inline Calendar::Calendar() :
    Calendar(ActivateInstance<Calendar>())
{}

inline Calendar::Calendar(const Windows::Foundation::Collections::IIterable<hstring> & languages) :
    Calendar(GetActivationFactory<Calendar, ICalendarFactory>().CreateCalendarDefaultCalendarAndClock(languages))
{}

inline Calendar::Calendar(const Windows::Foundation::Collections::IIterable<hstring> & languages, hstring_ref calendar, hstring_ref clock) :
    Calendar(GetActivationFactory<Calendar, ICalendarFactory>().CreateCalendar(languages, calendar, clock))
{}

inline Calendar::Calendar(const Windows::Foundation::Collections::IIterable<hstring> & languages, hstring_ref calendar, hstring_ref clock, hstring_ref timeZoneId) :
    Calendar(GetActivationFactory<Calendar, ICalendarFactory2>().CreateCalendarWithTimeZone(languages, calendar, clock, timeZoneId))
{}

inline hstring CalendarIdentifiers::Gregorian()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Gregorian();
}

inline hstring CalendarIdentifiers::Hebrew()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Hebrew();
}

inline hstring CalendarIdentifiers::Hijri()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Hijri();
}

inline hstring CalendarIdentifiers::Japanese()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Japanese();
}

inline hstring CalendarIdentifiers::Julian()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Julian();
}

inline hstring CalendarIdentifiers::Korean()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Korean();
}

inline hstring CalendarIdentifiers::Taiwan()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Taiwan();
}

inline hstring CalendarIdentifiers::Thai()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics>().Thai();
}

inline hstring CalendarIdentifiers::UmAlQura()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics>().UmAlQura();
}

inline hstring CalendarIdentifiers::Persian()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics2>().Persian();
}

inline hstring CalendarIdentifiers::ChineseLunar()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics3>().ChineseLunar();
}

inline hstring CalendarIdentifiers::JapaneseLunar()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics3>().JapaneseLunar();
}

inline hstring CalendarIdentifiers::KoreanLunar()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics3>().KoreanLunar();
}

inline hstring CalendarIdentifiers::TaiwanLunar()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics3>().TaiwanLunar();
}

inline hstring CalendarIdentifiers::VietnameseLunar()
{
    return GetActivationFactory<CalendarIdentifiers, ICalendarIdentifiersStatics3>().VietnameseLunar();
}

inline hstring ClockIdentifiers::TwelveHour()
{
    return GetActivationFactory<ClockIdentifiers, IClockIdentifiersStatics>().TwelveHour();
}

inline hstring ClockIdentifiers::TwentyFourHour()
{
    return GetActivationFactory<ClockIdentifiers, IClockIdentifiersStatics>().TwentyFourHour();
}

inline hstring CurrencyIdentifiers::AED()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AED();
}

inline hstring CurrencyIdentifiers::AFN()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AFN();
}

inline hstring CurrencyIdentifiers::ALL()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ALL();
}

inline hstring CurrencyIdentifiers::AMD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AMD();
}

inline hstring CurrencyIdentifiers::ANG()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ANG();
}

inline hstring CurrencyIdentifiers::AOA()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AOA();
}

inline hstring CurrencyIdentifiers::ARS()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ARS();
}

inline hstring CurrencyIdentifiers::AUD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AUD();
}

inline hstring CurrencyIdentifiers::AWG()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AWG();
}

inline hstring CurrencyIdentifiers::AZN()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().AZN();
}

inline hstring CurrencyIdentifiers::BAM()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BAM();
}

inline hstring CurrencyIdentifiers::BBD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BBD();
}

inline hstring CurrencyIdentifiers::BDT()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BDT();
}

inline hstring CurrencyIdentifiers::BGN()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BGN();
}

inline hstring CurrencyIdentifiers::BHD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BHD();
}

inline hstring CurrencyIdentifiers::BIF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BIF();
}

inline hstring CurrencyIdentifiers::BMD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BMD();
}

inline hstring CurrencyIdentifiers::BND()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BND();
}

inline hstring CurrencyIdentifiers::BOB()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BOB();
}

inline hstring CurrencyIdentifiers::BRL()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BRL();
}

inline hstring CurrencyIdentifiers::BSD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BSD();
}

inline hstring CurrencyIdentifiers::BTN()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BTN();
}

inline hstring CurrencyIdentifiers::BWP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BWP();
}

inline hstring CurrencyIdentifiers::BYR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BYR();
}

inline hstring CurrencyIdentifiers::BZD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().BZD();
}

inline hstring CurrencyIdentifiers::CAD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CAD();
}

inline hstring CurrencyIdentifiers::CDF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CDF();
}

inline hstring CurrencyIdentifiers::CHF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CHF();
}

inline hstring CurrencyIdentifiers::CLP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CLP();
}

inline hstring CurrencyIdentifiers::CNY()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CNY();
}

inline hstring CurrencyIdentifiers::COP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().COP();
}

inline hstring CurrencyIdentifiers::CRC()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CRC();
}

inline hstring CurrencyIdentifiers::CUP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CUP();
}

inline hstring CurrencyIdentifiers::CVE()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CVE();
}

inline hstring CurrencyIdentifiers::CZK()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().CZK();
}

inline hstring CurrencyIdentifiers::DJF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().DJF();
}

inline hstring CurrencyIdentifiers::DKK()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().DKK();
}

inline hstring CurrencyIdentifiers::DOP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().DOP();
}

inline hstring CurrencyIdentifiers::DZD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().DZD();
}

inline hstring CurrencyIdentifiers::EGP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().EGP();
}

inline hstring CurrencyIdentifiers::ERN()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ERN();
}

inline hstring CurrencyIdentifiers::ETB()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ETB();
}

inline hstring CurrencyIdentifiers::EUR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().EUR();
}

inline hstring CurrencyIdentifiers::FJD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().FJD();
}

inline hstring CurrencyIdentifiers::FKP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().FKP();
}

inline hstring CurrencyIdentifiers::GBP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GBP();
}

inline hstring CurrencyIdentifiers::GEL()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GEL();
}

inline hstring CurrencyIdentifiers::GHS()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GHS();
}

inline hstring CurrencyIdentifiers::GIP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GIP();
}

inline hstring CurrencyIdentifiers::GMD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GMD();
}

inline hstring CurrencyIdentifiers::GNF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GNF();
}

inline hstring CurrencyIdentifiers::GTQ()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GTQ();
}

inline hstring CurrencyIdentifiers::GYD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().GYD();
}

inline hstring CurrencyIdentifiers::HKD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().HKD();
}

inline hstring CurrencyIdentifiers::HNL()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().HNL();
}

inline hstring CurrencyIdentifiers::HRK()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().HRK();
}

inline hstring CurrencyIdentifiers::HTG()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().HTG();
}

inline hstring CurrencyIdentifiers::HUF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().HUF();
}

inline hstring CurrencyIdentifiers::IDR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().IDR();
}

inline hstring CurrencyIdentifiers::ILS()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ILS();
}

inline hstring CurrencyIdentifiers::INR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().INR();
}

inline hstring CurrencyIdentifiers::IQD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().IQD();
}

inline hstring CurrencyIdentifiers::IRR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().IRR();
}

inline hstring CurrencyIdentifiers::ISK()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ISK();
}

inline hstring CurrencyIdentifiers::JMD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().JMD();
}

inline hstring CurrencyIdentifiers::JOD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().JOD();
}

inline hstring CurrencyIdentifiers::JPY()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().JPY();
}

inline hstring CurrencyIdentifiers::KES()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KES();
}

inline hstring CurrencyIdentifiers::KGS()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KGS();
}

inline hstring CurrencyIdentifiers::KHR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KHR();
}

inline hstring CurrencyIdentifiers::KMF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KMF();
}

inline hstring CurrencyIdentifiers::KPW()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KPW();
}

inline hstring CurrencyIdentifiers::KRW()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KRW();
}

inline hstring CurrencyIdentifiers::KWD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KWD();
}

inline hstring CurrencyIdentifiers::KYD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KYD();
}

inline hstring CurrencyIdentifiers::KZT()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().KZT();
}

inline hstring CurrencyIdentifiers::LAK()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LAK();
}

inline hstring CurrencyIdentifiers::LBP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LBP();
}

inline hstring CurrencyIdentifiers::LKR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LKR();
}

inline hstring CurrencyIdentifiers::LRD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LRD();
}

inline hstring CurrencyIdentifiers::LSL()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LSL();
}

inline hstring CurrencyIdentifiers::LTL()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LTL();
}

inline hstring CurrencyIdentifiers::LVL()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LVL();
}

inline hstring CurrencyIdentifiers::LYD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().LYD();
}

inline hstring CurrencyIdentifiers::MAD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MAD();
}

inline hstring CurrencyIdentifiers::MDL()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MDL();
}

inline hstring CurrencyIdentifiers::MGA()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MGA();
}

inline hstring CurrencyIdentifiers::MKD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MKD();
}

inline hstring CurrencyIdentifiers::MMK()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MMK();
}

inline hstring CurrencyIdentifiers::MNT()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MNT();
}

inline hstring CurrencyIdentifiers::MOP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MOP();
}

inline hstring CurrencyIdentifiers::MRO()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MRO();
}

inline hstring CurrencyIdentifiers::MUR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MUR();
}

inline hstring CurrencyIdentifiers::MVR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MVR();
}

inline hstring CurrencyIdentifiers::MWK()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MWK();
}

inline hstring CurrencyIdentifiers::MXN()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MXN();
}

inline hstring CurrencyIdentifiers::MYR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MYR();
}

inline hstring CurrencyIdentifiers::MZN()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().MZN();
}

inline hstring CurrencyIdentifiers::NAD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NAD();
}

inline hstring CurrencyIdentifiers::NGN()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NGN();
}

inline hstring CurrencyIdentifiers::NIO()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NIO();
}

inline hstring CurrencyIdentifiers::NOK()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NOK();
}

inline hstring CurrencyIdentifiers::NPR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NPR();
}

inline hstring CurrencyIdentifiers::NZD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().NZD();
}

inline hstring CurrencyIdentifiers::OMR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().OMR();
}

inline hstring CurrencyIdentifiers::PAB()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PAB();
}

inline hstring CurrencyIdentifiers::PEN()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PEN();
}

inline hstring CurrencyIdentifiers::PGK()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PGK();
}

inline hstring CurrencyIdentifiers::PHP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PHP();
}

inline hstring CurrencyIdentifiers::PKR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PKR();
}

inline hstring CurrencyIdentifiers::PLN()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PLN();
}

inline hstring CurrencyIdentifiers::PYG()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().PYG();
}

inline hstring CurrencyIdentifiers::QAR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().QAR();
}

inline hstring CurrencyIdentifiers::RON()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().RON();
}

inline hstring CurrencyIdentifiers::RSD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().RSD();
}

inline hstring CurrencyIdentifiers::RUB()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().RUB();
}

inline hstring CurrencyIdentifiers::RWF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().RWF();
}

inline hstring CurrencyIdentifiers::SAR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SAR();
}

inline hstring CurrencyIdentifiers::SBD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SBD();
}

inline hstring CurrencyIdentifiers::SCR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SCR();
}

inline hstring CurrencyIdentifiers::SDG()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SDG();
}

inline hstring CurrencyIdentifiers::SEK()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SEK();
}

inline hstring CurrencyIdentifiers::SGD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SGD();
}

inline hstring CurrencyIdentifiers::SHP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SHP();
}

inline hstring CurrencyIdentifiers::SLL()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SLL();
}

inline hstring CurrencyIdentifiers::SOS()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SOS();
}

inline hstring CurrencyIdentifiers::SRD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SRD();
}

inline hstring CurrencyIdentifiers::STD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().STD();
}

inline hstring CurrencyIdentifiers::SYP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SYP();
}

inline hstring CurrencyIdentifiers::SZL()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().SZL();
}

inline hstring CurrencyIdentifiers::THB()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().THB();
}

inline hstring CurrencyIdentifiers::TJS()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TJS();
}

inline hstring CurrencyIdentifiers::TMT()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TMT();
}

inline hstring CurrencyIdentifiers::TND()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TND();
}

inline hstring CurrencyIdentifiers::TOP()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TOP();
}

inline hstring CurrencyIdentifiers::TRY()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TRY();
}

inline hstring CurrencyIdentifiers::TTD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TTD();
}

inline hstring CurrencyIdentifiers::TWD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TWD();
}

inline hstring CurrencyIdentifiers::TZS()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().TZS();
}

inline hstring CurrencyIdentifiers::UAH()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().UAH();
}

inline hstring CurrencyIdentifiers::UGX()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().UGX();
}

inline hstring CurrencyIdentifiers::USD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().USD();
}

inline hstring CurrencyIdentifiers::UYU()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().UYU();
}

inline hstring CurrencyIdentifiers::UZS()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().UZS();
}

inline hstring CurrencyIdentifiers::VEF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().VEF();
}

inline hstring CurrencyIdentifiers::VND()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().VND();
}

inline hstring CurrencyIdentifiers::VUV()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().VUV();
}

inline hstring CurrencyIdentifiers::WST()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().WST();
}

inline hstring CurrencyIdentifiers::XAF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().XAF();
}

inline hstring CurrencyIdentifiers::XCD()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().XCD();
}

inline hstring CurrencyIdentifiers::XOF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().XOF();
}

inline hstring CurrencyIdentifiers::XPF()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().XPF();
}

inline hstring CurrencyIdentifiers::XXX()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().XXX();
}

inline hstring CurrencyIdentifiers::YER()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().YER();
}

inline hstring CurrencyIdentifiers::ZAR()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ZAR();
}

inline hstring CurrencyIdentifiers::ZMW()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ZMW();
}

inline hstring CurrencyIdentifiers::ZWL()
{
    return GetActivationFactory<CurrencyIdentifiers, ICurrencyIdentifiersStatics>().ZWL();
}

inline GeographicRegion::GeographicRegion() :
    GeographicRegion(ActivateInstance<GeographicRegion>())
{}

inline GeographicRegion::GeographicRegion(hstring_ref geographicRegionCode) :
    GeographicRegion(GetActivationFactory<GeographicRegion, IGeographicRegionFactory>().CreateGeographicRegion(geographicRegionCode))
{}

inline bool GeographicRegion::IsSupported(hstring_ref geographicRegionCode)
{
    return GetActivationFactory<GeographicRegion, IGeographicRegionStatics>().IsSupported(geographicRegionCode);
}

inline Language::Language(hstring_ref languageTag) :
    Language(GetActivationFactory<Language, ILanguageFactory>().CreateLanguage(languageTag))
{}

inline bool Language::IsWellFormed(hstring_ref languageTag)
{
    return GetActivationFactory<Language, ILanguageStatics>().IsWellFormed(languageTag);
}

inline hstring Language::CurrentInputMethodLanguageTag()
{
    return GetActivationFactory<Language, ILanguageStatics>().CurrentInputMethodLanguageTag();
}

inline bool Language::TrySetInputMethodLanguageTag(hstring_ref languageTag)
{
    return GetActivationFactory<Language, ILanguageStatics2>().TrySetInputMethodLanguageTag(languageTag);
}

inline hstring NumeralSystemIdentifiers::Arab()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Arab();
}

inline hstring NumeralSystemIdentifiers::ArabExt()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().ArabExt();
}

inline hstring NumeralSystemIdentifiers::Bali()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Bali();
}

inline hstring NumeralSystemIdentifiers::Beng()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Beng();
}

inline hstring NumeralSystemIdentifiers::Cham()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Cham();
}

inline hstring NumeralSystemIdentifiers::Deva()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Deva();
}

inline hstring NumeralSystemIdentifiers::FullWide()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().FullWide();
}

inline hstring NumeralSystemIdentifiers::Gujr()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Gujr();
}

inline hstring NumeralSystemIdentifiers::Guru()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Guru();
}

inline hstring NumeralSystemIdentifiers::HaniDec()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().HaniDec();
}

inline hstring NumeralSystemIdentifiers::Java()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Java();
}

inline hstring NumeralSystemIdentifiers::Kali()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Kali();
}

inline hstring NumeralSystemIdentifiers::Khmr()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Khmr();
}

inline hstring NumeralSystemIdentifiers::Knda()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Knda();
}

inline hstring NumeralSystemIdentifiers::Lana()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Lana();
}

inline hstring NumeralSystemIdentifiers::LanaTham()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().LanaTham();
}

inline hstring NumeralSystemIdentifiers::Laoo()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Laoo();
}

inline hstring NumeralSystemIdentifiers::Latn()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Latn();
}

inline hstring NumeralSystemIdentifiers::Lepc()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Lepc();
}

inline hstring NumeralSystemIdentifiers::Limb()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Limb();
}

inline hstring NumeralSystemIdentifiers::Mlym()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Mlym();
}

inline hstring NumeralSystemIdentifiers::Mong()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Mong();
}

inline hstring NumeralSystemIdentifiers::Mtei()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Mtei();
}

inline hstring NumeralSystemIdentifiers::Mymr()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Mymr();
}

inline hstring NumeralSystemIdentifiers::MymrShan()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().MymrShan();
}

inline hstring NumeralSystemIdentifiers::Nkoo()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Nkoo();
}

inline hstring NumeralSystemIdentifiers::Olck()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Olck();
}

inline hstring NumeralSystemIdentifiers::Orya()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Orya();
}

inline hstring NumeralSystemIdentifiers::Saur()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Saur();
}

inline hstring NumeralSystemIdentifiers::Sund()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Sund();
}

inline hstring NumeralSystemIdentifiers::Talu()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Talu();
}

inline hstring NumeralSystemIdentifiers::TamlDec()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().TamlDec();
}

inline hstring NumeralSystemIdentifiers::Telu()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Telu();
}

inline hstring NumeralSystemIdentifiers::Thai()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Thai();
}

inline hstring NumeralSystemIdentifiers::Tibt()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Tibt();
}

inline hstring NumeralSystemIdentifiers::Vaii()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics>().Vaii();
}

inline hstring NumeralSystemIdentifiers::Brah()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().Brah();
}

inline hstring NumeralSystemIdentifiers::Osma()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().Osma();
}

inline hstring NumeralSystemIdentifiers::MathBold()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().MathBold();
}

inline hstring NumeralSystemIdentifiers::MathDbl()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().MathDbl();
}

inline hstring NumeralSystemIdentifiers::MathSans()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().MathSans();
}

inline hstring NumeralSystemIdentifiers::MathSanb()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().MathSanb();
}

inline hstring NumeralSystemIdentifiers::MathMono()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().MathMono();
}

inline hstring NumeralSystemIdentifiers::ZmthBold()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().ZmthBold();
}

inline hstring NumeralSystemIdentifiers::ZmthDbl()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().ZmthDbl();
}

inline hstring NumeralSystemIdentifiers::ZmthSans()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().ZmthSans();
}

inline hstring NumeralSystemIdentifiers::ZmthSanb()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().ZmthSanb();
}

inline hstring NumeralSystemIdentifiers::ZmthMono()
{
    return GetActivationFactory<NumeralSystemIdentifiers, INumeralSystemIdentifiersStatics2>().ZmthMono();
}

}

}
