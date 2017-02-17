select RowId, Name, Namespace, ifnull(Deprecated, '') 'Deprecated'
from Interfaces
where not Delegate 
  and Namespace = ?1
order by Name