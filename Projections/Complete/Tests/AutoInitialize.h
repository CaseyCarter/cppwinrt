#pragma once

struct AutoInitialize
{
    AutoInitialize()
    {
        winrt::Initialize();
    }

    ~AutoInitialize()
    {
        winrt::Uninitialize();
    }
};
