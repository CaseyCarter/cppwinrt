using Microsoft.VisualStudio.TestTools.UnitTesting;

using System.Data;
using System.Data.SQLite;

namespace Microsoft.Wtl.Tests
{
    class FrontEndDatabaseTest : Wcl.DataStore.FrontEndDatabase
    {
        public FrontEndDatabaseTest(Wcl.FrontEndConfiguration configuration) : base(configuration)
        { }

        public ConnectionState Status
        {
            get
            {
                return this.Database.State;
            }
        }

        public SQLiteConnection Connection
        {
            get
            {
                return this.Database;
            }
        }
    }

    [TestClass]
    public class DatabaseTests
    {
        [TestMethod]
        public void DatabaseOpenedAfterInitialize()
        {
            FrontEndDatabaseTest database = new FrontEndDatabaseTest(new Wcl.FrontEndConfiguration());
            database.Initialize();

            Assert.IsNotNull(database.Connection);
            Assert.AreEqual(ConnectionState.Open, database.Connection.State);
        }

        [TestMethod]
        public void DatabaseCreatedAfterInitialize()
        {
            FrontEndDatabaseTest database = new FrontEndDatabaseTest(new Wcl.FrontEndConfiguration());
            database.Initialize();

            SQLiteCommand command = database.Connection.CreateCommand();
            command.CommandText = "SELECT * FROM Classes";
            var result = command.ExecuteNonQuery();

            Assert.AreEqual(-1, result);
        }

        [TestMethod]
        public void FolderForDatabaseIsCreated()
        {
            var currentDirectory = System.IO.Directory.GetCurrentDirectory();
            var targetDirectory = System.IO.Path.Combine(currentDirectory, "testfolderdelete");
            var databaseFileLocation = System.IO.Path.Combine(targetDirectory, "output.db");

            Wcl.FrontEndConfiguration configuration = new Wcl.FrontEndConfiguration()
            {
                DataStoreLocation = databaseFileLocation
            };

            if (System.IO.Directory.Exists(targetDirectory))
            {
                System.IO.Directory.Delete(targetDirectory, true);
            }

            FrontEndDatabaseTest database = new FrontEndDatabaseTest(configuration);

            database.Initialize();
            database.Save();

            Assert.IsTrue(System.IO.File.Exists(databaseFileLocation));
        }

        [TestMethod]
        public void FolderForDatabaseExists()
        {
            var currentDirectory = System.IO.Directory.GetCurrentDirectory();
            var targetDirectory = System.IO.Path.Combine(currentDirectory, "testfolderdelete");
            var databaseFileLocation = System.IO.Path.Combine(targetDirectory, "output.db");

            Wcl.FrontEndConfiguration configuration = new Wcl.FrontEndConfiguration()
            {
                DataStoreLocation = databaseFileLocation
            };

            // First get rid of everything (avoid noise all together). Then create the folder
            if (System.IO.Directory.Exists(targetDirectory))
            {
                System.IO.Directory.Delete(targetDirectory, true);
            }

            System.IO.Directory.CreateDirectory(targetDirectory);

            FrontEndDatabaseTest database = new FrontEndDatabaseTest(configuration);

            database.Initialize();
            database.Save();

            Assert.IsTrue(System.IO.File.Exists(databaseFileLocation));
        }

        [TestMethod]
        public void DatabaseIsCreatedInTheCurrentDirectory()
        {
            var databaseFileName = "output.db";
            var currentDirectory = System.IO.Directory.GetCurrentDirectory();
            var databaseFileLocation = System.IO.Path.Combine(currentDirectory, databaseFileName);

            Wcl.FrontEndConfiguration configuration = new Wcl.FrontEndConfiguration()
            {
                DataStoreLocation = databaseFileName
            };

            if (System.IO.File.Exists(databaseFileLocation))
            {
                System.IO.File.Delete(databaseFileLocation);
            }

            FrontEndDatabaseTest database = new FrontEndDatabaseTest(configuration);

            database.Initialize();
            database.Save();

            Assert.IsTrue(System.IO.File.Exists(databaseFileLocation));
        }
    }
}
