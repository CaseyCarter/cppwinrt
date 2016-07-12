select d.Name, d.Namespace, m.RowId
from Interfaces d 
  join Methods m on m.InterfaceId = d.RowId
where Delegate 
  and Namespace = ?1
order by d.Name