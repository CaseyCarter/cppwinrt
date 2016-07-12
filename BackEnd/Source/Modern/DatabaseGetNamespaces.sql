select Namespace, replace(Namespace, "::", ".") as NamespaceDotNotation
from
(
  select Namespace from Classes
  union
  select Namespace from Interfaces
  union
  select Namespace from Structures
  union
  select Namespace from Enumerations

  order by Namespace
)