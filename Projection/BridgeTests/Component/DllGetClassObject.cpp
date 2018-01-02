#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;

// {C40D08D9-051A-48DB-8DB1-B5902D89D594}
static constexpr GUID TestClassObjectGuid =
{ 0xc40d08d9, 0x51a, 0x48db,{ 0x8d, 0xb1, 0xb5, 0x90, 0x2d, 0x89, 0xd5, 0x94 } };

struct ClassObject : implements<ClassObject, IStringable>
{
    hstring ToString()
    {
        return L"ClassObject";
    }
};

HRESULT __stdcall DllGetClassObject(GUID const& clsid, GUID const& iid, void** object)
{
    try
    {
        *object = nullptr;

        if (clsid == TestClassObjectGuid)
        {
            return get_unknown(make<ClassObject>())->QueryInterface(iid, object);
        }

        return winrt::hresult_class_not_available().to_abi();
    }
    catch (...)
    {
        return winrt::to_hresult();
    }

}
