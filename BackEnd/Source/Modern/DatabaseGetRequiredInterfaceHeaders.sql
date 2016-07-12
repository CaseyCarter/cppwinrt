with recursive

Family(Id) as
(
  select rowid from Classes where Namespace = ?1
  union all
  select Base from Classes join Family on Classes.RowId = Id
),

Required(Id) as
(
  select Interface from ClassInterfaces where ClassId in (select Id from Family) and not Protected
  union
  select Requires from RequiredInterfaces join Required on InterfaceId = Id
)

select Namespace, NamespaceDotNotation
from
(
  select Namespace, replace(Namespace, "::", ".") as NamespaceDotNotation from Interfaces where RowId in (select Id from Required)
  union
  select "Windows::Foundation::Collections" as Namespace, "Windows.Foundation.Collections" as NamespaceDotNotation from ClassInterfaces
  where ClassId in (select Id from Family)
    and typeof(Interface) = 'text'
)
where
  Namespace not in (?1, "Windows", "Windows::Foundation::Numerics")