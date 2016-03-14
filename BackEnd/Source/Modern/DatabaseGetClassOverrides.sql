with recursive

Family(Id) as
(
	select ?1
	union all
	select Base from Classes, Family where Classes.RowId = Id
)

select FullName
from ClassInterfaces, Interfaces
where Interface = Interfaces.RowId and Overridable and
ClassId in (select Id from Family)