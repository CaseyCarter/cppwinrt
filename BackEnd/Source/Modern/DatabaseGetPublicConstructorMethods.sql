select c.Interface, i.Name, c.Composable, m.rowId, m.Name
from ClassConstructors c 
  join Interfaces i on c.Interface = i.RowId
  join Methods m on c.Interface = m.InterfaceId
where ClassId = ? 
  and not Protected