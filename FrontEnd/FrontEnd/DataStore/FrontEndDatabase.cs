using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SQLite;
using System.Diagnostics;
using System.Data;
using Microsoft.Wcl.Projection;
using Microsoft.Wcl.Parsers;
using System.IO;

namespace Microsoft.Wcl.DataStore
{
    internal class FrontEndDatabase : IDataStore
    {
        public FrontEndDatabase(FrontEndConfiguration configuration)
        {
            this.Configuration = configuration;
        }

        protected SQLiteConnection Database { get; set; }

        private SQLiteCommand InitializeDatabaseCommand { get; set; }

        private SQLiteCommand InterfacesCommand { get; set; }

        private SQLiteCommand InterfacedMethodCommand { get; set; }

        private SQLiteCommand InterfaceMethodParameterCommand { get; set; }

        private SQLiteCommand InterfaceRequiredInterfaceCommand { get; set; }

        private SQLiteCommand RuntimeclassCommand { get; set; }

        private SQLiteCommand RuntimeclassInterfaceCommand { get; set; }

        private SQLiteCommand RuntimeclassStaticInterfaceCommand { get; set; }

        private SQLiteCommand RuntimeclassConstructorInterfaceCommand { get; set; }

        private SQLiteCommand EnumCommand { get; set; }

        private SQLiteCommand EnumFieldCommand { get; set; }

        private SQLiteCommand StructCommand { get; set; }

        private SQLiteCommand StructFieldCommand { get; set; }

        private SQLiteCommand GenericInterfacesCommand { get; set; }

        private SQLiteCommand NamespaceToTypeCategoryDependencyCommand { get; set; }

        private SQLiteCommand NamespaceToGenericInterfaceDepedencyCommand { get; set; }

        private SQLiteTransaction Transaction { get; set; }

        /// <summary>
        /// Contains all *Info types except GenericInterfaceInfo (use GenericInterfacesRepository instead)
        /// </summary>
        /// <remarks>
        /// All keys use the dot form to help with lookup during generation of generic interfaces iids.
        /// </remarks>
        private IDictionary<string, object> Repository { get; set; }

        /// <summary>
        /// Contains all the GenericInterfacesInfo objects found/added during the parsin phase
        /// </summary>
        /// <remarks>
        /// All keys are in cpp form
        /// </remarks>
        public KeyedGenericInterfaceCollection GenericInterfacesRepository { get; set; }

        protected FrontEndConfiguration Configuration { get; set; }

        public void Initialize()
        {
            this.Database = new SQLiteConnection(FrontEndDatabaseResources.InMemoryDatabaseConnectionString);
            this.Database.Open();

            var command = this.Database.CreateCommand();
            command.CommandText = FrontEndDatabaseResources.dbText;
            var insertedCount = command.ExecuteNonQuery();
            this.ThrowIfCommandQueryFailed(insertedCount, 0, command.CommandText);

            this.InterfacesCommand = this.Database.CreateCommand();
            this.InterfacedMethodCommand = this.Database.CreateCommand();
            this.InterfaceMethodParameterCommand = this.Database.CreateCommand();
            this.InterfaceRequiredInterfaceCommand = this.Database.CreateCommand();
            this.RuntimeclassCommand = this.Database.CreateCommand();
            this.RuntimeclassInterfaceCommand = this.Database.CreateCommand();
            this.RuntimeclassStaticInterfaceCommand = this.Database.CreateCommand();
            this.RuntimeclassConstructorInterfaceCommand = this.Database.CreateCommand();
            this.EnumCommand = this.Database.CreateCommand();
            this.EnumFieldCommand = this.Database.CreateCommand();
            this.StructCommand = this.Database.CreateCommand();
            this.StructFieldCommand = this.Database.CreateCommand();
            this.GenericInterfacesCommand = this.Database.CreateCommand();
            this.NamespaceToTypeCategoryDependencyCommand = this.Database.CreateCommand();
            this.NamespaceToGenericInterfaceDepedencyCommand = this.Database.CreateCommand();

            var list = new[]
            {
                new { Command = InterfacesCommand,  TableName = "Interfaces",   ColumnNames =  new string []{ "FullName", "Namespace", "Name", "Delegate", "Uuid", "Deprecated" } },
                new { Command = InterfacedMethodCommand,  TableName = "Methods",   ColumnNames =  new string []{ "Name", "AbiName", "InterfaceId", "Deprecated" } },
                new { Command = InterfaceMethodParameterCommand,  TableName = "Parameters",   ColumnNames =  new string []{ "Name", "Type", "TypeName", "TypeNamespace", "Flags", "MethodId" } },
                new { Command = InterfaceRequiredInterfaceCommand,  TableName = "RequiredInterfaces",   ColumnNames =  new string []{ "InterfaceId", "Requires" } },
                new { Command = RuntimeclassCommand,  TableName = "Classes",   ColumnNames =  new string []{ "FullName", "Namespace", "Name", "Base", "DefaultInterface", "Activatable", "Deprecated" } },
                new { Command = RuntimeclassInterfaceCommand,  TableName = "ClassInterfaces",   ColumnNames =  new string []{ "ClassId", "Interface", "IsDefault", "Overridable", "Protected" } },
                new { Command = RuntimeclassStaticInterfaceCommand,  TableName = "ClassStatics",   ColumnNames =  new string []{ "ClassId", "Interface" } },
                new { Command = RuntimeclassConstructorInterfaceCommand,  TableName = "ClassConstructors",   ColumnNames =  new string []{ "ClassId", "Interface", "Composable", "Protected" } },
                new { Command = EnumCommand,  TableName = "Enumerations",   ColumnNames =  new string []{ "FullName", "Namespace", "Name", "Flags", "Deprecated" } },
                new { Command = EnumFieldCommand,  TableName = "Enumerators",   ColumnNames =  new string []{ "Name", "Value", "EnumerationId", "Deprecated" } },
                new { Command = StructCommand,  TableName = "Structures",   ColumnNames =  new string []{ "FullName", "Namespace", "Name", "Depends", "Deprecated" } },
                new { Command = StructFieldCommand,  TableName = "Fields",   ColumnNames =  new string []{ "Name", "Type", "TypeNamespace", "TypeName", "StructureId" } },
                new { Command = GenericInterfacesCommand,  TableName = "GenericInterfaces",   ColumnNames =  new string []{ "FullName", "Namespace", "Name", "Uuid", "MetadataFullNameInDotForm", "MetadataFullNameInCppForm", "Depth" } },
                new { Command = NamespaceToTypeCategoryDependencyCommand,  TableName = "NamespaceToTypeCategoryDependency",   ColumnNames =  new string []{ "Namespace", "DependentNamespace", "TypeCategory" } },
                new { Command = NamespaceToGenericInterfaceDepedencyCommand,  TableName = "NamespaceToGenericInterfaceDependency",   ColumnNames =  new string []{ "Namespace", "GenericInterfaceId" } },
            };

            foreach (var item in list)
            {
                UpdateCommandDefinition(item.Command, item.TableName, item.ColumnNames);
            }

            // Because of SQL dynamic type and the possible field values/types, using Int64 to cover all cases.
            // For example, -1 versus 0xFFFFFFFF.
            // If SQLite decides that column type is int32, then 0xFFFFFFFF does not fit.
            // If SQLite decides that column type is uin32, then -1 does not fit.
            this.EnumFieldCommand.Parameters[1].DbType = DbType.Int64;

            this.Repository = new Dictionary<string, object>();
            this.GenericInterfacesRepository = new KeyedGenericInterfaceCollection();

            this.Transaction = this.Database.BeginTransaction();
        }

