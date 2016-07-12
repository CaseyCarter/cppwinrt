select Name, Namespace, Uuid, RowId, replace(Uuid, "-", "_")
from GenericInterfaces
where RowId in (select GenericInterfaceId from NamespaceToGenericInterfaceDependency where Namespace=?1)
order by Depth