delete from Enumerations
where FullName = 'Windows::Foundation::Collections::CollectionChange';

delete from ClassInterfaces
where Interface in (select Name from Deprecated);

update Fields set Type = 'HSTRING' where Type = 'String';
update Fields set Type = 'boolean' where Type = 'bool';
update Fields set Type = 'ABI::' || Type || ' *' where Type like '%<%';

update Parameters
set Category = 16,
	Type = (select DefaultInterface from Classes where Type = FullName)
where Category = 64;

update Methods
set Deprecated = 1
where RowId in (select MethodId from Parameters where SizeIs <> '');

update ClassConstructors  set Interface = (select RowId from Interfaces where Interface = FullName);
update ClassStatics       set Interface = (select RowId from Interfaces where Interface = FullName);
update ClassInterfaces    set Interface = ifnull((select RowId from Interfaces where Interface = FullName), Interface);
update RequiredInterfaces set Requires  = ifnull((select RowId from Interfaces where Requires  = FullName), Requires);

delete from ClassInterfaces
where ClassId in (select RowId from Classes where DefaultInterface like '%<%')
and not IsDefault
and typeof(Interface) = 'text';