        public static Stopwatch watch = new Stopwatch();

        public void InsertRuntimeClassInfo(RuntimeClassInfo info)
        {
            watch.Start();

            object[] values = { info.FullTypeName, info.Namespace, info.Name, info.Base, info.DefaultInterface, info.Activatable, info.Deprecated };

            FrontEndDatabase.UpdateCommandValues(this.RuntimeclassCommand, values);
            var rowId = (long)this.RuntimeclassCommand.ExecuteScalar();

            this.InsertRuntimeclassInterfacesInfo(info.InterfacesInfo, rowId);
            this.InsertRuntimeclassStaticInterfacesInfo(info.StaticInterfacesInfo, rowId);
            this.InsertRuntimeclassConstructorInterfacesInfo(info.ContructorInterfacesInfo, rowId);

            this.Repository.Add(TypeNameUtilities.GetFullTypeNameInDotForm(info.FullTypeName), info);

            watch.Stop();
        }

        private void InsertRuntimeclassInterfacesInfo(IList<RuntimeClassInterfaceInfo> runtimeclassInterfacesInfo, long runtimeclassRowId)
        {
            foreach (var info in runtimeclassInterfacesInfo)
            {
                object[] values = { runtimeclassRowId, info.Interface, info.IsDefault, info.Overridable, info.Protected };
                FrontEndDatabase.UpdateCommandValues(this.RuntimeclassInterfaceCommand, values);
                var insertedCount = this.RuntimeclassInterfaceCommand.ExecuteNonQuery();
                this.ThrowIfCommandQueryFailed(insertedCount, 1, this.RuntimeclassInterfaceCommand.CommandText);
            }
        }

        private void InsertRuntimeclassConstructorInterfacesInfo(IList<RuntimeClassConstructorInterfaceInfo> runtimeClassConstructorInterfaceInfo, long runtimeclassRowId)
        {
            foreach (var info in runtimeClassConstructorInterfaceInfo)
            {
                object[] values = { runtimeclassRowId, info.Interface, info.Composable, info.Protected };
                FrontEndDatabase.UpdateCommandValues(this.RuntimeclassConstructorInterfaceCommand, values);
                var insertedCount = this.RuntimeclassConstructorInterfaceCommand.ExecuteNonQuery();
                this.ThrowIfCommandQueryFailed(insertedCount, 1, this.RuntimeclassConstructorInterfaceCommand.CommandText);
            }
        }

        private void InsertRuntimeclassStaticInterfacesInfo(IList<RuntimeClassStaticInterfaceInfo> runtimeclassStaticInterfacesInfo, long runtimeclassRowId)
        {
            foreach (var info in runtimeclassStaticInterfacesInfo)
            {
                object[] values = { runtimeclassRowId, info.Interface };
                FrontEndDatabase.UpdateCommandValues(this.RuntimeclassStaticInterfaceCommand, values);
                var insertedCount = this.RuntimeclassStaticInterfaceCommand.ExecuteNonQuery();
                this.ThrowIfCommandQueryFailed(insertedCount, 1, this.RuntimeclassStaticInterfaceCommand.CommandText);
            }
        }

        public void InsertInterfaceInfo(InterfaceInfo info)
        {
            watch.Start();

            object[] values = { info.FullName, info.Namespace, info.Name, info.Delegate, info.Uuid, info.Deprecated };

            FrontEndDatabase.UpdateCommandValues(this.InterfacesCommand, values);
            var rowId = (long)this.InterfacesCommand.ExecuteScalar();

            this.InsertInterfacesMethodsInfo(info.MethodsInfo, rowId);
            this.InsertInterfaceRequiredInterfaces(info.RequiredInterfacesInfo, rowId);

            this.Repository.Add(TypeNameUtilities.GetFullTypeNameInDotForm(info.FullName), info);


            watch.Stop();
        }

        private void InsertInterfacesMethodsInfo(IList<InterfaceMethodInfo> methodsInfo, long interfaceRowId)
        {
            foreach (var info in methodsInfo)
            {
                object[] values = { info.Name, info.AbiName, interfaceRowId, info.Deprecated };
                FrontEndDatabase.UpdateCommandValues(this.InterfacedMethodCommand, values);
                var rowId = (long)this.InterfacedMethodCommand.ExecuteScalar();

                InsertInterfaceMethodParametersInfo(info.ParametersInfo, rowId);
            }
        }

        private void InsertInterfaceMethodParametersInfo(IList<InterfaceMethodParameterInfo> methodParametersInfo, long methodRowId)
        {
            foreach (var info in methodParametersInfo)
            {
                object[] values = { info.Name, info.Type, info.TypeNamespace, info.TypeName, info.Flags, methodRowId };
                FrontEndDatabase.UpdateCommandValues(this.InterfaceMethodParameterCommand, values);
                var insertedCount = this.InterfaceMethodParameterCommand.ExecuteNonQuery();
                this.ThrowIfCommandQueryFailed(insertedCount, 1, this.InterfaceMethodParameterCommand.CommandText);
            }
        }

