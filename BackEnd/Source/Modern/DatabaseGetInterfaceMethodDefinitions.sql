select i.Name, i.Namespace, m.RowId, m.Name, m.AbiName
from Interfaces i
  join Methods m on m.InterfaceId = i.rowId
where not i.Delegate 
  and i.Namespace = ?1