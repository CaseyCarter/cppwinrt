select RowId, Name, AbiName, ifnull(Deprecated, '') 'Deprecated'
from Methods
where InterfaceId = ?