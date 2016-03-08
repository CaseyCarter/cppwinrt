insert or ignore into Structures (FullName, Name)
values (?2 || '::' || ?1, length(?2))