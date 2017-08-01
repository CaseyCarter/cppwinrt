
namespace impl
{
    template <typename T>
    struct handle_traits
    {
        using type = T;

        constexpr static type invalid() noexcept
        {
            return nullptr;
        }

        // static void close(type value) noexcept;
    };

    template <typename T>
    struct handle
    {
        using type = typename T::type;

        handle() noexcept = default;

        handle(type value) noexcept :
        m_value(value)
        {}

        handle(handle&& other) noexcept :
            m_value(other.detach())
        {}

        handle& operator=(handle&& other) noexcept
        {
            if (this != &other)
            {
                attach(other.detach());
            }

            return*this;
        }

        ~handle() noexcept
        {
            close();
        }

        void close() noexcept
        {
            if (*this)
            {
                T::close(m_value);
                m_value = T::invalid();
            }
        }

        explicit operator bool() const noexcept
        {
            return T::invalid() != m_value;
        }

        type get() const noexcept
        {
            return m_value;
        }

        type* put() noexcept
        {
            WINRT_ASSERT(m_value == T::invalid());
            return &m_value;
        }

        void attach(type value) noexcept
        {
            close();
            *put() = value;
        }

        type detach() noexcept
        {
            type value = m_value;
            m_value = T::invalid();
            return value;
        }

        friend void swap(handle& left, handle& right) noexcept
        {
            std::swap(left.m_value, right.m_value);
        }

    private:

        type m_value = T::invalid();
    };

    template <typename T>
    bool operator==(handle<T> const& left, handle<T> const& right) noexcept
    {
        return left.get() == right.get();
    }

    template <typename T>
    bool operator!=(handle<T> const& left, handle<T> const& right) noexcept
    {
        return !(left == right);
    }

    template <typename T>
    bool operator<(handle<T> const& left, handle<T> const& right) noexcept
    {
        return left.get() < right.get();
    }

    template <typename T>
    bool operator>(handle<T> const& left, handle<T> const& right) noexcept
    {
        return right < left;
    }

    template <typename T>
    bool operator<=(handle<T> const& left, handle<T> const& right) noexcept
    {
        return !(right < left);
    }

    template <typename T>
    bool operator>=(handle<T> const& left, handle<T> const& right) noexcept
    {
        return !(left < right);
    }
}
