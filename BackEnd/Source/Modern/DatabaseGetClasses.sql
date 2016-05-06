select RowId, substr(FullName, Name + 3) as Name, substr(FullName, 1, Name) as Namespace, DefaultInterface, Activatable
from Classes
order by Namespace, Name
