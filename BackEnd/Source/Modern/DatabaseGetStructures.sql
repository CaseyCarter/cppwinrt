select RowId, substr(FullName, Name + 3), substr(FullName, 1, Name)
from Structures
order by Depends