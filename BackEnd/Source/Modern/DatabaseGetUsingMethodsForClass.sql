with recursive

Family(Id) as
(
  select ?1
  union all
  select Base from Classes join Family on Classes.RowId = Id
),

Required(Id) as
(
  select Interface from ClassInterfaces where ClassId in (select Id from Family)
  union
  select Requires from RequiredInterfaces join Required on InterfaceId = Id
),

BaseMethods(Id) as
(
  select RowId from Methods where InterfaceId in (select Id from Required)
),

BasePairs(Interface, Method) as
(
  select distinct i.Name, m.Name from Interfaces i join Methods m on i.RowId = m.InterfaceId where m.RowId in (select Id from BaseMethods)
),

CountedMethods(Method, Count) as
(
  select Method, count(*) from BasePairs group by Method
)

select Interface, Method
from BasePairs
where Method in (select Method from CountedMethods where Count > 1)
order by Interface, Method