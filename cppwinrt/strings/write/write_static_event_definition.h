
inline factory_event_revoker<%> %::%(auto_revoke_t, %)
{
    auto factory = get_activation_factory<%, %>();
    return { factory, &abi_t<%>::remove_%, factory.%(%) };
}
