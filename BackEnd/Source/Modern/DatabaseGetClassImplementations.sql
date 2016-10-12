select Name, Namespace, DefaultInterface, replace(FullName, '::', '.')
from Classes
where Namespace = ?1
order by Name