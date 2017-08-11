
WINRT_EXPORT namespace std::experimental
{
    template <typename TResult, typename ... Args>
    struct coroutine_traits<winrt::Windows::Foundation::IAsyncOperation<TResult>, Args ...>
    {
        struct promise_type : winrt::impl::promise_base<promise_type, winrt::Windows::Foundation::IAsyncOperation<TResult>,
            winrt::Windows::Foundation::AsyncOperationCompletedHandler<TResult>>
        {
            using AsyncStatus = winrt::Windows::Foundation::AsyncStatus;

            TResult GetResults()
            {
                winrt::impl::lock_guard const guard(this->m_lock);

                if (this->m_status == AsyncStatus::Completed)
                {
                    return m_result;
                }

                if (this->m_status == AsyncStatus::Error || this->m_status == AsyncStatus::Canceled)
                {
                    rethrow_exception(*reinterpret_cast<exception_ptr*>(&this->m_exception));
                }

                WINRT_ASSERT(this->m_status == AsyncStatus::Started);
                throw winrt::hresult_illegal_method_call();
            }

            void return_value(TResult const& result)
            {
                winrt::Windows::Foundation::AsyncOperationCompletedHandler<TResult> handler;
                AsyncStatus status;

                {
                    winrt::impl::lock_guard const guard(this->m_lock);

                    if (this->m_status == AsyncStatus::Started)
                    {
                        this->m_status = AsyncStatus::Completed;
                        m_result = result;
                    }
                    else
                    {
                        WINRT_ASSERT(this->m_status == AsyncStatus::Canceled);
                        new (&this->m_exception) exception_ptr(make_exception_ptr(winrt::hresult_canceled()));
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

            TResult m_result{ winrt::impl::empty_value<TResult>() };
        };
    };
}
