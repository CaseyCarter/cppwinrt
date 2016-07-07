#include "pch.h"
#include "Microsoft.Sample.Hen.h"

using namespace winrt;
using namespace Windows::Foundation;

HRESULT __stdcall DllCanUnloadNow()
{
    return S_FALSE;
}

HRESULT __stdcall DllGetActivationFactory(HSTRING classId, abi<IActivationFactory> ** factory)
{
    try
    {
        wchar_t const * const name = WindowsGetStringRawBuffer(classId, nullptr);

        if (0 == wcscmp(name, L"Microsoft.Sample.Hen"))
        {
            *factory = detach(make<Microsoft::Sample::HenFactory>());
        }
        else
        {
            throw hresult_class_not_available();
        }

        return S_OK;
    }
    catch (...)
    {
        *factory = nullptr;
        return impl::to_hresult();
    }
}
