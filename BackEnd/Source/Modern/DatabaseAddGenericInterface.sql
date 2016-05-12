insert or ignore into GenericInterfaces (FullName, Name, Uuid)
values (?2 || '::' || ?1, length(?2), lower(?3))