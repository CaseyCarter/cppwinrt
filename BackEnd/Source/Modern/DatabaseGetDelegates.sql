select substr(d.FullName, d.Name + 3) as Name, substr(d.FullName, 1, d.Name) as Namespace, m.RowId
from Interfaces d join Methods m on m.InterfaceId = d.RowId
where Delegate
order by Namespace, Name