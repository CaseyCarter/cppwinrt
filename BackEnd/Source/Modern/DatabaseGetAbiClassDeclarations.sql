select Name, Namespace, DefaultInterface
from Classes
where DefaultInterface <> '' 
  and Namespace = ?1
order by Name