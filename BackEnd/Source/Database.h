#pragma once

#include "SQLite.h"
#include "Meta.h"
#include "Strings.h"
#include "Settings.h"

namespace Modern::Database {

using SQLite::Statement;

void Initialize();
Statement Prepare(char const * text);
void Project();

template <typename T> void GetEnumerations(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetEnumerations);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::EnumerationId = s.GetInt(0);
        Settings::EnumerationName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::EnumerationFlag = s.GetBool(3);
        Settings::Deprecated = s.GetString(4);

        callback();
    }
}

template <typename T> void GetEnumeratorsFlag(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetEnumeratorsFlag);
    s.Reset(Settings::EnumerationId);

    while (s.Step())
    {
        Settings::EnumeratorName = s.GetString(0);
        Settings::EnumeratorValue = s.GetString(1);

        callback();
    }
}

template <typename T> void GetEnumerators(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetEnumerators);
    s.Reset(Settings::EnumerationId);

    while (s.Step())
    {
        Settings::EnumeratorName = s.GetString(0);
        Settings::EnumeratorValue = s.GetString(1);
        Settings::Deprecated = s.GetString(2);

        callback();
    }
}

template <typename T> void GetStructures(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetStructures);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::StructureId = s.GetInt(0);
        Settings::StructureName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::Deprecated = s.GetString(3);

        callback();
    }
}

template <typename T> void GetAbiStructures(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetAbiStructures);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::StructureId = s.GetInt(0);
        Settings::StructureName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::Deprecated = s.GetString(3);

        callback();
    }
}

template <typename T> void GetNonAbiStructures(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetNonAbiStructures);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::StructureId = s.GetInt(0);
        Settings::StructureName = s.GetString(1);
        Settings::Namespace = s.GetString(2);

        callback();
    }
}

template <typename T> void GetFields(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetFields);
    s.Reset(Settings::StructureId);

    while(s.Step())
    {
        Settings::FieldName = s.GetString(0);
        Settings::FieldType = s.GetString(1);
        Settings::FieldCategory = static_cast<TypeCategory>(s.GetInt(2));
        Settings::Deprecated = s.GetString(3);

        callback();
    }
}

template <typename T> void GetRequiredAbis(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetRequiredAbis);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::Namespace = s.GetString(0);
        Settings::NamespaceDotName = s.GetString(1);

        callback();
    }
}

template <typename T> void GetInterfaceDeclarations(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetInterfaceDeclarations);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::InterfaceName = s.GetString(0);
        Settings::Namespace = s.GetString(1);

        callback();
    }
}

template <typename T> void GetAbiClassDeclarations(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetAbiClassDeclarations);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::ClassName = s.GetString(0);
        Settings::Namespace = s.GetString(1);
        Settings::InterfaceName = s.GetString(2);

        callback();
    }
}

template <typename T> void GetClassImplementations(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetClassImplementations);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::ClassName = s.GetString(0);
        Settings::Namespace = s.GetString(1);
        Settings::ClassDefaultInterface = s.GetString(2);
        Settings::ClassDotName = s.GetString(3);
        Settings::ClassDotNameLength = s.GetStringLength(3);

        callback();
    }
}

template <typename T> void GetClassOverrides(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetClassOverrides);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        Settings::InterfaceName = s.GetString(0);
        Settings::Namespace = s.GetString(1);
        Settings::NamespaceDotName = s.GetString(2);

        callback();
    }
}

template <typename T> void GetRequiredComposableInterfaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetRequiredComposableInterfaces);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        Settings::InterfaceName = s.GetString();

        callback();
    }
}

template <typename T> void GetComposableConstructors(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetComposableConstructors);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);
        Settings::MethodId = s.GetInt(2);
        Settings::MethodName = s.GetString(3);
        GetParameters();

        callback();
    }
}

