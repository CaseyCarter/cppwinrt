select Namespace, replace(Namespace, "::", ".") as NamespaceDotNotation
from
(
  select TypeNamespace as Namespace
  from Parameters
  where MethodId in
  (
    select RowId
    from Methods
    where InterfaceId in
    (
      select RowId
      from Interfaces
      where Namespace = ?1
    )
  )
    and TypeName is not null
    and Type not in (select FullName from GenericInterfaces where FullName = Type)

  union

  select Namespace
  from Interfaces
  where RowId in (select Interface from ClassInterfaces where ClassId in (select RowId from Classes where Namespace = ?1))

  union

  select TypeNamespace as Namespace
  from Fields
  where StructureId in
  (
    select RowId
    from Structures
    where Namespace = ?1
  )
    and TypeName is not null
)
where Namespace not in (?1, "Windows::Foundation::Numerics", "Windows")