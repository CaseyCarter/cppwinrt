
namespace winrt {

template <typename ... Interfaces>
class __declspec(novtable) implements : public Interfaces ...
{
	template <typename T>
	using is_cloaked = std::integral_constant<bool, !std::is_base_of<::IInspectable, typename T>::value>;

	template <int = 0>
	constexpr unsigned count_interfaces() const noexcept
	{
		return 0;
	}

	template <typename First, typename ... Rest>
	constexpr unsigned count_interfaces() const noexcept
	{
		return !is_cloaked<First>::value + count_interfaces<Rest ...>();
	}

	template <int = 0>
	constexpr bool inspectable() const noexcept
	{
		return false;
	}

	template <typename First, typename ... Rest>
	constexpr bool inspectable() const noexcept
	{
		return std::is_base_of<::IInspectable, First>::value || inspectable<Rest ...>();
	}

	template <int = 0>
	void * find_inspectable() noexcept
	{
		return nullptr;
	}

	template <typename First, typename ... Rest>
	void * find_inspectable() noexcept
	{
		#pragma warning(push)
		#pragma warning(disable:4127) // conditional expression is constant

		if (std::is_base_of<::IInspectable, First>::value)
		{
			return static_cast<First *>(this);
		}

		#pragma warning(pop)

		return find_inspectable<Rest ...>();
	}

	template <int = 0>
	void copy_interfaces(GUID *) const noexcept {}

	template <typename First, typename ... Rest>
	void copy_interfaces(GUID * ids) const noexcept
	{
		#pragma warning(push)
		#pragma warning(disable:4127) // conditional expression is constant

		if (!is_cloaked<First>::value)
		{
			*ids++ = __uuidof(First);
		}

		#pragma warning(pop)

		copy_interfaces<Rest ...>(ids);
	}

	template <int = 0>
	void * find_interface(GUID const &) noexcept
	{
		return nullptr;
	}

	template <typename First, typename ... Rest>
	void * find_interface(GUID const & id) noexcept
	{
		if (id == __uuidof(First))
		{
			return static_cast<First *>(this);
		}

		return find_interface<Rest ...>(id);
	}

protected:

	unsigned long m_references = 1;

	implements() noexcept = default;

	virtual ~implements() noexcept
	{}

	template <typename First, typename ... Rest>
	void * query_interface(GUID const & id) noexcept
	{
		if (id == __uuidof(First) || id == __uuidof(::IUnknown))
		{
			return static_cast<First *>(this);
		}

		if (inspectable<Interfaces ...>() && id == __uuidof(::IInspectable))
		{
			return find_inspectable<Interfaces ...>();
		}

		return find_interface<Rest ...>(id);
	}

public:

	implements(implements const &) = delete;
	implements & operator=(implements const &) = delete;

	virtual HRESULT __stdcall QueryInterface(GUID const & id, void ** object) noexcept override
	{
		*object = query_interface<Interfaces ...>(id);

		if (nullptr == *object)
		{
			return E_NOINTERFACE;
		}

		static_cast<::IUnknown *>(*object)->AddRef();
		return S_OK;
	}

	virtual unsigned long __stdcall AddRef() noexcept override
	{
		return InterlockedIncrement(&m_references);
	}

	virtual unsigned long __stdcall Release() noexcept override
	{
		unsigned long const remaining = InterlockedDecrement(&m_references);

		if (0 == remaining)
		{
			delete this;
		}

		return remaining;
	}

	HRESULT __stdcall GetIids(unsigned long * count, GUID ** array) noexcept
	{
		*count = 0;
		*array = nullptr;

		unsigned const localCount = count_interfaces<Interfaces ...>();

		if (0 == localCount)
		{
			return S_OK;
		}

		GUID * localArray = static_cast<GUID *>(CoTaskMemAlloc(sizeof(GUID) * localCount));

		if (nullptr == localArray)
		{
			return E_OUTOFMEMORY;
		}

		copy_interfaces<Interfaces ...>(localArray);

		*count = localCount;
		*array = localArray;
		return S_OK;
	}

	HRESULT __stdcall GetRuntimeClassName(HSTRING * name) noexcept
	{
		*name = nullptr;
		return E_NOTIMPL;
	}

	HRESULT __stdcall GetTrustLevel(TrustLevel * trustLevel) noexcept
	{
		*trustLevel = BaseTrust;
		return S_OK;
	}
};

}