        private void InsertInterfaceRequiredInterfaces(IList<InterfaceRequiredInterfaceInfo> requiredInterfacesInfo, long interfaceRowId)
        {
            foreach (var info in requiredInterfacesInfo)
            {
                object[] values = { interfaceRowId, info.Requires };
                FrontEndDatabase.UpdateCommandValues(this.InterfaceRequiredInterfaceCommand, values);
                var insertedCount = this.InterfaceRequiredInterfaceCommand.ExecuteNonQuery();
                this.ThrowIfCommandQueryFailed(insertedCount, 1, this.InterfaceRequiredInterfaceCommand.CommandText);
            }
        }

        public void InsertEnumInfo(EnumInfo info)
        {
            watch.Start();

            object[] values = { info.FullName, info.Namespace, info.Name, info.Flags, info.Deprecated };
            FrontEndDatabase.UpdateCommandValues(this.EnumCommand, values);
            var rowId = (long)this.EnumCommand.ExecuteScalar();

            InsertEnumFieldsInfo(info.FieldNames, rowId);

            this.Repository.Add(TypeNameUtilities.GetFullTypeNameInDotForm(info.FullName), info);

            watch.Stop();
        }

        private void InsertEnumFieldsInfo(IList<EnumFieldInfo> enumFieldsInfo, long enumRowId)
        {
            foreach (var info in enumFieldsInfo)
            {
                object[] values = { info.Name, info.Value, enumRowId, info.Deprecated };
                // This is the only case (so far) where the underline type could be different.
                Debug.Assert(info.Value is int || info.Value is uint);

                FrontEndDatabase.UpdateCommandValues(this.EnumFieldCommand, values);
                var insertedCount = this.EnumFieldCommand.ExecuteNonQuery();
                this.ThrowIfCommandQueryFailed(insertedCount, 1, this.EnumFieldCommand.CommandText);
            }
        }

        public void InsertStructInfo(StructInfo info)
        {
            watch.Start();

            object[] values = { info.FullName, info.Namespace, info.Name, info.Depends, info.Deprecated };
            FrontEndDatabase.UpdateCommandValues(this.StructCommand, values);
            var rowId = (long)this.StructCommand.ExecuteScalar();

            InsertStructFieldsInfo(info.FieldsInfo, rowId);

            this.Repository.Add(TypeNameUtilities.GetFullTypeNameInDotForm(info.FullName), info);

            watch.Stop();
        }

        private void InsertStructFieldsInfo(IList<StructFieldInfo> structFieldsInfo, long structRowId)
        {
            foreach (var info in structFieldsInfo)
            {
                object[] values = { info.Name, info.Type, info.TypeNamespace, info.TypeName, structRowId };
                FrontEndDatabase.UpdateCommandValues(this.StructFieldCommand, values);
                var insertedCount = this.StructFieldCommand.ExecuteNonQuery();
                this.ThrowIfCommandQueryFailed(insertedCount, 1, this.StructFieldCommand.CommandText);
            }
        }

        public void InsertGenericInterfaceInfo(GenericInterfaceInfo info)
        {
            Debug.Assert(info.MetadataFullTypeNameInCppForm != null);
            Debug.Assert(info.Depth != 0);

            watch.Start();

            object[] values = { info.FullName, info.Namespace, info.Name, info.Uuid, info.MetadataFullTypeNameInDotForm, info.MetadataFullTypeNameInCppForm, info.Depth };
            FrontEndDatabase.UpdateCommandValues(this.GenericInterfacesCommand, values);
            var insertedCount = this.GenericInterfacesCommand.ExecuteNonQuery();
            this.ThrowIfCommandQueryFailed(insertedCount, 1, this.GenericInterfacesCommand.CommandText);

            watch.Stop();
        }

        public void InsertNamespaceToTypeCategoryDependency(string topLevelNamespaceName, string dependentNamespace, IList<TypeCategory> dependentTypeCategories)
        {
            watch.Start();

            foreach (var typeCategory in dependentTypeCategories)
            {
                object[] values = { topLevelNamespaceName, dependentNamespace, typeCategory };
                FrontEndDatabase.UpdateCommandValues(this.NamespaceToTypeCategoryDependencyCommand, values);
                var insertedCount = this.NamespaceToTypeCategoryDependencyCommand.ExecuteNonQuery();
                this.ThrowIfCommandQueryFailed(insertedCount, 1, this.NamespaceToTypeCategoryDependencyCommand.CommandText);
            }

            watch.Stop();
        }

        public void InsertNamespaceToGenericInterfaceDependency(string namespaceName, IList<string> dependentGenericInterfaces)
        {
            watch.Start();

            foreach (var item in dependentGenericInterfaces)
            {
                object[] values = { namespaceName, item };
                FrontEndDatabase.UpdateCommandValues(this.NamespaceToGenericInterfaceDepedencyCommand, values);
                var insertedCount = this.NamespaceToGenericInterfaceDepedencyCommand.ExecuteNonQuery();
                this.ThrowIfCommandQueryFailed(insertedCount, 1, this.NamespaceToGenericInterfaceDepedencyCommand.CommandText);
            }

            watch.Stop();
        }

        public void Save()
        {
            this.Transaction.Commit();

            var dataStoreDirectory = Path.GetDirectoryName(this.Configuration.DataStoreLocation);
            if (!string.IsNullOrEmpty(dataStoreDirectory) && !System.IO.Directory.Exists(dataStoreDirectory))
            {
                Directory.CreateDirectory(dataStoreDirectory);
            }

            var connectionString = String.Format(FrontEndDatabaseResources.FileDatabaseConnectionString, this.Configuration.DataStoreLocation);
            var destination = new SQLiteConnection(connectionString);
            destination.Open();
            this.Database.BackupDatabase(destination, this.Database.Database, this.Database.Database, -1, null, 0);
            destination.Close();
        }

        public IDictionary<string, object> GetRepository()
        {
            return this.Repository;
        }

