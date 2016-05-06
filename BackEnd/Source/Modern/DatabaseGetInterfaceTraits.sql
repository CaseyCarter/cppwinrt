select substr(FullName, Name + 3) as Name, substr(FullName, 1, Name) as Namespace, Delegate
from Interfaces
order by Namespace, Name