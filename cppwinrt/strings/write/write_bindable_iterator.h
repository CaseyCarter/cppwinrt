
    auto& operator++()
    {
        if (!MoveNext())
        {
            static_cast<D&>(*this) = nullptr;
        }

        return *this;
    }

    auto operator*() const
    {
        return Current();
    }