template <typename T> bool GetClassesComposable(T callback)
{
    bool composablesExist = false;
    static Statement s = Prepare(Strings::DatabaseGetClassesComposable);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        composablesExist = true;
        Settings::ClassId = s.GetInt(0);
        Settings::ClassName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::ClassDefaultInterface = s.GetString(3);

        callback();
    }

    return composablesExist;
}

template <typename T> bool GetOverrides(T callback)
{
    bool overridesExist = false;
    static Statement s = Prepare(Strings::DatabaseGetOverrides);
    s.Reset(Settings::FileNamespace);
    
    while (s.Step())
    {
        overridesExist = true;
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);
        Settings::Namespace = s.GetString(2);

        callback();
    }

    return overridesExist;
}

template <typename T> void GetBases(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetBases);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        Settings::BaseName = s.GetString();

        callback();
    }
}

template <typename T> void GetClasses(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetClasses);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::ClassId = s.GetInt(0);
        Settings::ClassName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::ClassDefaultInterface = s.GetString(3);
        Settings::ClassActivatable = s.GetBool(4);
        Settings::Deprecated = s.GetString(5);

        callback();
    }
}

template <typename T> void GetInterfaceTraits(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetInterfaceTraits);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::InterfaceName = s.GetString(0);
        Settings::Namespace = s.GetString(1);
        Settings::InterfaceDelegate = s.GetBool(2);

        callback();
    }
}

template <typename T> void GetDelegateDefinitions(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetDelegateDefinitions);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::MethodId = s.GetInt(3);
        Settings::Deprecated = s.GetString(4);
        GetParameters();

        callback();
    }
}

template <typename T> void GetInterfaceDefinitions(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetInterfaceDefinitions);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::Deprecated = s.GetString(3);

        callback();
    }
}

template <typename T> void GetAbiInterfaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetAbiInterfaces);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::InterfaceGuid = s.GetString(3);
        Settings::InterfaceDelegate = s.GetBool(4);

        callback();
    }
}

template <typename T> void GetInterfaceMethodDefinitions(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetInterfaceMethodDefinitions);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::InterfaceName = s.GetString(0);
        Settings::Namespace = s.GetString(1);
        Settings::MethodId = s.GetInt(2);
        Settings::MethodName = s.GetString(3);
        Settings::MethodAbi = s.GetString(4);
        GetParameters();

        callback();
    }
}

template <typename T> void GetInterfaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetInterfaces);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::InterfaceGuid = s.GetString(3);

        callback();
    }
}

template <typename T> void GetGenericInterfaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetGenericInterfaces);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::InterfaceName = s.GetString(0);
        Settings::Namespace = s.GetString(1);
        Settings::InterfaceGuid = s.GetString(2);
        Settings::InterfaceId = s.GetInt(3);
        Settings::GenericDefine = s.GetString(4);

        callback();
    }
}

template <typename T> void GetInterfaceMethods(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetInterfaceMethods);
    s.Reset(Settings::InterfaceId);

    while (s.Step())
    {
        Settings::MethodId = s.GetInt(0);
        Settings::MethodName = s.GetString(1);
        Settings::MethodAbi = s.GetString(2);
        Settings::Deprecated = s.GetString(3);
        GetParameters();

        callback();
    }
}

inline void GetParameters()
{
    static Statement s = Prepare(Strings::DatabaseGetParameters);
    s.Reset(Settings::MethodId);

    ParameterInfo & info = Settings::ParameterInfo;
    info.Clear();

    while (s.Step())
    {
        info.Parameters.emplace_back(s.GetString(0),
                                     s.GetString(1),
                                     s.GetString(2),
                                     static_cast<TypeCategory>(s.GetInt(3)),
                                     static_cast<ParameterFlags>(s.GetInt(4)));
    }

    if (!info.Parameters.empty() && ParameterFlags::Return == (info.Parameters.back().Flags & ParameterFlags::Return))
    {
        info.HasReturnType = true;
        
        if (ParameterFlags::Array == (info.Parameters.back().Flags & ParameterFlags::Array))
        {
            info.ReturnType = "com_array<" + info.Parameters.back().ModernType() + ">";
        }
        else
        {
            info.ReturnType = info.Parameters.back().ModernType();
        }
    }
    else
    {
        info.ReturnType = "void";
    }
}

