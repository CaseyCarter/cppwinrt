select Name, Namespace, Delegate
from Interfaces
where Namespace = ?1
order by Name