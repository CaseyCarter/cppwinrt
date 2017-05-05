<?xml version="1.0" encoding="utf-8"?> 
<AutoVisualizer xmlns="http://schemas.microsoft.com/vstudio/debugger/natvis/2010">

<!--Base support for C++/WinRT projections-->
<Type Name="winrt::Windows::Foundation::IInspectable">
    <Intrinsic Name="WINRT_get_ref" Expression='"C++/WinRT reference properties are not supported."'>
        <Parameter Name="object" Type="void *" />
        <Parameter Name="iid" Type="const wchar_t *" />
        <Parameter Name="method" Type="int" />
    </Intrinsic>
</Type>

%
</AutoVisualizer>
