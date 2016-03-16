with recursive

Required(Id) as
(
	select Requires from RequiredInterfaces where InterfaceId = ?1 
	union
	select Requires from RequiredInterfaces join Required on InterfaceId = Id
)

select FullName from Required r join Interfaces i on r.Id = i.RowId
union all
select Requires from RequiredInterfaces where InterfaceId = ?1 and typeof(Requires) = 'text'