select RowId, substr(FullName, Name + 3), substr(FullName, 1, Name) as Namespace, Flags
from Enumerations
order by Namespace