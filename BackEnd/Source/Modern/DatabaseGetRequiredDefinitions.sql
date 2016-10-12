select Namespace
from Classes
where FullName in
(
  select ClassType
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
    and ClassType is not null
)