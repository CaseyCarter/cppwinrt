
namespace Modern { namespace Interop {

template <typename T>
class Windows_Foundation_Collections_IIterator : public Implements<typename Abi<Windows::Foundation::Collections::IIterator<T>>::Type>
{
    Windows::Foundation::Collections::IVectorView<T> v;
    unsigned i = 0;

public:

    using DefaultInterface = Windows::Foundation::Collections::IIterator<T>;

    Windows_Foundation_Collections_IIterator(typename Abi<Windows::Foundation::Collections::IVectorView<T>>::Type * other)
    {
        v.CopyAbi(other);
    }

    virtual HRESULT __stdcall get_Current(typename AbiArgument<T>::Out current) noexcept override
    {
        return v->abi_GetAt(i, current);
    }

    virtual HRESULT __stdcall get_HasCurrent(boolean * hasCurrent) noexcept override
    {
        return Call([&]
        {
            *hasCurrent = i < v.Size();
        });
    }

    virtual HRESULT __stdcall abi_MoveNext(boolean * hasCurrent) noexcept override
    {
        return Call([&]
        {
            if (i + 1 < v.Size())
            {
                ++i;
                *hasCurrent = true;
            }
            else
            {
                *hasCurrent = false;
            }
        });
    }

    virtual HRESULT __stdcall abi_GetMany(unsigned /*capacity*/, typename AbiArgument<T>::Out /*value*/, unsigned * /*actual*/) noexcept override
    {
        return E_NOTIMPL;
    }
};

template <typename T>
class Windows_Foundation_Collections_IVector : public Implements<typename Abi<Windows::Foundation::Collections::IVector<T>>::Type, 
                                                                 typename Abi<Windows::Foundation::Collections::IVectorView<T>>::Type,
                                                                 typename Abi<Windows::Foundation::Collections::IIterable<T>>::Type>
{
	std::vector<T> v;

public:

	using DefaultInterface = Windows::Foundation::Collections::IVector<T>;

    Windows_Foundation_Collections_IVector() = default;

    Windows_Foundation_Collections_IVector(std::vector<T> const & other) :
		v(other)
	{}

    Windows_Foundation_Collections_IVector(std::vector<T> && other) :
		v(std::move(other))
	{}

	virtual HRESULT __stdcall abi_GetAt(unsigned index, typename AbiArgument<T>::Out item) noexcept override
	{
		return Call([&]
		{
			CopyToAbi(*item, v.at(index));
		});
	}

	virtual HRESULT __stdcall get_Size(unsigned * size) noexcept override
	{
        *size = v.size();
        return S_OK;
	}

	virtual HRESULT __stdcall abi_GetView(typename Abi<Windows::Foundation::Collections::IVectorView<T>>::Type ** view) noexcept override
	{
        *view = this;
        static_cast<::IUnknown *>(*view)->AddRef();
        return S_OK;
	}

	virtual HRESULT __stdcall abi_IndexOf(typename AbiArgument<T>::In value, unsigned * index, boolean * found) noexcept override
	{
		return Call([&]
		{
			*index = std::find(begin(v), end(v), Interop::Forward<T>(value)) - begin(v);
			*found = *index < v.size();
		});
	}

	virtual HRESULT __stdcall abi_SetAt(unsigned index, typename AbiArgument<T>::In item) noexcept override
	{
		return Call([&]
		{
			CopyFromAbi(v.at(index), item);
		});
	}

	virtual HRESULT __stdcall abi_InsertAt(unsigned index, typename AbiArgument<T>::In item) noexcept override
	{
        if (index > v.size())
        {
            return E_FAIL;
        }

		return Call([&]
		{
			CopyFromAbi(*v.emplace(begin(v) + index), item);
		});
	}

	virtual HRESULT __stdcall abi_RemoveAt(unsigned index) noexcept override
	{
        if (index >= v.size())
        {
            return E_FAIL;
        }

		return Call([&]
		{
			v.erase(begin(v) + index);
		});
	}

	virtual HRESULT __stdcall abi_Append(typename AbiArgument<T>::In item) noexcept override
	{
		return Call([&]
		{
			v.emplace_back();
			CopyFromAbi(v.back(), item);
		});
	}

	virtual HRESULT __stdcall abi_RemoveAtEnd() noexcept override
	{
        if (v.empty())
        {
            return E_FAIL;
        }

		return Call([&]
		{
			v.pop_back();
		});
	}

	virtual HRESULT __stdcall abi_Clear() noexcept override
	{
        v.clear();
        return S_OK;
	}

	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, typename AbiArgument<T>::Out /*value*/, unsigned * actual) noexcept override
	{
		return Call([&]
		{
			*actual = v.size() - startIndex;

			if (*actual > capacity)
			{
				*actual = capacity;
			}

			for (unsigned i = 0; i != *actual; ++i)
			{
				//value[i] = v[startIndex + i];
			}
		});
	}

	virtual HRESULT __stdcall abi_ReplaceAll(unsigned /*count*/, typename AbiArgument<T>::Out /*value*/) noexcept override
	{
		return Call([&]
		{
			// v.assign(value, value + count);
		});
	}

    virtual HRESULT __stdcall abi_First(typename Abi<Windows::Foundation::Collections::IIterator<T>>::Type ** first) noexcept override
    {
        return Call([&]
        {
            *first = Make<Windows_Foundation_Collections_IIterator<T>>(this).DetachAbi();
        });
    }
};

}}

namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename T>
IVector<T> Vector()
{
	return Make<Interop::Windows_Foundation_Collections_IVector<T>>();
}

template <typename T>
IVector<T> Vector(std::vector<T> && other)
{
	return Make<Interop::Windows_Foundation_Collections_IVector<T>>(std::move(other));
}

template <typename T>
IVector<T> Vector(std::vector<T> const & other)
{
	return Make<Interop::Windows_Foundation_Collections_IVector<T>>(other);
}

}}}}
