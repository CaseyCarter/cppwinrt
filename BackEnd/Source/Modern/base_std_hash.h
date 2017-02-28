namespace winrt::impl
{
    inline size_t hash_data(const void* ptr, size_t numBytes) noexcept
    {
#ifdef WINRT_64
        constexpr size_t fnv_offset_basis = 14695981039346656037ULL;
        constexpr size_t fnv_prime = 1099511628211ULL;
#else
        constexpr size_t fnv_offset_basis = 2166136261U;
        constexpr size_t fnv_prime = 16777619U;
#endif
        size_t result = fnv_offset_basis;
        const uint8_t* const buffer = static_cast<const uint8_t*>(ptr);
        for (size_t next = 0; next < numBytes; ++next)
        {
            result ^= buffer[next];
            result *= fnv_prime;
        }
        return result;
    }

    inline size_t hash_unknown(const Windows::Foundation::IUnknown& value) noexcept
    {
        ::IUnknown* abi_value = nullptr;
        if (value)
        {
            abi_value = get_abi(value.as<Windows::Foundation::IUnknown>());
        }
        return std::hash<::IUnknown*>{}(abi_value);
    }
}

namespace std
{
    template<> struct hash<winrt::Windows::Foundation::IUnknown>
    {
        size_t operator()(const winrt::Windows::Foundation::IUnknown& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<> struct hash<winrt::Windows::Foundation::IInspectable>
    {
        size_t operator()(const winrt::Windows::Foundation::IInspectable& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<> struct hash<winrt::Windows::Foundation::IActivationFactory>
    {
        size_t operator()(const winrt::Windows::Foundation::IActivationFactory& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename T> struct hash<winrt::Windows::Foundation::Collections::IIterator<T>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::IIterator<T>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename T> struct hash<winrt::Windows::Foundation::Collections::IIterable<T>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::IIterable<T>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename T> struct hash<winrt::Windows::Foundation::Collections::IVectorView<T>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::IVectorView<T>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename T> struct hash<winrt::Windows::Foundation::Collections::IVector<T>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::IVector<T>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename T> struct hash<winrt::Windows::Foundation::Collections::IObservableVector<T>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::IObservableVector<T>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename T> struct hash<winrt::Windows::Foundation::Collections::VectorChangedEventHandler<T>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::VectorChangedEventHandler<T>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<> struct hash<winrt::Windows::Foundation::Collections::IVectorChangedEventArgs>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::IVectorChangedEventArgs& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename K, typename V> struct hash<winrt::Windows::Foundation::Collections::IKeyValuePair<K, V>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::IKeyValuePair<K, V>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename K, typename V> struct hash<winrt::Windows::Foundation::Collections::IMapView<K, V>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::IMapView<K, V>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename K, typename V> struct hash<winrt::Windows::Foundation::Collections::IMap<K, V>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::IMap<K, V>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename K, typename V> struct hash<winrt::Windows::Foundation::Collections::IObservableMap<K, V>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::IObservableMap<K, V>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename K, typename V> struct hash<winrt::Windows::Foundation::Collections::MapChangedEventHandler<K, V>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::MapChangedEventHandler<K, V>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename K> struct hash<winrt::Windows::Foundation::Collections::IMapChangedEventArgs<K>>
    {
        size_t operator()(const winrt::Windows::Foundation::Collections::IMapChangedEventArgs<K>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<> struct hash<winrt::Windows::Foundation::IAsyncInfo>
    {
        size_t operator()(const winrt::Windows::Foundation::IAsyncInfo& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<> struct hash<winrt::Windows::Foundation::IAsyncAction>
    {
        size_t operator()(const winrt::Windows::Foundation::IAsyncAction& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename TProgress> struct hash<winrt::Windows::Foundation::IAsyncActionWithProgress<TProgress>>
    {
        size_t operator()(const winrt::Windows::Foundation::IAsyncActionWithProgress<TProgress>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename TResult> struct hash<winrt::Windows::Foundation::IAsyncOperation<TResult>>
    {
        size_t operator()(const winrt::Windows::Foundation::IAsyncOperation<TResult>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename TResult, typename TProgress> struct hash<winrt::Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>>
    {
        size_t operator()(const winrt::Windows::Foundation::IAsyncOperationWithProgress<TResult, TProgress>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<> struct hash<winrt::Windows::Foundation::AsyncActionCompletedHandler>
    {
        size_t operator()(const winrt::Windows::Foundation::AsyncActionCompletedHandler& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename TProgress> struct hash<winrt::Windows::Foundation::AsyncActionProgressHandler<TProgress>>
    {
        size_t operator()(const winrt::Windows::Foundation::AsyncActionProgressHandler<TProgress>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename TProgress> struct hash<winrt::Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>>
    {
        size_t operator()(const winrt::Windows::Foundation::AsyncActionWithProgressCompletedHandler<TProgress>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename TResult> struct hash<winrt::Windows::Foundation::AsyncOperationCompletedHandler<TResult>>
    {
        size_t operator()(const winrt::Windows::Foundation::AsyncOperationCompletedHandler<TResult>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename TResult, typename TProgress> struct hash<winrt::Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>>
    {
        size_t operator()(const winrt::Windows::Foundation::AsyncOperationProgressHandler<TResult, TProgress>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename TResult, typename TProgress> struct hash<winrt::Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>>
    {
        size_t operator()(const winrt::Windows::Foundation::AsyncOperationWithProgressCompletedHandler<TResult, TProgress>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<> struct hash<winrt::Windows::Foundation::IPropertyValue>
    {
        size_t operator()(const winrt::Windows::Foundation::IPropertyValue& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<> struct hash<winrt::Windows::Foundation::IPropertyValueStatics>
    {
        size_t operator()(const winrt::Windows::Foundation::IPropertyValueStatics& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename T> struct hash<winrt::Windows::Foundation::IReference<T>>
    {
        size_t operator()(const winrt::Windows::Foundation::IReference<T>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename T> struct hash<winrt::Windows::Foundation::EventHandler<T>>
    {
        size_t operator()(const winrt::Windows::Foundation::EventHandler<T>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<typename TSender, typename TArgs> struct hash<winrt::Windows::Foundation::TypedEventHandler<TSender, TArgs>>
    {
        size_t operator()(const winrt::Windows::Foundation::TypedEventHandler<TSender, TArgs>& value) const noexcept
        {
            return winrt::impl::hash_unknown(value);
        }
    };

    template<> struct hash<winrt::hstring>
    {
        size_t operator()(const winrt::hstring & value) const noexcept
        {
            uint32_t length = 0;
            const wchar_t* const buffer = WindowsGetStringRawBuffer(get_abi(value), &length);
            return winrt::impl::hash_data(buffer, length * sizeof(wchar_t));
        }
    };
}
