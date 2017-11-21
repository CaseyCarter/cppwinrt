#include "pch.h"
#include "winrtvisualizer.h"

using namespace winrt;

struct WinrtVisualizerFactory : implements<WinrtVisualizerFactory, IClassFactory>
{
    HRESULT __stdcall CreateInstance(IUnknown* outer, GUID const& id, void** object) noexcept final
    {
        if (outer != nullptr)
        {
            return E_INVALIDARG;
        }

        com_ptr<IUnknown> temp = make<CWinrtVisualizer>();
        return temp->QueryInterface(id, object);
    }

    HRESULT __stdcall LockServer(BOOL) noexcept final
    {
        return S_OK;
    }
};

extern "C" HRESULT STDAPICALLTYPE DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
    *ppv = nullptr;
    static constexpr GUID winrtVisualizerIID{ 0x2ea3526b, 0x93a1, 0x4854,{ 0xae, 0x18, 0x90, 0x28, 0x28, 0x8f, 0x6f, 0x64 } };

    if (rclsid == winrtVisualizerIID)
    {
        try
        {
            com_ptr<IClassFactory> factory = make<WinrtVisualizerFactory>();
            
            return factory->QueryInterface(riid, ppv);
        }
        catch (...)
        {
            return to_hresult();
        }
    }

    return CLASS_E_CLASSNOTAVAILABLE;
}

STDAPI DllCanUnloadNow(void)
{
    return S_FALSE;
}