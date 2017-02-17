select RowId, Name, Namespace, ifnull(Deprecated, '') 'Deprecated'
from Structures
where Namespace = ?1