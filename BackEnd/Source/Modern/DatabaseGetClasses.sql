select RowId, Name, Namespace, DefaultInterface, Activatable
from Classes
where Namespace = ?1
order by Name
