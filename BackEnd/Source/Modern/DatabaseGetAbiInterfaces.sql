select RowId, Name, Namespace, Uuid, Delegate
from Interfaces
where Namespace = ?1
order by Name