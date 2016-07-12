select RowId, Name, Namespace
from Structures
where RowId not in (select StructureId from Fields where Category = 2 or Category = 16) 
  and Namespace = ?1