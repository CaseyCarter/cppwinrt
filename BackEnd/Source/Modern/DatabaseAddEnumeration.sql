insert or replace into Enumerations (FullName, Name, Flags)
values (?2 || '::' || ?1, length(?2), ?3)