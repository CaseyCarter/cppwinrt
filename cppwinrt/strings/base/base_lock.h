
namespace winrt::impl
{
    struct mutex
    {
        mutex(mutex const&) = delete;
        mutex& operator=(mutex const&) = delete;
        mutex() noexcept = default;

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
        friend struct condition_variable;

        PSRWLOCK get() noexcept
        {
            return&m_lock;
        }

        SRWLOCK m_lock{SRWLOCK_INIT};
    };

    using shared_mutex = mutex;

    struct lock_guard
    {
        explicit lock_guard(mutex& lock) noexcept :
            m_lock(lock)
        {
            m_lock.lock();
        }

        ~lock_guard() noexcept
        {
            m_lock.unlock();
        }

    private:

        mutex& m_lock;
    };

    struct shared_lock_guard
    {
        explicit shared_lock_guard(shared_mutex& lock) noexcept :
            m_lock(lock)
        {
            m_lock.lock_shared();
        }

        ~shared_lock_guard() noexcept
        {
            m_lock.unlock_shared();
        }

    private:

        shared_mutex& m_lock;
    };

    struct condition_variable
    {
        condition_variable(condition_variable const&) = delete;
        condition_variable const& operator=(condition_variable const&) = delete;
        condition_variable() noexcept = default;

        template <typename T>
        void wait(mutex& x, T predicate)
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

        CONDITION_VARIABLE m_cv{CONDITION_VARIABLE_INIT};
    };
}
