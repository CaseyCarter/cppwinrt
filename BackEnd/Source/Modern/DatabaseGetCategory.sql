select case
when exists (select * from Enumerations where FullName = ?1) then 4
when exists (select * from Structures where FullName = ?1) then 8
when exists (select * from Interfaces where FullName = ?1) then 16
when exists (select * from Classes where FullName = ?1) then 64
when exists (select * from Interfaces where Delegate = ?1) then 32
when exists (select * from Deprecated where Name = ?1) then 256
else 0
end