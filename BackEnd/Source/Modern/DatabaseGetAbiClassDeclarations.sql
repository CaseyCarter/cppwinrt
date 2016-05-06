select substr(FullName, Name + 3) as Name, substr(FullName, 1, Name) as Namespace, DefaultInterface
from Classes
where DefaultInterface <> ''
order by Namespace, Name