select RowId, substr(FullName, Name + 3) as Name, substr(FullName, 1, Name) as Namespace, replace(FullName, '::', '.'), DefaultInterface
from Classes
order by Namespace
