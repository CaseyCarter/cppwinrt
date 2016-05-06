select Interfaces.RowId, substr(FullName, Name + 3) as Name, substr(FullName, 1, Name) as Namespace
from ClassInterfaces, Interfaces
where Overridable
and Interface = Interfaces.RowId
order by Namespace, Name