<?xml version="1.0" encoding="utf-8"?>
<Project DefaultTargets="Build" ToolsVersion="15.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ItemGroup Label="ProjectConfigurations">
    <ProjectConfiguration Include="Debug|Win32">
      <Configuration>Debug</Configuration>
      <Platform>Win32</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|Win32">
      <Configuration>Release</Configuration>
      <Platform>Win32</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Debug|x64">
      <Configuration>Debug</Configuration>
      <Platform>x64</Platform>
    </ProjectConfiguration>
    <ProjectConfiguration Include="Release|x64">
      <Configuration>Release</Configuration>
      <Platform>x64</Platform>
    </ProjectConfiguration>
  </ItemGroup>
  <PropertyGroup Label="Globals">
    <VCProjectVersion>15.0</VCProjectVersion>
    <ProjectGuid>{%}</ProjectGuid>
    <Keyword>Win32Proj</Keyword>
    <RootNamespace>%</RootNamespace>
    <WindowsTargetPlatformVersion>%</WindowsTargetPlatformVersion>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Default.props" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'" Label="Configuration">
    <ConfigurationType>DynamicLibrary</ConfigurationType>
    <UseDebugLibraries>true</UseDebugLibraries>
    <PlatformToolset>%</PlatformToolset>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'" Label="Configuration">
    <ConfigurationType>DynamicLibrary</ConfigurationType>
    <UseDebugLibraries>false</UseDebugLibraries>
    <PlatformToolset>%</PlatformToolset>
    <WholeProgramOptimization>true</WholeProgramOptimization>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'" Label="Configuration">
    <ConfigurationType>DynamicLibrary</ConfigurationType>
    <UseDebugLibraries>true</UseDebugLibraries>
    <PlatformToolset>%</PlatformToolset>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'" Label="Configuration">
    <ConfigurationType>DynamicLibrary</ConfigurationType>
    <UseDebugLibraries>false</UseDebugLibraries>
    <PlatformToolset>%</PlatformToolset>
    <WholeProgramOptimization>true</WholeProgramOptimization>
    <CharacterSet>Unicode</CharacterSet>
  </PropertyGroup>
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />
  <ImportGroup Label="ExtensionSettings">
  </ImportGroup>
  <ImportGroup Label="Shared">
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <ImportGroup Label="PropertySheets" Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    <Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
  <PropertyGroup Label="UserMacros" />
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <LinkIncremental>true</LinkIncremental>
    <CustomBuildAfterTargets>Midl</CustomBuildAfterTargets>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <LinkIncremental>true</LinkIncremental>
    <CustomBuildAfterTargets>Midl</CustomBuildAfterTargets>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <LinkIncremental>false</LinkIncremental>
    <CustomBuildAfterTargets>Midl</CustomBuildAfterTargets>
  </PropertyGroup>
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    <LinkIncremental>false</LinkIncremental>
    <CustomBuildAfterTargets>Midl</CustomBuildAfterTargets>
  </PropertyGroup>
  <ItemDefinitionGroup>
    <CustomBuildStep>
      <Command>% -out $(ProjectDir)</Command>
      <Message>C++/WinRT compiler</Message>
      <Outputs>winrt/%.h;module.h</Outputs>
      <Inputs>%</Inputs>
    </CustomBuildStep>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">
    <ClCompile>
      <PrecompiledHeader>Use</PrecompiledHeader>
      <WarningLevel>Level4</WarningLevel>
      <Optimization>Disabled</Optimization>
      <PreprocessorDefinitions>WIN32;_DEBUG;_WINDOWS;_USRDLL;%;^%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <PrecompiledHeaderFile>pch.h</PrecompiledHeaderFile>
      <AdditionalOptions>/std:c++17 /permissive- /await  /D "NDEBUG" ^%(AdditionalOptions)</AdditionalOptions>
    </ClCompile>
    <Link>
      <SubSystem>Windows</SubSystem>
      <ModuleDefinitionFile>module.def</ModuleDefinitionFile>
      <AdditionalDependencies>kernel32.lib;</AdditionalDependencies>
    </Link>
    <PostBuildEvent>
      <Command>copy $(TargetPath) $(ProjectDir)</Command>
    </PostBuildEvent>
    <PostBuildEvent>
      <Message>Copy implementation dll so App can generate registration data</Message>
    </PostBuildEvent>
    <Midl>
      <AdditionalOptions>/nomidl /struct_by_ref ^%(AdditionalOptions)</AdditionalOptions>
    </Midl>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">
    <ClCompile>
      <PrecompiledHeader>Use</PrecompiledHeader>
      <WarningLevel>Level4</WarningLevel>
      <Optimization>Disabled</Optimization>
      <PreprocessorDefinitions>_DEBUG;_WINDOWS;_USRDLL;%;^%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <PrecompiledHeaderFile>pch.h</PrecompiledHeaderFile>
      <AdditionalOptions>/std:c++17 /permissive- /await ^%(AdditionalOptions)</AdditionalOptions>
    </ClCompile>
    <Link>
      <SubSystem>Windows</SubSystem>
      <ModuleDefinitionFile>module.def</ModuleDefinitionFile>
      <AdditionalDependencies>kernel32.lib;</AdditionalDependencies>
    </Link>
    <PostBuildEvent>
      <Command>copy $(TargetPath) $(ProjectDir)</Command>
    </PostBuildEvent>
    <PostBuildEvent>
      <Message>Copy implementation dll so App can generate registration data</Message>
    </PostBuildEvent>
    <Midl>
      <AdditionalOptions>/nomidl /struct_by_ref ^%(AdditionalOptions)</AdditionalOptions>
    </Midl>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">
    <ClCompile>
      <WarningLevel>Level4</WarningLevel>
      <PrecompiledHeader>Use</PrecompiledHeader>
      <Optimization>MaxSpeed</Optimization>
      <FunctionLevelLinking>true</FunctionLevelLinking>
      <IntrinsicFunctions>true</IntrinsicFunctions>
      <PreprocessorDefinitions>WIN32;NDEBUG;_WINDOWS;_USRDLL;%;^%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <PrecompiledHeaderFile>pch.h</PrecompiledHeaderFile>
      <AdditionalOptions>/std:c++17 /permissive- /await ^%(AdditionalOptions)</AdditionalOptions>
    </ClCompile>
    <Link>
      <SubSystem>Windows</SubSystem>
      <EnableCOMDATFolding>true</EnableCOMDATFolding>
      <OptimizeReferences>true</OptimizeReferences>
      <ModuleDefinitionFile>module.def</ModuleDefinitionFile>
      <AdditionalDependencies>kernel32.lib;</AdditionalDependencies>
    </Link>
    <PostBuildEvent>
      <Command>copy $(TargetPath) $(ProjectDir)</Command>
    </PostBuildEvent>
    <PostBuildEvent>
      <Message>Copy implementation dll so App can generate registration data</Message>
    </PostBuildEvent>
    <Midl>
      <AdditionalOptions>/nomidl /struct_by_ref ^%(AdditionalOptions)</AdditionalOptions>
    </Midl>
  </ItemDefinitionGroup>
  <ItemDefinitionGroup Condition="'$(Configuration)|$(Platform)'=='Release|x64'">
    <ClCompile>
      <WarningLevel>Level4</WarningLevel>
      <PrecompiledHeader>Use</PrecompiledHeader>
      <Optimization>MaxSpeed</Optimization>
      <FunctionLevelLinking>true</FunctionLevelLinking>
      <IntrinsicFunctions>true</IntrinsicFunctions>
      <PreprocessorDefinitions>NDEBUG;_WINDOWS;_USRDLL;%;^%(PreprocessorDefinitions)</PreprocessorDefinitions>
      <PrecompiledHeaderFile>pch.h</PrecompiledHeaderFile>
      <AdditionalOptions>/std:c++17 /permissive- /await ^%(AdditionalOptions)</AdditionalOptions>
    </ClCompile>
    <Link>
      <SubSystem>Windows</SubSystem>
      <EnableCOMDATFolding>true</EnableCOMDATFolding>
      <OptimizeReferences>true</OptimizeReferences>
      <ModuleDefinitionFile>module.def</ModuleDefinitionFile>
      <AdditionalDependencies>kernel32.lib;</AdditionalDependencies>
    </Link>
    <PostBuildEvent>
      <Command>copy $(TargetPath) $(ProjectDir)</Command>
    </PostBuildEvent>
    <PostBuildEvent>
      <Message>Copy implementation dll so App can generate registration data</Message>
    </PostBuildEvent>
    <Midl>
      <AdditionalOptions>/nomidl /struct_by_ref ^%(AdditionalOptions)</AdditionalOptions>
    </Midl>
  </ItemDefinitionGroup>
  <ItemGroup>
    <ClCompile Include="module.cpp" />
    <ClCompile Include="pch.cpp">
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'">Create</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Release|Win32'">Create</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Debug|x64'">Create</PrecompiledHeader>
      <PrecompiledHeader Condition="'$(Configuration)|$(Platform)'=='Release|x64'">Create</PrecompiledHeader>
    </ClCompile>%
  </ItemGroup>
  <ItemGroup>
    <ClInclude Include="module.h" />
    <ClInclude Include="pch.h" />%
  </ItemGroup>
  <ItemGroup>
    <None Include="module.def" />
  </ItemGroup>%
  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />
  <ImportGroup Label="ExtensionTargets">
  </ImportGroup>
</Project>