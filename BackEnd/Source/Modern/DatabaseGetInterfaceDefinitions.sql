select RowId, Name, Namespace
from Interfaces
where not Delegate 
  and Namespace = ?1
order by Name