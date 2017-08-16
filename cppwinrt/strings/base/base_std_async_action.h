
WINRT_EXPORT namespace std::experimental
{
    template <typename ... Args>
    struct coroutine_traits<winrt::Windows::Foundation::IAsyncAction, Args ...>
    {
        struct promise_type : winrt::impl::promise_base<promise_type, winrt::Windows::Foundation::IAsyncAction,
            winrt::Windows::Foundation::AsyncActionCompletedHandler>
        {
            using AsyncStatus = winrt::Windows::Foundation::AsyncStatus;

            void GetResults()
            {
                winrt::impl::lock_guard const guard(this->m_lock);

                if (this->m_status == AsyncStatus::Completed)
                {
                    return;
                }

                this->rethrow_if_failed();
                WINRT_ASSERT(this->m_status == AsyncStatus::Started);
                throw winrt::hresult_illegal_method_call();
            }

            void return_void()
            {
                winrt::Windows::Foundation::AsyncActionCompletedHandler handler;
                AsyncStatus status;

                {
                    winrt::impl::lock_guard const guard(this->m_lock);

                    if (this->m_status == AsyncStatus::Started)
                    {
                        this->m_status = AsyncStatus::Completed;
                    }
                    else
                    {
                        WINRT_ASSERT(this->m_status == AsyncStatus::Canceled);
                        this->m_exception = make_exception_ptr(winrt::hresult_canceled());
                    }

                    handler = std::move(this->m_completed);
                    status = this->m_status;
                }

                if (handler)
                {
                    handler(*this, status);
                }
            }

            template <typename Expression>
            Expression&& await_transform(Expression&& expression)
            {
                if (this->Status() == AsyncStatus::Canceled)
                {
                    throw winrt::hresult_canceled();
                }

                return forward<Expression>(expression);
            }

            winrt::impl::cancellation_token<promise_type> await_transform(winrt::get_cancellation_token_t) noexcept
            {
                return{ this };
            }
        };
    };
}
