
WINRT_EXPORT namespace winrt
{
    inline auto resume_background()
    {
        struct awaitable
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
                if (!TrySubmitThreadpoolCallback(callback, handle.address(), nullptr))
                {
                    throw_last_error();
                }
            }

        private:

            static void __stdcall callback(PTP_CALLBACK_INSTANCE, void* context) noexcept
            {
                std::experimental::coroutine_handle<>::from_address(context)();
            }
        };

        return awaitable{};
    }

    template <typename T>
    auto resume_background(T&& context)
    {
        struct awaitable
        {
            awaitable(T&& context) : m_context(std::forward<T>(context))
            {
            }

            bool await_ready() const noexcept
            {
                return false;
            }

            void await_resume() const noexcept
            {
            }

            void await_suspend(std::experimental::coroutine_handle<> resume)
            {
                m_resume = resume;

                if (!TrySubmitThreadpoolCallback(callback, this, nullptr))
                {
                    throw_last_error();
                }
            }

        private:

            static void __stdcall callback(PTP_CALLBACK_INSTANCE, void* context) noexcept
            {
                auto that = static_cast<awaitable*>(context);
                auto guard = that->m_context();
                that->m_resume();
            }

            T&& m_context;
            std::experimental::coroutine_handle<> m_resume{ nullptr };
        };

        return awaitable{ std::forward<T>(context) };
    }

    struct apartment_context
    {
        apartment_context()
        {
            check_hresult(CoGetObjectContext(__uuidof(m_context), m_context.put_void()));
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
            check_hresult(m_context->ContextCallback(callback, &data, IID_ICallbackWithNoReentrancyToApplicationSTA, 5, nullptr));
        }

    private:

        static HRESULT __stdcall callback(ComCallData* data) noexcept
        {
            std::experimental::coroutine_handle<>::from_address(data->pUserDefined)();
            return S_OK;
        }

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
            m_timer = check_pointer(CreateThreadpoolTimer(callback, handle.address(), nullptr));
            int64_t relative_count = -m_duration.count();
            SetThreadpoolTimer(m_timer.get(), reinterpret_cast<PFILETIME>(&relative_count), 0, 0);
        }

        void await_resume() const noexcept
        {
        }

    private:

        static void __stdcall callback(PTP_CALLBACK_INSTANCE, void* context, PTP_TIMER) noexcept
        {
            std::experimental::coroutine_handle<>::from_address(context)();
        }

        struct timer_traits
        {
            using type = PTP_TIMER;

            static void close(type value) noexcept
            {
                CloseThreadpoolTimer(value);
            }

            static constexpr type invalid() noexcept
            {
                return nullptr;
            }
        };

        handle_type<timer_traits> m_timer;
        Windows::Foundation::TimeSpan m_duration;
    };

    struct resume_on_signal
    {
        explicit resume_on_signal(HANDLE handle) noexcept :
            m_handle(handle)
        {}

        resume_on_signal(HANDLE handle, Windows::Foundation::TimeSpan timeout) noexcept :
            m_timeout(timeout),
            m_handle(handle)
        {}

        bool await_ready() const noexcept
        {
            return WaitForSingleObject(m_handle, 0) == WAIT_OBJECT_0;
        }

        void await_suspend(std::experimental::coroutine_handle<> resume)
        {
            m_resume = resume;
            m_wait = check_pointer(CreateThreadpoolWait(callback, this, nullptr));
            int64_t relative_count = -m_timeout.count();
            PFILETIME file_time = relative_count != 0 ? reinterpret_cast<PFILETIME>(&relative_count) : nullptr;
            SetThreadpoolWait(m_wait.get(), m_handle, file_time);
        }

        bool await_resume() const noexcept
        {
            return m_result == WAIT_OBJECT_0;
        }

    private:

        static void __stdcall callback(PTP_CALLBACK_INSTANCE, void* context, PTP_WAIT, TP_WAIT_RESULT result) noexcept
        {
            auto that = static_cast<resume_on_signal*>(context);
            that->m_result = result;
            that->m_resume();
        }

        struct wait_traits
        {
            using type = PTP_WAIT;

            static void close(type value) noexcept
            {
                CloseThreadpoolWait(value);
            }

            static constexpr type invalid() noexcept
            {
                return nullptr;
            }
        };

        handle_type<wait_traits> m_wait;
        Windows::Foundation::TimeSpan m_timeout{ 0 };
        HANDLE m_handle{};
        uint32_t m_result{};
        std::experimental::coroutine_handle<> m_resume{ nullptr };
    };

    struct awaitable_base
    {
        static void __stdcall callback(PTP_CALLBACK_INSTANCE, void*, void* overlapped, ULONG result, ULONG_PTR, PTP_IO) noexcept
        {
            auto context = static_cast<awaitable_base*>(overlapped);
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
            m_io(check_pointer(CreateThreadpoolIo(object, awaitable_base::callback, nullptr, nullptr)))
        {
        }

        template <typename F>
        auto start(F callback)
        {
            struct awaitable : awaitable_base, F
            {
                awaitable(PTP_IO io, F callback) noexcept :
                    F(callback),
                    m_io(io)
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
                    if (m_result != ERROR_HANDLE_EOF)
                    {
                        check_win32(m_result);
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
                    F(callback),
                    m_io(io)
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
                        bool const pending = (*this)(m_overlapped);

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
                    if (m_result != ERROR_HANDLE_EOF)
                    {
                        check_win32(m_result);
                    }
                    return static_cast<uint32_t>(m_overlapped.InternalHigh);
                }

                PTP_IO m_io = nullptr;
            };

            return awaitable(get(), callback);
        }

        PTP_IO get() const noexcept
        {
            return m_io.get();
        }

    private:

        struct io_traits
        {
            using type = PTP_IO;

            static void close(type value) noexcept
            {
                CloseThreadpoolIo(value);
            }

            static constexpr type invalid() noexcept
            {
                return nullptr;
            }
        };

        handle_type<io_traits> m_io;
    };

#ifdef _RESUMABLE_FUNCTIONS_SUPPORTED
    inline auto operator co_await(Windows::Foundation::TimeSpan duration)
    {
        return resume_after(duration);
    }
#endif

    struct get_progress_token_t {};

    inline get_progress_token_t get_progress_token() noexcept
    {
        return{};
    }

    struct get_cancellation_token_t {};

    inline get_cancellation_token_t get_cancellation_token() noexcept
    {
        return{};
    }

    struct fire_and_forget {};
}

