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
    }
}
