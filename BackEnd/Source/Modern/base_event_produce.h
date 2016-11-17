
namespace impl {

template <typename T>
struct event_array
{
    using value_type = T;
    using reference = value_type &;
    using pointer = value_type *;
    using iterator = impl::array_iterator<value_type>;

    explicit event_array(const uint32_t count) noexcept : m_size(count)
    {
        std::uninitialized_fill_n(data(), count, value_type());
    }

    unsigned long AddRef() noexcept
    {
        return 1 + m_references.fetch_add(1, std::memory_order_relaxed);
    }

    unsigned long Release() noexcept
    {
        const uint32_t remaining = m_references.fetch_sub(1, std::memory_order_release) - 1;

        if (remaining == 0)
        {
            std::atomic_thread_fence(std::memory_order_acquire);
            this->~event_array();
            ::operator delete(static_cast<void*>(this));
        }

        return remaining;
    }

    reference back() noexcept
    {
        WINRT_ASSERT(m_size > 0);
        return *(data() + m_size - 1);
    }

    iterator begin() noexcept
    {
        return impl::make_array_iterator(data(), m_size);
    }

    iterator end() noexcept
    {
        return impl::make_array_iterator(data(), m_size, m_size);
    }

    uint32_t size() const noexcept
    {
        return m_size;
    }

    ~event_array() noexcept
    {
        for (reference element : *this)
        {
            element.~T();
        }
    }

private:

    pointer data() noexcept
    {
        return reinterpret_cast<pointer>(this + 1);
    }

    std::atomic<uint32_t> m_references{ 1 };
    uint32_t m_size{ 0 };
};

template <typename T>
auto make_event_array(const uint32_t capacity)
{
    com_ptr<event_array<T>> instance;
    void* raw = ::operator new(sizeof(event_array<T>) + (sizeof(T) * capacity));
    *put(instance) = new(raw) event_array<T>(capacity);
    return instance;
}

}

template<typename Delegate>
struct event
{
    event() = default;
    event(const event<Delegate>&) = delete;
    event<Delegate> &operator =(const event<Delegate> &) = delete;

    explicit operator bool() const noexcept
    {
        return m_targets != nullptr;
    }

    event_token add(const Delegate & delegate)
    {
        if (delegate == nullptr)
        {
            throw hresult_invalid_argument();
        }

        event_token token{};
        delegate_array temp_targets;

        {
            lock_guard add_remove_lock(m_add_remove_lock);
            delegate_array new_targets = impl::make_event_array<agile_delegate>((!m_targets) ? 1 : m_targets->size() + 1);

            if (m_targets)
            {
                std::copy_n(m_targets->begin(), m_targets->size(), new_targets->begin());
            }

            token.value = reinterpret_cast<int64_t>(get(delegate));
            new_targets->back() = delegate;

            lock_guard targets_pointer_lock(m_targets_pointer_lock);
            temp_targets = m_targets;
            m_targets = new_targets;
        }

        return token;
    }

    void remove(const event_token token)
    {
        delegate_array temp_targets;

        {
            lock_guard add_remove_lock(m_add_remove_lock);

            if (!m_targets)
            {
                return;
            }

            uint32_t available_slots = m_targets->size() - 1;
            delegate_array new_targets;
            bool removed = false;

            if (available_slots == 0)
            {
                abi<Delegate> * raw_delegate_address = get(m_targets->begin()->get());

                if (reinterpret_cast<int64_t>(raw_delegate_address) == token.value)
                {
                    removed = true;
                }
            }
            else
            {
                new_targets = impl::make_event_array<agile_delegate>(available_slots);
                auto new_iterator = new_targets->begin();

                for (const agile_delegate & element : *m_targets)
                {
                    if (!removed && token.value == reinterpret_cast<int64_t>(get(element.get())))
                    {
                        removed = true;
                        continue;
                    }

                    *new_iterator = element;
                    ++new_iterator;
                }
            }

            if (removed)
            {
                lock_guard targets_pointer_lock(m_targets_pointer_lock);
                temp_targets = m_targets;
                m_targets = new_targets;
            }
        }
    }

    template<typename ...Arg>
    void operator()(const Arg & ... args)
    {
        delegate_array temp_targets;

        {
            lock_guard targets_pointer_lock(m_targets_pointer_lock);
            temp_targets = m_targets;
        }

        if (temp_targets)
        {
            for (const agile_delegate & element : *temp_targets)
            {
                bool remove_delegate = false;

                try
                {
                    element.get()(args...);
                }
                catch (const hresult_error& e)
                {
                    if (e.code() == JSCRIPT_E_CANTEXECUTE ||
                        e.code() == RPC_S_SERVER_UNAVAILABLE ||
                        e.code() == RPC_E_DISCONNECTED)
                    {
                        remove_delegate = true;
                    }
                }

                if (remove_delegate)
                {
                    remove(event_token{ reinterpret_cast<__int64>(get(element.get())) });
                }
            }
        }
    }

private:
    using agile_delegate = agile_ref<Delegate>;
    using delegate_array = com_ptr<impl::event_array<agile_delegate>>;

    delegate_array m_targets;
    lock m_targets_pointer_lock;
    lock m_add_remove_lock;
};