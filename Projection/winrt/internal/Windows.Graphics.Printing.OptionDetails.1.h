// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once

#include "../base.h"
#include "Windows.Graphics.Printing.OptionDetails.0.h"
#include "Windows.Graphics.Printing.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::Printing::OptionDetails {

struct __declspec(uuid("5704b637-5c3a-449a-aa36-b3291b1192fd")) __declspec(novtable) IPrintCustomItemDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_ItemId(hstring * value) = 0;
    virtual HRESULT __stdcall put_ItemDisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_ItemDisplayName(hstring * value) = 0;
};

struct __declspec(uuid("a5fafd88-58f2-4ebd-b90f-51e4f2944c5d")) __declspec(novtable) IPrintCustomItemListOptionDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_AddItem(hstring itemId, hstring displayName) = 0;
};

struct __declspec(uuid("e32bde1c-28af-4b90-95da-a3acf320b929")) __declspec(novtable) IPrintCustomOptionDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
};

struct __declspec(uuid("2ad171f8-c8bd-4905-9192-0d75136e8b31")) __declspec(novtable) IPrintCustomTextOptionDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall put_MaxCharacters(uint32_t value) = 0;
    virtual HRESULT __stdcall get_MaxCharacters(uint32_t * value) = 0;
};

struct __declspec(uuid("9a2257bf-fe61-43d8-a24f-a3f6ab7320e7")) __declspec(novtable) IPrintItemListOptionDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Items(Windows::Foundation::Collections::IVectorView<Windows::IInspectable> ** value) = 0;
};

struct __declspec(uuid("4d01bbaf-645c-4de9-965f-6fc6bbc47cab")) __declspec(novtable) IPrintNumberOptionDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_MinValue(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_MaxValue(uint32_t * value) = 0;
};

struct __declspec(uuid("390686cf-d682-495f-adfe-d7333f5c1808")) __declspec(novtable) IPrintOptionDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_OptionId(hstring * value) = 0;
    virtual HRESULT __stdcall get_OptionType(winrt::Windows::Graphics::Printing::OptionDetails::PrintOptionType * value) = 0;
    virtual HRESULT __stdcall put_ErrorText(hstring value) = 0;
    virtual HRESULT __stdcall get_ErrorText(hstring * value) = 0;
    virtual HRESULT __stdcall put_State(winrt::Windows::Graphics::Printing::OptionDetails::PrintOptionStates value) = 0;
    virtual HRESULT __stdcall get_State(winrt::Windows::Graphics::Printing::OptionDetails::PrintOptionStates * value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_TrySetValue(Windows::IInspectable * value, bool * succeeded) = 0;
};

struct __declspec(uuid("65197d05-a5ee-4307-9407-9acad147679c")) __declspec(novtable) IPrintTaskOptionChangedEventArgs : Windows::IInspectable
{
    virtual HRESULT __stdcall get_OptionId(Windows::IInspectable ** value) = 0;
};

struct __declspec(uuid("f5720af1-a89e-42a6-81af-f8e010b38a68")) __declspec(novtable) IPrintTaskOptionDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_Options(Windows::Foundation::Collections::IMapView<hstring, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails> ** value) = 0;
    virtual HRESULT __stdcall abi_CreateItemListOption(hstring optionId, hstring displayName, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails ** itemListOption) = 0;
    virtual HRESULT __stdcall abi_CreateTextOption(hstring optionId, hstring displayName, Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails ** textOption) = 0;
    virtual HRESULT __stdcall add_OptionChanged(Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_OptionChanged(event_token eventCookie) = 0;
    virtual HRESULT __stdcall add_BeginValidation(Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails, Windows::IInspectable> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_BeginValidation(event_token eventCookie) = 0;
};

struct __declspec(uuid("135da193-0961-4b6e-8766-f13b7fbccd58")) __declspec(novtable) IPrintTaskOptionDetailsStatic : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetFromPrintTaskOptions(Windows::Graphics::Printing::IPrintTaskOptionsCore * printTaskOptions, Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails ** printTaskOptionDetails) = 0;
};

