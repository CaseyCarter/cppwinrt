select Name, Type, ClassType, Category, Flags, TypeName
from Parameters
where MethodId = ?
order by RowId