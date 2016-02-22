#pragma once

#include "Meta.h"

namespace Modern { namespace Settings {

extern std::string OutPath;
extern std::string DatabasePath;
extern std::string LibraryName;
extern std::string ComponentName;
extern Modern::Options Options;
extern SQLite::Connection Connection;

extern std::string Namespace;

extern int EnumerationId;
extern std::string EnumerationName;
extern bool EnumerationFlag;

extern std::string EnumeratorName;
extern std::string EnumeratorValue;

extern int StructureId;
extern std::string StructureName;

extern std::string FieldName;
extern std::string FieldType;

extern int ClassId;
extern std::string ClassName;
extern std::string ClassDefaultInterface;
extern std::string ClassDotName;
extern unsigned ClassDotNameLength;
extern bool ClassActivatable;

extern int InterfaceId;
extern std::string InterfaceName;
extern std::string InterfaceGuid;
extern bool InterfaceDelegate;
extern bool InterfaceComposable;

extern std::string UsingInterface;
extern std::string UsingMethod;

extern int MethodId;
extern std::string MethodName;
extern std::string MethodAbi;
extern bool MethodDeprecated;

extern std::string DelegateName;
extern std::string DelegateImplementation;

extern Modern::ParameterInfo ParameterInfo;

}}
