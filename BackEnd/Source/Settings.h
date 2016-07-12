#pragma once

#include "Meta.h"

namespace Modern::Settings {

extern std::string OutPath;
extern std::string DatabasePath;
extern const std::string PublicPath;
extern const std::string InternalPath;
extern Modern::Options Options;

extern std::string Namespace;
extern std::string NamespaceDotName;
extern std::string FileNamespace;
extern std::string FileNamespaceDotName;

extern int EnumerationId;
extern std::string EnumerationName;
extern bool EnumerationFlag;
extern std::string EnumeratorName;
extern std::string EnumeratorValue;

extern int StructureId;
extern std::string StructureName;
extern std::string FieldName;
extern std::string FieldType;
extern TypeCategory FieldCategory;

extern int ClassId;
extern std::string ClassName;
extern std::string ClassDefaultInterface;
extern std::string ClassDotName;
extern unsigned ClassDotNameLength;
extern bool ClassActivatable;
extern std::string BaseName;
extern std::string GenericDefine;

extern int InterfaceId;
extern std::string InterfaceName;
extern std::string InterfaceGuid;
extern bool InterfaceDelegate;
extern bool InterfaceComposable;
extern std::string RequiredInterfaceName;

extern std::string UsingInterface;
extern std::string UsingMethod;

extern int MethodId;
extern std::string MethodName;
extern std::string MethodAbi;
extern bool MethodDeprecated;
extern std::string MethodShim;
extern std::string UsingInterfaceName;
extern std::string UsingMethodName;

extern std::string DelegateName;
extern std::string DelegateImplementation;

extern Modern::ParameterInfo ParameterInfo;

}
