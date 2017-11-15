
        if (0 == wcscmp(name, L"%"))
        {
            *factory = detach_abi(make<@::factory_implementation::%>());
            return S_OK;
        }
