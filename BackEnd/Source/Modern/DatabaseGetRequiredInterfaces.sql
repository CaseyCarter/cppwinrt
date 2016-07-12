with recursive

Required(Id) as
(
  select Requires from RequiredInterfaces where InterfaceId = ?1 
  union
  select Requires from RequiredInterfaces join Required on InterfaceId = Id
)

select FullName from Interfaces where RowId in (select Id from Required)
union
select Requires as FullName from RequiredInterfaces where InterfaceId = ?1 and typeof(Requires) = 'text'
order by FullName