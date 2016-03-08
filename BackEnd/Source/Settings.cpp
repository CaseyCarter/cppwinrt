#include "Precompiled.h"
#include "Settings.h"

namespace Modern { namespace Settings {

std::string Include;
Modern::Options Options;

std::string Namespace;

int EnumerationId;
std::string EnumerationName;
bool EnumerationFlag;

std::string EnumeratorName;
std::string EnumeratorValue;

int StructureId;
std::string StructureName;

std::string FieldName;
std::string FieldType;

int ClassId;
std::string ClassName;
std::string ClassDefaultInterface;
std::string ClassDotName;
unsigned ClassDotNameLength;
bool ClassActivatable;

int InterfaceId;
std::string InterfaceName;
std::string InterfaceGuid;
bool InterfaceDelegate;
bool InterfaceComposable;

std::string UsingInterface;
std::string UsingMethod;

int MethodId;
std::string MethodName;
std::string MethodAbi;
bool MethodDeprecated;

std::string DelegateName;
std::string DelegateImplementation;

Modern::ParameterInfo ParameterInfo;

}}
