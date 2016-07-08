using System;

namespace Microsoft.Wcl
{
    internal static class TypeNameUtilities
    {
        public static string GetFullTypeNameInDotForm(string fullTypeName)
        {
            return fullTypeName.Replace("::", ".");
        }

        public static string GetFullTypeNameInCPPForm(string fullTypeName)
        {
            return fullTypeName.Replace(".", "::");
        }

        public static string GetFormattedFullTypeName(string namespaceName, string typeName)
        {
            return String.Format("{0}::{1}", GetFullTypeNameInCPPForm(namespaceName), typeName);
        }

        public static int GetIndexOfTypeName(string fullTypeName)
        {
            // Not suitable for generic interfaces
            // Dont want to make this more expensive. USe GetIndexOfTypeNameForGenericInterface instead for such cases.
            return fullTypeName.LastIndexOf("::");
        }

        public static bool IsTypeInANamespace(string fullTypeName)
        {
            return fullTypeName.Contains("::");
        }

        public static int GetIndexOfTypeNameForGenericInterface(string fullTypeName)
        {
            var indexLessThan = fullTypeName.IndexOf("<");
            return fullTypeName.LastIndexOf("::", indexLessThan - 1, indexLessThan);
        }

        public static string GetNamespaceNameFromType(string fullTypeName)
        {
            return fullTypeName.Substring(0, GetIndexOfTypeName(fullTypeName));
        }

        public static string GetNamespaceNameFromGenericInterface(string fullTypeName)
        {
            return fullTypeName.Substring(0, GetIndexOfTypeNameForGenericInterface(fullTypeName));
        }
    }
}
