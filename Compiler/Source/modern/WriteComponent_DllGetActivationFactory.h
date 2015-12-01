
HRESULT __stdcall DllGetActivationFactory(HSTRING classId, ABI::Windows::IActivationFactory ** factory)
{
    *factory = nullptr;
    wchar_t const * expected = WindowsGetStringRawBuffer(classId, nullptr);

    return call([&]
    {
        %
        {
            throw Exception(CLASS_E_CLASSNOTAVAILABLE);
        }
    });
}
