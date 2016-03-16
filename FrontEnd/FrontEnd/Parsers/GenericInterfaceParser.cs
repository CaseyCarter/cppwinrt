using System;
using System.Text.RegularExpressions;

namespace Microsoft.Wcl.Parsers
{
    internal static class GenericInterfaceParser
    {
        public static bool IsGenericInterface(string nameElement)
        {
            return nameElement.Contains("<");
        }

        public static bool IsOpenInterface(string nameElement)
        {
            return nameElement.Contains("`") && !nameElement.Contains("<");
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

        static Regex RegexGenericInterfaceNormalizer = new Regex(@"`\d+", RegexOptions.Compiled);
    }
}
