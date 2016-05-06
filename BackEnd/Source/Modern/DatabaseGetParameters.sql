select Name, Type, ClassType, Category, Flags
from Parameters
where MethodId = ?
order by RowId