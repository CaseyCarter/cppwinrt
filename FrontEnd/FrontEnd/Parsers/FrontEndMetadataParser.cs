using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;

using Microsoft.Wcl.DataStore;

namespace Microsoft.Wcl.Parsers
{
    internal class FrontEndMetadataParser
    {
        public void Initialize(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;
            this.Winmds = this.Configuration.Arguments["winmd"].Values;

            this.RuntimeclassMetadataParser = new RuntimeclassMetadataParser();
            this.RuntimeclassMetadataParser.Initialize(this.Configuration);
            this.InterfaceMetadataParser = new InterfaceMetadataParser();
            this.InterfaceMetadataParser.Initialize(this.Configuration);
            this.StructMetadataParser = new StructMetadataParser();
            this.StructMetadataParser.Initialize(this.Configuration);
            this.EnumMetadataParser = new EnumMetadataParser();
            this.EnumMetadataParser.Initialize(this.Configuration);
        }

        public void ProcessMetadata()
        {
            try
            {
                Stopwatch watch = new Stopwatch();
                FrontEndDatabase.watch.Reset();
                watch.Start();

                MetadataParserHelpers.ParameterizedTypeInstanceParsed += this.Configuration.DataStore.OnParameterizedTypeInstanceParsed;

                foreach (var winmd in this.Winmds)
                {
                    FrontEndConfiguration.Output.WriteLine(StringMessageFormats.ParsingWinmd, winmd);

                    ProcessWinmd(winmd);
                }

                watch.Stop();
                FrontEndConfiguration.Output.WriteLine(StringMessageFormats.TimeProcessingMetadata, watch.ElapsedMilliseconds);
            }
            finally
            {
                MetadataParserHelpers.ParameterizedTypeInstanceParsed -= this.Configuration.DataStore.OnParameterizedTypeInstanceParsed;
            }
        }

        private void ProcessWinmd(string winmd)
        {
            using (var stream = File.OpenRead(winmd))
            using (var pereader = new PEReader(stream))
            {
                // MetadataReaderOptions.None: Give me the raw info. Do not apply C# semantics (eg, give me IVector instead of IList)
                var assembly = pereader.GetMetadataReader(MetadataReaderOptions.None);
                // When resolving interface methods, which includes properties and events, the map below will help to 
                // resolve the method names against pretty names.
                // For example, put_MyPropertyValue or set_MyPropertyValue versus MyPropertyValue setter
                var specialMethodNamesRepository = GetSpecialMethodNamesRepository(assembly);
                TypeDefinition? typeDef = null;

                try
                {
                    foreach (var typeDefHandle in assembly.TypeDefinitions)
                    {
                        typeDef = assembly.GetTypeDefinition(typeDefHandle);

                        if (FrontEndMetadataParser.ShouldIgnoreType(typeDef.Value))
                        {
                            continue;
                        }

                        var typeDefinitionKind = MetadataParserHelpers.GetTypeDefinitionKind(assembly, typeDef.Value);

                        switch (typeDefinitionKind)
                        {
                            case TypeDefinitionKind.RuntimeClass:
                                ProcessRuntimeClass(assembly, typeDef.Value);
                                break;
                            case TypeDefinitionKind.Interface:
                                ProcessInterface(assembly, typeDef.Value, specialMethodNamesRepository);
                                break;
                            case TypeDefinitionKind.Struct:
                                ProcessStruct(assembly, typeDef.Value);
                                break;
                            case TypeDefinitionKind.Enum:
                                ProcessEnum(assembly, typeDef.Value);
                                break;
                            case TypeDefinitionKind.Attribute:
                                // DO NOTHING AT THIS LEVEL. Attributes are only used later on when they are applied to types.
                                break;
                            case TypeDefinitionKind.Delegate:
                                ProcessDelegate(assembly, typeDef.Value, specialMethodNamesRepository);
                                break;
                            default:
                                throw new NotImplementedException();
                        }
                    }
                }
                catch (Exception exp)
                {
                    if (typeDef.HasValue && assembly != null)
                    {
                        // In the case of an error while parsing, provide the full type name and winmd
                        var namespaceName = assembly.GetString(typeDef.Value.Namespace);
                        var typeName = assembly.GetString(typeDef.Value.Name);
                        var fullTypeName = TypeNameUtilities.GetFormattedFullTypeName(namespaceName, typeName);

                        throw new InvalidOperationException(String.Format(StringExceptionFormats.CouldNotParseTypeInMetadataWinmd, fullTypeName, winmd), exp);
                    }
                    else
                    {
                        throw;
                    }
                }
            }
        }

