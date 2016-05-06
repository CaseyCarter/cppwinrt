select case
when exists (select * from Enumerations where FullName = ?1) then 4
when exists (select * from Structures where FullName = ?1) then 8
when exists (select * from Interfaces where FullName = ?1 and not Delegate) then 16
when exists (select * from Classes where FullName = ?1) then 64
when exists (select * from Interfaces where FullName = ?1 and Delegate) then 32
else 0
end