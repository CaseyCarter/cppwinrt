
        if (0 == wcscmp(name, L"%"))
        {
            *factory = winrt::detach_abi(winrt::make<winrt::@::factory_implementation::%>());
            return S_OK;
        }
