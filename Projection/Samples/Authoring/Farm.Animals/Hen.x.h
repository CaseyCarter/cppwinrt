// TODO: placeholder for XAML compiler generated authoring shims

#pragma once

#define _HEN_X_H_

template <typename D, typename ... I>
using HenT = HenBase<D, I ...>;

template <typename D, typename T, typename ... I>
using HenFactoryT = HenFactoryBase<D, T, I ...>;
