insert or ignore into Interfaces (FullName, Name, Delegate)
values (?2 || '::I' || ?1, length(?2), ?2 || '::' || ?1)