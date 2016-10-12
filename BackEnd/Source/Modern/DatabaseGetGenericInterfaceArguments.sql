select distinct DependentNamespace, replace(DependentNamespace, "::", ".") as DependentNamespaceDotNotation
from NamespaceToTypeCategoryDependency 
where Namespace=?1 
  and DependentNamespace not in ("", ?1, "Windows::Foundation::Numerics", "Windows")