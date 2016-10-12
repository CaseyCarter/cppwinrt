using Microsoft.Wcl.Projection;
using System.Collections.Generic;
using System.Collections.ObjectModel;

namespace Microsoft.Wcl.DataStore
{
    class KeyedGenericInterfaceCollection : KeyedCollection<string, GenericInterfaceInfo>
    {
        protected override string GetKeyForItem(GenericInterfaceInfo item)
        {
            return item.MetadataFullTypeNameInCppForm;
        }

        public bool TryGetValue(string key, out GenericInterfaceInfo value)
        {
            bool success = false;
            value = null;

            if (this.Contains(key))
            {
                value = this[key];
                success = true;
            }

            return success;
        }
    }

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
        KeyedGenericInterfaceCollection GetGenericInterfacesRepository();
    }
}
