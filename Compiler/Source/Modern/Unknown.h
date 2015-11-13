
#define MODERN_INTERFACE(THIS_CLASS)\
private:\
using AbiType = Modern::Internal::Implementation<THIS_CLASS>::AbiType;\
public:\
THIS_CLASS() noexcept = default;\
THIS_CLASS(std::nullptr_t) {}\
Modern::Internal::RemoveAddRefRelease<AbiType> * operator->() const noexcept { return static_cast<Modern::Internal::RemoveAddRefRelease<AbiType> *>(GetAbi()); }\
AbiType * GetAbi() const noexcept { return static_cast<AbiType *>(IUnknown::GetAbi()); }\
AbiType ** SetAbi() noexcept { return reinterpret_cast<AbiType **>(IUnknown::SetAbi()); }\
void AttachAbi(AbiType * other) noexcept { IUnknown::AttachAbi(other); };\
void CopyAbi(AbiType * other) noexcept { IUnknown::CopyAbi(other); };\
AbiType * DetachAbi() noexcept { return static_cast<AbiType *>(IUnknown::DetachAbi()); }

namespace Modern {

class IUnknown
{
public:

	using AbiType = ::IUnknown;

	IUnknown() noexcept = default;

	IUnknown(IUnknown const & other) noexcept :
		m_ptr(other.m_ptr)
	{
		InternalAddRef();
	}

	IUnknown(IUnknown && other) noexcept :
		m_ptr(other.m_ptr)
	{
		other.m_ptr = nullptr;
	}

	~IUnknown() noexcept
	{
		InternalRelease();
	}

	IUnknown & operator=(IUnknown const & other) noexcept
	{
		InternalCopy(other);
		return *this;
	}

	IUnknown & operator=(IUnknown && other) noexcept
	{
		InternalMove(std::forward<IUnknown>(other));
		return *this;
	}

	explicit operator bool() const noexcept
	{
		return nullptr != m_ptr;
	}

	Internal::RemoveAddRefRelease<AbiType> * operator->() const noexcept
	{
		return static_cast<Internal::RemoveAddRefRelease<AbiType> *>(m_ptr);
	}

	void Swap(IUnknown & other) noexcept
	{
		AbiType * temp = m_ptr;
		m_ptr = other.m_ptr;
		other.m_ptr = temp;
	}

	void Reset() noexcept
	{
		InternalRelease();
	}

	template <typename T>
	T As() const
	{
		T temp(nullptr);
		Check(m_ptr->QueryInterface(temp.SetAbi()));
		return temp;
	}

	AbiType * GetAbi() const noexcept
	{
		return m_ptr;
	}

	AbiType ** SetAbi() noexcept
	{
		MODERN_ASSERT(!m_ptr);
		return &m_ptr;
	}

	void AttachAbi(AbiType * other) noexcept
	{
		InternalRelease();
		m_ptr = other;
	}

	AbiType * DetachAbi() noexcept
	{
		AbiType * temp = m_ptr;
		m_ptr = nullptr;
		return temp;
	}

	void CopyAbi(AbiType * other) noexcept
	{
		InternalCopy(other);
	}

protected:

	void InternalCopy(AbiType * other) noexcept
	{
		if (m_ptr != other)
		{
			InternalRelease();
			m_ptr = other;
			InternalAddRef();
		}
	}

	void InternalCopy(IUnknown const & other) noexcept
	{
		if (this != &other)
		{
			InternalRelease();
			m_ptr = other.m_ptr;
			InternalAddRef();
		}
	}

	void InternalMove(IUnknown && other) noexcept
	{
		if (this != &other)
		{
			InternalRelease();
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
	}

private:

	void InternalAddRef() const noexcept
	{
		if (m_ptr)
		{
			m_ptr->AddRef();
		}
	}

	void InternalRelease() noexcept
	{
		AbiType * temp = m_ptr;

		if (temp)
		{
			m_ptr = nullptr;
			temp->Release();
		}
	}

	AbiType * m_ptr = nullptr;
};

inline void swap(IUnknown & left, IUnknown & right) noexcept
{
	left.Swap(right);
}
inline bool operator==(IUnknown const & left, IUnknown const & right) noexcept
{
	return left.GetAbi() == right.GetAbi();
}
inline bool operator!=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(left == right);
}
inline bool operator<(IUnknown const & left, IUnknown const & right) noexcept
{
	return left.GetAbi() < right.GetAbi();
}
inline bool operator>(IUnknown const & left, IUnknown const & right) noexcept
{
	return right < left;
}
inline bool operator<=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(right < left);
}
inline bool operator>=(IUnknown const & left, IUnknown const & right) noexcept
{
	return !(left < right);
}

}
