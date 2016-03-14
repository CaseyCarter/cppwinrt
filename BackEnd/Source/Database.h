#pragma once

#include "SQLite.h"
#include "Meta.h"
#include "Strings.h"
#include "Settings.h"

namespace Modern { namespace Database {

using SQLite::Statement;

void Initialize();
Statement Prepare(char const * text);

inline void StructureDepends(int const structureId, int const depends)
{
    static Statement s = Prepare(Strings::DatabaseStructureDepends);
    s.Reset(structureId, depends);
    s.Execute();
}

//
// Library
//

template <typename T> void GetIncludes(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetIncludes);
    s.Reset();

    while (s.Step())
    {
        callback(s.GetString());
    }
}

template <typename T> void GetHeaders(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetHeaders);
    s.Reset();

    while (s.Step())
    {
        callback(s.GetString());
    }
}

template <typename T> void GetEnumerations(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetEnumerations);
    s.Reset();

    while (s.Step())
    {
        Settings::EnumerationId = s.GetInt(0);
        Settings::EnumerationName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::EnumerationFlag = s.GetBool(3);

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

        callback();
    }
}

template <typename T> void GetEnumeratorsInt(int const enumerationId, T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetEnumeratorsInt);
    s.Reset(enumerationId);

    while (s.Step())
    {
        callback(s.GetString(0),
                 s.GetInt(1));
    }
}

template <typename T> void GetStructures(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetStructures);
    s.Reset();

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

        callback();
    }
}

template <typename T> void GetDeclarations(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetDeclarations);
    s.Reset();

    while (s.Step())
    {
        Settings::ClassName = s.GetString(0);
        Settings::Namespace = s.GetString(1);

        callback();
    }
}

template <typename T> void GetInterfaceDeclarations(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetInterfaceDeclarations);
    s.Reset();

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
    s.Reset();

    while (s.Step())
    {
        Settings::ClassName = s.GetString(0);
        Settings::Namespace = s.GetString(1);
        Settings::InterfaceName = s.GetString(2);

        callback();
    }
}

template <typename T> void GetClassDeclarations(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetClassDeclarations);
    s.Reset();

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

template <typename T> void GetClassImplementations(T callback)
{
	static Statement s = Prepare(Strings::DatabaseGetClassImplementations);
	s.Reset();

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
        Settings::InterfaceName = s.GetString();

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

        callback();
    }
}

template <typename T> void GetClassesComposable(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetClassesComposable);
    s.Reset();

    while (s.Step())
    {
        Settings::ClassId = s.GetInt(0);
        Settings::ClassName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::ClassDefaultInterface = s.GetString(3);

        callback();
    }
}

template <typename T> void GetOverrides(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetOverrides);
    s.Reset();

    while (s.Step())
    {
        callback(s.GetInt(0),
                 s.GetString(1),
                 s.GetString(2));
    }
}

template <typename T> void GetBases(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetBases);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        callback(s.GetString());
    }
}

template <typename T> void GetClasses(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetClasses);
    s.Reset();

    while (s.Step())
    {
        Settings::ClassId = s.GetInt(0);
        Settings::ClassName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::ClassDefaultInterface = s.GetString(3);
        Settings::ClassActivatable = s.GetBool(4);

        callback();
    }
}

template <typename T> void GetComponentClasses(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetComponentClasses);
    s.Reset();

    while (s.Step())
    {
        Settings::ClassId = s.GetInt(0);
        Settings::ClassName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::ClassDotName = s.GetString(3);
        Settings::ClassDefaultInterface = s.GetString(4);
        Settings::ClassActivatable = s.GetBool(5);

        callback();
    }
}

template <typename T> void GetOverridables(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetOverridables);
    s.Reset();

    while (s.Step())
    {
        callback(s.GetString(0),
                 s.GetString(1));
    }
}

template <typename T> void GetInterfaceNames(T callback)
{
	static Statement s = Prepare(Strings::DatabaseGetInterfaceNames);
	s.Reset();

	while (s.Step())
	{
        Settings::InterfaceName = s.GetString(0);
        Settings::Namespace = s.GetString(1);

        callback();
	}
}

template <typename T> void GetInterfaceDefinitions(T callback)
{
	static Statement s = Prepare(Strings::DatabaseGetInterfaceDefinitions);
	s.Reset();

	while (s.Step())
	{
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::InterfaceDelegate = s.GetBool(3);

        callback();
	}
}

