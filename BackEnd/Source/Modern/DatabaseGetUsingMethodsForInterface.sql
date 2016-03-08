with recursive

Required(Id) as
(
	select Requires from RequiredInterfaces where InterfaceId = ?1
	union
	select Requires from RequiredInterfaces join Required on InterfaceId = Id
),

Bases(Id) as
(
	select ?1
	union all
	select Id from Required
),

BaseMethods(Id) as
(
	select RowId from Methods where InterfaceId in (select Id from Bases)
),

BasePairs(Interface, Method) as
(
	select distinct substr(i.FullName, i.Name + 3), m.Name from Interfaces i join Methods m on i.RowId = m.InterfaceId where m.RowId in (select Id from BaseMethods)
),

CountedMethods(Method, Count) as
(
	select Method, count(*) from BasePairs group by Method
)

select Interface, Method from BasePairs where Method in (select Method from CountedMethods where Count > 1)
