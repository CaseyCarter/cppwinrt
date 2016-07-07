#pragma once

//
// This is simple event implementation that is used for testing until the base library
// provides a formal implementation.
//

namespace winrt {

template <typename T>
class event
{
    lock m_lock;
    std::shared_ptr<std::set<T>> m_handlers;

public:

    using type = T;

    event(const event &) = delete;
    event & operator=(const event &) = delete;

    event() = default;

    event_token add(const T & handler)
    {
        lock_guard guard(m_lock);
        std::shared_ptr<std::set<T>> handlers = std::make_shared<std::set<T>>();

        if (std::set<T> * set = m_handlers.get())
        {
            handlers->insert(set->begin(), set->end());
        }

        handlers->insert(handler);
        m_handlers = std::move(handlers);
        return { reinterpret_cast<int64_t>(get(handler)) };
    }

    void remove(const event_token token)
    {
        lock_guard guard(m_lock);
        std::shared_ptr<std::set<T>> handlers = std::make_shared<std::set<T>>();

        if (std::set<T> * set = m_handlers.get())
        {
            handlers->insert(set->begin(), set->end());
        }

        handlers->erase(reinterpret_cast<const T &>(token));
        m_handlers = std::move(handlers);
    }

    template <typename ... A> void operator()(A const & ... args) const
    {
        std::shared_ptr<std::set<T>> handlers = m_handlers;

        if (std::set<T> * set = handlers.get())
        {
            for (const T & handler : *set)
            {
                handler(args ...);
            }
        }
    }
};

}
