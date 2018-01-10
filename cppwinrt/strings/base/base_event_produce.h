
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
            std::destroy(begin(), end());
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
            event_token token{};

            // Extends life of old targets array to release delegates outside of lock.
            delegate_array temp_targets;

            {
                auto change_guard = this->get_change_guard();
                delegate_array new_targets = make_event_array<delegate_type>((!m_targets) ? 1 : m_targets->size() + 1);

                if (m_targets)
                {
                    std::copy_n(m_targets->begin(), m_targets->size(), new_targets->begin());
                }

                if (delegate.template try_as<IAgileObject>())
                {
                    new_targets->back() = delegate;
                }
                else
                {
                    WINRT_ASSERT(delegate.template try_as<IMarshal>());

                    new_targets->back() = [delegate = agile_ref<delegate_type>(delegate)](auto&&... args)
                    {
                        delegate.get()(args...);
                    };
                }

                token = get_token(new_targets->back());

                auto swap_guard = this->get_swap_guard();
                temp_targets = m_targets;
                m_targets = new_targets;
            }

            return token;
        }

        void remove(event_token const token)
        {
            // Extends life of old targets array to release delegates outside of lock.
            delegate_array temp_targets;

            {
                auto change_guard = this->get_change_guard();

                if (!m_targets)
                {
                    return;
                }

                uint32_t const available_slots = m_targets->size() - 1;
                delegate_array new_targets;
                bool removed = false;

                if (available_slots == 0)
                {
                    if (get_token(*m_targets->begin()) == token)
                    {
                        removed = true;
                    }
                }
                else
                {
                    new_targets = make_event_array<delegate_type>(available_slots);
                    auto new_iterator = new_targets->begin();

                    for (delegate_type const& element : *m_targets)
                    {
                        if (!removed&& token == get_token(element))
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

        template<typename...Arg>
        void operator()(Arg const&... args)
        {
            delegate_array temp_targets;

            {
                auto swap_guard = this->get_swap_guard();
                temp_targets = m_targets;
            }

            if (temp_targets)
            {
                for (delegate_type const& element : *temp_targets)
                {
                    bool remove_delegate = false;

                    try
                    {
                        element(args...);
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
                        remove(get_token(element));
                    }
                }
            }
        }

    private:

        event_token get_token(delegate_type const& delegate) const noexcept
        {
            return event_token{ reinterpret_cast<int64_t>(get_abi(delegate)) };
        }

        using delegate_array = com_ptr<event_array<delegate_type>>;

        delegate_array m_targets;
    };

    template <typename Delegate>
    struct event_traits
    {
        using delegate_type = Delegate;

        slim_lock_guard get_swap_guard() noexcept
        {
            return slim_lock_guard(m_swap);
        }

        slim_lock_guard get_change_guard() noexcept
        {
            return slim_lock_guard(m_change);
        }

    private:

        slim_mutex m_swap;
        slim_mutex m_change;
    };

    struct no_lock_guard {};

    template <typename Delegate>
    struct single_threaded_event_traits
    {
        using delegate_type = Delegate;

        no_lock_guard get_swap_guard() const noexcept
        {
            return{};
        }

        no_lock_guard get_change_guard() const noexcept
        {
            return{};
        }
    };
}

WINRT_EXPORT namespace winrt
{
    template <typename Delegate>
    using event = impl::event<impl::event_traits<Delegate>>;

    template <typename Delegate>
    using single_threaded_event = impl::event<impl::single_threaded_event_traits<Delegate>>;
}