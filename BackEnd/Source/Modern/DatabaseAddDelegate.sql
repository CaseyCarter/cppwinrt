insert or replace into Interfaces (FullName, Name, Delegate, Uuid)
values (?2 || '::I' || ?1, length(?2), ?2 || '::' || ?1, lower(?3))