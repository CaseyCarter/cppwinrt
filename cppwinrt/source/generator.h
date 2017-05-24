#pragma once

namespace cppwinrt
{
    template <typename T>
    struct generator
    {
        struct promise_type
        {
            T const* m_current{ nullptr };
            std::optional<std::exception_ptr> m_exception;

            promise_type& get_return_object() noexcept
            {
                return *this;
            }

            bool initial_suspend() noexcept
            {
                return true;
            }

            bool final_suspend() noexcept
            {
                return true;
            }

            void yield_value(T const& value) noexcept
            {
                m_current = std::addressof(value);
            }

            template <typename Expression>
            Expression&& await_transform(Expression&& expression) noexcept
            {
                static_assert(false, "co_await is not supported in coroutines of type generator");
                return std::forward<Expression>(expression);
            }

            void set_exception(std::exception_ptr&& exception) noexcept
            {
                m_exception = std::move(exception);
            }

            void rethrow_exception()
            {
                if (m_exception)
                {
                    std::rethrow_exception(m_exception.value());
                }
            }
        };

        struct iterator
        {
            using iterator_category = std::input_iterator_tag;
            using value_type = T;
            using difference_type = ptrdiff_t;
            using pointer = T*;
            using reference = T&;

            std::experimental::coroutine_handle<promise_type> m_coroutine;

            iterator(std::nullptr_t) noexcept : m_coroutine(nullptr)
            {
            }

            iterator(std::experimental::coroutine_handle<promise_type> handle) noexcept : m_coroutine(handle)
            {
            }

            iterator &operator++()
            {
                m_coroutine.resume();

                if (m_coroutine.done())
                {
                    m_coroutine.promise().rethrow_exception();
                    m_coroutine = nullptr;
                }

                return *this;
            }

            iterator operator++(int) = delete;

            bool operator==(iterator const& other) const noexcept
            {
                return m_coroutine == other.m_coroutine;
            }

            bool operator!=(iterator const& other) const noexcept
            {
                return !(*this == other);
            }

            T const& operator*() const noexcept
            {
                return *m_coroutine.promise().m_current;
            }

            T const* operator->() const noexcept
            {
                return std::addressof(operator*());
            }
        };

        iterator begin()
        {
            if (m_coroutine)
            {
                m_coroutine.resume();

                if (m_coroutine.done())
                {
                    m_coroutine.promise().rethrow_exception();
                    return nullptr;
                }
            }

            return m_coroutine;
        }

        iterator end() noexcept
        {
            return nullptr;
        }

        explicit generator(promise_type& promise) noexcept :
            m_coroutine(std::experimental::coroutine_handle<promise_type>::from_promise(promise))
        {
        }

        generator() = default;
        generator(generator const&) = delete;
        generator &operator=(generator const&) = delete;

        generator(generator&& other) noexcept : m_coroutine(other.m_coroutine)
        {
            other.m_coroutine = nullptr;
        }

        generator &operator=(generator&& other) noexcept
        {
            if (this != std::addressof(other))
            {
                m_coroutine = other.m_coroutine;
                other.m_coroutine = nullptr;
            }

            return *this;
        }

        ~generator() noexcept
        {
            if (m_coroutine)
            {
                m_coroutine.destroy();
            }
        }

    private:

        std::experimental::coroutine_handle<promise_type> m_coroutine{ nullptr };
    };
}
