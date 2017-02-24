select RowId, Name, Namespace, DefaultInterface, Activatable, ifnull(Deprecated, '') 'Deprecated'
from Classes
where Namespace = ?1
order by Name