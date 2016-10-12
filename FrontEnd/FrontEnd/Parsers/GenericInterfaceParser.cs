using System;
using System.Linq;
using System.Text.RegularExpressions;

namespace Microsoft.Wcl.Parsers
{
    internal static class GenericInterfaceParser
    {
        /// <summary>
        /// Returns true or false whether the input looks like a generic interface. If it contains at least one 'less than' character, it is considered to be a generic interface.
        /// </summary>
        /// <param name="nameElement">The name element to be inspected</param>
        /// <returns></returns>
        public static bool IsGenericInterface(string nameElement)
        {
            return nameElement.Contains("<");
        }

        /// <summary>
        /// Returns true or false whether the type is an open type. An open type does not contain any arguments.
        /// Example: Windows::Collections::IMap`2
        /// </summary>
        /// <param name="nameElement">The name element to be inspected</param>
        /// <returns></returns>
        public static bool IsOpenInterface(string nameElement)
        {
            return nameElement.Contains("`") && !nameElement.Contains("<");
        }

        public static bool IsOpenType(string nameElement)
        {
            return nameElement.Contains("!!");
        }

        /// <summary>
        /// Remove `# from GenericInterface.
        /// Eg, from Windows.Foundation.Collections.IVector`1&lt;Windows.UI.ApplicationSettings.WebAccountCommand&gt;
        /// return Windows::Foundation::Collections::IVector&lt;Windows::UI::ApplicationSettings::WebAccountCommand&gt;
        /// </summary>
        /// <param name="nameElement">Generic interface to be parsed</param>
        /// <param name="interfaceFullTypeName"></param>
        /// <returns></returns>
        public static bool TryGetNormalizedInterfaceFullTypeName(string nameElement, out string interfaceFullTypeName)
        {
            interfaceFullTypeName = null;

            if (GenericInterfaceParser.RegexGenericInterfaceNormalizer.IsMatch(nameElement))
            {
                interfaceFullTypeName = GenericInterfaceParser.RegexGenericInterfaceNormalizer.Replace(nameElement, String.Empty);
            }

            return interfaceFullTypeName != null;
        }

        /// <summary>
        /// Remove `# from GenericInterface.
        /// Eg, from Windows.Foundation.Collections.IVector`1&lt;Windows.UI.ApplicationSettings.WebAccountCommand&gt;
        /// return Windows::Foundation::Collections::IVector&lt;Windows::UI::ApplicationSettings::WebAccountCommand&gt;
        /// </summary>
        /// <param name="nameElement">Generic interface to be parsed</param>
        /// <param name="interfaceFullTypeName"></param>
        /// <returns></returns>
        public static string GetNormalizedInterfaceFullTypeName(string nameElement)
        {
            string interfaceFullTypeName = null;
            if (!TryGetNormalizedInterfaceFullTypeName(nameElement, out interfaceFullTypeName))
            {
                throw new InvalidOperationException(String.Format("Could not parse type {0}", nameElement));
            }

            return interfaceFullTypeName;
        }

        /// <summary>
        /// Parse generic type and return the number of arguments
        /// Eg, from Windows.Foundation.TypedEventHandler`2&lt;Windows.UI.Xaml.FrameworkElement, Object&gt;
        /// return 2
        /// </summary>
        /// <param name="nameElement">Generic interface to be parsed</param>
        /// <param name="argumentCount"></param>
        /// <returns></returns>
        public static bool TryGetGenericInterfaceArgumentCount(string nameElement, out uint argumentCount)
        {
            argumentCount = 0;

            if (GenericInterfaceParser.RegexGenericInterfaceNormalizer.IsMatch(nameElement))
            {
                var match = GenericInterfaceParser.RegexGenericInterfaceNormalizer.Match(nameElement);
                var value = match.Value.Replace("`", String.Empty);
                uint.TryParse(value, out argumentCount);
            }

            return argumentCount != 0;
        }

