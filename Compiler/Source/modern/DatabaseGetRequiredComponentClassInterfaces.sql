with recursive

Family(Id) as
(
	select ?1
	union all
	select Base from Classes, Family where Classes.RowId = Id
),

Required(Id) as
(
	select Interface from ClassInterfaces where ClassId in (select Id from Family) and not Protected
	union
	select Requires from RequiredInterfaces, Required where InterfaceId = Id
)

select Interfaces.RowId, FullName from Required, Interfaces where Id = Interfaces.RowId
union all
select 0, Interface from ClassInterfaces
where ClassId in (select Id from Family)
and typeof(Interface) = 'text'
