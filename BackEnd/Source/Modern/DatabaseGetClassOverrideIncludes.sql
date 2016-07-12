with recursive

Family(Id) as
(
  select RowId
  from Classes
  where RowId in (select ClassId from ClassConstructors where Composable and Interface in (select InterfaceId from Methods)) 
    and Namespace = ?1

  union

  select Base from Classes join Family on Classes.RowId = Id
)

select distinct Namespace, replace(Namespace, "::", ".") as NamespaceDotNotation
from Interfaces
where RowId in (select Interface from ClassInterfaces where overridable and ClassId in (select Id from Family))
  and Namespace not in (?1, "Windows::Foundation::Numerics", "Windows")