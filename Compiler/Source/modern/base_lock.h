
namespace winrt {

struct lock
{
	lock(lock const &) = delete;
	lock & operator=(lock const &) = delete;

	lock() noexcept
	{
		InitializeSRWLock(&m_lock);
	}

	void enter() noexcept
	{
		AcquireSRWLockExclusive(&m_lock);
	}

	bool try_enter() noexcept
	{
		return 0 != TryAcquireSRWLockExclusive(&m_lock);
	}

	void exit() noexcept
	{
		ReleaseSRWLockExclusive(&m_lock);
	}

private:

	SRWLOCK m_lock;
};

struct lock_guard
{
	lock_guard(lock_guard const &) = delete;
	lock_guard & operator=(lock_guard const &) = delete;

	explicit lock_guard(lock & lock) noexcept :
		m_lock(lock)
	{
		m_lock.enter();
	}

	~lock_guard() noexcept
	{
		m_lock.exit();
	}

private:

	lock & m_lock;
};

}
