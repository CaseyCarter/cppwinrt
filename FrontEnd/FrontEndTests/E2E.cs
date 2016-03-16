using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace Microsoft.Wtl.Tests
{
    [TestClass]
    public class E2E
    {
        public E2E()
        {
            
        }

        [TestInitialize]
        public void Initialize()
        {
            var directory = Path.Combine(Directory.GetCurrentDirectory(), @"TestData\E2E");
            var winmd1 = Path.Combine(directory, @"windows.networking.connectivity.wwancontract.winmd");
            var winmd2 = Path.Combine(directory, @"Windows.Foundation.FoundationContract.winmd");
            var winmd3 = Path.Combine(directory, @"Windows.Foundation.UniversalApiContract.winmd");

            string[] winmds = { winmd1, winmd2, winmd3 };

            MetadataTestHelper.RunFrontEnd(winmds, false);
        }

        [TestMethod]
        public void ParseClasses()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "Classes.base",
                @"TestData\E2E",
                "Classes.test",
                "SELECT FullName, Name, (SELECT FullName FROM Classes C1 WHERE C1.FullName = Classes.Base), DefaultInterface, Activatable, ifnull(Deprecated, 0) FROM Classes ORDER BY FullName;");
        }

        [TestMethod]
        public void ParseEnumerations()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "Enumerations.base",
                @"TestData\E2E",
                "Enumerations.test",
                "SELECT FullName, Name, Flags, ifnull(Deprecated, 0) FROM Enumerations ORDER BY FullName;");
        }

        [TestMethod]
        public void ParseEnumerators()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "Enumerators.base",
                @"TestData\E2E",
                "Enumerators.test",
                "SELECT Enumerators.Name, Enumerators.Value, Enumerations.FullName, ifnull(Enumerators.Deprecated, 0) FROM Enumerators, Enumerations WHERE Enumerators.EnumerationId = Enumerations.RowId ORDER BY Enumerations.FullName, Enumerators.Name;");
        }

        [TestMethod]
        public void ParseInterfaces()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "Interfaces.base",
                @"TestData\E2E",
                "Interfaces.test",
                "SELECT  FullName, Name, Delegate, Uuid, ifnull(Deprecated, 0) FROM Interfaces ORDER BY FullName;");
        }

        [TestMethod]
        public void ParseMethods()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "Methods.base",
                @"TestData\E2E",
                "Methods.test",
                "SELECT Methods.AbiName, Interfaces.FullName, ifnull(Methods.Deprecated, 0) FROM Methods, Interfaces WHERE Methods.InterfaceId = Interfaces.RowId ORDER BY Interfaces.FullName, Methods.AbiName;");
        }

        [TestMethod]
        public void ParseParameters()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "Parameters.base",
                @"TestData\E2E",
                "Parameters.test",
                "SELECT Parameters.Name, Parameters.Type, Parameters.ClassType, Parameters.Category, CASE WHEN Parameters.Flags=65536 THEN 4 WHEN Parameters.Flags=262145 THEN 17 WHEN Parameters.Flags=131074 THEN 2 WHEN Parameters.Flags=262146 THEN 18 WHEN Parameters.Flags=327680 THEN 28 WHEN Parameters.Flags=393218 THEN 26 ELSE Parameters.Flags END, Methods.AbiName FROM Parameters, Methods, Interfaces WHERE Parameters.MethodId = Methods.RowId AND Methods.InterfaceId = Interfaces.RowId ORDER BY Interfaces.FullName, Methods.AbiName, Parameters.Name;");
        }

        [TestMethod]
        public void ParseRequiredInterfaces()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "RequiredInterfaces.base",
                @"TestData\E2E",
                "RequiredInterfaces.test",
                "SELECT ifnull((SELECT Interfaces.FullName FROM Interfaces WHERE Interfaces.RowId = RequiredInterfaces.InterfaceId), RequiredInterfaces.InterfaceId) as InterfaceName, ifnull((SELECT Interfaces.FullName FROM Interfaces WHERE Interfaces.RowId = RequiredInterfaces.Requires), RequiredInterfaces.Requires) as RequiredInterface FROM RequiredInterfaces ORDER BY InterfaceName, RequiredInterface;");
        }

        [TestMethod]
        public void ParseClassInterfaces()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "ClassInterfaces.base",
                @"TestData\E2E",
                "ClassInterfaces.test",
                "SELECT Classes.FullName, Interfaces.FullName, ClassInterfaces.IsDefault, ClassInterfaces.Overridable, ClassInterfaces.Protected FROM ClassInterfaces, Classes, Interfaces WHERE ClassInterfaces.ClassId = Classes.RowId AND Interfaces.RowId = ClassInterfaces.Interface ORDER BY Classes.FullName, Interfaces.FullName;");
        }

        [TestMethod]
        public void ParseClassInterfaces_GenericInterfaces()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "ClassInterfaces_GenericInterface.base",
                @"TestData\E2E",
                "ClassInterfaces_GenericInterface.test",
                "SELECT (SELECT Classes.FullName FROM Classes WHERE Classes.RowId = ClassInterfaces.ClassId) as Class, ClassInterfaces.Interface, ClassInterfaces.IsDefault, ClassInterfaces.Overridable, ClassInterfaces.Protected FROM ClassInterfaces WHERE instr(ClassInterfaces.Interface, '<') > 0 ORDER BY Class, Interface;");
        }

        [TestMethod]
        public void ParseClassStatics()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "ClassStatics.base",
                @"TestData\E2E",
                "ClassStatics.test",
                "SELECT Classes.FullName, Interfaces.FullName FROM ClassStatics, Classes, Interfaces WHERE ClassStatics.ClassId = Classes.RowId AND Interfaces.RowId = ClassStatics.Interface ORDER BY Classes.FullName, Interfaces.FullName;");
        }

        [TestMethod]
        public void ParseClassConstructors()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "ClassConstructors.base",
                @"TestData\E2E",
                "ClassConstructors.test",
                "SELECT Classes.FullName, Interfaces.FullName, ClassConstructors.Composable, ClassConstructors.Protected FROM ClassConstructors, Classes, Interfaces WHERE ClassConstructors.ClassId = Classes.RowId AND Interfaces.RowId = ClassConstructors.Interface ORDER BY Classes.FullName, Interfaces.FullName;");
        }

        [TestMethod]
        public void ParseStructures()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "Structures.base",
                @"TestData\E2E",
                "Structures.test",
                "SELECT FullName, Name, Depends, ifnull(Deprecated, 0) FROM Structures ORDER BY FullName;");
        }

        [TestMethod]
        public void ParseFields()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "Fields.base",
                @"TestData\E2E",
                "Fields.test",
                "SELECT Fields.Name, Fields.Type, Fields.Category, Structures.FullName FROM Structures, Fields WHERE Fields.StructureId = Structures.RowId ORDER BY Structures.FullName, Fields.Name;");
        }

        [TestMethod]
        public void ParseGenericInterfaces()
        {
            MetadataTestHelper.VerifyDatabaseByQuery(@"TestData\E2E",
                "GenericInterfaces.base",
                @"TestData\E2E",
                "GenericInterfaces.test",
                "SELECT * FROM GenericInterfaces ORDER BY FullName;");
        }
    }
}
