select RowId, substr(FullName, Name + 3) as Name, substr(FullName, 1, Name) as Namespace, Flags
from Enumerations
order by Namespace, Name