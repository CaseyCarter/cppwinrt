with recursive

Exclude(Id) as
(
  select Interface from ClassInterfaces where ClassId = ?1 and IsDefault
  union all 
  select Requires from RequiredInterfaces join Exclude on InterfaceId = Id
),

Family(Id) as
(
  select ?1
  union all
  select Base from Classes join Family on Classes.RowId = Id
),

Required(Id) as
(
  select Interface from ClassInterfaces where ClassId in (select Id from Family) and not Protected
  union
  select Requires from RequiredInterfaces join Required on InterfaceId = Id
)

select FullName from Interfaces where RowId in (select Id from Required where Id not in (select Id from Exclude))
union all
select Interface as FullName from ClassInterfaces
where ClassId in (select Id from Family)
  and typeof(Interface) = 'text'
  and Interface not in (select Requires from RequiredInterfaces where InterfaceId = (select Interface from ClassInterfaces where ClassId = ?1 and IsDefault))
  and Interface not in (select Interface from ClassInterfaces where ClassId = ?1 and IsDefault)