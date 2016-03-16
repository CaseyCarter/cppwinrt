using Microsoft.Wcl.DataStore;
using Microsoft.Wcl.Parsers;
using System;
using System.Collections.Generic;

namespace Microsoft.Wcl.ParameterizedTypeInstanceIID
{
    /// <summary>
    /// Wraps native API GetParameterizedInstanceIID (and everything that comes with it) to get iids for generic interfaces.
    /// It uses the Repository of all *Info objects to provide the info needed by the lower level APIs that are used.
    /// </summary>
    internal class ParameterizedTypeInstanceIIDMaker
    {
        public ParameterizedTypeInstanceIIDMaker(IDictionary<string, object> repository)
        {
            this.Repository = repository;
        }

        public Guid GetIID(string fullTypeName)
        {
            Guid guid = Guid.Empty;

            this.CurrentType = fullTypeName;

            try
            {
                ParameterizedTypeInstanceIIDNativeAdapter adapter = new ParameterizedTypeInstanceIIDNativeAdapter();
                guid = adapter.GetParameterizedInstanceIID(fullTypeName, Locate);
            }
            finally
            {
                this.CurrentType = null;
            }

            return guid;
        }

        /// <summary>
        /// Called by RoGetParameterizedIID (via the adapter) when it needs information about a part within the type for which the IID is been generated for
        /// </summary>
        /// <param name="nameElement">Type that RoGetParameterizedIID needs information about</param>
        /// <param name="simpleMetadataBuilder">Object (actually nicely wrapped) provided during RoGetParameterizedIID callback that is used to provide the information needed to generate the IID</param>
        private int Locate(string nameElement, SimpleMetadataBuilder simpleMetadataBuilder)
        {
            object obj = null;
            if (!this.Repository.TryGetValue(nameElement, out obj))
            {
                throw new InvalidOperationException(String.Format(StringExceptionFormats.TypeNotFoundInRepositoryWithKnownCurrent, nameElement, this.CurrentType));
            }

            var typeKind = InfoObjectTypeDefinition.GetInfoObjectTypeKind(obj, this.CurrentType);

            switch (typeKind)
            {
                case TypeDefinitionKind.RuntimeClass:
                    DoRuntimeclass(nameElement, (RuntimeClassInfo)obj, simpleMetadataBuilder);
                    break;
                case TypeDefinitionKind.Interface:
                    DoInterface(nameElement, (InterfaceInfo)obj, simpleMetadataBuilder);
                    break;
                case TypeDefinitionKind.Delegate:
                    DoDelegate(nameElement, (InterfaceInfo)obj, simpleMetadataBuilder);
                    break;
                case TypeDefinitionKind.Struct:
                    DoStruct(nameElement, (StructInfo)obj, simpleMetadataBuilder);
                    break;
                case TypeDefinitionKind.Enum:
                    DoEnum(nameElement, (EnumInfo)obj, simpleMetadataBuilder);
                    break;
                default:
                    throw new NotImplementedException(String.Format(StringExceptionFormats.InvalidRepositoryTypeKind, this.CurrentType));
            }

            return 0;
        }

        private void DoStruct(string nameElement, StructInfo info, SimpleMetadataBuilder builder)
        {
            var typeSignature = GetTypeSignature(nameElement);
            var typeSignatures = new List<string>();

            // Structs require that if a field is a Generic type, the parts should be broken and used as part of the input to the builder
            for (int i = 0; i < info.FieldsInfo.Count; i++)
            {
                if (GenericInterfaceParser.IsGenericInterface(info.FieldsInfo[i].Type))
                {
                    string[] parts = TypeNameParser.GetParts(info.FieldsInfo[i].Type);
                    foreach (var part in parts)
                    {
                        typeSignatures.Add(this.GetTypeSignature(part));
                    }
                }
                else
                {
                    typeSignatures.Add(this.GetTypeSignature(info.FieldsInfo[i].Type));
                }
            }

            builder.SetStruct(typeSignature, typeSignatures.ToArray());
        }

