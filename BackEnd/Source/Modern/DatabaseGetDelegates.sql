select substr(d.FullName, d.Name + 3), substr(d.FullName, 1, d.Name) as Namespace, replace(d.Delegate, '::', '_'), m.RowId
from Interfaces d join Methods m on m.InterfaceId = d.RowId
where Delegate not null
order by Namespace