
namespace Modern { namespace Internal {

template <typename T>
class Windows_Foundation_Collections_Iterator
{
    T const * m_collection = nullptr;
	unsigned m_index = 0;

public:

	Windows_Foundation_Collections_Iterator(T const & collection, unsigned const index) noexcept :
		m_collection(&collection),
		m_index(index)
	{}

	Windows_Foundation_Collections_Iterator & operator++() noexcept
	{
		++m_index;
		return *this;
	}

	auto operator *() const
	{
		return m_collection->GetAt(m_index);
	}

	inline bool operator ==(Windows_Foundation_Collections_Iterator const & other) const noexcept
	{
        MODERN_ASSERT(m_collection == other.m_collection);
		return m_index == other.m_index;
	}

	inline bool operator !=(Windows_Foundation_Collections_Iterator const & other) const noexcept
	{
		return !(*this == other);
	}
};

}}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename T, typename std::enable_if<!Internal::IsRandom<T>::Value>::type * = nullptr>
auto begin(T const & collection) -> decltype(collection.First())
{
	auto result = collection.First();

	if (result.HasCurrent())
	{
		return result;
	}
	else
	{
		return {};
	}
}

template <typename T, typename std::enable_if<!Internal::IsRandom<T>::Value>::type * = nullptr>
auto end(T const & collection) -> decltype(collection.First())
{
    collection;
	return {};
}


template <typename T, typename std::enable_if<Internal::IsRandom<T>::Value>::type * = nullptr>
Internal::Windows_Foundation_Collections_Iterator<T> begin(T const & collection)
{
	return Internal::Windows_Foundation_Collections_Iterator<T>(collection, 0);
}

template <typename T, typename std::enable_if<Internal::IsRandom<T>::Value>::type * = nullptr>
Internal::Windows_Foundation_Collections_Iterator<T> end(T const & collection)
{
	return Internal::Windows_Foundation_Collections_Iterator<T>(collection, collection.Size());
}

}}}}
