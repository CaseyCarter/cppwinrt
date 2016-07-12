select Interface, Name, Composable
from ClassConstructors c 
  join Interfaces i on c.Interface = i.RowId
where ClassId = ? 
  and not Protected