        public static uint GetGenericInterfaceArgumentCount(string nameElement)
        {
            uint argumentCount = 0;
            if (!TryGetGenericInterfaceArgumentCount(nameElement, out argumentCount))
            {
                throw new InvalidOperationException(StringExceptionFormats.CouldNotGetArgumentCountFromGenericType);
            }

            return argumentCount;
        }

        /// <summary>
        /// Get the open interface without the the argument count.
        /// Eg, from Windows.Foundation.TypedEventHandler`2&lt;Windows.UI.Xaml.FrameworkElement, Object&gt;
        /// return Windows.Foundation.TypedEventHandler
        /// </summary>
        /// <param name="nameElement">Generic interface to be parsed</param>
        /// <param name="openInterfaceFullTypeName"></param>
        /// <returns></returns>
        public static bool TryGetOpenInterfaceFullTypeNameWithoutArgumentCount(string nameElement, out string openInterfaceFullTypeName)
        {
            openInterfaceFullTypeName = null;

            if (GenericInterfaceParser.RegexGenericInterfaceNormalizer.IsMatch(nameElement))
            {
                var match = GenericInterfaceParser.RegexGenericInterfaceNormalizer.Match(nameElement);
                openInterfaceFullTypeName = nameElement.Substring(0, match.Index);
            }

            return openInterfaceFullTypeName != null;
        }

        public static string GetOpenInterfaceFullTypeNameWithoutArgumentCount(string nameElement)
        {
            string openInterfaceFullTypeName = null;
            if (!TryGetOpenInterfaceFullTypeNameWithoutArgumentCount(nameElement, out openInterfaceFullTypeName))
            {
                throw new InvalidOperationException(String.Format("Could not properly parse the interface", nameElement));
            }

            return openInterfaceFullTypeName;
        }

        /// <summary>
        /// Get the open interface, including the argument count.
        /// Eg, from Windows.Foundation.TypedEventHandler`2&lt;Windows.UI.Xaml.FrameworkElement, Object&gt;
        /// return Windows.Foundation.TypedEventHandler`2
        /// </summary>
        /// <param name="nameElement">Generic interface to be parsed</param>
        /// <param name="openInterfaceFullTypeName"></param>
        /// <returns></returns>
        public static bool TryGetOpenInterface(string nameElement, out string openInterfaceFullTypeName)
        {
            openInterfaceFullTypeName = null;

            if (GenericInterfaceParser.RegexGenericInterfaceNormalizer.IsMatch(nameElement))
            {
                var match = GenericInterfaceParser.RegexGenericInterfaceNormalizer.Match(nameElement);
                openInterfaceFullTypeName = nameElement.Substring(0, match.Index + match.Value.Length);
            }

            return openInterfaceFullTypeName != null;
        }

        /// <summary>
        /// Get the arguments of a GenericInterface.
        /// Eg, from Windows.Foundation.TypedEventHandler`2&lt;Windows.UI.Xaml.FrameworkElement, Object&gt;
        /// return Windows.UI.Xaml.FrameworkElement, Object
        /// </summary>
        /// <param name="nameElement">Generic interface to be parsed</param>
        /// <param name="arguments"></param>
        /// <returns></returns>
        public static bool TryGetGenericInterfaceArguments(string nameElement, out string arguments)
        {
            arguments = null;
            int lessThanIndex = 0;
            int greatherThanIndex = 0;

            lessThanIndex = nameElement.IndexOf("<");
            greatherThanIndex = nameElement.LastIndexOf(">");

            if (lessThanIndex > 0 && greatherThanIndex == nameElement.Length - 1)
            {
                arguments = nameElement.Substring(lessThanIndex + 1, greatherThanIndex - lessThanIndex - 1);
            }

            return arguments != null;
        }

        public static int GetGenericInterfaceDepthness(string fullTypeName)
        {
            return fullTypeName.Count(c => c == '<');
        }

        static Regex RegexGenericInterfaceNormalizer = new Regex(@"`\d+", RegexOptions.Compiled);
    }
}
