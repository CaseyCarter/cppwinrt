# The file produced by this script is awesome. But it is not the long term solution.
# The generation of this file should be in the compiler and piggy back on the compiler's test option.

# Get the current header from the SDK that contains the guids and types of supported generic instantiations
$header = get-content ($env:WindowsSdkDir + '\Include\' + $env:WindowsSDKVersion + '\winrt\windows.foundation.h')

# Make a list of all of the generic type instantiations and their corresponding and guids
$types = New-Object System.Collections.Generic.List[System.String[]]

for($i = 0; $i -lt $header.Count; $i++)
{
    $guidMatch = $header[$i] -cmatch '^struct\ __declspec\(uuid.*'
    if($guidMatch) 
    {
        $typesToMatch = 'IMapChangedEventArgs|'
        $typesToMatch += 'VectorChangedEventHandler|'
        $typesToMatch += 'MapChangedEventHandler|'
        $typesToMatch += 'IIterator|'
        $typesToMatch += 'IIterable|'
        $typesToMatch += 'IVectorView|'
        $typesToMatch += 'IVector|'
        $typesToMatch += 'IObservableVector|'
        $typesToMatch += 'IKeyValuePair|'
        $typesToMatch += 'IMapView|'
        $typesToMatch += 'IMap|'
        $typesToMatch += 'IObservableMap|'
        $typesToMatch += 'IReference|'
        $typesToMatch += 'AsyncOperationCompletedHandler|'
        $typesToMatch += 'AsyncActionProgressHandler|'
        $typesToMatch += 'AsyncOperationProgressHandler|'
        $typesToMatch += 'AsyncOperationWithProgressCompletedHandler|'
        $typesToMatch += 'IAsyncOperation|'
        $typesToMatch += 'IAsyncActionWithProgress|'
        $typesToMatch += 'IAsyncOperationWithProgress|'
        $typesToMatch += 'EventHandler|'
        $typesToMatch += "TypedEventHandler"

        $typeMatch = $header[$i + 1] -cmatch '^(' + $typesToMatch + ')<'
        if($typeMatch)
        {
            # Isolate the guid and type name
            $matchedGuid = [regex]::Match($header[$i], 'uuid\("([0-9a-fA-F-]{36})"\)').captures[0].groups[1].value
            $matchedType = [regex]::Match($header[$i + 1], '^(.*>)\s:').captures[0].groups[1].value

            # Fix up types so they are in the format expected by the projection.
            $matchedType = $matchedType.Replace('HSTRING', 'hstring')
            $matchedType = $matchedType.Replace('UINT32', 'unsigned int')
            $matchedType = $matchedType.Replace('__int64', 'long long')
            $matchedType = $matchedType.Replace('UINT64', 'unsigned long long')
            $matchedType = $matchedType.Replace('*', '')
            $matchedType = $matchedType.Replace('ABI::', '')
            $matchedType = $matchedType.Replace('struct ', '')
            $matchedType = $matchedType.Replace('__C', '::')

            # winrt::Windows::Foundation::IInspectable will be aliased
            $matchedType = $matchedType.Replace('IInspectable', 'cppwinrtIInspectable')
            
            # Change MIDL type constant to C++ syntax
            while($matchedType.Contains('__F'))
            {
                $matchedType = [regex]::Replace($matchedType, '__F(.*?)_[0-9]+_?(.*)', '$1<$2>')
            }
            
            # There should be no more underscores in names. Any remaining should really be commas
            $matchedType = $matchedType.Replace('_', ',')

            $pair = $matchedType, $matchedGuid
            $types.Add($pair)
        }
    }
}

#figure out the headers we need
$headers = New-Object System.Collections.Generic.HashSet[System.String]
$added = $headers.Add('Windows.Foundation.h')
$added = $headers.Add('Windows.Foundation.Collections.h')

foreach($pair in $types)
{
    $separators = '<', '>', ',', ' '
    $tokens = $pair[0].Split($separators)

    foreach($token in $tokens)
    {
        if($token.Contains('::'))
        {
            $added = $headers.Add($token.Substring(0, $token.LastIndexOf('::')).Replace('::', '.') + '.h')
        }
    }
}

# Write the test file
$filename = $args[0] + '\constexpr_test.cpp'

'// constexpr static assert tests for generics' | out-file $filename

foreach($header in $headers)
{
    ('#include "' + $header + '"') |  out-file -append $filename
}

'using namespace winrt;' | out-file -append $filename
'using namespace Windows::Foundation;' | out-file -append $filename
'using namespace Windows::Foundation::Collections;' | out-file -append $filename
'using cppwinrtIInspectable = winrt::Windows::Foundation::IInspectable;' | out-file -append $filename
'constexpr bool compare(GUID const & left, GUID const & right)' | out-file -append $filename
'{' | out-file -append $filename
'    return (left.Data1 == right.Data1) && (left.Data2 == right.Data2) && (left.Data3 == right.Data3) && (left.Data4[0] == right.Data4[0]) && (left.Data4[1] == right.Data4[1]) && (left.Data4[2] == right.Data4[2]) && (left.Data4[3] == right.Data4[3]) && (left.Data4[4] == right.Data4[4]) && (left.Data4[5] == right.Data4[5]) && (left.Data4[6] == right.Data4[6]) && (left.Data4[7] == right.Data4[7]);' | out-file -append $filename
'}' | out-file -append $filename

#Write the static asserts
foreach($pair in $types)
{
    $guid = [Guid]::Empty
    $success = [Guid]::TryParse($pair[1], [ref]$guid)
    

    ('static_assert(compare(' + $guid.ToString('X') + ', winrt::impl::guid_v<' + $pair[0] + '>));') | out-file -append $filename
}