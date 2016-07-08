using Microsoft.Wcl.Projection;
using System.Collections.Generic;

namespace Microsoft.Wcl.DataStore
{
    internal interface IDataStore
    {
        void Initialize();
        void InsertRuntimeClassInfo(RuntimeClassInfo info);
        void InsertInterfaceInfo(InterfaceInfo info);
        void InsertStructInfo(StructInfo info);
        void InsertEnumInfo(EnumInfo info);
        void InsertGenericInterfaceInfo(GenericInterfaceInfo info);
        void InsertNamespaceToTypeCategoryDependency(string topLevelNamespaceName, string dependentNamespace, IList<TypeCategory> dependentTypeCategories);
        void InsertNamespaceToGenericInterfaceDependency(string namespaceName, IList<string> dependentGenericInterfaces);
        void UpdateSchema();
        void ReconcileData();
        void Save();
        void VerifySemantics();
        void OnParameterizedTypeInstanceParsed(object sender, ParameterizedTypeInstanceParsedEventArgs args);
        IDictionary<string, object> GetRepository();
        IDictionary<string, GenericInterfaceInfo> GetGenericInterfacesRepository();
    }
}
