select RowId, substr(FullName, Name + 3) as Name, substr(FullName, 1, Name) as Namespace, Uuid, Delegate
from Interfaces
order by Namespace, Name