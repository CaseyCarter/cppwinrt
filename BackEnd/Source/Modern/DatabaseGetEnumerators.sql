select Name, Value, ifnull(Deprecated, '')
from Enumerators
where EnumerationId = ?