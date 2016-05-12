select Interface, substr(FullName, Name + 3)
from ClassStatics c join Interfaces i on c.Interface = i.RowId
where ClassId = ?
order by FullName