
HRESULT __stdcall DllGetActivationFactory(HSTRING classId, ABI::Windows::IActivationFactory ** factory)
{
	*factory = nullptr;
	wchar_t const * expected = WindowsGetStringRawBuffer(classId, nullptr);

	try
	{
		%
		{
			throw hresult_error(CLASS_E_CLASSNOTAVAILABLE);
		}

		return S_OK;
	}
	catch (...) { return impl::to_hresult(); }
}
