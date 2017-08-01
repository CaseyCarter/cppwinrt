
namespace impl
{
    struct free_threaded_marshaler : ::IMarshal
    {
        free_threaded_marshaler(::IUnknown* object)
        {
            m_object.copy_from(object);
        }

        HRESULT __stdcall QueryInterface(GUID const& id, void** object) noexcept final
        {
            if (id == guid_v<::IMarshal>)
            {
                *object = static_cast<::IMarshal*>(this);
                AddRef();
                return S_OK;
            }

            return m_object->QueryInterface(id, object);
        }

        unsigned long __stdcall AddRef() noexcept final
        {
            return 1 + m_references.fetch_add(1, std::memory_order_relaxed);
        }

        unsigned long __stdcall Release() noexcept final
        {
            uint32_t const remaining = m_references.fetch_sub(1, std::memory_order_relaxed) - 1;

            if (remaining == 0)
            {
                delete this;
            }

            return remaining;
        }

        HRESULT __stdcall GetUnmarshalClass(REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags, CLSID* pCid) noexcept final
        {
            if (m_marshaler)
            {
                return m_marshaler->GetUnmarshalClass(riid, pv, dwDestContext, pvDestContext, mshlflags, pCid);
            }

            return E_OUTOFMEMORY;
        }

        HRESULT __stdcall GetMarshalSizeMax(REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags, DWORD* pSize) noexcept final
        {
            if (m_marshaler)
            {
                return m_marshaler->GetMarshalSizeMax(riid, pv, dwDestContext, pvDestContext, mshlflags, pSize);
            }

            return E_OUTOFMEMORY;
        }

        HRESULT __stdcall MarshalInterface(IStream* pStm, REFIID riid, void* pv, DWORD dwDestContext, void* pvDestContext, DWORD mshlflags) noexcept final
        {
            if (m_marshaler)
            {
                return m_marshaler->MarshalInterface(pStm, riid, pv, dwDestContext, pvDestContext, mshlflags);
            }

            return E_OUTOFMEMORY;
        }

        HRESULT __stdcall UnmarshalInterface(IStream* pStm, REFIID riid, void** ppv) noexcept final
        {
            if (m_marshaler)
            {
                return m_marshaler->UnmarshalInterface(pStm, riid, ppv);
            }

            *ppv = nullptr;
            return E_OUTOFMEMORY;
        }

        HRESULT __stdcall ReleaseMarshalData(IStream* pStm) noexcept final
        {
            if (m_marshaler)
            {
                return m_marshaler->ReleaseMarshalData(pStm);
            }

            return E_OUTOFMEMORY;
        }

        HRESULT __stdcall DisconnectObject(DWORD dwReserved) noexcept final
        {
            if (m_marshaler)
            {
                return m_marshaler->DisconnectObject(dwReserved);
            }

            return E_OUTOFMEMORY;
        }

    private:

        static com_ptr<::IMarshal> get_marshaler() noexcept
        {
            com_ptr<::IUnknown> unknown;
            WINRT_VERIFY_(S_OK, CoCreateFreeThreadedMarshaler(nullptr, unknown.put()));
            return unknown ? unknown.try_as<::IMarshal>() : nullptr;
        }

        com_ptr<::IUnknown> m_object;
        com_ptr<::IMarshal> m_marshaler{ get_marshaler() };
        std::atomic<uint32_t> m_references{ 1 };
    };
}
