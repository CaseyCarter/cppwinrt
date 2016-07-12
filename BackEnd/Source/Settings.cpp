#include "Precompiled.h"
#include "Settings.h"

namespace Modern::Settings {

std::string OutPath;
const std::string PublicPath = "winrt\\";
const std::string InternalPath = "internal\\";
std::string DatabasePath;
Modern::Options Options;

std::string Namespace;
std::string NamespaceDotName;
std::string FileNamespace;
std::string FileNamespaceDotName;

int EnumerationId;
std::string EnumerationName;
bool EnumerationFlag;
std::string EnumeratorName;
std::string EnumeratorValue;

int StructureId;
std::string StructureName;
std::string FieldName;
std::string FieldType;
TypeCategory FieldCategory;

int ClassId;
std::string ClassName;
std::string ClassDefaultInterface;
std::string ClassDotName;
unsigned ClassDotNameLength;
bool ClassActivatable;
std::string BaseName;
std::string GenericDefine;

int InterfaceId;
std::string InterfaceName;
std::string InterfaceGuid;
bool InterfaceDelegate;
bool InterfaceComposable;
std::string RequiredInterfaceName;

std::string UsingInterface;
std::string UsingMethod;

int MethodId;
std::string MethodName;
std::string MethodAbi;
bool MethodDeprecated;
std::string MethodShim;
std::string UsingInterfaceName;
std::string UsingMethodName;

std::string DelegateName;
std::string DelegateImplementation;

Modern::ParameterInfo ParameterInfo;

}
