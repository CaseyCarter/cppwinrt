select RowId, Name, Namespace
from Structures
where RowId in (select StructureId from Fields where Category in (2, 16))
  and Namespace = ?1