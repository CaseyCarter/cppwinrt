
WINRT_EXPORT namespace winrt
{
    struct access_token : handle
    {
        static access_token process()
        {
            access_token token;
            check_bool(OpenProcessToken(GetCurrentProcess(), TOKEN_DUPLICATE, token.put()));
            access_token duplicate;
            check_bool(DuplicateToken(token.get(), SecurityImpersonation, duplicate.put()));
            return duplicate;
        }

        static access_token thread()
        {
            access_token token;

            if (!OpenThreadToken(GetCurrentThread(), TOKEN_IMPERSONATE, TRUE, token.put()))
            {
                DWORD const error = GetLastError();

                if (error != ERROR_NO_TOKEN)
                {
                    throw_hresult(HRESULT_FROM_WIN32(error));
                }
            }

            return token;
        }

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
        static access_token client()
        {
            struct impersonate_guard
            {
                impersonate_guard(com_ptr<IServerSecurity> const& server) : m_server(server)
                {
                    check_hresult(m_server->ImpersonateClient());
                }

                ~impersonate_guard()
                {
                    check_hresult(m_server->RevertToSelf());
                }

            private:

                com_ptr<IServerSecurity> const& m_server;
            };

            com_ptr<IServerSecurity> server;
            check_hresult(CoGetCallContext(__uuidof(server), server.put_void()));
            impersonate_guard impersonate(server);
            return thread();
        }
#endif

        access_token() = default;
        access_token(access_token&& other) = default;
        access_token& operator=(access_token&& other) = default;

        access_token impersonate() const
        {
            auto previous = thread();
            check_bool(SetThreadToken(nullptr, get()));
            return previous;
        }

        void revert() const
        {
            check_bool(SetThreadToken(nullptr, get()));
        }

        auto operator()() const
        {
            struct guard
            {
                guard(access_token&& previous) noexcept : m_previous(std::move(previous))
                {
                }

                ~guard()
                {
                    m_previous.revert();
                }

                guard(guard const&)
                {
                    // A Visual C++ compiler bug (550631) requires the copy constructor even though it is never called.
                    WINRT_ASSERT(false);
                }

            private:

                access_token const m_previous;
            };

            return guard(impersonate());
        }
    };
}
