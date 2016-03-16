using System.Collections.Generic;
using System.Reflection.Metadata;

using Microsoft.Wcl.DataStore;
using System.Diagnostics;

namespace Microsoft.Wcl.Parsers
{
    internal class RuntimeclassMetadataParser
    {
        public void Initialize(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;
        }

        public RuntimeClassInfo Parse(MetadataReader assembly, TypeDefinition typeDef)
        {
            var runtimeClassInfo = new RuntimeClassInfo();
            string defaultInterfaceFullTypeName = null;
            IList<RuntimeClassInterfaceInfo> classInterfaces = null;

            var namespaceName = assembly.GetString(typeDef.Namespace);
            var typeName = assembly.GetString(typeDef.Name);
            var fullTypeName = TypeNameUtilities.GetFormattedFullTypeName(namespaceName, typeName);
            var customAttributes = CustomAttributeMetadataParser.GetAttributes(assembly, typeDef);

            GetInterfacesInfo(assembly, typeDef, fullTypeName, out defaultInterfaceFullTypeName, out classInterfaces);

            runtimeClassInfo.FullTypeName = fullTypeName;
            runtimeClassInfo.Name = TypeNameUtilities.GetIndexOfTypeName(runtimeClassInfo.FullTypeName);
            runtimeClassInfo.Activatable = CustomAttributeMetadataParser.FindAttribute(assembly, customAttributes, CustomAttributeKind.DefaultActivatable);
            runtimeClassInfo.DefaultInterface = (defaultInterfaceFullTypeName != null ? defaultInterfaceFullTypeName : string.Empty);
            runtimeClassInfo.InterfacesInfo = classInterfaces;
            runtimeClassInfo.Deprecated = CustomAttributeMetadataParser.FindAttribute(assembly, customAttributes, CustomAttributeKind.Deprecated);

            var parentTypeHandle = typeDef.BaseType;
            var parentFullTypeName = MetadataParserHelpers.GetFullTypeNameFromMetadata(assembly, parentTypeHandle);

            if (parentFullTypeName != FullTypeNameConstants.System_Object)
            {
                runtimeClassInfo.Base = parentFullTypeName;
            }

            IList<RuntimeClassInterfaceInfo> moreInterfacesInfo = null;
            IList<RuntimeClassStaticInterfaceInfo> staticInterfacesInfo = null;
            IList<RuntimeClassConstructorInterfaceInfo> contructorInterfacesInfo = null;

            this.GetInfoObjectsFromCustomAttributes(assembly, fullTypeName, customAttributes, out moreInterfacesInfo, out staticInterfacesInfo, out contructorInterfacesInfo);

            runtimeClassInfo.InterfacesInfo.Add(moreInterfacesInfo);
            runtimeClassInfo.StaticInterfacesInfo = staticInterfacesInfo;
            runtimeClassInfo.ContructorInterfacesInfo = contructorInterfacesInfo;

            return runtimeClassInfo;
        }

