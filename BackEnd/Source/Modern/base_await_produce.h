
#ifdef WINRT_ASYNC

struct get_progress_token_t {};
constexpr get_progress_token_t get_progress_token{};

struct get_cancellation_token_t {};
constexpr get_cancellation_token_t get_cancellation_token{};

struct fire_and_forget {};

namespace impl
{
    template <typename Derived, typename AsyncInterface, typename CompletedHandler>
    struct promise_base : implements<Derived, AsyncInterface, Windows::Foundation::IAsyncInfo>
    {
        using AsyncStatus = Windows::Foundation::AsyncStatus;

        ~promise_base() noexcept
        {
            if (m_status == AsyncStatus::Error || m_status == AsyncStatus::Canceled)
            {
                reinterpret_cast<std::exception_ptr *>(&m_exception)->~exception_ptr();
            }
        }

        unsigned long __stdcall Release() noexcept
        {
            const uint32_t remaining = just_release();

            if (remaining == 0)
            {
                std::atomic_thread_fence(std::memory_order_acquire);
                std::experimental::coroutine_handle<Derived>::from_promise(*static_cast<Derived *>(this)).destroy();
            }

            return remaining;
        }

        void Completed(const CompletedHandler & handler)
        {
            AsyncStatus status;

            {
                const lock_guard guard(m_lock);

                if (m_completed_assigned)
                {
                    throw winrt::hresult_illegal_delegate_assignment();
                }

                m_completed_assigned = true;

                if (m_status == AsyncStatus::Started)
                {
                    m_completed = handler;
                    return;
                }

                status = m_status;
            }

            if (handler)
            {
                handler(*this, status);
            }
        }

        CompletedHandler Completed() noexcept
        {
            const lock_guard guard(m_lock);
            return m_completed;
        }

        uint32_t Id() const noexcept
        {
            return 1;
        }

        AsyncStatus Status() noexcept
        {
            const lock_guard guard(m_lock);
            return m_status;
        }

        HRESULT ErrorCode() noexcept
        {
            try
            {
                const lock_guard guard(m_lock);

                if (m_status == AsyncStatus::Error)
                {
                    rethrow_exception(*reinterpret_cast<std::exception_ptr *>(&m_exception));
                }

                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        void Cancel() noexcept
        {
            const lock_guard guard(m_lock);

            if (m_status == AsyncStatus::Started)
            {
                m_status = AsyncStatus::Canceled;
            }
        }

        void Close()
        {
            const lock_guard guard(m_lock);

            if (m_status == AsyncStatus::Started)
            {
                throw winrt::hresult_illegal_state_change();
            }
        }

        AsyncInterface get_return_object() const noexcept
        {
            return *this;
        }

        std::experimental::suspend_never initial_suspend() const noexcept
        {
            return{};
        }

        struct final_suspend_type
        {
            promise_base * promise;

            bool await_ready() const noexcept
            {
                return false;
            }

            void await_resume() const noexcept
            {
            }

            bool await_suspend(std::experimental::coroutine_handle<>) const noexcept
            {
                return 0 < promise->just_release();
            }
        };

        final_suspend_type final_suspend() noexcept
        {
            return{ this };
        }

        void set_exception(std::exception_ptr && exception)
        {
            CompletedHandler handler;
            AsyncStatus status;

            {
                const winrt::lock_guard guard(m_lock);
                WINRT_ASSERT(m_status == AsyncStatus::Started || m_status == AsyncStatus::Canceled);

                try
                {
                    rethrow_exception(exception);
                }
                catch (const winrt::hresult_canceled &)
                {
                    m_status = AsyncStatus::Canceled;
                }
                catch (...)
                {
                    m_status = AsyncStatus::Error;
                }

                new (&m_exception) std::exception_ptr(std::move(exception));
                handler = std::move(m_completed);
                status = m_status;
            }

            if (handler)
            {
                handler(*this, status);
            }
        }

    protected:

        std::aligned_union_t<0, std::exception_ptr> m_exception;
        winrt::lock m_lock;
        CompletedHandler m_completed;
        AsyncStatus m_status{ AsyncStatus::Started };
        bool m_completed_assigned{ false };

    private:

        uint32_t just_release() noexcept
        {
            return this->m_references.fetch_sub(1, std::memory_order_acq_rel) - 1;
        }
    };

    template <typename Promise>
    struct cancellation_token
    {
        cancellation_token(Promise * promise) noexcept :
            m_promise(promise)
        {
        }

        bool await_ready() const noexcept
        {
            return true;
        }

        void await_suspend(std::experimental::coroutine_handle<>) const noexcept
        {
        }

        cancellation_token<Promise> await_resume() const noexcept
        {
            return *this;
        }

        bool operator()() const noexcept
        {
            return m_promise->Status() == AsyncStatus::Canceled;
        }

    private:

        Promise * m_promise;
    };

    template <typename Promise, typename Progress>
    struct progress_token
    {
        progress_token(Promise * promise) noexcept :
            m_promise(promise)
        {
        }

        bool await_ready() const noexcept
        {
            return true;
        }

        void await_suspend(std::experimental::coroutine_handle<>) const noexcept
        {
        }

        progress_token<Promise, Progress> await_resume() const noexcept
        {
            return *this;
        }

        void operator()(const Progress & result)
        {
            m_promise->set_progress(result);
        }

    private:

        Promise * m_promise;
    };
}

#endif
