
static long s_lock;

void lock_module()
{
	InterlockedIncrement(&s_lock);
}

void unlock_module()
{
	InterlockedDecrement(&s_lock);
}

HRESULT __stdcall DllCanUnloadNow()
{
	return s_lock ? S_FALSE : S_OK;
}
