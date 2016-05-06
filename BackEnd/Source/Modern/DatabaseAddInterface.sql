insert or replace into Interfaces (FullName, Name, Uuid)
values (?2 || '::' || ?1, length(?2), lower(?3))