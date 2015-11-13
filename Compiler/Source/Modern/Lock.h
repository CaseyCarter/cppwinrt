
namespace Modern {

class Lock
{
	SRWLOCK m_lock;

public:

	Lock(Lock const &) = delete;
	Lock & operator=(Lock const &) = delete;

	Lock() noexcept
	{
		InitializeSRWLock(&m_lock);
	}

	void Enter() noexcept
	{
		AcquireSRWLockExclusive(&m_lock);
	}

	bool TryEnter() noexcept
	{
		return 0 != TryAcquireSRWLockExclusive(&m_lock);
	}

	void Exit() noexcept
	{
		ReleaseSRWLockExclusive(&m_lock);
	}
};

class LockGuard
{
	Lock & m_lock;

public:

	LockGuard(LockGuard const &) = delete;
	LockGuard & operator=(LockGuard const &) = delete;

	explicit LockGuard(Lock & lock) noexcept :
		m_lock(lock)
	{
		m_lock.Enter();
	}

	~LockGuard() noexcept
	{
		m_lock.Exit();
	}
};

}