template <typename T> void GetRequiredInterfaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetRequiredInterfaces);
    s.Reset(Settings::InterfaceId);

    while (s.Step())
    {
        Settings::RequiredInterfaceName = s.GetString();

        callback();
    }
}

template <typename T> void GetRequiredClassInterfaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetRequiredClassInterfaces);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        Settings::RequiredInterfaceName = s.GetString();

        callback();
    }
}

template <typename T> void GetPublicConstructorMethods(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetPublicConstructorMethods);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);
        Settings::InterfaceComposable = s.GetBool(2);
        Settings::MethodId = s.GetInt(3);
        Settings::MethodName = s.GetString(4);
        GetParameters();

        callback();
    }
}

template <typename T> void GetClassConstructorsPublic(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetClassConstructorsPublic);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);
        Settings::InterfaceComposable = s.GetBool(2);

        callback();
    }
}

template <typename T> void GetStaticMethodDeclarations(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetStaticMethodDeclarations);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);
        Settings::MethodId = s.GetInt(2);
        Settings::MethodName = s.GetString(3);
        Settings::MethodAbi = s.GetString(4);
        Settings::Deprecated = s.GetString(5);
        GetParameters();

        callback();
    }
}

template <typename T> void GetUsingMethodsForInterface(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetUsingMethodsForInterface);
    s.Reset(Settings::InterfaceId);

    while (s.Step())
    {
        Settings::UsingInterface = s.GetString(0);
        Settings::UsingMethod = s.GetString(1);

        callback();
    }
}

template <typename T> void GetUsingMethodsForClass(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetUsingMethodsForClass);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        Settings::UsingInterfaceName = s.GetString(0);
        Settings::UsingMethodName = s.GetString(1);

        callback();
    }
}

template <typename T> void GetDelegates(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetDelegates);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::DelegateName = s.GetString(0);
        Settings::Namespace = s.GetString(1);
        Settings::MethodId = s.GetInt(2);
        GetParameters();

        callback();
    }
}

template <typename T> void GetNamespaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetNamespaces);
    s.Reset();

    while (s.Step())
    {
        Settings::FileNamespace = s.GetString(0);
        Settings::FileNamespaceDotName = s.GetString(1);
        callback();
    }
}

template <typename T> void GetRequiredForwards(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetRequiredForwards);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::Namespace = s.GetString(0);
        Settings::NamespaceDotName = s.GetString(1);
        callback();
    }
}

template <typename T> void GetRequiredParamImpls(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetRequiredParamImpls);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::Namespace = s.GetString(0);
        Settings::NamespaceDotName = s.GetString(1);
        callback();
    }
}

template <typename T> void GetGenericInterfaceArguments(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetGenericInterfaceArguments);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::Namespace = s.GetString(0);
        Settings::NamespaceDotName = s.GetString(1);
        callback();
    }
}

template <typename T> void GetRequiredInterfaceHeaders(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetRequiredInterfaceHeaders);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::Namespace = s.GetString(0);
        Settings::NamespaceDotName = s.GetString(1);
        callback();
    }
}

template <typename T> void GetRequiredInterfaceIncludes(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetRequiredInterfaceIncludes);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::Namespace = s.GetString(0);
        Settings::NamespaceDotName = s.GetString(1);
        callback();
    }
}

template <typename T> void GetClassOverrideIncludes(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetClassOverrideIncludes);
    s.Reset(Settings::FileNamespace);

    while (s.Step())
    {
        Settings::Namespace = s.GetString(0);
        Settings::NamespaceDotName = s.GetString(1);
        callback();
    }
}

}
