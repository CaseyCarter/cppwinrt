
template <typename TProgress, typename ... Args>
struct coroutine_traits<winrt::Windows::Foundation::IAsyncActionWithProgress<TProgress>, Args ...>
{
    struct promise_type : winrt::impl::promise_base<promise_type, winrt::Windows::Foundation::IAsyncActionWithProgress<TProgress>,
                                                                  winrt::Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
    {
        using ProgressHandler = winrt::Windows::Foundation::AsyncActionProgressHandler<TProgress>;

        void Progress(const ProgressHandler & handler)
        {
            const winrt::lock_guard guard(this->m_lock);
            m_progress = handler;
        }

        ProgressHandler Progress()
        {
            const winrt::lock_guard guard(this->m_lock);
            return m_progress;
        }

        void GetResults()
        {
            const winrt::lock_guard guard(this->m_lock);

            if (this->m_status == AsyncStatus::Completed)
            {
                return;
            }

            if (this->m_status == AsyncStatus::Error || this->m_status == AsyncStatus::Canceled)
            {
                rethrow_exception(*reinterpret_cast<exception_ptr *>(&this->m_exception));
            }

            WINRT_ASSERT(this->m_status == AsyncStatus::Started);
            throw winrt::hresult_illegal_method_call();
        }

        void return_void()
        {
            winrt::Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress> handler;
            winrt::Windows::Foundation::AsyncStatus status;

            {
                const winrt::lock_guard guard(this->m_lock);

                if (this->m_status == AsyncStatus::Started)
                {
                    this->m_status = AsyncStatus::Completed;
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

        void set_progress(const TProgress & result)
        {
            if (auto handler = Progress())
            {
                handler(*this, result);
            }
        }

        template <typename Expression>
        Expression && await_transform(Expression && expression)
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

        winrt::impl::progress_token<promise_type, TProgress> await_transform(winrt::get_progress_token_t) noexcept
        {
            return{ this };
        }

        ProgressHandler m_progress;
    };
};
