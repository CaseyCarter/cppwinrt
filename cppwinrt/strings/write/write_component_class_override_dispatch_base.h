protected:
    using dispatch = impl::dispatch_to_super<D@>;
    auto super() noexcept { return dispatch::super(static_cast<D&>(*this)); }
