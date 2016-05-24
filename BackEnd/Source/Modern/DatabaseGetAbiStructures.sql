select RowId, substr(FullName, Name + 3), substr(FullName, 1, Name)
from Structures
where RowId in (select StructureId from Fields where Category = 2 or Category = 16);