insert or ignore into Enumerations (FullName, Name)
values (?2 || '::' || ?1, length(?2))