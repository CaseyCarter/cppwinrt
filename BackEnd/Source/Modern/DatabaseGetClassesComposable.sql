select RowId, substr(FullName, Name + 3) as Name, substr(FullName, 1, Name) as Namespace, DefaultInterface
from Classes
where RowId in (select ClassId from ClassConstructors where Composable and Interface in (select InterfaceId from Methods))
order by Namespace