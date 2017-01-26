// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Cryptography.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
#define WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
template <> struct __declspec(uuid("3bee8834-b9a7-5a80-a746-5ef097227878")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IBuffer> : impl_IAsyncOperation<Windows::Storage::Streams::IBuffer> {};
#endif

#ifndef WINRT_GENERIC_81ca789b_98df_5c6a_9531_966238e3e7ae
#define WINRT_GENERIC_81ca789b_98df_5c6a_9531_966238e3e7ae
template <> struct __declspec(uuid("81ca789b-98df-5c6a-9531-966238e3e7ae")) __declspec(novtable) IAsyncOperation<Windows::Security::Cryptography::Core::CryptographicKey> : impl_IAsyncOperation<Windows::Security::Cryptography::Core::CryptographicKey> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
#define WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
template <> struct __declspec(uuid("51c3d2fd-b8a1-5620-b746-7ee6d533aca3")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> {};
#endif

#ifndef WINRT_GENERIC_04ca4378_f594_5de6_a555_304f62cb4faf
#define WINRT_GENERIC_04ca4378_f594_5de6_a555_304f62cb4faf
template <> struct __declspec(uuid("04ca4378-f594-5de6-a555-304f62cb4faf")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Security::Cryptography::Core::CryptographicKey> : impl_AsyncOperationCompletedHandler<Windows::Security::Cryptography::Core::CryptographicKey> {};
#endif


}

namespace Windows::Security::Cryptography::Core {

struct IAsymmetricAlgorithmNamesStatics :
    Windows::IInspectable,
    impl::consume<IAsymmetricAlgorithmNamesStatics>
{
    IAsymmetricAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsymmetricAlgorithmNamesStatics>(m_ptr); }
};

struct IAsymmetricAlgorithmNamesStatics2 :
    Windows::IInspectable,
    impl::consume<IAsymmetricAlgorithmNamesStatics2>
{
    IAsymmetricAlgorithmNamesStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsymmetricAlgorithmNamesStatics2>(m_ptr); }
};

struct IAsymmetricKeyAlgorithmProvider :
    Windows::IInspectable,
    impl::consume<IAsymmetricKeyAlgorithmProvider>
{
    IAsymmetricKeyAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsymmetricKeyAlgorithmProvider>(m_ptr); }
};

struct IAsymmetricKeyAlgorithmProvider2 :
    Windows::IInspectable,
    impl::consume<IAsymmetricKeyAlgorithmProvider2>
{
    IAsymmetricKeyAlgorithmProvider2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsymmetricKeyAlgorithmProvider2>(m_ptr); }
};

struct IAsymmetricKeyAlgorithmProviderStatics :
    Windows::IInspectable,
    impl::consume<IAsymmetricKeyAlgorithmProviderStatics>
{
    IAsymmetricKeyAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IAsymmetricKeyAlgorithmProviderStatics>(m_ptr); }
};

struct ICryptographicEngineStatics :
    Windows::IInspectable,
    impl::consume<ICryptographicEngineStatics>
{
    ICryptographicEngineStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICryptographicEngineStatics>(m_ptr); }
};

struct ICryptographicEngineStatics2 :
    Windows::IInspectable,
    impl::consume<ICryptographicEngineStatics2>
{
    ICryptographicEngineStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICryptographicEngineStatics2>(m_ptr); }
};

struct ICryptographicKey :
    Windows::IInspectable,
    impl::consume<ICryptographicKey>
{
    ICryptographicKey(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ICryptographicKey>(m_ptr); }
};

struct IEccCurveNamesStatics :
    Windows::IInspectable,
    impl::consume<IEccCurveNamesStatics>
{
    IEccCurveNamesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IEccCurveNamesStatics>(m_ptr); }
};

struct IEncryptedAndAuthenticatedData :
    Windows::IInspectable,
    impl::consume<IEncryptedAndAuthenticatedData>
{
    IEncryptedAndAuthenticatedData(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IEncryptedAndAuthenticatedData>(m_ptr); }
};

struct IHashAlgorithmNamesStatics :
    Windows::IInspectable,
    impl::consume<IHashAlgorithmNamesStatics>
{
    IHashAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHashAlgorithmNamesStatics>(m_ptr); }
};

struct IHashAlgorithmProvider :
    Windows::IInspectable,
    impl::consume<IHashAlgorithmProvider>
{
    IHashAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHashAlgorithmProvider>(m_ptr); }
};