        /// <summary>
        /// For method name resolution, specifically with properties and events, build a map with the info needed to resolve them
        /// </summary>
        /// <param name="assembly"></param>
        /// <returns></returns>
        private IDictionary<MethodDefinitionHandle, string> GetSpecialMethodNamesRepository(MetadataReader assembly)
        {
            var specialMethodNamesRepository = new Dictionary<MethodDefinitionHandle, string>();

            specialMethodNamesRepository.Clear();
            foreach (var propertyHandle in assembly.PropertyDefinitions)
            {
                var propertyDef = assembly.GetPropertyDefinition(propertyHandle);
                var propertyAccessors = propertyDef.GetAccessors();
                var name = assembly.GetString(propertyDef.Name);
                if (!propertyAccessors.Getter.IsNil)
                {
                    specialMethodNamesRepository.Add(propertyAccessors.Getter, name);
                }
                if (!propertyAccessors.Setter.IsNil)
                {
                    specialMethodNamesRepository.Add(propertyAccessors.Setter, name);
                }
            }

            foreach (var eventHandle in assembly.EventDefinitions)
            {
                var eventDef = assembly.GetEventDefinition(eventHandle);
                var eventAccessors = eventDef.GetAccessors();
                var name = assembly.GetString(eventDef.Name);
                if (!eventAccessors.Adder.IsNil)
                {
                    specialMethodNamesRepository.Add(eventAccessors.Adder, name);
                }
                if (!eventAccessors.Remover.IsNil)
                {
                    specialMethodNamesRepository.Add(eventAccessors.Remover, name);
                }
            }

            return specialMethodNamesRepository;
        }

        private void ProcessRuntimeClass(MetadataReader assembly, TypeDefinition typeDef)
        {
            var info = this.RuntimeclassMetadataParser.Parse(assembly, typeDef);
            this.Configuration.DataStore.InsertRuntimeClassInfo(info);
        }

        private void ProcessInterface(MetadataReader assembly, TypeDefinition typeDef, IDictionary<MethodDefinitionHandle, string> propertiesRepository)
        {
            var info = this.InterfaceMetadataParser.Parse(assembly, typeDef, null, false, propertiesRepository);
            this.Configuration.DataStore.InsertInterfaceInfo(info);
        }

        private void ProcessStruct(MetadataReader assembly, TypeDefinition typeDef)
        {
            var info = this.StructMetadataParser.Parse(assembly, typeDef);
            this.Configuration.DataStore.InsertStructInfo(info);
        }

        private void ProcessEnum(MetadataReader assembly, TypeDefinition typeDef)
        {
            var info = this.EnumMetadataParser.Parse(assembly, typeDef);
            this.Configuration.DataStore.InsertEnumInfo(info);
        }

        private void ProcessDelegate(MetadataReader assembly, TypeDefinition typeDef, IDictionary<MethodDefinitionHandle, string> fieldsRepository)
        {
            // Delegates are treated just like interfaces.
            var info = this.InterfaceMetadataParser.Parse(assembly, typeDef, null, true, fieldsRepository);
            this.Configuration.DataStore.InsertInterfaceInfo(info);
        }

        private static bool ShouldIgnoreType(TypeDefinition typeDef)
        {
            // The Windows Runtime doesn't use nested types.
            if (!typeDef.GetDeclaringType().IsNil)
            {
                return true;
            }
            // If there is any type that is not a Windows Runtime type.
            else if ((typeDef.Attributes & System.Reflection.TypeAttributes.WindowsRuntime) != System.Reflection.TypeAttributes.WindowsRuntime)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        private IList<string> Winmds { get; set; }
        private FrontEndConfiguration Configuration { get; set; }
        private RuntimeclassMetadataParser RuntimeclassMetadataParser { get; set; }
        private InterfaceMetadataParser InterfaceMetadataParser { get; set; }
        private StructMetadataParser StructMetadataParser { get; set; }
        private EnumMetadataParser EnumMetadataParser { get; set; }
    }
}