﻿// WARNING: Please don't edit this file. It was generated by C++/WinRT v1.0.170906.1

#pragma once

namespace winrt::impl {

struct module_lock
{
    module_lock();
    ~module_lock();
};

template <typename T, typename D>
struct WINRT_EBO produce_dispatch_to_super<T, D, Composable::Base::IRootOverrides>
    : produce_dispatch_to_super_base<T, D, Composable::Base::IRootOverrides>
{
    hstring VirtualPublicRootMethod()
    {
        Composable::Base::IRootOverrides super = this->shim_super();
        if (super)
        {
            return super.VirtualPublicRootMethod();
        }
        return this->shim().VirtualPublicRootMethod();
    }
};
}
