select Name, Value, ifnull(Deprecated, '') 'Deprecated'
from Enumerators
where EnumerationId = ?