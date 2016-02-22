select Name, Type, ClassType, Flags, Category
from Parameters
where MethodId = ?
order by RowId