select Interface, Name, Namespace
from Interfaces
where RowId in (select Interface from ClassStatics where ClassId = ?1)
order by Name