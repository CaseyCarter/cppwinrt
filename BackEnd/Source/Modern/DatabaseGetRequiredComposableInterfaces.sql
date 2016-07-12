with recursive

Family(Id) as
(
  select ?1
  union all
  select Base from Classes join Family on Classes.RowId = Id
),

Required(Id) as
(
  select Interface from ClassInterfaces where ClassId in (select Id from Family) and not Overridable
  union
  select Requires from RequiredInterfaces join Required on InterfaceId = Id
)

select FullName from Interfaces where RowId in (select Id from Required)
union all
select Interface from ClassInterfaces where ClassId in (select Id from Family) and typeof(Interface) = 'text'
