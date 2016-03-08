select RowId, substr(FullName, Name + 3), substr(FullName, 1, Name) as Namespace, Delegate is not null, Uuid
from Interfaces
order by Namespace