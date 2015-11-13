
create table Settings
(
	Version,
	Sdk default '',
	Out default '',
	Library default '',
	Name default '',
	Command default 0,
	Options default 0
);

create table Includes
(
	Name
);

create table Sources
(
	Name unique collate nocase,
	Parsed default 0,
	Include default 0
);

create table Classes
(
	FullName,
	Name,
	Base,
	DefaultInterface default '',
	Activatable default 0
);
create unique index ClassesIndex on Classes(FullName);

create table Enumerations
(
	FullName,
	Name,
	Flags
);
create unique index EnumerationsIndex on Enumerations(FullName);

create table Enumerators
(
	Name,
	Value,
	EnumerationId
);
create index EnumeratorsIndex on Enumerators(EnumerationId);

create table Interfaces
(
	FullName,
	Name,
	Delegate,
	Uuid
);
create unique index InterfacesIndex on Interfaces(FullName);

create table GenericInterfaces
(
	Name,
	Namespace,
	Uuid
);
create unique index GenericInterfacesIndex on GenericInterfaces(Name, Namespace);

create table Methods
(
	Name,
	AbiName,
	Deprecated,
	InterfaceId
);
create index MethodsIndex on Methods(InterfaceId);

create table Parameters
(
	Name,
	Type,
	ClassType,
	Direction,
	SizeIs,
	LengthIs,
	Category,
	MethodId
);
create index ParametersIndex on Parameters(MethodId);

create table RequiredInterfaces
(
	InterfaceId,
	Requires
);

create table ClassInterfaces
(
	ClassId,
	Interface,
	IsDefault,
	Overridable,
	Protected
);

create table ClassStatics
(
	ClassId,
	Interface
);

create table ClassConstructors
(
	ClassId,
	Interface,
	Composable,
	Protected
);

create table Structures
(
	FullName,
	Name,
	Depends default 0
);
create unique index StructuresIndex on Structures(FullName);

create table Fields
(
	Name,
	Type,
	StructureId
);
create index FieldsIndex on Fields(StructureId);

create table Deprecated
(
	Name text primary key
)
without rowid;
