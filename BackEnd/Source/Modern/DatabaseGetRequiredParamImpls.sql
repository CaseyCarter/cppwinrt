select TypeNamespace, replace(TypeNamespace, "::", ".") as TypeNamespaceDotNotation
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
  and TypeNamespace not in (?1, "Windows::Foundation::Numerics", "Windows")