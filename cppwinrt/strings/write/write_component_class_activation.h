
        if (0 == wcscmp(name, L"%"))
        {
            *factory = winrt::@::factory_implementation::make_for_%();
            return S_OK;
        }
