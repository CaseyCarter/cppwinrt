with

Class(Id) as
	(select ifnull((select RowId from Classes where FullName = ?2 || '::' || ?1), (select max(RowId) + 1 from Classes)))

insert or replace into Classes (RowId, FullName, Name, Base)
values ((select Id from Class), ?2 || '::' || ?1, length(?2), (select RowId from Classes where FullName = ?3))