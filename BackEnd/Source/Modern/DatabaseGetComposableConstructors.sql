select c.Interface, i.Name, m.RowId, m.Name
from ClassConstructors c 
  join Interfaces i on c.Interface = i.RowId
  join methods m on m.InterfaceId = c.Interface
where ClassId = ? 
  and Composable