template <typename T> void GetInterfaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetInterfaces);
    s.Reset();

    while (s.Step())
    {
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);
        Settings::Namespace = s.GetString(2);
        Settings::InterfaceDelegate = s.GetBool(3);
        Settings::InterfaceGuid = s.GetString(4);

        callback();
    }
}

template <typename T> void GetGenericInterfaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetGenericInterfaces);
    s.Reset();

    while (s.Step())
    {
        Settings::InterfaceName = s.GetString(0);
        Settings::Namespace = s.GetString(1);
        Settings::InterfaceGuid = s.GetString(2);

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
        Settings::MethodDeprecated = s.GetBool(3);

        GetParameters();

        callback();
    }
}

template <typename T> void GetConstructorMethods(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetConstructorMethods);
    s.Reset(Settings::InterfaceId);

    while (s.Step())
    {
        Settings::MethodId = s.GetInt(0);
        Settings::MethodName = s.GetString(1);
        GetParameters();

        // TODO: Remove once arrays are implemented
        if (!Settings::ParameterInfo.HasArrayParam)
        {
            callback();
        }
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
        // TODO: Remove once array support is added
        if (static_cast<ParameterAttribute>(s.GetInt(3)) & ParameterAttribute::Array)
        {
            info.HasArrayParam = true;
        }

        if (static_cast<ParameterAttribute>(s.GetInt(3)) & ParameterAttribute::Return)
        {
            info.HasReturnType = true;
            continue;
        }

        info.Parameters.emplace_back(s.GetString(0),
                                     s.GetString(1),
                                     s.GetString(2),
                                     static_cast<ParameterAttribute>(s.GetInt(3)),
                                     static_cast<TypeCategory>(s.GetInt(4)));

        Parameter const & back = info.Parameters.back();

        if (back.Attribute & ParameterAttribute::In)
        {
            if (back.Category == TypeCategory::String)
            {
                //++info.StringCount;
            }
            else if (back.Category == TypeCategory::Delegate)
            {
                info.HasDelegate = true;
            }
        }
    }

    if (info.HasReturnType)
    {
        s.Reset();
        s.Step();
        info.Parameters.emplace_back(s.GetString(0),
            s.GetString(1),
            s.GetString(2),
            static_cast<ParameterAttribute>(s.GetInt(3)),
            static_cast<TypeCategory>(s.GetInt(4)));
    }
}

template <typename T> void GetRequiredInterfaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetRequiredInterfaces);
    s.Reset(Settings::InterfaceId);

    while (s.Step())
    {
        callback(s.GetString());
    }
}

template <typename T> void GetRequiredClassInterfaces(T callback)
{
	static Statement s = Prepare(Strings::DatabaseGetRequiredClassInterfaces);
	s.Reset(Settings::ClassId);

	while (s.Step())
	{
		callback(s.GetString());
	}
}

template <typename T> void GetRequiredComponentClassInterfaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetRequiredComponentClassInterfaces);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);

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

template <typename T> void GetStaticInterfaces(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetStaticInterfaces);
    s.Reset(Settings::ClassId);

    while (s.Step())
    {
        Settings::InterfaceId = s.GetInt(0);
        Settings::InterfaceName = s.GetString(1);

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
		callback(s.GetString(0),
			s.GetString(1));
	}
}

template <typename T> void GetDelegates(T callback)
{
    static Statement s = Prepare(Strings::DatabaseGetDelegates);
    s.Reset();

    while (s.Step())
    {
        Settings::DelegateName = s.GetString(0);
        Settings::Namespace = s.GetString(1);
        Settings::DelegateImplementation = s.GetString(2);
        Settings::MethodId = s.GetInt(3);
        GetParameters();

        callback();
    }
}

template <typename T> void GetComponentClassInterfaceNames(T callback)
{
	static Statement s = Prepare(Strings::DatabaseGetComponentClassInterfaceNames);
	s.Reset(Settings::ClassId);

	while (s.Step())
	{
		Settings::InterfaceName = s.GetString(0);

		callback();
	}
}

template <typename T> void GetComponentClassFactoryInterfaceNames(T callback)
{
	static Statement s = Prepare(Strings::DatabaseGetComponentClassFactoryInterfaceNames);
	s.Reset(Settings::ClassId);

	while (s.Step())
	{
		Settings::InterfaceName = s.GetString();

		callback();
	}
}

inline bool IncludesCoreWindow()
{
    static Statement s = Prepare(Strings::DatabaseIncludesCoreWindow);
    s.Reset();
    MODERN_VERIFY(s.Step());
    return s.GetBool();
}

}}
