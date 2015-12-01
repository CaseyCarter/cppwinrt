#pragma once

#include "SQLite.h"
#include "Meta.h"
#include "Strings.h"
#include "Settings.h"

namespace Modern { namespace Database {

using SQLite::Statement;

void Initialize();
void SaveToFile(std::string const & filename);
Statement Prepare(char const * text);
int RowId() noexcept;
int Changes() noexcept;
void Project();
void Profile();

inline void Command(Modern::Command command)
{
    static Statement s = Prepare("update Settings set Command = ?");
    s.Reset(static_cast<int>(command));
    s.Execute();
}

inline Modern::Command Command()
{
    static Statement s = Prepare("select Command from Settings");
    s.Reset();
    MODERN_VERIFY(s.Step());
    return static_cast<Modern::Command>(s.GetInt());
}

inline void Sdk(std::string const & sdk)
{
    static Statement s = Prepare("update Settings set Sdk = ?");
    s.Reset(sdk);
    s.Execute();
}

inline std::string Sdk()
{
    static Statement s = Prepare("select Sdk from Settings");
    s.Reset();
    MODERN_VERIFY(s.Step());
    return s.GetString();
}

inline void Name(char const * const name)
{
    static Statement s = Prepare("update Settings set Name = ?");
    s.Reset(name);
    s.Execute();
}

inline std::string Name()
{
    static Statement s = Prepare("select Name from Settings");
    s.Reset();
    MODERN_VERIFY(s.Step());
    return s.GetString();
}

inline void Library(std::string const & library)
{
    static Statement s = Prepare("update Settings set Library = ?");
    s.Reset(library);
    s.Execute();
}

inline std::string Library()
{
    static Statement s = Prepare("select Library from Settings");
    s.Reset();
    MODERN_VERIFY(s.Step());
    return s.GetString();
}

inline void Out(std::string const & out)
{
    static Statement s = Prepare("update Settings set Out = ?");
    s.Reset(out);
    s.Execute();
}

inline std::string Out()
{
    static Statement s = Prepare("select Out from Settings");
    s.Reset();
    MODERN_VERIFY(s.Step());
    return s.GetString();
}

inline void Include(char const * const include)
{
    static Statement s = Prepare("insert into Includes values (?)");
    s.Reset(include);
    s.Execute();
}

inline bool HasIncludes()
{
    static Statement s = Prepare("select count(*) from Includes");
    s.Reset();
    MODERN_VERIFY(s.Step());
    return s.GetBool();
}

template <typename T> void Includes(T callback)
{
    static Statement s = Prepare("select Name from Includes");
    s.Reset();

    while (s.Step())
    {
        Settings::Include = s.GetString();

        callback();
    }
}

inline void AddDeprecated(std::string const & name, std::string const & ns)
{
    static Statement s = Prepare(Strings::DatabaseAddDeprecated);
    s.Reset(name, ns);
    s.Execute();
    MODERN_ASSERT(1 == Changes());
}

//
// Sources
//

inline int AddSource(char const * const filename, bool const include)
{
    static Statement s = Prepare(Strings::DatabaseAddSource);
    s.Reset(filename, include);
    s.Execute();
    return 0 != Changes() ? RowId() : 0;
}

inline std::pair<int, std::string> GetNextSource()
{
    static Statement s = Prepare(Strings::DatabaseGetNextSource);
    s.Reset();

    if (s.Step())
    {
        return std::make_pair(s.GetInt(0), s.GetString(1));
    }

    return std::make_pair(0, std::string());
}

inline bool IncludesCoreWindow()
{
    static Statement s = Prepare(Strings::DatabaseIncludesCoreWindow);
    s.Reset();
    MODERN_VERIFY(s.Step());
    return s.GetBool();
}

inline void SetSourceParsed(int const sourceId)
{
    static Statement s = Prepare(Strings::DatabaseSourceParsed);
    s.Reset(sourceId);
    s.Execute();
}

//
// Classes
//

inline void AddClassDeclaration(std::string const & name, std::string const & ns)
{
    static Statement s = Prepare(Strings::DatabaseAddClassDeclaration);
    s.Reset(name, ns);
    s.Execute();
}

inline int AddClass(std::string const & name, std::string const & ns, std::string const & base)
{
	if (!base.empty())
	{
		static Statement s = Prepare("insert or ignore into Classes (FullName) values (?1)");
		s.Reset(base);
		s.Execute();
	}

    static Statement s = Prepare(Strings::DatabaseAddClass);
    s.Reset(name, ns, base);
    s.Execute();
    return RowId();
}

inline void RemoveClass(std::string const & name, std::string const & ns)
{
    static Statement s = Prepare(Strings::DatabaseRemoveClass);
    s.Reset(name, ns);
    s.Execute();
}

inline void SetClassDefaultConstructor(int const classId)
{
    static Statement s = Prepare(Strings::DatabaseSetClassDefaultConstructor);
    s.Reset(classId);
    s.Execute();
}

inline void AddClassDefaultConstructor(int const classId)
{
    static Statement s = Prepare(Strings::DatabaseAddClassDefaultConstructor);
    s.Reset(classId);
    s.Execute();
}

inline void AddClassConstructor(int classId, std::string const & name)
{
    static Statement s = Prepare(Strings::DatabaseAddClassConstructor);
    s.Reset(classId, name);
    s.Execute();
}

inline void AddClassStatic(int classId, std::string const & name)
{
    static Statement s = Prepare(Strings::DatabaseAddClassStatic);
    s.Reset(classId, name);
    s.Execute();
}

inline void AddClassComposable(int classId, char const * const name, bool const isProtected)
{
	static Statement s = Prepare(Strings::DatabaseAddClassComposable);
	s.Reset(classId, name, isProtected);
	s.Execute();
}

inline void AddClassInterface(int const classId, std::string const & name, bool const isDefault, bool const overridable, bool const isProtected)
{
    static Statement s = Prepare(Strings::DatabaseAddClassInterface);
    s.Reset(classId, name, isDefault, overridable, isProtected);
    s.Execute();
}

inline void AddClassDefaultInterface(int const classId, std::string const & name)
{
    static Statement s = Prepare(Strings::DatabaseAddClassDefaultInterface);
    s.Reset(name, classId);
    s.Execute();
}

//
// Enumerations
//

inline void AddEnumerationDeclaration(std::string const & name, std::string const & ns)
{
    static Statement s = Prepare(Strings::DatabaseAddEnumerationDeclaration);
    s.Reset(name, ns);
    s.Execute();
}

inline int AddEnumeration(std::string const & name, std::string const & ns, bool const flags)
{
    static Statement s = Prepare(Strings::DatabaseAddEnumeration);
    s.Reset(name, ns, flags);
    s.Execute();
    return RowId();
}

inline void RemoveEnumeration(std::string const & name, std::string const & ns)
{
    static Statement s = Prepare(Strings::DatabaseRemoveEnumeration);
    s.Reset(name, ns);
    s.Execute();
}

inline void AddEnumerator(int const enumerationId, std::string const & name, long long const value)
{
    static Statement s = Prepare(Strings::DatabaseAddEnumerator);
    s.Reset(enumerationId, name, value);
    s.Execute();
}

//
// Structures
//

inline void AddStructureDeclaration(std::string const & name, std::string const & ns)
{
    static Statement s = Prepare(Strings::DatabaseAddStructureDeclaration);
    s.Reset(name, ns);
    s.Execute();
}

inline int AddStructure(std::string const & name, std::string const & ns)
{
    static Statement s = Prepare(Strings::DatabaseAddStructure);
    s.Reset(name, ns);
    s.Execute();
    return RowId();
}

inline void AddField(int structureId, std::string const & name, std::string const & type)
{
    static Statement s = Prepare(Strings::DatabaseAddField);
    s.Reset(structureId, name, type);
    s.Execute();
}

inline void StructureDepends(int const structureId, int const depends)
{
    static Statement s = Prepare(Strings::DatabaseStructureDepends);
    s.Reset(structureId, depends);
    s.Execute();
}

//
// Interfaces
//

inline void AddGenericInterface(std::string const & name, std::string const & ns, char const * const guidBegin, char const * const guidEnd)
{
    static Statement s = Prepare(Strings::DatabaseAddGenericInterface);
    s.Reset();
    s.Bind(1, name);
    s.Bind(2, ns);
    s.Bind(3, guidBegin, guidEnd - guidBegin);
    s.Execute();
}

inline void AddInterfaceDeclaration(std::string const & name, std::string const & ns)
{
    static Statement s = Prepare(Strings::DatabaseAddInterfaceDeclaration);
    s.Reset(name, ns);
    s.Execute();
}

inline int AddInterface(std::string const & name, std::string const & ns, std::string const & uuid)
{
    static Statement s = Prepare(Strings::DatabaseAddInterface);
    s.Reset(name, ns, uuid);
    s.Execute();
    return RowId();
}

inline void RemoveInterface(std::string const & name, std::string const & ns)
{
    static Statement s = Prepare(Strings::DatabaseRemoveInterface);
    s.Reset(name, ns);
    s.Execute();
}

inline void AddRequiredInterface(int const interfaceId, std::string const & name)
{
    static Statement s = Prepare(Strings::DatabaseAddRequiredInterface);
    s.Reset(interfaceId, name);
    s.Execute();
}

inline int AddMethod(int const interfaceId, std::string const & name, std::string const & abiName, bool const deprecated)
{
    static Statement s = Prepare(Strings::DatabaseAddMethod);
    s.Reset(interfaceId, name, abiName, deprecated);
    s.Execute();
    return RowId();
}

inline void AddParameter(int const methodId, std::string const & name, std::string const & type, ParameterDirection const direction, TypeCategory const category, std::string const & sizeIs, std::string const & lengthIs)
{
    if (category == TypeCategory::Class)
    {
        static Statement s = Prepare(Strings::DatabaseAddParameterWithClass);
        s.Reset(methodId, name, type, static_cast<int>(direction), static_cast<int>(category), sizeIs, lengthIs);
        s.Execute();
    }
    else
    {
        static Statement s = Prepare(Strings::DatabaseAddParameter);
        s.Reset(methodId, name, type, static_cast<int>(direction), static_cast<int>(category), sizeIs, lengthIs);
        s.Execute();
    }
}

inline void AddDelegateDeclaration(std::string const & name, std::string const & ns)
{
    static Statement s = Prepare(Strings::DatabaseAddDelegateDeclaration);
    s.Reset(name, ns);
    s.Execute();
}

inline int AddDelegate(std::string const & name, std::string const & ns, std::string const & uuid)
{
    // TODO: does the Delegate column need to duplicate the namespace?

    static Statement s = Prepare(Strings::DatabaseAddDelegate);
    s.Reset(name, ns, uuid);
    s.Execute();
    return RowId();
}

inline void RemoveDelegate(std::string const & name, std::string const & ns)
{
    static Statement s = Prepare(Strings::DatabaseRemoveDelegate);
    s.Reset(name, ns);
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

//inline bool HasEnumerations()
//{
//    static Statement s = Prepare(Strings::DatabaseHasEnumerations);
//    s.Reset();
//    s.Step();
//    return s.GetBool();
//}

inline TypeCategory GetCategory(std::string const & fullname)
{
    static Statement s = Prepare(Strings::DatabaseGetCategory);
    s.Reset(fullname);
    MODERN_VERIFY(s.Step());
    return static_cast<TypeCategory>(s.GetInt());

    //TypeCategory const category = static_cast<TypeCategory>(s.GetInt());
    //MODERN_ASSERT(category != TypeCategory::Unknown);
    //return category;
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

        if (!Settings::MethodDeprecated)
        {
            GetParameters();
        }

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
                                     static_cast<ParameterDirection>(s.GetInt(3)),
                                     static_cast<TypeCategory>(s.GetInt(4)));

        Parameter const & back = info.Parameters.back();

        if (back.Direction == ParameterDirection::In)
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

    if (!info.Parameters.empty() && info.Parameters.back().Direction == ParameterDirection::Return)
    {
        info.HasReturnType = true;
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

}}