        private void DoDelegate(string nameElement, InterfaceInfo info, SimpleMetadataBuilder builder)
        {
            this.DoInterface(nameElement, info, builder);
        }

        private void DoInterface(string nameElement, InterfaceInfo info, SimpleMetadataBuilder builder)
        {
            var genericInterfaceArgumentCount = 0u;
            var interfaceGuid = Guid.Parse(info.Uuid);
            var isGenericInterface = GenericInterfaceParser.TryGetGenericInterfaceArgumentCount(nameElement, out genericInterfaceArgumentCount);
            
            if (info.Delegate == null)
            {
                if (isGenericInterface)
                {
                    builder.SetParameterizedInterface(interfaceGuid, genericInterfaceArgumentCount);
                }
                else
                {
                    builder.SetWinRtInterface(interfaceGuid);
                }
            }
            else
            {
                if (isGenericInterface)
                {
                    builder.SetParameterizedDelegate(interfaceGuid, genericInterfaceArgumentCount);
                }
                else
                {
                    builder.SetDelegate(interfaceGuid);
                }
            }
        }

        private void DoRuntimeclass(string nameElement, RuntimeClassInfo info, SimpleMetadataBuilder builder)
        {
            var typeSignature = GetTypeSignature(nameElement);
            var defaultInterfaceSignatureName = GetTypeSignature(info.DefaultInterface);
            var isDefaultInterfaceAGenericInterface = GenericInterfaceParser.IsGenericInterface(info.DefaultInterface);

            if (info.DefaultInterface != null)
            {
                if (isDefaultInterfaceAGenericInterface)
                {
                    string[] parts = TypeNameParser.GetParts(info.DefaultInterface);
                    string[] typeSignatures = GetTypesSignatures(parts);
                    builder.SetRuntimeClassParameterizedDefault(typeSignature, typeSignatures);
                }
                else
                {
                    object interfaceInfoObj = null;
                    InterfaceInfo interfaceInfo = null;
                    if (!this.Repository.TryGetValue(TypeNameUtilities.GetFullTypeNameInDotForm(info.DefaultInterface), out interfaceInfoObj))
                    {
                        throw new InvalidOperationException(String.Format(StringExceptionFormats.TypeNotFoundInRepositoryWithKnownCurrent, nameElement, this.CurrentType));
                    }
                    interfaceInfo = (InterfaceInfo)interfaceInfoObj;

                    Guid interfaceGuid = Guid.Parse(interfaceInfo.Uuid);
                    builder.SetRuntimeClassSimpleDefault(typeSignature, defaultInterfaceSignatureName, ref interfaceGuid);
                }
            }
            else
            {
                Guid nullGuid = Guid.Empty;
                builder.SetRuntimeClassSimpleDefault(typeSignature, defaultInterfaceSignatureName, ref nullGuid);
            }
        }

        private void DoEnum(string nameElement, EnumInfo info, SimpleMetadataBuilder builder)
        {
            var typeSignature = GetTypeSignature(nameElement);
            var baseType = (info.Flags ? "UInt32" : "Int32");

            builder.SetEnum(typeSignature, baseType);
        }

        private string GetTypeSignature(string typeName)
        {
            return TypeNameUtilities.GetFullTypeNameInDotForm(typeName);
        }

        private string[] GetTypesSignatures(string[] types)
        {
            string[] output = new string[types.Length];

            for (int i = 0; i < types.Length; i++)
            {
                output[i] = GetTypeSignature(types[i]);
            }

            return output;
        }

        /// <summary>
        /// Dictionary with all the *Info objects (Interface, Runtimeclass, etc). Needed when querying for info needed to answer the questions 
        /// that RoGetParameterizedIIDs needs in order to create the IIDs
        /// </summary>
        IDictionary<string, object> Repository { get; set; }

        /// <summary>
        /// Due to constrains witht the contract of IRoMetaDataLocator.Locate AND in order to provide a better exception error
        /// when attemping to generate and IID, the type is cached here and if something goes wrong, it is used as part
        /// of the exception info.
        /// </summary>
        string CurrentType { get; set; }
    }
}
