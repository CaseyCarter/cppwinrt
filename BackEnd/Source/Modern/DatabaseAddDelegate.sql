insert or replace into Interfaces (FullName, Name, Delegate, Uuid)
values (?2 || '::' || ?1, length(?2), 1, lower(?3))