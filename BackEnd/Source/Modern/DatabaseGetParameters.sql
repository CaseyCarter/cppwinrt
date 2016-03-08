select Name, Type, ClassType, Direction, Category
from Parameters
where MethodId = ?
order by RowId