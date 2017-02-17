select Name, Type, Category, ifnull(Deprecated, '') 'Deprecated'
from Fields
where StructureId = ?
order by RowId