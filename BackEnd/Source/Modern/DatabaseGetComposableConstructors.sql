select Interface, substr(FullName, Name + 3)
from ClassConstructors c join Interfaces i on c.Interface = i.RowId
where ClassId = ? and Composable