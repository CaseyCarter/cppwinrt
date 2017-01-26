// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Markup.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.UI.Xaml.Interop.0.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Markup {

struct XamlBinaryWriterErrorInformation
{
    uint32_t InputStreamIndex;
    uint32_t LineNumber;
    uint32_t LinePosition;
};

struct XmlnsDefinition
{
    hstring XmlNamespace;
    hstring Namespace;
};

}

namespace Windows::UI::Xaml::Markup {

using XamlBinaryWriterErrorInformation = ABI::Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation;

struct XmlnsDefinition
{
    hstring XmlNamespace;
    hstring Namespace;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Markup::XmlnsDefinition>
{
    using abi = ABI::Windows::UI::Xaml::Markup::XmlnsDefinition;
};

}

namespace ABI::Windows::UI::Xaml::Markup {

struct __declspec(uuid("f6790987-e6e5-47f2-92c6-eccce4ba159a")) __declspec(novtable) IComponentConnector : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Connect(int32_t connectionId, Windows::IInspectable * target) = 0;
};

struct __declspec(uuid("dc8f368b-eccc-498e-b139-91142254d7ae")) __declspec(novtable) IComponentConnector2 : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetBindingConnector(int32_t connectionId, Windows::IInspectable * target, Windows::UI::Xaml::Markup::IComponentConnector ** returnValue) = 0;
};

struct __declspec(uuid("08429dc8-8ab0-4747-aa9a-feadfc8da8e1")) __declspec(novtable) IDataTemplateComponent : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Recycle() = 0;
    virtual HRESULT __stdcall abi_ProcessBindings(Windows::IInspectable * item, int32_t itemIndex, int32_t phase, int32_t * nextPhase) = 0;
};

struct __declspec(uuid("829d2ad3-620a-46f6-845d-436a05927100")) __declspec(novtable) IXamlBinaryWriter : Windows::IInspectable
{
};

struct __declspec(uuid("0d8ed07a-9b82-4aa8-b68b-026f2de1cc86")) __declspec(novtable) IXamlBinaryWriterStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Write(Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> * inputStreams, Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> * outputStreams, Windows::UI::Xaml::Markup::IXamlMetadataProvider * xamlMetadataProvider, Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation * returnValue) = 0;
};

struct __declspec(uuid("faa6fb06-8ab9-4ef7-8ae7-fbd30bbfd06d")) __declspec(novtable) IXamlBindingHelper : Windows::IInspectable
{
};