        public KeyedGenericInterfaceCollection GetGenericInterfacesRepository()
        {
            return this.GenericInterfacesRepository;
        }

        public void OnParameterizedTypeInstanceParsed(object sender, ParameterizedTypeInstanceParsedEventArgs args)
        {
            this.InsertParameterizedTypeInstance(args.OpenInterfaceFullTypeName, args.FullTypeName);
        }

        public void InsertParameterizedTypeInstance(string openInterfaceFullTypeName, string fullTypeName)
        {
            // Check for the open types and then check if we already know about it.
            // During parsing, open types use !!# to describe the arguments of a Generic Interface.
            // For example Windows::Foundaton::Collections::IVector<!!0>
            if (!fullTypeName.Contains("!!") && !this.GenericInterfacesRepository.Contains(fullTypeName))
            {
                var info = new GenericInterfaceInfo();
                info.FullName = fullTypeName;
                info.Namespace = null;
                info.Name = null;
                info.MetadataFullTypeNameInDotForm = TypeNameUtilities.GetFullTypeNameInDotForm(fullTypeName);
                info.MetadataFullTypeNameInCppForm = fullTypeName;
                info.Depth = GenericInterfaceParser.GetGenericInterfaceDepthness(fullTypeName);
                
                var nameIndex = TypeNameUtilities.GetIndexOfTypeName(openInterfaceFullTypeName);
                if (nameIndex > 0)
                {
                    info.Namespace = openInterfaceFullTypeName.Substring(0, nameIndex);
                    info.Name = openInterfaceFullTypeName.Substring(nameIndex + 2);
                }

                // Insert to database is derefed until uuid are calculated. This avoids insert + update.
                this.GenericInterfacesRepository.Add(info);
            }
        }

        private static void UpdateCommandDefinition(SQLiteCommand command, string tableName, string[] fields)
        {
            var queryFields = new StringBuilder();
            var queryValues = new StringBuilder();

            command.Parameters.Clear();

            foreach (string field in fields)
            {
                queryFields.AppendFormat("{0},", field);
                queryValues.AppendFormat("@{0},", field);

                var param = command.CreateParameter();
                param.ParameterName = String.Format("@{0}", field);
                command.Parameters.Add(param);
            }

            // Get rid of the last ','
            queryFields.Length--;
            queryValues.Length--;

            command.CommandText = String.Format(FrontEndDatabaseResources.InsertValuesAndReturnRowIdQueryText, tableName, queryFields, queryValues);
            command.CommandType = System.Data.CommandType.Text;
            command.Prepare();
        }

        private static void UpdateCommandValues(SQLiteCommand command, object[] values)
        {
            Debug.Assert(command.Parameters.Count == values.Length);

            for (int i = 0; i < values.Length; i++)
            {
                command.Parameters[i].Value = values[i];
            }
        }

        public void UpdateSchema()
        {
            var command = this.Database.CreateCommand();
            command.CommandText = FrontEndDatabaseResources.CreateIndexesQueryText;
            var insertedCount = command.ExecuteNonQuery();
            // Don't hardcode an expected count. If things changed and it is > 0, it can be considered as success.
            this.ThrowIfCommandQueryFailed(insertedCount > 0, command.CommandText);
        }

        public void ReconcileData()
        {
            Stopwatch watch = new Stopwatch();
            watch.Start();

            this.BulkUpdateDatabase();
            this.UpdateStructureFieldTypes();
            this.UpdateParameterTypes();
            this.UpdateRuntimeClassDefaultInterfaces();
            this.UpdateClassInterfaces();
            this.UpdateRequiredInterfaces();
            this.UpdateGenericInterfaces();

            watch.Stop();
            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.TimeToRecondileData, watch.ElapsedMilliseconds);
        }

        public void VerifySemantics()
        {
            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.SemanticChecks);

            Stopwatch watch = new Stopwatch();
            watch.Start();

            uint result = 0;
            var command = this.Database.CreateCommand();

            // Every Class default interface that is not a Generic Interface exists in the interfaces table
            command.CommandText = @"SELECT COUNT(DefaultInterface) FROM Classes WHERE DefaultInterface <> '' AND instr(DefaultInterface, '<') = 0 AND NOT EXISTS (SELECT FullName FROM Interfaces);";
            result = Convert.ToUInt32(command.ExecuteScalar());
            if (result != 0)
            {
                throw new InvalidOperationException(StringExceptionFormats.RuntimeclassNonGenericDefaultInterfaceExists);
            }

            // When test cases skip generic interface resolution, this check is not valid.
            if (!this.Configuration.SkipGenericInterfaceResolution)
            {
                // Every Class default interface that is a Generic Interface exists in the interfaces table
                command.CommandText = @"SELECT COUNT(DefaultInterface) FROM Classes WHERE instr(DefaultInterface, '<') = 0 AND NOT EXISTS (SELECT FullName FROM GenericInterfaces);";
                result = Convert.ToUInt32(command.ExecuteScalar());
                if (result != 0)
                {
                    throw new InvalidOperationException(StringExceptionFormats.RuntimeclassWithoutStaticOrDefaultInterface);
                }
            }

