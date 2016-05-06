select RowId, substr(FullName, Name + 3) as Name, substr(FullName, 1, Name) as Namespace, Uuid
from Interfaces
where not Delegate
order by Namespace, Name