struct __declspec(uuid("f65cfb71-c80c-4ffa-86ee-558754ee336d")) __declspec(novtable) IXamlBindingHelperStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall get_DataTemplateComponentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetDataTemplateComponent(Windows::UI::Xaml::IDependencyObject * element, Windows::UI::Xaml::Markup::IDataTemplateComponent ** value) = 0;
    virtual HRESULT __stdcall abi_SetDataTemplateComponent(Windows::UI::Xaml::IDependencyObject * element, Windows::UI::Xaml::Markup::IDataTemplateComponent * value) = 0;
    virtual HRESULT __stdcall abi_SuspendRendering(Windows::UI::Xaml::IUIElement * target) = 0;
    virtual HRESULT __stdcall abi_ResumeRendering(Windows::UI::Xaml::IUIElement * target) = 0;
    virtual HRESULT __stdcall abi_ConvertValue(Windows::UI::Xaml::Interop::TypeName type, Windows::IInspectable * value, Windows::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromString(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, hstring value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromBoolean(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, bool value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromChar16(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, wchar_t value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromDateTime(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromDouble(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, double value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromInt32(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, int32_t value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromUInt32(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, uint32_t value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromInt64(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, int64_t value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromUInt64(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, uint64_t value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromSingle(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, float value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromPoint(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromRect(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, Windows::Foundation::Rect value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromSize(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, Windows::Foundation::Size value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromTimeSpan(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromByte(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, uint8_t value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromUri(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall abi_SetPropertyFromObject(Windows::IInspectable * dependencyObject, Windows::UI::Xaml::IDependencyProperty * propertyToSet, Windows::IInspectable * value) = 0;
};

struct __declspec(uuid("c541f58c-43a9-4216-b718-e0b11b14e93e")) __declspec(novtable) IXamlMember : Windows::IInspectable
{
    virtual HRESULT __stdcall get_IsAttachable(bool * value) = 0;
    virtual HRESULT __stdcall get_IsDependencyProperty(bool * value) = 0;
    virtual HRESULT __stdcall get_IsReadOnly(bool * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_TargetType(Windows::UI::Xaml::Markup::IXamlType ** value) = 0;
    virtual HRESULT __stdcall get_Type(Windows::UI::Xaml::Markup::IXamlType ** value) = 0;
    virtual HRESULT __stdcall abi_GetValue(Windows::IInspectable * instance, Windows::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetValue(Windows::IInspectable * instance, Windows::IInspectable * value) = 0;
};

struct __declspec(uuid("b3765d69-68a5-4b32-8861-fdb90c1f5836")) __declspec(novtable) IXamlMetadataProvider : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_GetXamlType(Windows::UI::Xaml::Interop::TypeName type, Windows::UI::Xaml::Markup::IXamlType ** xamlType) = 0;
    virtual HRESULT __stdcall abi_GetXamlTypeByFullName(hstring fullName, Windows::UI::Xaml::Markup::IXamlType ** xamlType) = 0;
    virtual HRESULT __stdcall abi_GetXmlnsDefinitions(uint32_t * __definitionsSize, Windows::UI::Xaml::Markup::XmlnsDefinition ** definitions) = 0;
};

struct __declspec(uuid("24374cf1-cceb-48bf-a514-41b0186f84c2")) __declspec(novtable) IXamlReader : Windows::IInspectable
{
};

struct __declspec(uuid("9891c6bd-534f-4955-b85a-8a8dc0dca602")) __declspec(novtable) IXamlReaderStatics : Windows::IInspectable
{
    virtual HRESULT __stdcall abi_Load(hstring xaml, Windows::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_LoadWithInitialTemplateValidation(hstring xaml, Windows::IInspectable ** returnValue) = 0;
};

struct __declspec(uuid("7920eab1-a2e5-479a-bd50-6cef3c0b4970")) __declspec(novtable) IXamlType : Windows::IInspectable
{
    virtual HRESULT __stdcall get_BaseType(Windows::UI::Xaml::Markup::IXamlType ** value) = 0;
    virtual HRESULT __stdcall get_ContentProperty(Windows::UI::Xaml::Markup::IXamlMember ** value) = 0;
    virtual HRESULT __stdcall get_FullName(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsArray(bool * value) = 0;
    virtual HRESULT __stdcall get_IsCollection(bool * value) = 0;
    virtual HRESULT __stdcall get_IsConstructible(bool * value) = 0;
    virtual HRESULT __stdcall get_IsDictionary(bool * value) = 0;
    virtual HRESULT __stdcall get_IsMarkupExtension(bool * value) = 0;
    virtual HRESULT __stdcall get_IsBindable(bool * value) = 0;
    virtual HRESULT __stdcall get_ItemType(Windows::UI::Xaml::Markup::IXamlType ** value) = 0;
    virtual HRESULT __stdcall get_KeyType(Windows::UI::Xaml::Markup::IXamlType ** value) = 0;
    virtual HRESULT __stdcall get_UnderlyingType(Windows::UI::Xaml::Interop::TypeName * value) = 0;
    virtual HRESULT __stdcall abi_ActivateInstance(Windows::IInspectable ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateFromString(hstring value, Windows::IInspectable ** instance) = 0;
    virtual HRESULT __stdcall abi_GetMember(hstring name, Windows::UI::Xaml::Markup::IXamlMember ** xamlMember) = 0;
    virtual HRESULT __stdcall abi_AddToVector(Windows::IInspectable * instance, Windows::IInspectable * value) = 0;
    virtual HRESULT __stdcall abi_AddToMap(Windows::IInspectable * instance, Windows::IInspectable * key, Windows::IInspectable * value) = 0;
    virtual HRESULT __stdcall abi_RunInitializer() = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Markup::XamlBinaryWriter> { using default_interface = Windows::UI::Xaml::Markup::IXamlBinaryWriter; };
template <> struct traits<Windows::UI::Xaml::Markup::XamlBindingHelper> { using default_interface = Windows::UI::Xaml::Markup::IXamlBindingHelper; };
template <> struct traits<Windows::UI::Xaml::Markup::XamlReader> { using default_interface = Windows::UI::Xaml::Markup::IXamlReader; };

}

namespace Windows::UI::Xaml::Markup {

template <typename D>
struct WINRT_EBO impl_IComponentConnector
{
    void Connect(int32_t connectionId, const Windows::IInspectable & target) const;
};

template <typename D>
struct WINRT_EBO impl_IComponentConnector2
{
    Windows::UI::Xaml::Markup::IComponentConnector GetBindingConnector(int32_t connectionId, const Windows::IInspectable & target) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplateComponent
{
    void Recycle() const;
    void ProcessBindings(const Windows::IInspectable & item, int32_t itemIndex, int32_t phase, int32_t & nextPhase) const;
};

template <typename D>
struct WINRT_EBO impl_IXamlBinaryWriter
{
};

template <typename D>
struct WINRT_EBO impl_IXamlBinaryWriterStatics
{
    Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation Write(const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> & inputStreams, const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> & outputStreams, const Windows::UI::Xaml::Markup::IXamlMetadataProvider & xamlMetadataProvider) const;
};

template <typename D>
struct WINRT_EBO impl_IXamlBindingHelper
{
};

template <typename D>
struct WINRT_EBO impl_IXamlBindingHelperStatics
{
    Windows::UI::Xaml::DependencyProperty DataTemplateComponentProperty() const;
    Windows::UI::Xaml::Markup::IDataTemplateComponent GetDataTemplateComponent(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetDataTemplateComponent(const Windows::UI::Xaml::DependencyObject & element, const Windows::UI::Xaml::Markup::IDataTemplateComponent & value) const;
    void SuspendRendering(const Windows::UI::Xaml::UIElement & target) const;
    void ResumeRendering(const Windows::UI::Xaml::UIElement & target) const;
    Windows::IInspectable ConvertValue(const Windows::UI::Xaml::Interop::TypeName & type, const Windows::IInspectable & value) const;
    void SetPropertyFromString(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, hstring_ref value) const;
    void SetPropertyFromBoolean(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, bool value) const;
    void SetPropertyFromChar16(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, wchar_t value) const;
    void SetPropertyFromDateTime(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::DateTime & value) const;
    void SetPropertyFromDouble(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, double value) const;
    void SetPropertyFromInt32(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, int32_t value) const;
    void SetPropertyFromUInt32(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint32_t value) const;
    void SetPropertyFromInt64(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, int64_t value) const;
    void SetPropertyFromUInt64(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint64_t value) const;
    void SetPropertyFromSingle(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, float value) const;
    void SetPropertyFromPoint(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Point & value) const;
    void SetPropertyFromRect(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Rect & value) const;
    void SetPropertyFromSize(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Size & value) const;
    void SetPropertyFromTimeSpan(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::TimeSpan & value) const;
    void SetPropertyFromByte(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint8_t value) const;
    void SetPropertyFromUri(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Uri & value) const;
    void SetPropertyFromObject(const Windows::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_IXamlMember
{
    bool IsAttachable() const;
    bool IsDependencyProperty() const;
    bool IsReadOnly() const;
    hstring Name() const;
    Windows::UI::Xaml::Markup::IXamlType TargetType() const;
    Windows::UI::Xaml::Markup::IXamlType Type() const;
    Windows::IInspectable GetValue(const Windows::IInspectable & instance) const;
    void SetValue(const Windows::IInspectable & instance, const Windows::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_IXamlMetadataProvider
{
    Windows::UI::Xaml::Markup::IXamlType GetXamlType(const Windows::UI::Xaml::Interop::TypeName & type) const;
    Windows::UI::Xaml::Markup::IXamlType GetXamlType(hstring_ref fullName) const;
    com_array<Windows::UI::Xaml::Markup::XmlnsDefinition> GetXmlnsDefinitions() const;
};

template <typename D>
struct WINRT_EBO impl_IXamlReader
{
};

template <typename D>
struct WINRT_EBO impl_IXamlReaderStatics
{
    Windows::IInspectable Load(hstring_ref xaml) const;
    Windows::IInspectable LoadWithInitialTemplateValidation(hstring_ref xaml) const;
};

template <typename D>
struct WINRT_EBO impl_IXamlType
{
    Windows::UI::Xaml::Markup::IXamlType BaseType() const;
    Windows::UI::Xaml::Markup::IXamlMember ContentProperty() const;
    hstring FullName() const;
    bool IsArray() const;
    bool IsCollection() const;
    bool IsConstructible() const;
    bool IsDictionary() const;
    bool IsMarkupExtension() const;
    bool IsBindable() const;
    Windows::UI::Xaml::Markup::IXamlType ItemType() const;
    Windows::UI::Xaml::Markup::IXamlType KeyType() const;
    Windows::UI::Xaml::Interop::TypeName UnderlyingType() const;
    Windows::IInspectable ActivateInstance() const;
    Windows::IInspectable CreateFromString(hstring_ref value) const;
    Windows::UI::Xaml::Markup::IXamlMember GetMember(hstring_ref name) const;
    void AddToVector(const Windows::IInspectable & instance, const Windows::IInspectable & value) const;
    void AddToMap(const Windows::IInspectable & instance, const Windows::IInspectable & key, const Windows::IInspectable & value) const;
    void RunInitializer() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Markup::IComponentConnector>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IComponentConnector;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IComponentConnector<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::IComponentConnector2>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IComponentConnector2;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IComponentConnector2<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::IDataTemplateComponent>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IDataTemplateComponent;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IDataTemplateComponent<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::IXamlBinaryWriter>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IXamlBinaryWriter;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IXamlBinaryWriter<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::IXamlBinaryWriterStatics>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IXamlBinaryWriterStatics;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IXamlBinaryWriterStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::IXamlBindingHelper>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IXamlBindingHelper;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IXamlBindingHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::IXamlBindingHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IXamlBindingHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IXamlBindingHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::IXamlMember>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IXamlMember;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IXamlMember<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::IXamlMetadataProvider>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IXamlMetadataProvider;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IXamlMetadataProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::IXamlReader>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IXamlReader;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IXamlReader<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::IXamlReaderStatics>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IXamlReaderStatics;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IXamlReaderStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::IXamlType>
{
    using abi = ABI::Windows::UI::Xaml::Markup::IXamlType;
    template <typename D> using consume = Windows::UI::Xaml::Markup::impl_IXamlType<D>;
};

template <> struct traits<Windows::UI::Xaml::Markup::XamlBinaryWriter>
{
    using abi = ABI::Windows::UI::Xaml::Markup::XamlBinaryWriter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Markup.XamlBinaryWriter"; }
};

template <> struct traits<Windows::UI::Xaml::Markup::XamlBindingHelper>
{
    using abi = ABI::Windows::UI::Xaml::Markup::XamlBindingHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Markup.XamlBindingHelper"; }
};

template <> struct traits<Windows::UI::Xaml::Markup::XamlReader>
{
    using abi = ABI::Windows::UI::Xaml::Markup::XamlReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Markup.XamlReader"; }
};

}

}
