select substr(FullName, Name + 3), substr(FullName, 1, Name) as Namespace
from Interfaces, ClassInterfaces
where Overridable
and Interfaces.RowId = Interface
order by Namespace