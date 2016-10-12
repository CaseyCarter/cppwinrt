select RowId, Name, Namespace, Flags
from Enumerations
where Namespace = ?1
order by Name