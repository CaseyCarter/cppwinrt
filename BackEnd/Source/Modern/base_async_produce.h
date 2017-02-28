
namespace impl
{
    template <typename D>
    struct produce<D, Windows::Foundation::IAsyncAction> : produce_base<D, Windows::Foundation::IAsyncAction>
    {
        HRESULT __stdcall put_Completed(abi_arg_in<Windows::Foundation::AsyncActionCompletedHandler> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<const Windows::Foundation::AsyncActionCompletedHandler *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(abi_arg_out<Windows::Foundation::AsyncActionCompletedHandler> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetResults() noexcept final
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
        HRESULT __stdcall get_Id(uint32_t * id) noexcept final
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

        HRESULT __stdcall get_Status(winrt::Windows::Foundation::AsyncStatus * status) noexcept final
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

        HRESULT __stdcall get_ErrorCode(HRESULT * errorCode) noexcept final
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

        HRESULT __stdcall abi_Cancel() noexcept final
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

        HRESULT __stdcall abi_Close() noexcept final
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
        HRESULT __stdcall put_Progress(abi_arg_in<Windows::Foundation::AsyncActionProgressHandler<TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Progress(*reinterpret_cast<const Windows::Foundation::AsyncActionProgressHandler<TProgress> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Progress(abi_arg_out<Windows::Foundation::AsyncActionProgressHandler<TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Progress());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall put_Completed(abi_arg_in<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<const Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(abi_arg_out<Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetResults() noexcept final
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
        HRESULT __stdcall put_Completed(abi_arg_in<Windows::Foundation::AsyncOperationCompletedHandler<TResult>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<const Windows::Foundation::AsyncOperationCompletedHandler<TResult> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(abi_arg_out<Windows::Foundation::AsyncOperationCompletedHandler<TResult>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetResults(abi_arg_out<TResult> results) noexcept final
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
        HRESULT __stdcall put_Progress(abi_arg_in<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Progress(*reinterpret_cast<const Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Progress(abi_arg_out<Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Progress());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall put_Completed(abi_arg_in<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                this->shim().Completed(*reinterpret_cast<const Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress> *>(&handler));
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        HRESULT __stdcall get_Completed(abi_arg_out<Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>> handler) noexcept final
        {
            try
            {
                typename D::abi_guard guard(this->shim());
                *handler = detach_abi(this->shim().Completed());
                return S_OK;
            }
            catch (...)
            {
                *handler = nullptr;
                return to_hresult();
            }
        }

        HRESULT __stdcall abi_GetResults(abi_arg_out<TResult> results) noexcept final
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
