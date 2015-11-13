select substr(FullName, Name + 3), substr(FullName, 1, Name) as Namespace, DefaultInterface
from Classes
where DefaultInterface <> ''
order by Namespace