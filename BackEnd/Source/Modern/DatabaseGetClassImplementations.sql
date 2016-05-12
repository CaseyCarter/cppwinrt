select substr(FullName, Name + 3) as Name, substr(FullName, 1, Name) as Namespace, DefaultInterface, replace(FullName, '::', '.')
from Classes
order by Namespace, Name