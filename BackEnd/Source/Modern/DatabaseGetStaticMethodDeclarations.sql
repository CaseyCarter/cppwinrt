select c.Interface, i.Name, m.RowId, m.Name, m.AbiName, ifnull(m.Deprecated, '')
from ClassStatics c 
  join Interfaces i on c.Interface = i.RowId
  join methods m on c.Interface = m.InterfaceId
where ClassId = ?1
order by i.Name