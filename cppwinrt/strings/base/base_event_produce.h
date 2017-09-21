
namespace winrt::impl
{
    template <typename T>
    struct event_array
    {
        using value_type = T;
        using reference = value_type&;
        using pointer = value_type*;
        using iterator = array_iterator<value_type>;

        explicit event_array(uint32_t const count) noexcept : m_size(count)
        {
            std::uninitialized_fill_n(data(), count, value_type());
        }

        unsigned long AddRef() noexcept
        {
            return 1 + m_references.fetch_add(1, std::memory_order_relaxed);
        }

        unsigned long Release() noexcept
        {
            uint32_t const remaining = m_references.fetch_sub(1, std::memory_order_release) - 1;

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
            return*(data() + m_size - 1);
        }

        iterator begin() noexcept
        {
            return make_array_iterator(data(), m_size);
        }

        iterator end() noexcept
        {
            return make_array_iterator(data(), m_size, m_size);
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
    auto make_event_array(uint32_t const capacity)
    {
        com_ptr<event_array<T>> instance;
        void* raw = ::operator new(sizeof(event_array<T>) + (sizeof(T)* capacity));
        #pragma warning(suppress: 6386)
        *put_abi(instance) = new(raw) event_array<T>(capacity);
        return instance;
    }

    template <typename Traits>
    struct event : Traits
    {
        using delegate_type = typename Traits::delegate_type;

        event() = default;
        event(event<Traits> const&) = delete;
        event<Traits>& operator =(event<Traits> const&) = delete;

        explicit operator bool() const noexcept
        {
            return m_targets != nullptr;
        }

        event_token add(delegate_type const& delegate)
        {
            if (delegate == nullptr)
            {
                throw hresult_invalid_argument();
            }

            event_token token{};
            delegate_array temp_targets;

            {
                auto change_guard = this->get_change_guard();
                delegate_array new_targets = make_event_array<storage_type>((!m_targets) ? 1 : m_targets->size() + 1);

                if (m_targets)
                {
                    std::copy_n(m_targets->begin(), m_targets->size(), new_targets->begin());
                }

                token.value = reinterpret_cast<int64_t>(get_abi(delegate));
                new_targets->back() = delegate;

                auto swap_guard = this->get_swap_guard();
                temp_targets = m_targets;
                m_targets = new_targets;
            }

            return token;
        }

        void remove(event_token const token)
        {
            delegate_array temp_targets;

            {
                auto change_guard = this->get_change_guard();

                if (!m_targets)
                {
                    return;
                }

                uint32_t available_slots = m_targets->size() - 1;
                delegate_array new_targets;
                bool removed = false;

                if (available_slots == 0)
                {
                    if (this->get_token(*m_targets->begin()) == token)
                    {
                        removed = true;
                    }
                }
                else
                {
                    new_targets = make_event_array<storage_type>(available_slots);
                    auto new_iterator = new_targets->begin();

                    for (storage_type const& element : *m_targets)
                    {
                        if (!removed&& token == this->get_token(element))
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
                    auto swap_guard = this->get_swap_guard();
                    temp_targets = m_targets;
                    m_targets = new_targets;
                }
            }
        }

        template<typename ...Arg>
        void operator()(Arg const& ... args)
        {
            delegate_array temp_targets;

            {
                auto swap_guard = this->get_swap_guard();
                temp_targets = m_targets;
            }

            if (temp_targets)
            {
                for (storage_type const& element : *temp_targets)
                {
                    bool remove_delegate = false;

                    try
                    {
                        this->invoke(element, args...);
                    }
                    catch (hresult_error const& e)
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
                        remove(this->get_token(element));
                    }
                }
            }
        }

    private:

        using storage_type = typename Traits::storage_type;
        using delegate_array = com_ptr<event_array<storage_type>>;

        delegate_array m_targets;
    };

    struct no_lock_guard {};

    struct locked_event_traits
    {
        lock_guard get_swap_guard() noexcept
        {
            return lock_guard(m_swap);
        }

        lock_guard get_change_guard() noexcept
        {
            return lock_guard(m_change);
        }

    private:

        mutex m_swap;
        mutex m_change;
    };

    template <typename Delegate>
    struct single_threaded_event_traits
    {
        using delegate_type = Delegate;
        using storage_type = Delegate;

        template <typename ... Args>
        void invoke(storage_type const& delegate, Args const& ... args) const
        {
            delegate(args ...);
        }

        event_token get_token(storage_type const& delegate) const noexcept
        {
            return event_token{ reinterpret_cast<int64_t>(get_abi(delegate)) };
        }

        no_lock_guard get_swap_guard() const noexcept
        {
            return{};
        }

        no_lock_guard get_change_guard() const noexcept
        {
            return{};
        }
    };

#ifndef WINRT_NO_AGILE_REFERENCE

    template <typename Delegate>
    struct agile_event_traits : locked_event_traits
    {
        using delegate_type = Delegate;
        using storage_type = agile_ref<Delegate>;

        template <typename ... Args>
        void invoke(storage_type const& delegate, Args const& ... args) const
        {
            delegate.get()(args ...);
        }

        event_token get_token(storage_type const& delegate) const noexcept
        {
            return event_token{ reinterpret_cast<int64_t>(get_abi(delegate.get())) };
        }
    };

#endif

    template <typename Delegate>
    struct non_agile_event_traits : locked_event_traits
    {
        using delegate_type = Delegate;
        using storage_type = Delegate;

        template <typename ... Args>
        void invoke(storage_type const& delegate, Args const& ... args) const
        {
            delegate(args ...);
        }

        event_token get_token(storage_type const& delegate) const noexcept
        {
            return event_token{ reinterpret_cast<int64_t>(get_abi(delegate)) };
        }
    };
}

WINRT_EXPORT namespace winrt
{
#ifndef WINRT_NO_AGILE_REFERENCE

    template <typename Delegate>
    using agile_event = impl::event<impl::agile_event_traits<Delegate>>;

#endif

    template <typename Delegate>
    using non_agile_event = impl::event<impl::non_agile_event_traits<Delegate>>;

    template <typename Delegate>
    using single_threaded_event = impl::event<impl::single_threaded_event_traits<Delegate>>;
}