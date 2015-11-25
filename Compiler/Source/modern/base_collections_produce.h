
namespace Modern { namespace Windows { namespace Foundation { namespace Collections {

template <typename T>
struct impl_VectorIterator : ImplementsDefault<IIterator<T>>
{
	Windows::Foundation::Collections::IVectorView<T> v;
	unsigned i = 0;

	impl_VectorIterator(AbiArgIn<IVectorView<T>> other)
	{
		copy(v, other);
	}

	virtual HRESULT __stdcall get_Current(AbiArgOut<T> current) noexcept override
	{
		return v->abi_GetAt(i, current);
	}

	virtual HRESULT __stdcall get_HasCurrent(boolean * hasCurrent) noexcept override
	{
		return call([&]
		{
			*hasCurrent = i < v.Size();
		});
	}

	virtual HRESULT __stdcall abi_MoveNext(boolean * hasCurrent) noexcept override
	{
		return call([&]
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

	virtual HRESULT __stdcall abi_GetMany(unsigned /*capacity*/, AbiArgOut<T> /*value*/, unsigned * /*actual*/) noexcept override
	{
		return E_NOTIMPL;
	}
};

template <typename T>
struct impl_Vector : ImplementsDefault<IVector<T>, IVectorView<T>, IIterable<T>>
{
	std::vector<T> v;

	template <typename ... Args>
	impl_Vector(Args && ... args) :
		v(std::forward(args) ...)
	{}

	virtual HRESULT __stdcall abi_GetAt(unsigned /*index*/, AbiArgOut<T> /*item*/) noexcept override
	{
		return call([&]
		{
			//CopyToAbi(*item, v.at(index));
		});
	}

	virtual HRESULT __stdcall get_Size(unsigned * size) noexcept override
	{
		*size = v.size();
		return S_OK;
	}

	virtual HRESULT __stdcall abi_GetView(AbiArgOut<IVectorView<T>> view) noexcept override
	{
		*view = this;
		static_cast<::IUnknown *>(*view)->AddRef();
		return S_OK;
	}

	virtual HRESULT __stdcall abi_IndexOf(AbiArgIn<T> /*value*/, unsigned * index, boolean * found) noexcept override
	{
		return call([&]
		{
			//*index = std::find(begin(v), end(v), Interop::Forward<T>(value)) - begin(v);
			*found = *index < v.size();
		});
	}

	virtual HRESULT __stdcall abi_SetAt(unsigned /*index*/, AbiArgIn<T> /*item*/) noexcept override
	{
		return call([&]
		{
			//CopyFromAbi(v.at(index), item);
		});
	}

	virtual HRESULT __stdcall abi_InsertAt(unsigned index, AbiArgIn<T> /*item*/) noexcept override
	{
		if (index > v.size())
		{
			return E_FAIL;
		}

		return call([&]
		{
			//CopyFromAbi(*v.emplace(begin(v) + index), item);
		});
	}

	virtual HRESULT __stdcall abi_RemoveAt(unsigned index) noexcept override
	{
		if (index >= v.size())
		{
			return E_FAIL;
		}

		return call([&]
		{
			v.erase(begin(v) + index);
		});
	}

	virtual HRESULT __stdcall abi_Append(AbiArgIn<T> /*item*/) noexcept override
	{
		return call([&]
		{
			v.emplace_back();
			//CopyFromAbi(v.back(), item);
		});
	}

	virtual HRESULT __stdcall abi_RemoveAtEnd() noexcept override
	{
		if (v.empty())
		{
			return E_FAIL;
		}

		return call([&]
		{
			v.pop_back();
		});
	}

	virtual HRESULT __stdcall abi_Clear() noexcept override
	{
		v.clear();
		return S_OK;
	}

	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, AbiArgOut<T> /*value*/, unsigned * actual) noexcept override
	{
		return call([&]
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

	virtual HRESULT __stdcall abi_ReplaceAll(unsigned /*count*/, AbiArgOut<T> /*value*/) noexcept override
	{
		return call([&]
		{
			// v.assign(value, value + count);
		});
	}

	virtual HRESULT __stdcall abi_First(Abi<IIterator<T>> ** first) noexcept override
	{
		return call([&]
		{
			*first = detach(make<impl_VectorIterator<T>>(this));
		});
	}
};

}}}}
