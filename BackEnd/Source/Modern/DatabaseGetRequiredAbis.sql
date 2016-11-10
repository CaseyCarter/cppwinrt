with recursive

BaseFamily(Id) as
(
  select Base from Classes where Namespace = ?1
  union all
  select Base from Classes join BaseFamily on Classes.RowId = Id
),

Family(Id) as
(
  select rowId from Classes where Namespace = ?1
  union all
  select Base from Classes join Family on Classes.RowId = Id
),

RequiredInterfaceForClass(Id) as
(
  select Interface from ClassInterfaces where ClassId in (select Id from Family) and not Protected
  union
  select Requires from RequiredInterfaces join RequiredInterfaceForClass on InterfaceId = Id
),

RequiredInterfaceForInterface(Id) as
(
  select Requires from RequiredInterfaces where InterfaceId in (select rowId from Interfaces where Namespace = ?1)
  union
  select Requires from RequiredInterfaces join RequiredInterfaceForInterface on InterfaceId = Id
)

select distinct Namespace, replace(Namespace, "::", ".") as NamespaceDotNotation
from 
(
  select TypeNamespace as Namespace
  from
  Fields
  where StructureId in
  (
    select RowId
    from Structures
    where Namespace = ?1
  )
  and TypeName is not null
  
  union

  select Namespace
  from Interfaces
  where RowId in (select Id from RequiredInterfaceForClass)

  union

  select Namespace from Interfaces where RowId in (select Id from RequiredInterfaceForInterface)
)
where Namespace not in (?1, "Windows::Foundation::Numerics", "Windows")