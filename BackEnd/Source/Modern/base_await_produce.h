
#ifdef WINRT_ASYNC

struct resume_background
{
    bool await_ready() const noexcept
    {
        return false;
    }

    void await_resume() const noexcept
    {
    }

    void await_suspend(std::experimental::coroutine_handle<> handle) const
    {
        auto callback = [](PTP_CALLBACK_INSTANCE, void * context)
        {
            std::experimental::coroutine_handle<>::from_address(context)();
        };

        if (!TrySubmitThreadpoolCallback(callback, handle.address(), nullptr))
        {
            throw_last_error();
        }
    }
};

struct thread_context
{
    thread_context()
    {
        check_hresult(CoGetObjectContext(__uuidof(m_context), reinterpret_cast<void **>(put(m_context))));
    }

    bool await_ready() const noexcept
    {
        return false;
    }

    void await_resume() const noexcept
    {
    }

    void await_suspend(std::experimental::coroutine_handle<> handle) const
    {
        ComCallData data = {};
        data.pUserDefined = handle.address();

        auto callback = [](ComCallData * data)
        {
            std::experimental::coroutine_handle<>::from_address(data->pUserDefined)();
            return S_OK;
        };

        check_hresult(m_context->ContextCallback(callback, &data, IID_ICallbackWithNoReentrancyToApplicationSTA, 5, nullptr));
    }

private:

    com_ptr<IContextCallback> m_context;
};

struct resume_after
{
    explicit resume_after(Windows::Foundation::TimeSpan duration) noexcept :
        m_duration(duration)
    {
    }

    bool await_ready() const noexcept
    {
        return m_duration.count() <= 0;
    }

    void await_suspend(std::experimental::coroutine_handle<> handle)
    {
        m_timer = CreateThreadpoolTimer(callback, handle.address(), nullptr);

        if (!m_timer)
        {
            throw_last_error();
        }

        int64_t relative_count = -m_duration.count();
        SetThreadpoolTimer(get(m_timer), reinterpret_cast<PFILETIME>(&relative_count), 0, 0);
    }

    void await_resume() const noexcept
    {
    }

private:

    static void __stdcall callback(PTP_CALLBACK_INSTANCE, void * context, PTP_TIMER) noexcept
    {
        std::experimental::coroutine_handle<>::from_address(context)();
    }

    struct timer_traits : handle_traits<PTP_TIMER>
    {
        static void close(type value) noexcept
        {
            CloseThreadpoolTimer(value);
        }
    };

    handle<timer_traits> m_timer;
    Windows::Foundation::TimeSpan m_duration;
};

struct resume_on_signal
{
    explicit resume_on_signal(HANDLE handle) noexcept :
        m_handle(handle)
    {}

    resume_on_signal(HANDLE handle, Windows::Foundation::TimeSpan timeout) noexcept :
        m_handle(handle),
        m_timeout(timeout)
    {}

    bool await_ready() const noexcept
    {
        return WaitForSingleObject(m_handle, 0) == WAIT_OBJECT_0;
    }

    void await_suspend(std::experimental::coroutine_handle<> resume)
    {
        m_resume = resume;
        m_wait = CreateThreadpoolWait(callback, this, nullptr);

        if (!m_wait)
        {
            throw_last_error();
        }

        int64_t relative_count = -m_timeout.count();
        PFILETIME file_time = relative_count != 0 ? reinterpret_cast<PFILETIME>(&relative_count) : nullptr;
        SetThreadpoolWait(get(m_wait), m_handle, file_time);
    }

    bool await_resume() const noexcept
    {
        return m_result == WAIT_OBJECT_0;
    }

private:

    static void __stdcall callback(PTP_CALLBACK_INSTANCE, void * context, PTP_WAIT, TP_WAIT_RESULT result) noexcept
    {
        auto that = static_cast<resume_on_signal *>(context);
        that->m_result = result;
        that->m_resume();
    }

    struct wait_traits : handle_traits<PTP_WAIT>
    {
        static void close(type value) noexcept
        {
            CloseThreadpoolWait(value);
        }
    };

    handle<wait_traits> m_wait;
    Windows::Foundation::TimeSpan m_timeout{ 0 };
    HANDLE m_handle{};
    uint32_t m_result{};
    std::experimental::coroutine_handle<> m_resume{ nullptr };
};

struct awaitable_base
{
    static void __stdcall callback(PTP_CALLBACK_INSTANCE, void *, void * overlapped, ULONG result, ULONG_PTR, PTP_IO) noexcept
    {
        auto context = static_cast<awaitable_base *>(overlapped);
        context->m_result = result;
        context->m_resume();
    }

protected:

    OVERLAPPED m_overlapped{};
    uint32_t m_result{};
    std::experimental::coroutine_handle<> m_resume{ nullptr };
};

struct resumable_io
{
    resumable_io(HANDLE object) :
        m_io(CreateThreadpoolIo(object, awaitable_base::callback, nullptr, nullptr))
    {
        if (!m_io)
        {
            throw_last_error();
        }
    }

    template <typename F>
    auto start(F callback)
    {
        struct awaitable : awaitable_base, F
        {
            awaitable(PTP_IO io, F callback) noexcept :
                m_io(io),
                F(callback)
            {}

            bool await_ready() const noexcept
            {
                return false;
            }

            void await_suspend(std::experimental::coroutine_handle<> resume_handle)
            {
                m_resume = resume_handle;
                StartThreadpoolIo(m_io);

                try
                {
                    (*this)(m_overlapped);
                }
                catch (...)
                {
                    CancelThreadpoolIo(m_io);
                    throw;
                }
            }

            uint32_t await_resume() const
            {
                if (m_result != NO_ERROR && m_result != ERROR_HANDLE_EOF)
                {
                    throw hresult_error(HRESULT_FROM_WIN32(m_result));
                }

                return static_cast<uint32_t>(m_overlapped.InternalHigh);
            }

            PTP_IO m_io = nullptr;
        };

        return awaitable(get(), callback);
    }

    template <typename F>
    auto start_pending(F callback)
    {
        struct awaitable : awaitable_base, F
        {
            awaitable(PTP_IO io, F callback) noexcept :
                m_io(io),
                F(callback)
            {}

            bool await_ready() const noexcept
            {
                return false;
            }

            bool await_suspend(std::experimental::coroutine_handle<> resume_handle)
            {
                m_resume = resume_handle;
                StartThreadpoolIo(m_io);

                try
                {
                    const bool pending = (*this)(m_overlapped);

                    if (!pending)
                    {
                        CancelThreadpoolIo(m_io);
                    }

                    return pending;
                }
                catch (...)
                {
                    CancelThreadpoolIo(m_io);
                    throw;
                }
            }

            uint32_t await_resume() const
            {
                if (m_result != NO_ERROR && m_result != ERROR_HANDLE_EOF)
                {
                    throw hresult_error(HRESULT_FROM_WIN32(m_result));
                }

                return static_cast<uint32_t>(m_overlapped.InternalHigh);
            }

            PTP_IO m_io = nullptr;
        };

        return awaitable(get(), callback);
    }

    PTP_IO get() const noexcept
    {
        return winrt::get(m_io);
    }

private:

    struct io_traits : handle_traits<PTP_IO>
    {
        static void close(type value) noexcept
        {
            CloseThreadpoolIo(value);
        }
    };

    handle<io_traits> m_io;
};

inline auto operator co_await(Windows::Foundation::TimeSpan duration)
{
    return resume_after(duration);
}

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
