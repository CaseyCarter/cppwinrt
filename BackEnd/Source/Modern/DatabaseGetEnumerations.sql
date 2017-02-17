select RowId, Name, Namespace, Flags, ifnull(Deprecated, '') 'Deprecated'
from Enumerations
where Namespace = ?1
order by Name