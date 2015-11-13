select Name, printf('%X', Value)
from Enumerators
where EnumerationId = ?