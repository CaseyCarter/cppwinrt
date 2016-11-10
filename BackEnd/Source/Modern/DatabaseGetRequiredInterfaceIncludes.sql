with recursive

BaseFamily(Id) as
(
  select Base from Classes where Namespace = ?1
  union all
  select Base from Classes join BaseFamily on Classes.RowId = Id
)

select Namespace, replace(Namespace, "::", ".") as NamespaceDotNotation
from
(
  select Namespace
  from Classes
  where RowId in (select Id from BaseFamily)

  union

  select Namespace
  from Interfaces
  where FullName in
  (
    select DefaultInterface
    from classes
    where Namespace = ?1
  )
)
where Namespace not in (?1, "Windows::Foundation::Numerics", "Windows")