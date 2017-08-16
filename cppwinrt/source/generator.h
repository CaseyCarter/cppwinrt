#pragma once

namespace cppwinrt
{
    template <typename T>
    struct generator
    {
        struct promise_type
        {
            std::variant<T const*, std::exception_ptr> value;

            promise_type& get_return_object() noexcept
            {
                return *this;
            }

            std::experimental::suspend_always initial_suspend() const noexcept
            {
                return {};
            }

            std::experimental::suspend_always final_suspend() const noexcept
            {
                return {};
            }

            std::experimental::suspend_always yield_value(T const& other) noexcept
            {
                value = std::addressof(other);
                return {};
            }

            void return_void() const noexcept
            {
            }

            template <typename Expression>
            Expression&& await_transform(Expression&& expression) const noexcept
            {
                static_assert(sizeof(expression) == 0, "co_await is not supported in coroutines of type generator");
                return std::forward<Expression>(expression);
            }

            void unhandled_exception() noexcept
            {
                value = std::current_exception();
            }

            void rethrow_if_failed() const
            {
                if (value.index() == 1)
                {
                    std::rethrow_exception(std::get<1>(value));
                }
            }
        };

        using handle_type = std::experimental::coroutine_handle<promise_type>;

        struct iterator
        {
            using iterator_category = std::input_iterator_tag;
            using value_type = T;
            using difference_type = ptrdiff_t;
            using pointer = T const*;
            using reference = T const&;

            handle_type m_handle;

            iterator(std::nullptr_t) noexcept : m_handle(nullptr)
            {
            }

            iterator(handle_type handle_type) noexcept : m_handle(handle_type)
            {
            }

            iterator &operator++()
            {
                m_handle.resume();

                if (m_handle.done())
                {
                    promise_type& promise = m_handle.promise();
                    m_handle = nullptr;
                    promise.rethrow_if_failed();
                }

                return *this;
            }

            iterator operator++(int) = delete;

            bool operator==(iterator const& other) const noexcept
            {
                return m_handle == other.m_handle;
            }

            bool operator!=(iterator const& other) const noexcept
            {
                return !(*this == other);
            }

            T const& operator*() const noexcept
            {
                return *std::get<0>(m_handle.promise().value);
            }

            T const* operator->() const noexcept
            {
                return std::addressof(operator*());
            }
        };

        iterator begin()
        {
            if (!m_handle)
            {
                return nullptr;
            }

            m_handle.resume();

            if (m_handle.done())
            {
                m_handle.promise().rethrow_if_failed();
                return nullptr;
            }

            return m_handle;
        }

        iterator end() noexcept
        {
            return nullptr;
        }

        generator(promise_type& promise) noexcept : m_handle(handle_type::from_promise(promise))
        {
        }

        generator() = default;
        generator(generator const&) = delete;
        generator &operator=(generator const&) = delete;

        generator(generator&& other) noexcept : m_handle(other.m_handle)
        {
            other.m_handle = nullptr;
        }

        generator &operator=(generator&& other) noexcept
        {
            if (this != &other)
            {
                m_handle = other.m_handle;
                other.m_handle = nullptr;
            }

            return *this;
        }

        ~generator() noexcept
        {
            if (m_handle)
            {
                m_handle.destroy();
            }
        }

    private:

        handle_type m_handle{ nullptr };
    };
}
