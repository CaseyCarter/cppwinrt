select RowId, Name
from Methods
where InterfaceId = ?
  and not Deprecated