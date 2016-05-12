insert or ignore into Interfaces (FullName, Name, Delegate)
values (?2 || '::' || ?1, length(?2), 1)