            // Other tests can't be easily done without lots of runtime work. 
            // For example, to check that every type in the Parameters table exists either in the known list (foundamental types) or in the tables.
            // Right now, there are special cases for Generic Interfaces and how they are projected, including that enums and enumerations are projected in a special way.
            // Doing that work means that at runtime, every generic interface would have to be broken into pieces and each element verified.
            // Not recommended at this point.
            watch.Stop();
            FrontEndConfiguration.Output.WriteLine(StringMessageFormats.TimeToRunSemanticChecks, watch.ElapsedMilliseconds);

        }

        private void UpdateClassInterfaces()
        {
            var selectCommand = this.Database.CreateCommand();
            selectCommand.CommandText = FrontEndDatabaseResources.UpdateClassInterfacesSelectQueryText;
            var reader = selectCommand.ExecuteReader();

            if (reader.HasRows)
            {
                var updateCommand = this.Database.CreateCommand();
                updateCommand.CommandText = FrontEndDatabaseResources.UpdateClassInterfacesUpdateQueryText;
                var interfaceParameter = updateCommand.CreateParameter();
                interfaceParameter.ParameterName = "Interface";
                updateCommand.Parameters.Add(interfaceParameter);
                var rowIdParameter = updateCommand.CreateParameter();
                rowIdParameter.ParameterName = "RowId";
                updateCommand.Parameters.Add(rowIdParameter);

                while (reader.Read())
                {
                    var rowId = reader.GetInt32(0);
                    var interfaceTypeName = reader.GetString(1);
                    var projectedType = MetadataTypeToProjectedTypeConverter.GetProjectedTypeFromMetadataType(interfaceTypeName, false, this.GetRepository());

                    interfaceParameter.Value = projectedType;
                    rowIdParameter.Value = rowId;
                    var updatedCount = updateCommand.ExecuteNonQuery();
                    this.ThrowIfCommandQueryFailed(updatedCount, 1, updateCommand.CommandText);
                }
            }
        }

        private void UpdateRuntimeClassDefaultInterfaces()
        {
            var selectCommand = this.Database.CreateCommand();
            selectCommand.CommandText = FrontEndDatabaseResources.UpdateRuntimeClassDefaultInterfacesSelectQueryText;
            var reader = selectCommand.ExecuteReader();

            if (reader.HasRows)
            {
                var updateCommand = this.Database.CreateCommand();
                updateCommand.CommandText = FrontEndDatabaseResources.UpdateRuntimeClassDefaultInterfacesUpdateQueryText;
                var defaultInterfaceParameter = updateCommand.CreateParameter();
                defaultInterfaceParameter.ParameterName = "DefaultInterface";
                updateCommand.Parameters.Add(defaultInterfaceParameter);
                var rowIdParameter = updateCommand.CreateParameter();
                rowIdParameter.ParameterName = "RowId";
                updateCommand.Parameters.Add(rowIdParameter);

                while (reader.Read())
                {
                    var rowId = reader.GetInt32(0);
                    var defaultInterface = reader.GetString(1);
                    var projectedType = MetadataTypeToProjectedTypeConverter.GetProjectedTypeFromMetadataType(defaultInterface, false, this.GetRepository());

                    defaultInterfaceParameter.Value = projectedType;
                    rowIdParameter.Value = rowId;
                    var updatedCount = updateCommand.ExecuteNonQuery();
                    this.ThrowIfCommandQueryFailed(updatedCount, 1, updateCommand.CommandText);
                }
            }
        }

        private void UpdateStructureFieldTypes()
        {
            var selectCommand = this.Database.CreateCommand();
            selectCommand.CommandText = FrontEndDatabaseResources.UpdateStructureFieldTypesSelectQueryText;
            var reader = selectCommand.ExecuteReader();

            if (reader.HasRows)
            {
                var updateCommand = this.Database.CreateCommand();
                updateCommand.CommandText = FrontEndDatabaseResources.UpdateStructureFieldTypesUpdateQueryText;
                var typeParameter = updateCommand.CreateParameter();
                typeParameter.ParameterName = "Type";
                updateCommand.Parameters.Add(typeParameter);
                var typeNamespaceParameter = updateCommand.CreateParameter();
                typeNamespaceParameter.ParameterName = "TypeNamespace";
                updateCommand.Parameters.Add(typeNamespaceParameter);
                var typeNameParameter = updateCommand.CreateParameter();
                typeNameParameter.ParameterName = "TypeName";
                updateCommand.Parameters.Add(typeNameParameter);
                var categoryParameter = updateCommand.CreateParameter();
                categoryParameter.ParameterName = "Category";
                updateCommand.Parameters.Add(categoryParameter);
                var rowIdParameter = updateCommand.CreateParameter();
                rowIdParameter.ParameterName = "RowId";
                updateCommand.Parameters.Add(rowIdParameter);

                while (reader.Read())
                {
                    var rowId = reader.GetInt32(0);
                    var type = reader.GetString(1);
                    string projectedType = null;
                    TypeCategory typeCategory;

                    MetadataTypeToProjectedTypeConverter.GetProjectedTypeAndCategoryFromMetadataType(type, false, this.GetRepository(), out projectedType, out typeCategory);

                    typeParameter.Value = projectedType;
                    rowIdParameter.Value = rowId;
                    categoryParameter.Value = typeCategory;

                    typeNamespaceParameter.Value = null;
                    typeNameParameter.Value = null;

                    var nameIndex = TypeNameUtilities.GetIndexOfTypeNameForAnyInterface(projectedType);
                    if (nameIndex > 0)
                    {
                        typeNamespaceParameter.Value = projectedType.Substring(0, nameIndex);
                        typeNameParameter.Value = projectedType.Substring(nameIndex + 2);
                    }

                    var updatedCount = updateCommand.ExecuteNonQuery();
                    this.ThrowIfCommandQueryFailed(updatedCount, 1, updateCommand.CommandText);
                }
            }
        }

        private void UpdateParameterTypes()
        {
            var selectCommand = this.Database.CreateCommand();
            selectCommand.CommandText = FrontEndDatabaseResources.UpdateParameterTypesSelectQueryText;
            var reader = selectCommand.ExecuteReader();

            if (reader.HasRows)
            {
                var updateCommand = this.Database.CreateCommand();
                updateCommand.CommandText = FrontEndDatabaseResources.UpdateParameterTypesUpdateQueryText;
                var typeParameter = updateCommand.CreateParameter();
                typeParameter.ParameterName = "Type";
                updateCommand.Parameters.Add(typeParameter);
                var typeNamespaceParameter = updateCommand.CreateParameter();
                typeNamespaceParameter.ParameterName = "TypeNamespace";
                updateCommand.Parameters.Add(typeNamespaceParameter);
                var typeNameParameter = updateCommand.CreateParameter();
                typeNameParameter.ParameterName = "TypeName";
                updateCommand.Parameters.Add(typeNameParameter);
                var rowIdParameter = updateCommand.CreateParameter();
                rowIdParameter.ParameterName = "RowId";
                updateCommand.Parameters.Add(rowIdParameter);
                var classTypeParameter = updateCommand.CreateParameter();
                classTypeParameter.ParameterName = "ClassType";
                updateCommand.Parameters.Add(classTypeParameter);
                var typeCategoryParameter = updateCommand.CreateParameter();
                typeCategoryParameter.ParameterName = "Category";
                updateCommand.Parameters.Add(typeCategoryParameter);

                while (reader.Read())
                {
                    var rowId = reader.GetInt32(0);
                    var type = reader.GetString(1);
                    var name = reader.GetString(2);
                    string projectedType = null;
                    TypeCategory typeCategory;
                    string projectedClassType = null;

                    MetadataTypeToProjectedTypeConverter.GetProjectedTypeAndCategoryFromMetadataType(type, false, this.GetRepository(), out projectedType, out typeCategory, out projectedClassType);

                    typeParameter.Value = projectedType;
                    typeNamespaceParameter.Value = null;
                    typeNameParameter.Value = null;
                    rowIdParameter.Value = rowId;
                    classTypeParameter.Value = projectedClassType;
                    typeCategoryParameter.Value = typeCategory;

                    var nameIndex = TypeNameUtilities.GetIndexOfTypeNameForAnyInterface(projectedType);
                    if (nameIndex > 0)
                    {
                        typeNamespaceParameter.Value = projectedType.Substring(0, nameIndex);
                        typeNameParameter.Value = projectedType.Substring(nameIndex + 2);
                    }

                    var updatedCount = updateCommand.ExecuteNonQuery();
                    this.ThrowIfCommandQueryFailed(updatedCount, 1, updateCommand.CommandText);
                }
            }
        }

        private void UpdateRequiredInterfaces()
        {
            var selectCommand = this.Database.CreateCommand();
            selectCommand.CommandText = FrontEndDatabaseResources.UpdateRequiredInterfacesSelectQueryText;
            var reader = selectCommand.ExecuteReader();

            if (reader.HasRows)
            {
                var updateCommand = this.Database.CreateCommand();
                updateCommand.CommandText = FrontEndDatabaseResources.UpdateRequiredInterfacesUpdateQueryText;
                var requiresParameter = updateCommand.CreateParameter();
                requiresParameter.ParameterName = "Requires";
                updateCommand.Parameters.Add(requiresParameter);
                var rowIdParameter = updateCommand.CreateParameter();
                rowIdParameter.ParameterName = "RowId";
                updateCommand.Parameters.Add(rowIdParameter);

                while (reader.Read())
                {
                    var rowId = reader.GetInt32(0);
                    var requires = reader.GetString(1);
                    var projectedType = MetadataTypeToProjectedTypeConverter.GetProjectedTypeFromMetadataType(requires, false, this.GetRepository());

                    rowIdParameter.Value = rowId;
                    requiresParameter.Value = projectedType;
                    var updatedCount = updateCommand.ExecuteNonQuery();
                    this.ThrowIfCommandQueryFailed(updatedCount, 1, updateCommand.CommandText);
                }
            }
        }

        private void UpdateGenericInterfaces()
        {
            var selectCommand = this.Database.CreateCommand();
            selectCommand.CommandText = FrontEndDatabaseResources.UpdateGenericInterfacesSelectQueryText;
            var reader = selectCommand.ExecuteReader();

            if (reader.HasRows)
            {
                var updateCommand = this.Database.CreateCommand();
                updateCommand.CommandText = FrontEndDatabaseResources.UpdateGenericInterfacesUpdateQueryText;
                var rowIdParameter = updateCommand.CreateParameter();
                rowIdParameter.ParameterName = "RowId";
                updateCommand.Parameters.Add(rowIdParameter);
                var projectedTypeParameter = updateCommand.CreateParameter();
                projectedTypeParameter.ParameterName = "ProjectedType";
                updateCommand.Parameters.Add(projectedTypeParameter);
                var namespaceParameter = updateCommand.CreateParameter();
                namespaceParameter.ParameterName = "Namespace";
                updateCommand.Parameters.Add(namespaceParameter);
                var nameParameter = updateCommand.CreateParameter();
                nameParameter.ParameterName = "Name";
                updateCommand.Parameters.Add(nameParameter);

                while (reader.Read())
                {
                    var rowId = reader.GetInt32(0);
                    var typeName = reader.GetString(1);

                    var projectedType = MetadataTypeToProjectedTypeConverter.GetProjectedTypeFromMetadataType(typeName, false, this.GetRepository());
                    projectedType = TypeNameUtilities.GetFullTypeNameInCPPForm(projectedType);
                    rowIdParameter.Value = rowId;
                    projectedTypeParameter.Value = projectedType;

                    var nameIndex = TypeNameUtilities.GetIndexOfTypeNameForGenericInterface(projectedType);
                    namespaceParameter.Value = projectedType.Substring(0, nameIndex);
                    nameParameter.Value = projectedType.Substring(nameIndex + 2);

                    var updatedCount = updateCommand.ExecuteNonQuery();
                    this.ThrowIfCommandQueryFailed(updatedCount, 1, updateCommand.CommandText);
                }
            }
        }

        private void BulkUpdateDatabase()
        {
            var command = this.Database.CreateCommand();
            command.CommandText = FrontEndDatabaseResources.BulkUpdateDatabaseQueryText;
            var updatedCount = command.ExecuteNonQuery();
            this.ThrowIfCommandQueryFailed(updatedCount > 0, command.CommandText);
        }

        /// <summary>
        /// Verify that the execution of a Command.ExecuteNonQuery completed within the expectation.
        /// Return value of Command.ExecuteNonQuery is either the count of inserted or updated records.
        /// </summary>
        /// <param name="result">The insert/updated count returned by Command.ExecuteNonQuery</param>
        /// <param name="expected">The expected insert/updated count</param>
        /// <param name="commandText">To provide useful output, commandText used</param>
        private void ThrowIfCommandQueryFailed(int result, int expected, string commandText)
        {
            ThrowIfCommandQueryFailed(result == expected, commandText);
        }

        /// <summary>
        /// Verify that the execution of a Command.ExecuteNonQuery completed within the expectation.
        /// Return value of Command.ExecuteNonQuery is either the count of inserted or updated records,
        /// but in some cases, a number can vary within changes, but as long as a condition is meet, things are good.
        /// </summary>
        /// <param name="condition">Boolean condition to be evaluated. If true, things are good.</param>
        /// <param name="commandText">To provide useful output, commandText used</param>
        private void ThrowIfCommandQueryFailed(bool condition, string commandText)
        {
            if (!condition)
            {
                throw new InvalidOperationException(String.Format(StringExceptionFormats.QueryDidNotYieldExpectedResult, commandText));
            }
        }
    }

    internal static class FrontEndDatabaseResources
    {
        public const string FileDatabaseConnectionString = "Data Source=\"{0}\"";
        public const string InMemoryDatabaseConnectionString = "Data Source =:memory:";

        public const string InsertValuesAndReturnRowIdQueryText = @"INSERT INTO {0}({1}) VALUES({2});SELECT last_insert_rowid();";

        public const string BulkUpdateDatabaseQueryText = @"
            UPDATE Classes SET Base = (SELECT RowId FROM Classes C1 WHERE C1.FullName = Classes.Base) WHERE Base <> '';
            UPDATE RequiredInterfaces SET Requires = (SELECT RowId FROM Interfaces WHERE Interfaces.FullName = RequiredInterfaces.Requires) WHERE instr(Requires, '<') = 0;
            UPDATE ClassInterfaces SET Interface = (SELECT RowId FROM Interfaces WHERE Interfaces.FullName = ClassInterfaces.Interface) WHERE instr(Interface, '<') = 0;
            UPDATE ClassStatics SET Interface = (SELECT RowId FROM Interfaces WHERE Interfaces.FullName = ClassStatics.Interface) WHERE instr(Interface, '<') = 0;
            UPDATE ClassConstructors SET Interface = (SELECT RowId FROM Interfaces WHERE Interfaces.FullName = ClassConstructors.Interface) WHERE instr(Interface, '<') = 0;

            -- Must be executed at least after the UPDATE ClassInterfaces query from above.
            DELETE from ClassInterfaces WHERE ClassId in (SELECT RowId FROM Classes WHERE DefaultInterface LIKE '%<%') AND NOT IsDefault AND typeof(Interface) = 'text'; 

            DELETE FROM Enumerators WHERE EnumerationId = (SELECT RowId FROM Enumerations WHERE FullName = 'Windows::Foundation::AsyncStatus');
            DELETE FROM Enumerations WHERE FullName = 'Windows::Foundation::AsyncStatus';
            DELETE FROM Enumerators WHERE EnumerationId = (SELECT RowId FROM Enumerations WHERE FullName = 'Windows::Foundation::Collections::CollectionChange');
            DELETE FROM Enumerations WHERE FullName = 'Windows::Foundation::Collections::CollectionChange';
            DELETE FROM Enumerators WHERE EnumerationId = (SELECT RowId FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::AttributeTargets');
            DELETE FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::AttributeTargets';
            DELETE FROM Enumerators WHERE EnumerationId = (SELECT RowId FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::CompositionType');
            DELETE FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::CompositionType';
            DELETE FROM Enumerators WHERE EnumerationId = (SELECT RowId FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::DeprecationType');
            DELETE FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::DeprecationType';
            DELETE FROM Enumerators WHERE EnumerationId = (SELECT RowId FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::MarshalingType');
            DELETE FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::MarshalingType';
            DELETE FROM Enumerators WHERE EnumerationId = (SELECT RowId FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::Platform');
            DELETE FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::Platform';
            DELETE FROM Enumerators WHERE EnumerationId = (SELECT RowId FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::ThreadingModel');
            DELETE FROM Enumerations WHERE FullName = 'Windows::Foundation::Metadata::ThreadingModel';

            -- Temp table used to save multiple queries for the same value via a query that matches a string.
            CREATE TEMP TABLE _Variables(Value);
            INSERT INTO _Variables (Value) Values(0);

            -- Delete Open Generic Interfaces

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::IIterable`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::IIterator`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);            

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::IKeyValuePair`2');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::IMapChangedEventArgs`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::IMapView`2');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::IMap`2');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::IObservableMap`2');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::IObservableVector`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::IVectorChangedEventArgs');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::IVectorView`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::IVector`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::IAsyncActionWithProgress`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::IAsyncOperationWithProgress`2');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::IAsyncOperation`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::IReferenceArray`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::IReference`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::IAsyncInfo');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            -- Special case compared to above cases
            UPDATE RequiredInterfaces SET Requires = 'IAsyncInfo' WHERE Requires = (SELECT Value FROM _Variables WHERE RowId = 1);

            -- End of Delete Open Generic Interfaces

            -- Delete Open Generic Delegates
            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::VectorChangedEventHandler`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::Collections::MapChangedEventHandler`2');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::AsyncOperationWithProgressCompletedHandler`2');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::AsyncOperationCompletedHandler`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::AsyncActionWithProgressCompletedHandler`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::AsyncOperationProgressHandler`2');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::AsyncActionProgressHandler`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::TypedEventHandler`2');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            UPDATE _Variables SET Value = (SELECT RowId FROM Interfaces WHERE FullName = 'Windows::Foundation::EventHandler`1');
            DELETE FROM Parameters WHERE MethodId IN (SELECT RowId FROM Methods WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1) );
            DELETE FROM Methods WHERE InterfaceId IN (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM Interfaces WHERE RowId = (SELECT Value FROM _Variables WHERE RowId = 1);
            DELETE FROM RequiredInterfaces WHERE InterfaceId = (SELECT Value FROM _Variables WHERE RowId = 1);

            -- End of Delete Open Generic Delegates

            DELETE FROM Fields WHERE StructureId = (SELECT RowId FROM Structures WHERE FullName='Windows::Foundation::EventRegistrationToken');
            DELETE FROM Structures WHERE FullName = 'Windows::Foundation::EventRegistrationToken';
            DELETE FROM Fields WHERE StructureId = (SELECT RowId FROM Structures WHERE FullName='Windows::Foundation::HResult');
            DELETE FROM Structures WHERE FullName = 'Windows::Foundation::HResult';

            DELETE FROM Structures WHERE FullName LIKE '%Contract';

            UPDATE NamespaceToGenericInterfaceDependency SET GenericInterfaceId = (SELECT RowId FROM GenericInterfaces WHERE MetadataFullNameInCppForm = GenericInterfaceId);

            -- Deal with parameters where the type is array. Current compiler sets those methods as Deprecated.
            -- UPDATE Methods SET Deprecated = 1 WHERE RowId IN (SELECT MethodId FROM Parameters WHERE Flags & 262144);
            ";

        public const string UpdateClassInterfacesSelectQueryText = @"SELECT RowId, Interface FROM ClassInterfaces WHERE instr(Interface, '<') > 0;";
        public const string UpdateClassInterfacesUpdateQueryText = @"UPDATE ClassInterfaces SET Interface=@Interface WHERE RowId=@RowId;";

        public const string UpdateRuntimeClassDefaultInterfacesSelectQueryText = @"SELECT RowId, DefaultInterface FROM Classes WHERE DefaultInterface LIKE '%`%';";
        public const string UpdateRuntimeClassDefaultInterfacesUpdateQueryText = @"UPDATE Classes SET DefaultInterface=@DefaultInterface WHERE RowId=@RowId;";

        public const string UpdateStructureFieldTypesSelectQueryText = @"SELECT RowId, Type, Category FROM Fields;";
        public const string UpdateStructureFieldTypesUpdateQueryText = @"UPDATE Fields SET Type=@Type, TypeNamespace=@TypeNamespace, TypeName=@TypeName, Category=@Category WHERE RowId=@RowId;";

        public const string UpdateParameterTypesSelectQueryText = @"SELECT Parameters.RowId, Parameters.Type, Methods.AbiName FROM Parameters, Methods WHERE Parameters.MethodId = Methods.RowId;";
        public const string UpdateParameterTypesUpdateQueryText = @"UPDATE Parameters SET Type=@Type, TypeNamespace=@TypeNamespace, TypeName=@TypeName, ClassType=@ClassType, Category=@Category WHERE RowId=@RowId;";

        public const string UpdateRequiredInterfacesSelectQueryText = @"SELECT RowId, Requires FROM RequiredInterfaces WHERE instr(Requires, '<') > 0;";
        public const string UpdateRequiredInterfacesUpdateQueryText = @"UPDATE RequiredInterfaces SET Requires=@Requires WHERE RowId=@RowId;";

        public const string UpdateGenericInterfacesSelectQueryText = @"SELECT RowId, MetadataFullNameInDotForm FROM GenericInterfaces;";
        public const string UpdateGenericInterfacesUpdateQueryText = @"UPDATE GenericInterfaces SET FullName=@ProjectedType, Namespace=@Namespace, Name=@Name WHERE RowId=@RowId;";

        public const string CreateIndexesQueryText = @"
            create unique index ClassesIndex on Classes(FullName);
            create unique index EnumerationsIndex on Enumerations(FullName);
            create index EnumeratorsIndex on Enumerators(EnumerationId);
            create unique index InterfacesIndex on Interfaces(FullName);
            create unique index GenericInterfacesIndex on GenericInterfaces(FullName);
            create index MethodsIndex on Methods(InterfaceId);
            create index ParametersIndex on Parameters(MethodId);
            create unique index StructuresIndex on Structures(FullName);
            create index FieldsIndex on Fields(StructureId);
            create index FieldsNameIndex on Fields(Type);
            create index ClassNamespaceIndex on Classes(Namespace);
            create index EnumNamespaceIndex on Enumerations(Namespace);
            create index FieldsNamespaceIndex on Fields(TypeNamespace);
            create index InterfaceNamespaceIndex on Interfaces(Namespace);
            create index ParameterNamespaceIndex on Parameters(TypeNamespace);
            create index ParameterTypeIndex on Parameters(Type);
            create index StructureNamespaceIndex on Structures(Namespace);
            create Index ConstructorInterfaceIndex on ClassConstructors(Interface);
            create Index ConstructorClassIndex on ClassConstructors(ClassId);
            create Index ClassInterfaceIndex on ClassInterfaces(ClassId);
            create Index ClassInterfaceInterfaceIndex on ClassInterfaces(Interface);
            create Index GenericNamespaceIndex on NamespaceToTypeCategoryDependency(Namespace);
            create Index GenericDependentNamespaceIndex on NamespaceToTypeCategoryDependency(DependentNamespace);
            create Index GenericInterfaceNamespaceIndex on NamespaceToGenericInterfaceDependency(Namespace);
            ";

        public const string dbText = @"
            create table Classes
            (
                FullName,
                Namespace,
                Name,
                Base,
                DefaultInterface default '',
                Activatable default 0,
                Deprecated
            );

            create table Enumerations
            (
                FullName,
                Namespace,
                Name,
                Flags,
                Deprecated
            );

            create table Enumerators
            (
                Name,
                Value,
                EnumerationId,
                Deprecated
            );

            create table Interfaces
            (
                FullName,
                Namespace,
                Name,
                Delegate,
                Uuid,
                Deprecated
            );

            create table GenericInterfaces
            (
                FullName,
                Namespace,
                Name,
                Uuid,
                MetadataFullNameInDotForm,
                MetadataFullNameInCppForm,
                Depth
            );


            create table Methods
            (
                Name,
                AbiName,
                InterfaceId,
                Deprecated
            );

            create table Parameters
            (
                Name,
                Type,
                TypeNamespace,
                TypeName,
                ClassType,
                Category,
                Flags,
                MethodId
            );

            create table RequiredInterfaces
            (
                InterfaceId,
                Requires
            );

            create table ClassInterfaces
            (
                ClassId,
                Interface,
                IsDefault,
                Overridable,
                Protected
            );

            create table ClassStatics
            (
                ClassId,
                Interface
            );

            create table ClassConstructors
            (
                ClassId,
                Interface,
                Composable,
                Protected
            );

            create table Structures
            (
                FullName,
                Namespace,
                Name,
                Depends default 0,
                Deprecated
            );

            create table Fields
            (
                Name,
                Type,
                TypeNamespace,
                TypeName,
                Category,
                StructureId
            );

            create table NamespaceToTypeCategoryDependency
            (
                Namespace,
                DependentNamespace,
                TypeCategory
            );

            create table NamespaceToGenericInterfaceDependency
            (
                Namespace,
                GenericInterfaceId
            );";
    }
}