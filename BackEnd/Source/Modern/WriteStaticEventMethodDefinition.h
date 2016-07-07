
inline factory_event_revoker<%> %::%(auto_revoke_t, %)
{
    auto factory = GetActivationFactory<%, %>();
    return { factory, &ABI::%::%::remove_%, factory.%(%) };
}