struct __declspec(uuid("ad75e563-5ce4-46bc-9918-ab9fad144c5b")) __declspec(novtable) IPrintTextOptionDetails : Windows::IInspectable
{
    virtual HRESULT __stdcall get_MaxCharacters(uint32_t * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintBindingOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintBorderingOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintCollationOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintColorModeOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintCopiesOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintCustomItemDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintCustomItemDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintCustomItemListOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintCustomTextOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintDuplexOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintHolePunchOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintMediaSizeOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintMediaTypeOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintOrientationOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintQualityOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintStapleOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs; };
template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails> { using default_interface = Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails; };

}

namespace Windows::Graphics::Printing::OptionDetails {

template <typename T> struct impl_IPrintCustomItemDetails;
template <typename T> struct impl_IPrintCustomItemListOptionDetails;
template <typename T> struct impl_IPrintCustomOptionDetails;
template <typename T> struct impl_IPrintCustomTextOptionDetails;
template <typename T> struct impl_IPrintItemListOptionDetails;
template <typename T> struct impl_IPrintNumberOptionDetails;
template <typename T> struct impl_IPrintOptionDetails;
template <typename T> struct impl_IPrintTaskOptionChangedEventArgs;
template <typename T> struct impl_IPrintTaskOptionDetails;
template <typename T> struct impl_IPrintTaskOptionDetailsStatic;
template <typename T> struct impl_IPrintTextOptionDetails;

}

namespace impl {

template <> struct traits<Windows::Graphics::Printing::OptionDetails::IPrintCustomItemDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomItemDetails;
    template <typename D> using consume = Windows::Graphics::Printing::OptionDetails::impl_IPrintCustomItemDetails<D>;
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomItemListOptionDetails;
    template <typename D> using consume = Windows::Graphics::Printing::OptionDetails::impl_IPrintCustomItemListOptionDetails<D>;
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomOptionDetails;
    template <typename D> using consume = Windows::Graphics::Printing::OptionDetails::impl_IPrintCustomOptionDetails<D>;
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::IPrintCustomTextOptionDetails;
    template <typename D> using consume = Windows::Graphics::Printing::OptionDetails::impl_IPrintCustomTextOptionDetails<D>;
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::IPrintItemListOptionDetails;
    template <typename D> using consume = Windows::Graphics::Printing::OptionDetails::impl_IPrintItemListOptionDetails<D>;
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::IPrintNumberOptionDetails;
    template <typename D> using consume = Windows::Graphics::Printing::OptionDetails::impl_IPrintNumberOptionDetails<D>;
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::IPrintOptionDetails;
    template <typename D> using consume = Windows::Graphics::Printing::OptionDetails::impl_IPrintOptionDetails<D>;
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionChangedEventArgs;
    template <typename D> using consume = Windows::Graphics::Printing::OptionDetails::impl_IPrintTaskOptionChangedEventArgs<D>;
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetails;
    template <typename D> using consume = Windows::Graphics::Printing::OptionDetails::impl_IPrintTaskOptionDetails<D>;
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetailsStatic>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::IPrintTaskOptionDetailsStatic;
    template <typename D> using consume = Windows::Graphics::Printing::OptionDetails::impl_IPrintTaskOptionDetailsStatic<D>;
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::IPrintTextOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::IPrintTextOptionDetails;
    template <typename D> using consume = Windows::Graphics::Printing::OptionDetails::impl_IPrintTextOptionDetails<D>;
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintBindingOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintBindingOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintBindingOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintBorderingOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintBorderingOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintBorderingOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintCollationOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintCollationOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintCollationOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintColorModeOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintColorModeOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintColorModeOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintCopiesOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintCopiesOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintCopiesOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintCustomItemDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintCustomItemDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintCustomItemDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintCustomItemListOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintCustomItemListOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintCustomItemListOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintCustomTextOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintCustomTextOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintCustomTextOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintDuplexOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintDuplexOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintDuplexOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintHolePunchOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintHolePunchOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintHolePunchOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintMediaSizeOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintMediaSizeOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintMediaSizeOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintMediaTypeOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintMediaTypeOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintMediaTypeOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintOrientationOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintOrientationOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintOrientationOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintQualityOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintQualityOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintQualityOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintStapleOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintStapleOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintStapleOptionDetails"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintTaskOptionChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintTaskOptionChangedEventArgs"; }
};

template <> struct traits<Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails>
{
    using abi = ABI::Windows::Graphics::Printing::OptionDetails::PrintTaskOptionDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Graphics.Printing.OptionDetails.PrintTaskOptionDetails"; }
};

}

}
