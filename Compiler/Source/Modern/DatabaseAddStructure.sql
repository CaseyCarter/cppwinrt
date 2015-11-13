insert or replace into Structures (FullName, Name)
values (?2 || '::' || ?1, length(?2))