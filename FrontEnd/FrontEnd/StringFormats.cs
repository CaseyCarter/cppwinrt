using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Microsoft.Wcl
{
    internal static class StringExceptionFormats
    {
        public const string TypeNotFoundInRepositoryWithKnownCurrent = "Could not find type {0} for {1} in the repository";
        public const string InvalidRepositoryTypeKind = "Invalid type kind from the repository {0}";
        public const string ArgumentParseExceptionMessage = "Could not parse argument: {0}";
        public const string ArgumentValueWithoutName = "Encountered value without a name: {0}";
        public const string InvalidParameter = "Invalid parameter: {0}";
        public const string InvalidArgumentStatus = "Invalid ArgumentStatus value: {0}";
        public const string CouldNotParseGenericInterface = "Could not parse generic interface {0}";
        public const string CouldNotGetBackingBufferFromHSTRING = "Could not get the raw buffer for an HSTRING";
        public const string InvalidTypeValueForEnumField = "Parsing error on Enum Field {0}. The value of a field can only be int or uint";
        public const string InterfaceWithoutGuidAttribute = "Interface without a Guid attribute on type {0}";
        public const string InvalidSpecialNameOnMethod = "Unrecognized special name for method {0}";
        public const string CouldNotDeriveProjectedType = "Could not derive projected type for type {0}. Reason {1}";
        public const string CouldNotDeriveClassType = "Could not derive class type from type {0}";
        public const string CouldNotDeriveTypeCategory = "Could not derive type category from type {0}";
        public const string WinmdFileNotFound = "Could not find Winmd {0}";
        public const string CouldNotParseTypeInMetadataWinmd = "Could not parse type {0} from winmd {1}";
        public const string RuntimeclassWithoutStaticOrDefaultInterface = "Runtimeclass found without default interface or static interface";
        public const string RuntimeclassNonGenericDefaultInterfaceExists = "Default interface (non Generic) for Runtimeclass not found";
        public const string CantBuildTypeInfoFromCustomAttribute = "Can't build {0}. The information from the metadata seems to be incorrect.";
        public const string QueryDidNotYieldExpectedResult = "Query was executed, but did not yield expected result: {0}";
        public const string CouldNotParseWinmd = "Could not parse winmd {0}";
        public const string CouldNotFindFriendlyMethodNameInRepository = "Could not find friendly method name information in the repository for method {0}";
        public const string ResponseFileNotFound = "Could not find response file {0}";
    }

    internal static class StringFormats
    {
        public const string ProjectedAbiMethod = "abi_{0}";
        public const string OpenTypeFormat = "!!{0}";
        public const string ProjectedTypeInWinRTNamespace = "winrt::{0}";
        public const string ProjectedStructureField = "ABI::{0}*";
        public const string OpenGenericDependency1 = "{0}<{1}>";
        public const string OpenGenericDependency2 = "{0}<Windows::Foundation::Collections::IKeyValuePair`2<{1}>>";
    }

    internal static class StringMessageFormats
    {
        public const string InitializingDatabase = "Initializing database";
        public const string VerifyingWinmds = "Verifying input winmds";
        public const string ProcessingWinmds = "Processing winmds";
        public const string ParsingWinmd = "Parsing {0}";
        public const string TimeProcessingMetadata = "Time parsing + insert to database {0}ms";
        public const string TimeInsertingToDatabase = "Time inserting information in the database {0}ms";
        public const string TimeToRecondileData = "Time reconciling data {0}ms";
        public const string ReconcilingData = "Reconciling data";
        public const string GeneratingGenericInterfaceIIDs = "Generating generic interface iids";
        public const string TimeGeneratingGenericInterfacesIIDs = "Time generating generic interfaces iids {0}ms";
        public const string TotalTimeToProcessInput = "Total time {0}ms";
        public const string SemanticChecks = "Running semantic checks";
        public const string TimeToRunSemanticChecks = "Time to run semantic checks {0}ms";
    }
}
