select RowId, Name, Namespace
from Interfaces
where RowId in (select Interface from ClassInterfaces where Overridable) 
  and Namespace = ?1
order by Name