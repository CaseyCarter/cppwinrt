with recursive

Family(Id) as
(
  select ?1
  union all
  select Base from Classes join Family on Classes.RowId = Id
)

select FullName, Namespace, replace(Namespace, "::", ".") as NamespaceDotNotation
from Interfaces
where RowId in (select Interface from ClassInterfaces where overridable and ClassId in (select Id from Family))