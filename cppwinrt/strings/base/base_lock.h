
WINRT_EXPORT namespace winrt
{
    struct slim_condition_variable;

    struct slim_mutex
    {
        slim_mutex(slim_mutex const&) = delete;
        slim_mutex& operator=(slim_mutex const&) = delete;
        slim_mutex() noexcept = default;

        void lock() noexcept
        {
            AcquireSRWLockExclusive(&m_lock);
        }

        void lock_shared() noexcept
        {
            AcquireSRWLockShared(&m_lock);
        }

        bool try_lock() noexcept
        {
            return 0 != TryAcquireSRWLockExclusive(&m_lock);
        }

        bool try_lock_shared() noexcept
        {
            return 0 != TryAcquireSRWLockShared(&m_lock);
        }

        void unlock() noexcept
        {
            __analysis_assume_lock_acquired(m_lock);
            ReleaseSRWLockExclusive(&m_lock);
        }

        void unlock_shared() noexcept
        {
            __analysis_assume_lock_acquired(m_lock);
            ReleaseSRWLockShared(&m_lock);
        }

    private:
        friend slim_condition_variable;

        PSRWLOCK get() noexcept
        {
            return&m_lock;
        }

        SRWLOCK m_lock{};
    };

    struct slim_lock_guard
    {
        explicit slim_lock_guard(slim_mutex& m) noexcept :
            m_mutex(m)
        {
            m_mutex.lock();
        }

        ~slim_lock_guard() noexcept
        {
            m_mutex.unlock();
        }

    private:
        slim_mutex & m_mutex;
    };

    struct slim_shared_lock_guard
    {
        explicit slim_shared_lock_guard(slim_mutex& m) noexcept :
            m_mutex(m)
        {
            m_mutex.lock_shared();
        }

        ~slim_shared_lock_guard() noexcept
        {
            m_mutex.unlock_shared();
        }

    private:
        slim_mutex & m_mutex;
    };

    struct slim_condition_variable
    {
        slim_condition_variable(slim_condition_variable const&) = delete;
        slim_condition_variable const& operator=(slim_condition_variable const&) = delete;
        slim_condition_variable() noexcept = default;

        template <typename T>
        void wait(slim_mutex& x, T predicate)
        {
            while (!predicate())
            {
                WINRT_VERIFY(SleepConditionVariableSRW(&m_cv, x.get(), INFINITE, 0));
            }
        }

        void notify_one() noexcept
        {
            WakeConditionVariable(&m_cv);
        }

        void notify_all() noexcept
        {
            WakeAllConditionVariable(&m_cv);
        }

    private:
        CONDITION_VARIABLE m_cv{};
    };
}
