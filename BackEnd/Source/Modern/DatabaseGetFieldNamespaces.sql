select distinct TypeNamespace, replace(TypeNamespace, "::", ".") as TypeNamespaceDotNotation
from Fields
where StructureId in
(
  select RowId
  from Structures
  where Namespace = ?1
)
  and TypeName is not null
  and TypeNamespace not in (?1, "Windows::Foundation::Numerics", "Windows")