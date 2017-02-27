select RowId, Name, Namespace, ifnull(Deprecated, '')
from Structures
where Namespace = ?1