namespace winrt::impl
{
    template <typename Derived, typename AsyncInterface, typename CompletedHandler>
    struct promise_base : implements<Derived, AsyncInterface, Windows::Foundation::IAsyncInfo>
    {
        using AsyncStatus = Windows::Foundation::AsyncStatus;

        unsigned long __stdcall Release() noexcept
        {
            uint32_t const remaining = this->subtract_reference();

            if (remaining == 0)
            {
                std::atomic_thread_fence(std::memory_order_acquire);
                std::experimental::coroutine_handle<Derived>::from_promise(*static_cast<Derived*>(this)).destroy();
            }

            return remaining;
        }

        void Completed(CompletedHandler const& handler)
        {
            AsyncStatus status;

            {
                slim_lock_guard const guard(m_lock);

                if (m_completed_assigned)
                {
                    throw hresult_illegal_delegate_assignment();
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
            slim_lock_guard const guard(m_lock);
            return m_completed;
        }

        uint32_t Id() const noexcept
        {
            return 1;
        }

        AsyncStatus Status() noexcept
        {
            slim_lock_guard const guard(m_lock);
            return m_status;
        }

        HRESULT ErrorCode() noexcept
        {
            try
            {
                slim_lock_guard const guard(m_lock);
                rethrow_if_failed();
                return S_OK;
            }
            catch (...)
            {
                return to_hresult();
            }
        }

        void Cancel() noexcept
        {
            slim_lock_guard const guard(m_lock);

            if (m_status == AsyncStatus::Started)
            {
                m_status = AsyncStatus::Canceled;
            }
        }

        void Close()
        {
            slim_lock_guard const guard(m_lock);

            if (m_status == AsyncStatus::Started)
            {
                throw hresult_illegal_state_change();
            }
        }

        AsyncInterface get_return_object() const noexcept
        {
            return*this;
        }

        std::experimental::suspend_never initial_suspend() const noexcept
        {
            return{};
        }

        struct final_suspend_type
        {
            promise_base* promise;

            bool await_ready() const noexcept
            {
                return false;
            }

            void await_resume() const noexcept
            {
            }

            bool await_suspend(std::experimental::coroutine_handle<>) const noexcept
            {
                uint32_t const remaining = promise->subtract_reference();

                if (remaining == 0)
                {
                    std::atomic_thread_fence(std::memory_order_acquire);
                }

                return remaining > 0;
            }
        };

        final_suspend_type final_suspend() noexcept
        {
            return{ this };
        }

        void unhandled_exception() noexcept
        {
            CompletedHandler handler;
            AsyncStatus status;

            {
                slim_lock_guard const guard(m_lock);
                WINRT_ASSERT(m_status == AsyncStatus::Started || m_status == AsyncStatus::Canceled);
                m_exception = std::current_exception();

                try
                {
                    std::rethrow_exception(m_exception.value());
                }
                catch (hresult_canceled const&)
                {
                    m_status = AsyncStatus::Canceled;
                }
                catch (...)
                {
                    m_status = AsyncStatus::Error;
                }

                handler = std::move(m_completed);
                status = m_status;
            }

            if (handler)
            {
                handler(*this, status);
            }
        }

    protected:

        void rethrow_if_failed() const
        {
            if (this->m_status == AsyncStatus::Error || this->m_status == AsyncStatus::Canceled)
            {
                std::rethrow_exception(m_exception.value());
            }
        }

        std::optional<std::exception_ptr> m_exception;
        slim_mutex m_lock;
        CompletedHandler m_completed;
        AsyncStatus m_status{ AsyncStatus::Started };
        bool m_completed_assigned{ false };
    };

    template <typename Promise>
    struct cancellation_token
    {
        cancellation_token(Promise* promise) noexcept :
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
            return*this;
        }

        bool operator()() const noexcept
        {
            return m_promise->Status() == Windows::Foundation::AsyncStatus::Canceled;
        }

    private:

        Promise* m_promise;
    };

    template <typename Promise, typename Progress>
    struct progress_token
    {
        progress_token(Promise* promise) noexcept :
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
            return*this;
        }

        void operator()(Progress const& result)
        {
            m_promise->set_progress(result);
        }

    private:

        Promise* m_promise;
    };
}
