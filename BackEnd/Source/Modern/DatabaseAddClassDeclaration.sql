insert or ignore into Classes (FullName, Name)
values (?2 || '::' || ?1, length(?2))