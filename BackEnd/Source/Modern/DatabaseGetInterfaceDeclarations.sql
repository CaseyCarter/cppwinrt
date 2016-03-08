select substr(FullName, Name + 3), substr(FullName, 1, Name) as Namespace from Interfaces
union all 
select substr(FullName, Name + 3), substr(FullName, 1, Name) as Namespace from Classes where DefaultInterface <> ''
order by Namespace