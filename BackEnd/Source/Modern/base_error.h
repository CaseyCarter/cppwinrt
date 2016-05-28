
namespace impl {

struct heap_traits : handle_traits<wchar_t *>
{
    static void close(type value) noexcept
    {
        WINRT_VERIFY(HeapFree(GetProcessHeap(), 0, value));
    }
};

struct bstr_traits : handle_traits<BSTR>
{
    static void close(type value) noexcept
    {
        SysFreeString(value);
    }
};

inline hstring trim_hresult_message(const wchar_t * const message, uint32_t size) noexcept
{
    const wchar_t * back = message + size - 1;

    while (size && isspace(*back))
    {
        --size;
        --back;
    }

    hstring result;
    WindowsCreateString(message, size, put(result));
    return result;
}

}

struct hresult_error
{
    struct from_abi_t {};
    static constexpr from_abi_t from_abi {};

    explicit hresult_error(const HRESULT code) noexcept :
        m_code(code)
    {
        WINRT_RoOriginateError(code, nullptr);
        WINRT_GetRestrictedErrorInfo(put(m_info));
    }

    hresult_error(const HRESULT code, hstring_ref message) noexcept :
        m_code(code)
    {
        WINRT_RoOriginateError(code, get(message));
        WINRT_GetRestrictedErrorInfo(put(m_info));
    }

    hresult_error(const HRESULT code, from_abi_t) noexcept :
        m_code(code)
    {
        WINRT_GetRestrictedErrorInfo(put(m_info));
    }

    HRESULT code() const noexcept
    {
        return m_code;
    }

    hstring message() const noexcept
    {
        if (m_info)
        {
            handle<impl::bstr_traits> unused1;
            handle<impl::bstr_traits> unused2;

            HRESULT code = S_OK;
            handle<impl::bstr_traits> message;

            if (S_OK == m_info->GetErrorDetails(put(unused1), &code, put(message), put(unused2)))
            {
                if (code == m_code)
                {
                    return impl::trim_hresult_message(get(message), SysStringLen(get(message)));
                }
            }
        }

        handle<impl::heap_traits> message;

        const uint32_t size = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                             nullptr,
                                             m_code,
                                             MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                                             reinterpret_cast<wchar_t *>(put(message)),
                                             0,
                                             nullptr);

        return impl::trim_hresult_message(get(message), size);
    }

    HRESULT to_abi() const noexcept
    {
        WINRT_TRACE("winrt::hresult_error (0x%8X) %ls\n", code(), message().c_str());

        if (m_info)
        {
            WINRT_SetRestrictedErrorInfo(get(m_info));
        }

        return m_code;
    }

private:

    HRESULT m_code = S_OK;
    com_ptr<IRestrictedErrorInfo> m_info;
};

struct hresult_access_denied : hresult_error
{
    hresult_access_denied() : hresult_error(E_ACCESSDENIED) {}
    hresult_access_denied(hstring_ref message) : hresult_error(E_ACCESSDENIED, message) {}
    hresult_access_denied(from_abi_t) : hresult_error(E_ACCESSDENIED, from_abi) {}
};

struct hresult_wrong_thread : hresult_error
{
    hresult_wrong_thread() : hresult_error(RPC_E_WRONG_THREAD) {}
    hresult_wrong_thread(hstring_ref message) : hresult_error(RPC_E_WRONG_THREAD, message) {}
    hresult_wrong_thread(from_abi_t) : hresult_error(RPC_E_WRONG_THREAD, from_abi) {}
};

struct hresult_not_implemented : hresult_error
{
    hresult_not_implemented() : hresult_error(E_NOTIMPL) {}
    hresult_not_implemented(hstring_ref message) : hresult_error(E_NOTIMPL, message) {}
    hresult_not_implemented(from_abi_t) : hresult_error(E_NOTIMPL, from_abi) {}
};

struct hresult_invalid_argument : hresult_error
{
    hresult_invalid_argument() : hresult_error(E_INVALIDARG) {}
    hresult_invalid_argument(hstring_ref message) : hresult_error(E_INVALIDARG, message) {}
    hresult_invalid_argument(from_abi_t) : hresult_error(E_INVALIDARG, from_abi) {}
};

struct hresult_out_of_bounds : hresult_error
{
    hresult_out_of_bounds() : hresult_error(E_BOUNDS) {}
    hresult_out_of_bounds(hstring_ref message) : hresult_error(E_BOUNDS, message) {}
    hresult_out_of_bounds(from_abi_t) : hresult_error(E_BOUNDS, from_abi) {}
};

struct hresult_no_interface : hresult_error
{
    hresult_no_interface() : hresult_error(E_NOINTERFACE) {}
    hresult_no_interface(hstring_ref message) : hresult_error(E_NOINTERFACE, message) {}
    hresult_no_interface(from_abi_t) : hresult_error(E_NOINTERFACE, from_abi) {}
};

struct hresult_disconnected : hresult_error
{
    hresult_disconnected() : hresult_error(RPC_E_DISCONNECTED) {}
    hresult_disconnected(hstring_ref message) : hresult_error(RPC_E_DISCONNECTED, message) {}
    hresult_disconnected(from_abi_t) : hresult_error(RPC_E_DISCONNECTED, from_abi) {}
};

namespace impl {

[[noreturn]] inline __declspec(noinline) void throw_hresult(const HRESULT result)
{
    if (result == E_OUTOFMEMORY)
    {
        throw std::bad_alloc();
    }

    if (result == E_ACCESSDENIED)
    {
        throw hresult_access_denied(hresult_error::from_abi);
    }

    if (result == RPC_E_WRONG_THREAD)
    {
        throw hresult_wrong_thread(hresult_error::from_abi);
    }

    if (result == E_NOTIMPL)
    {
        throw hresult_not_implemented(hresult_error::from_abi);
    }

    if (result == E_INVALIDARG)
    {
        throw hresult_invalid_argument(hresult_error::from_abi);
    }

    if (result == E_BOUNDS)
    {
        throw hresult_out_of_bounds(hresult_error::from_abi);
    }

    if (result == E_NOINTERFACE)
    {
        throw hresult_no_interface(hresult_error::from_abi);
    }

    throw hresult_error(result, hresult_error::from_abi);
}

inline __declspec(noinline) HRESULT to_hresult() noexcept
{
    HRESULT value = S_OK;

    try
    {
        throw;
    }
    catch (const hresult_error & e)
    {
        return e.to_abi();
    }
    catch (const std::bad_alloc &)
    {
        return E_OUTOFMEMORY;
    }
    catch (const std::out_of_range &)
    {
        value = E_BOUNDS;
    }
    catch (const std::invalid_argument &)
    {
        value = E_INVALIDARG;
    }
    catch (const std::exception &)
    {
        value = E_FAIL;
    }

    WINRT_RoOriginateError(value, nullptr);
    return value;
}

}

__forceinline void check_hresult(const HRESULT result)
{
    if (result != S_OK)
    {
        impl::throw_hresult(result);
    }
}