struct IHashAlgorithmProviderStatics :
    Windows::IInspectable,
    impl::consume<IHashAlgorithmProviderStatics>
{
    IHashAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHashAlgorithmProviderStatics>(m_ptr); }
};

struct IHashComputation :
    Windows::IInspectable,
    impl::consume<IHashComputation>
{
    IHashComputation(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IHashComputation>(m_ptr); }
};

struct IKeyDerivationAlgorithmNamesStatics :
    Windows::IInspectable,
    impl::consume<IKeyDerivationAlgorithmNamesStatics>
{
    IKeyDerivationAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IKeyDerivationAlgorithmNamesStatics>(m_ptr); }
};

struct IKeyDerivationAlgorithmNamesStatics2 :
    Windows::IInspectable,
    impl::consume<IKeyDerivationAlgorithmNamesStatics2>
{
    IKeyDerivationAlgorithmNamesStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IKeyDerivationAlgorithmNamesStatics2>(m_ptr); }
};

struct IKeyDerivationAlgorithmProvider :
    Windows::IInspectable,
    impl::consume<IKeyDerivationAlgorithmProvider>
{
    IKeyDerivationAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IKeyDerivationAlgorithmProvider>(m_ptr); }
};

struct IKeyDerivationAlgorithmProviderStatics :
    Windows::IInspectable,
    impl::consume<IKeyDerivationAlgorithmProviderStatics>
{
    IKeyDerivationAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IKeyDerivationAlgorithmProviderStatics>(m_ptr); }
};

struct IKeyDerivationParameters :
    Windows::IInspectable,
    impl::consume<IKeyDerivationParameters>
{
    IKeyDerivationParameters(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IKeyDerivationParameters>(m_ptr); }
};

struct IKeyDerivationParameters2 :
    Windows::IInspectable,
    impl::consume<IKeyDerivationParameters2>
{
    IKeyDerivationParameters2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IKeyDerivationParameters2>(m_ptr); }
};

struct IKeyDerivationParametersStatics :
    Windows::IInspectable,
    impl::consume<IKeyDerivationParametersStatics>
{
    IKeyDerivationParametersStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IKeyDerivationParametersStatics>(m_ptr); }
};

struct IKeyDerivationParametersStatics2 :
    Windows::IInspectable,
    impl::consume<IKeyDerivationParametersStatics2>
{
    IKeyDerivationParametersStatics2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IKeyDerivationParametersStatics2>(m_ptr); }
};

struct IMacAlgorithmNamesStatics :
    Windows::IInspectable,
    impl::consume<IMacAlgorithmNamesStatics>
{
    IMacAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMacAlgorithmNamesStatics>(m_ptr); }
};

struct IMacAlgorithmProvider :
    Windows::IInspectable,
    impl::consume<IMacAlgorithmProvider>
{
    IMacAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMacAlgorithmProvider>(m_ptr); }
};

struct IMacAlgorithmProvider2 :
    Windows::IInspectable,
    impl::consume<IMacAlgorithmProvider2>
{
    IMacAlgorithmProvider2(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMacAlgorithmProvider2>(m_ptr); }
};

struct IMacAlgorithmProviderStatics :
    Windows::IInspectable,
    impl::consume<IMacAlgorithmProviderStatics>
{
    IMacAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IMacAlgorithmProviderStatics>(m_ptr); }
};

struct IPersistedKeyProviderStatics :
    Windows::IInspectable,
    impl::consume<IPersistedKeyProviderStatics>
{
    IPersistedKeyProviderStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<IPersistedKeyProviderStatics>(m_ptr); }
};

struct ISymmetricAlgorithmNamesStatics :
    Windows::IInspectable,
    impl::consume<ISymmetricAlgorithmNamesStatics>
{
    ISymmetricAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISymmetricAlgorithmNamesStatics>(m_ptr); }
};

struct ISymmetricKeyAlgorithmProvider :
    Windows::IInspectable,
    impl::consume<ISymmetricKeyAlgorithmProvider>
{
    ISymmetricKeyAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISymmetricKeyAlgorithmProvider>(m_ptr); }
};

struct ISymmetricKeyAlgorithmProviderStatics :
    Windows::IInspectable,
    impl::consume<ISymmetricKeyAlgorithmProviderStatics>
{
    ISymmetricKeyAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
    auto operator->() const noexcept { return ptr<ISymmetricKeyAlgorithmProviderStatics>(m_ptr); }
};

}

}
