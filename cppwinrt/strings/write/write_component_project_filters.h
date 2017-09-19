<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup>
    <ClCompile Include="module.cpp">
      <Filter>Generated</Filter>
    </ClCompile>
    <ClCompile Include="pch.cpp">
      <Filter>Generated</Filter>
    </ClCompile>
  </ItemGroup>
  <ItemGroup>
    <ClInclude Include="module.h">
      <Filter>Generated</Filter>
    </ClInclude>
    <ClInclude Include="pch.h">
      <Filter>Generated</Filter>
    </ClInclude>%
  </ItemGroup>
  <ItemGroup>
    <None Include="module.def">
      <Filter>Generated</Filter>
    </None>
  </ItemGroup>%
  <ItemGroup>
    <Filter Include="Generated">
      <UniqueIdentifier>{%}</UniqueIdentifier>
    </Filter>
  </ItemGroup>
</Project>