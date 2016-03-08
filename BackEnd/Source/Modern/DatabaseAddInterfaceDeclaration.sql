insert or ignore into Interfaces (FullName, Name)
values (?2 || '::' || ?1, length(?2))