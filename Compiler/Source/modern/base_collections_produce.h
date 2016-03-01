
namespace winrt { namespace Windows { namespace Foundation { namespace Collections {

template <typename T>
struct impl_VectorIterator : impl::implements<IIterator<T>>
{
	IVectorView<T> v;
	unsigned i = 0;

	impl_VectorIterator(abi_arg_in<IVectorView<T>> other)
	{
		copy_from(v, other);
	}

	virtual HRESULT __stdcall get_Current(abi_arg_out<T> current) noexcept override
	{
		return v->abi_GetAt(i, current);
	}

	virtual HRESULT __stdcall get_HasCurrent(bool * hasCurrent) noexcept override
	{
		try
		{
			*hasCurrent = i < v.Size();
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_MoveNext(bool * hasCurrent) noexcept override
	{
		try
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

			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_GetMany(unsigned /*capacity*/, abi_arg_out<T> /*value*/, unsigned * /*actual*/) noexcept override
	{
		return E_NOTIMPL;
	}
};

template <typename T>
struct impl_Vector : impl::implements<IVector<T>, IVectorView<T>, IIterable<T>>
{
	std::vector<T> v;

	impl_Vector(std::vector<T> const & other) :
		v(other)
	{}

	impl_Vector(std::vector<T> && other) :
		v(std::move(other))
	{}

	virtual HRESULT __stdcall abi_GetAt(unsigned index, abi_arg_out<T> item) noexcept override
	{
		try
		{
			copy_to(v.at(index), *item);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall get_Size(unsigned * size) noexcept override
	{
		*size = static_cast<unsigned>(v.size());
		return S_OK;
	}

	virtual HRESULT __stdcall abi_GetView(IVectorView<abi<T>> ** view) noexcept override
	{
		*view = this;
		static_cast<::IUnknown *>(*view)->AddRef();
		return S_OK;
	}

	virtual HRESULT __stdcall abi_IndexOf(abi_arg_in<T> value, unsigned * index, bool * found) noexcept override
	{
		try
		{
			*index = static_cast<unsigned>(std::find(begin(v), end(v), impl::forward<T>(value)) - begin(v));
			*found = *index < v.size();
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_SetAt(unsigned index, abi_arg_in<T> item) noexcept override
	{
		try
		{
			copy_from(v.at(index), item);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_InsertAt(unsigned index, abi_arg_in<T> item) noexcept override
	{
		if (index > v.size())
		{
			return E_BOUNDS;
		}

		try
		{
			copy_from(*v.emplace(begin(v) + index), item);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_RemoveAt(unsigned index) noexcept override
	{
		if (index >= v.size())
		{
			return E_BOUNDS;
		}

		try
		{
			v.erase(begin(v) + index);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_Append(abi_arg_in<T> item) noexcept override
	{
		try
		{
			v.emplace_back();
			copy_from(v.back(), item);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_RemoveAtEnd() noexcept override
	{
		if (v.empty())
		{
			return E_BOUNDS;
		}

		try
		{
			v.pop_back();
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_Clear() noexcept override
	{
		v.clear();
		return S_OK;
	}

	virtual HRESULT __stdcall abi_GetMany(unsigned startIndex, unsigned capacity, abi_arg_out<T> /*value*/, unsigned * actual) noexcept override
	{
		try
		{
			*actual = static_cast<unsigned>(v.size() - startIndex);

			if (*actual > capacity)
			{
				*actual = capacity;
			}

			for (unsigned i = 0; i != *actual; ++i)
			{
				//value[i] = v[startIndex + i];
			}

			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_ReplaceAll(unsigned /*count*/, abi_arg_out<T> /*value*/) noexcept override
	{
		try
		{
			// v.assign(value, value + count);
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}

	virtual HRESULT __stdcall abi_First(abi_arg_out<IIterator<T>> first) noexcept override
	{
		try
		{
			*first = detach(make<impl_VectorIterator<T>>(this));
			return S_OK;
		}
		catch (...) { return impl::to_hresult(); }
	}
};

template <typename T> IVector<T>::IVector(std::vector<T> const & other) : IVector<T>(make<impl_Vector<T>>(other)) {}

template <typename T> IVector<T>::IVector(std::vector<T> && other) : IVector<T>(make<impl_Vector<T>>(std::move(other))) {}

template <typename T> IVector<T>::IVector(std::initializer_list<T> other) : IVector<T>(make<impl_Vector<T>>(other)) {}

}}}}
