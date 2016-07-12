select RowId, Name, Namespace, DefaultInterface
from Classes
where RowId in (select ClassId from ClassConstructors where Composable and Interface in (select InterfaceId from Methods)) 
  and Namespace = ?1
order by Name