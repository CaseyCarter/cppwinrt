select Interfaces.RowId, substr(FullName, Name + 3), substr(FullName, 1, Name) as Namespace
from ClassInterfaces, Interfaces
where Overridable
and Interface = Interfaces.RowId
order by Namespace