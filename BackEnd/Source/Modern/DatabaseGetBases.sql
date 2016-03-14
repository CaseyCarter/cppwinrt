with recursive

Family(Id) as
(
	select Base from Classes where RowId = ?
	union all
	select Base from Classes, Family where Classes.RowId = Id
)

select FullName
from Classes
where RowId in (select Id from Family)
