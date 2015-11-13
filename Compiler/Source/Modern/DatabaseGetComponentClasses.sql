select RowId, substr(FullName, Name + 3) as Name, substr(FullName, 1, Name) as Namespace, substr(replace(FullName, '::', '.'), 2 + (select length(Name) from Settings)), DefaultInterface
from Classes
order by Namespace