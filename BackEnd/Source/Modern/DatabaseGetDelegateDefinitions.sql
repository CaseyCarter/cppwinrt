select i.RowId, substr(i.FullName, i.Name + 3) as Name, substr(i.FullName, 1, i.Name) as Namespace, m.RowId
from Interfaces i join Methods m on m.InterfaceId = i.RowId
where Delegate
order by Namespace, Name