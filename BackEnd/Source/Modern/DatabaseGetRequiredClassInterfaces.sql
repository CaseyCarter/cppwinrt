with recursive

Exclude(Id) as
(
	select Interface from ClassInterfaces where ClassId = ?1 and IsDefault
	union all 
	select Requires from RequiredInterfaces, Exclude where InterfaceId = Id
),

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

select FullName from Required, Interfaces where Id = Interfaces.RowId and Id not in (select Id from Exclude)
union all
select Interface from ClassInterfaces
where ClassId in (select Id from Family)
and typeof(Interface) = 'text'
and Interface not in (select Requires from RequiredInterfaces where InterfaceId = (select Interface from ClassInterfaces where ClassId = ?1 and IsDefault))
and Interface not in (select Interface from ClassInterfaces where ClassId = ?1 and IsDefault)