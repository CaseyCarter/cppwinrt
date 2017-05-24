
template <typename D> event_revoker<@> consume_%<D>::%(auto_revoke_t, %) const
{
    return impl::make_event_revoker<D, @>(this, &abi_t<@>::remove_%, %(%));
}
