select RowId, Name, Namespace, Uuid
from Interfaces
where not Delegate 
  and Namespace = ?1
order by Name