select Name, Type, Category, ifnull(Deprecated, '')
from Fields
where StructureId = ?
order by RowId