// C++ for the Windows Runtime v1.29
// Copyright (c) 2016 Microsoft Corporation

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Data {

struct LoadMoreItemsResult;

}

namespace Windows::UI::Xaml::Data {

using LoadMoreItemsResult = ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult;

}

namespace ABI::Windows::UI::Xaml::Data {

struct CurrentChangingEventHandler;
struct IBinding;
struct IBinding2;
struct IBindingBase;
struct IBindingBaseFactory;
struct IBindingExpression;
struct IBindingExpressionBase;
struct IBindingExpressionBaseFactory;
struct IBindingExpressionFactory;
struct IBindingFactory;
struct IBindingOperations;
struct IBindingOperationsStatics;
struct ICollectionView;
struct ICollectionViewFactory;
struct ICollectionViewGroup;
struct ICollectionViewSource;
struct ICollectionViewSourceStatics;
struct ICurrentChangingEventArgs;
struct ICurrentChangingEventArgsFactory;
struct ICustomProperty;
struct ICustomPropertyProvider;
struct IItemIndexRange;
struct IItemIndexRangeFactory;
struct IItemsRangeInfo;
struct INotifyPropertyChanged;
struct IPropertyChangedEventArgs;
struct IPropertyChangedEventArgsFactory;
struct IRelativeSource;
struct IRelativeSourceFactory;
struct ISelectionInfo;
struct ISupportIncrementalLoading;
struct IValueConverter;
struct PropertyChangedEventHandler;
struct Binding;
struct BindingBase;
struct BindingExpression;
struct BindingExpressionBase;
struct BindingOperations;
struct CollectionViewSource;
struct CurrentChangingEventArgs;
struct ItemIndexRange;
struct PropertyChangedEventArgs;
struct RelativeSource;

}

namespace Windows::UI::Xaml::Data {

struct CurrentChangingEventHandler;
struct PropertyChangedEventHandler;
struct IBinding;
struct IBinding2;
struct IBindingBase;
struct IBindingBaseFactory;
struct IBindingExpression;
struct IBindingExpressionBase;
struct IBindingExpressionBaseFactory;
struct IBindingExpressionFactory;
struct IBindingFactory;
struct IBindingOperations;
struct IBindingOperationsStatics;
struct ICollectionView;
struct ICollectionViewFactory;
struct ICollectionViewGroup;
struct ICollectionViewSource;
struct ICollectionViewSourceStatics;
struct ICurrentChangingEventArgs;
struct ICurrentChangingEventArgsFactory;
struct ICustomProperty;
struct ICustomPropertyProvider;
struct IItemIndexRange;
struct IItemIndexRangeFactory;
struct IItemsRangeInfo;
struct INotifyPropertyChanged;
struct IPropertyChangedEventArgs;
struct IPropertyChangedEventArgsFactory;
struct IRelativeSource;
struct IRelativeSourceFactory;
struct ISelectionInfo;
struct ISupportIncrementalLoading;
struct IValueConverter;
struct Binding;
struct BindingBase;
struct BindingExpression;
struct BindingExpressionBase;
struct BindingOperations;
struct CollectionViewSource;
struct CurrentChangingEventArgs;
struct ItemIndexRange;
struct PropertyChangedEventArgs;
struct RelativeSource;

}

namespace Windows::UI::Xaml::Data {

enum class BindingMode
{
    OneWay = 1,
    OneTime = 2,
    TwoWay = 3,
};

enum class RelativeSourceMode
{
    None = 0,
    TemplatedParent = 1,
    Self = 2,
};

enum class UpdateSourceTrigger
{
    Default = 0,
    PropertyChanged = 1,
    Explicit = 2,
};

}

}