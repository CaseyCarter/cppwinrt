select FullName
from ClassStatics c join Interfaces i on c.Interface = i.RowId
where ClassId = ?