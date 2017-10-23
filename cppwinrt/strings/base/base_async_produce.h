
namespace winrt::impl
{
    template <typename D>
    struct produce<D, Windows::Foundation::IAsyncAction> : produce_base<D, Windows::Foundation::IAsyncAction>
    {
        HRESULT __stdcall put_Completed(::IUnknown* handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<Windows::Foundation::AsyncActionCompletedHandler const*>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(::IUnknown** handler) noexcept final
        {
            try
            {
                *handler = nullptr;
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall GetResults() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetResults();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D>
    struct produce<D, Windows::Foundation::IAsyncInfo> : produce_base<D, Windows::Foundation::IAsyncInfo>
    {
        HRESULT __stdcall get_Id(uint32_t* id) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *id = this->shim().Id();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Status(winrt::Windows::Foundation::AsyncStatus* status) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *status = this->shim().Status();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_ErrorCode(HRESULT* errorCode) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *errorCode = this->shim().ErrorCode();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall Cancel() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Cancel();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall Close() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Close();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename TProgress>
    struct produce<D, Windows::Foundation::IAsyncActionWithProgress<TProgress>> : produce_base<D, Windows::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        HRESULT __stdcall put_Progress(::IUnknown* handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Progress(*reinterpret_cast<Windows::Foundation::AsyncActionProgressHandler<TProgress> const*>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Progress(::IUnknown** handler) noexcept final
        {
            try
            {
                *handler = nullptr;
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Progress());
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall put_Completed(::IUnknown* handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> const*>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(::IUnknown** handler) noexcept final
        {
            try
            {
                *handler = nullptr;
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall GetResults() noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().GetResults();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }
    };

    template <typename D, typename TResult>
    struct produce<D, Windows::Foundation::IAsyncOperation<TResult>> : produce_base<D, Windows::Foundation::IAsyncOperation<TResult>>
    {
        HRESULT __stdcall put_Completed(::IUnknown* handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<Windows::Foundation::AsyncOperationCompletedHandler<TResult> const*>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(::IUnknown** handler) noexcept final
        {
            try
            {
                *handler = nullptr;
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall GetResults(arg_out<TResult> results) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *results = detach_abi(this->shim().GetResults());
                return S_OK;
            }
            catch (...)
            {
                clear_abi(results);
                return to_hresult();
            }
        }
    };

    template <typename D, typename TResult, typename TProgress>
    struct produce<D, Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>> : produce_base<D, Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        HRESULT __stdcall put_Progress(::IUnknown* handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Progress(*reinterpret_cast<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress> const*>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Progress(::IUnknown** handler) noexcept final
        {
            try
            {
                *handler = nullptr;
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Progress());
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall put_Completed(::IUnknown* handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> const*>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(::IUnknown** handler) noexcept final
        {
            try
            {
                *handler = nullptr;
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall GetResults(arg_out<TResult> results) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *results = detach_abi(this->shim().GetResults());
                return S_OK;
            }
            catch (...)
            {
                clear_abi(results);
                return to_hresult();
            }
        }
    };
}
