select i.RowId, i.Name, i.Namespace, m.RowId, ifnull(i.Deprecated, '')
from Interfaces i 
  join Methods m on m.InterfaceId = i.RowId
where Delegate 
  and Namespace = ?1
order by i.Name