
namespace winrt::impl
{
    struct lock
    {
        lock(lock const&) = delete;
        lock& operator=(lock const&) = delete;
        lock() noexcept = default;

        void enter() noexcept
        {
            AcquireSRWLockExclusive(&m_lock);
        }

        void enter_shared() noexcept
        {
            AcquireSRWLockShared(&m_lock);
        }

        bool try_enter() noexcept
        {
            return 0 != TryAcquireSRWLockExclusive(&m_lock);
        }

        void exit() noexcept
        {
            __analysis_assume_lock_acquired(m_lock);
            ReleaseSRWLockExclusive(&m_lock);
        }

        void exit_shared() noexcept
        {
            __analysis_assume_lock_acquired(m_lock);
            ReleaseSRWLockShared(&m_lock);
        }

        PSRWLOCK get() noexcept
        {
            return&m_lock;
        }

    private:

        SRWLOCK m_lock{};
    };

    struct lock_guard
    {
        explicit lock_guard(lock& lock) noexcept :
            m_lock(lock)
        {
            m_lock.enter();
        }

        ~lock_guard() noexcept
        {
            m_lock.exit();
        }

    private:

        lock& m_lock;
    };

    struct shared_lock_guard
    {
        explicit shared_lock_guard(lock& lock) noexcept :
            m_lock(lock)
        {
            m_lock.enter_shared();
        }

        ~shared_lock_guard() noexcept
        {
            m_lock.exit_shared();
        }

    private:

        lock& m_lock;
    };

    struct condition_variable
    {
        condition_variable(condition_variable const&) = delete;
        condition_variable const& operator=(condition_variable const&) = delete;
        condition_variable() noexcept = default;

        template <typename T>
        void wait_while(lock& x, T predicate)
        {
            while (predicate())
            {
                WINRT_VERIFY(SleepConditionVariableSRW(&m_cv, x.get(), INFINITE, 0));
            }
        }

        void wake_one() noexcept
        {
            WakeConditionVariable(&m_cv);
        }

        void wake_all() noexcept
        {
            WakeAllConditionVariable(&m_cv);
        }

    private:

        CONDITION_VARIABLE m_cv{};
    };
}