        private void GetInfoObjectsFromCustomAttributes(MetadataReader assembly, 
            string runtimeclassFullTypeName,
            IList<CustomAttributeInfo> customAttributes,
            out IList<RuntimeClassInterfaceInfo> moreInterfacesInfo,
            out IList<RuntimeClassStaticInterfaceInfo> staticInterfacesInfo, 
            out IList<RuntimeClassConstructorInterfaceInfo> contructorInterfacesInfo)
        {
            moreInterfacesInfo = null;
            staticInterfacesInfo = null;
            contructorInterfacesInfo= null;

            var moreInterfacesInfoLocal = new List<RuntimeClassInterfaceInfo>();
            var staticInterfacesInfoLocal = new List<RuntimeClassStaticInterfaceInfo>();
            var contructorInterfacesInfoLocal = new List<RuntimeClassConstructorInterfaceInfo>();

            foreach (var customAttribute in customAttributes)
            {
                if (customAttribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_ComposableAttribute)
                {
                    var compositionTypeInfo = CompositionTypeInfo.Unknown;
                    string composableInterfaceFullTypeName = null;

                    CustomAttributeMetadataParser.GetCompositionTypeInfo(assembly, customAttribute, out compositionTypeInfo, out composableInterfaceFullTypeName);
                    {
                        var info = new RuntimeClassConstructorInterfaceInfo();
                        info.RuntimeclassFullTypeName = runtimeclassFullTypeName;
                        info.Interface = composableInterfaceFullTypeName;
                        info.Composable = true;
                        info.Protected = (compositionTypeInfo == CompositionTypeInfo.Protected);

                        contructorInterfacesInfoLocal.Add(info);
                    }
                }
                else if (customAttribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_StaticAttribute)
                {
                    string staticInterfaceFullTypeName = null;

                    CustomAttributeMetadataParser.GetStaticInterface(assembly, customAttribute, out staticInterfaceFullTypeName);
                    {
                        var info = new RuntimeClassStaticInterfaceInfo();
                        info.RuntimeclassFullTypeName = runtimeclassFullTypeName;
                        info.Interface = staticInterfaceFullTypeName;

                        staticInterfacesInfoLocal.Add(info);
                    }
                }
                else if (customAttribute.FullTypeName == FullTypeNameConstants.Windows_Foundation_Metadata_ActivatableAttribute)
                {
                    string activatableInterfaceFullTypeName = null;

                    CustomAttributeMetadataParser.GetActivatableInterface(assembly, customAttribute, out activatableInterfaceFullTypeName);
                    if (activatableInterfaceFullTypeName != null)
                    {
                        {
                            var info = new RuntimeClassConstructorInterfaceInfo();
                            info.RuntimeclassFullTypeName = runtimeclassFullTypeName;
                            info.Interface = activatableInterfaceFullTypeName;
                            info.Composable = false;
                            info.Protected = false;

                            contructorInterfacesInfoLocal.Add(info);
                        }
                    }
                }
            }

            moreInterfacesInfo = moreInterfacesInfoLocal;
            staticInterfacesInfo = staticInterfacesInfoLocal;
            contructorInterfacesInfo = contructorInterfacesInfoLocal;
        }

        private void GetInterfacesInfo(MetadataReader assembly, TypeDefinition typeDef, string runtimeClassFullTypeName, out string defaultInterfaceFullTypeName, out IList<RuntimeClassInterfaceInfo> classInterfaces)
        {
            var list = new List<RuntimeClassInterfaceInfo>();
            bool defaultIntefaceFound = false;

            defaultInterfaceFullTypeName = null;

            foreach (var implDefHandle in typeDef.GetInterfaceImplementations())
            {
                var implDef = assembly.GetInterfaceImplementation(implDefHandle);
                var interfaceHandle = implDef.Interface;
                var interfaceFullTypeName = MetadataParserHelpers.GetFullTypeNameFromMetadata(assembly, interfaceHandle);
                CustomAttributeInfo defaultInterfaceCustomAttributeInfo = null;
                var implInterfaceCustomAttributes = CustomAttributeMetadataParser.GetAttributes(assembly, implDef);

                var info = new RuntimeClassInterfaceInfo();
                info.RuntimeclassFullTypeName = runtimeClassFullTypeName;
                info.Interface = interfaceFullTypeName;
                // This value is true only when dealing with composable types, where one interface is defined as the composable one.
                info.Overridable = CustomAttributeMetadataParser.FindAttribute(assembly, implInterfaceCustomAttributes, CustomAttributeKind.Overridable);
                info.Protected = CustomAttributeMetadataParser.FindAttribute(assembly, implInterfaceCustomAttributes, CustomAttributeKind.Protected);

                // Only check for default interface if we have not found it yet.
                if (!defaultIntefaceFound)
                {
                    if (CustomAttributeMetadataParser.FindAttribute(assembly, implInterfaceCustomAttributes, CustomAttributeKind.DefaultInterface, out defaultInterfaceCustomAttributeInfo))
                    {
                        defaultInterfaceFullTypeName = interfaceFullTypeName;
                        info.IsDefault = true;
                        defaultIntefaceFound = true;
                    }
                }

                list.Add(info);
            }

            classInterfaces = list;
        }


        private FrontEndConfiguration Configuration { get; set; }
    }
}
