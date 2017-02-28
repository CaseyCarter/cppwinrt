select RowId, Name, AbiName, ifnull(Deprecated, '')
from Methods
where InterfaceId = ?