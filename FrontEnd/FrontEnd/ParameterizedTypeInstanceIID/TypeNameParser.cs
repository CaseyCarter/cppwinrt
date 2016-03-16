using System;
using System.Runtime.InteropServices;

namespace Microsoft.Wcl.ParameterizedTypeInstanceIID
{
    /// <summary>
    /// Wrapper around RoParseTypeName, see https://msdn.microsoft.com/en-us/library/hh438434(v=vs.85).aspx.
    /// Used to get the parts of a parameterized type, eg Windows::Foundation::ITypedEventHandler`2 of T1, T2
    /// </summary>
    internal static class TypeNameParser
    {
        /// <summary>
        /// Wraps the call to RoParseTypeName and marshalling of the HSTRINGS returned by the call
        /// </summary>
        /// <param name="fullTypeName"></param>
        /// <returns>Array of parts returned by RoParseTypeName</returns>
        public static string[] GetParts(string fullTypeName)
        {
            string[] stringParts = null;
            IntPtr[] nativeParts = null;

            try
            {
                nativeParts = GetNativeParts(fullTypeName);
                stringParts = GetManagedParts(nativeParts);
            }
            finally
            {
                foreach (var part in nativeParts)
                {
                    Marshal.FreeCoTaskMem(part);
                }
            }

            return stringParts;
        }

        private static IntPtr[] GetNativeParts(string fullTypeName)
        {
            int hresult = 0;
            // During marshalling, all we get is the IntPtr to the first part (C style array)
            var firstPart = IntPtr.Zero;
            var partCount = 0u;
            IntPtr[] nativeParts = null;

            hresult = NativeMethods.RoParseTypeName(fullTypeName, out partCount, out firstPart);
            if (hresult != HResultConstants.S_OK)
            {
                Marshal.ThrowExceptionForHR(hresult);
            }

            // Get all the HSTRING elements of the actual array
            nativeParts = new IntPtr[partCount];
            Marshal.Copy(firstPart, nativeParts, 0, (int)partCount);

            return nativeParts;
        }

        private static string[] GetManagedParts(IntPtr[] nativeParts)
        {
            var stringParts = new string[nativeParts.Length];

            for (int i = 0; i < nativeParts.Length; i++)
            {
                var lenght = 0u;
                IntPtr strPtr = NativeMethods.WindowsGetStringRawBuffer(nativeParts[i], out lenght);
                if (strPtr == IntPtr.Zero)
                {
                    throw new InvalidOperationException(StringExceptionFormats.CouldNotGetBackingBufferFromHSTRING);
                }
                stringParts[i] = Marshal.PtrToStringUni(strPtr);
            }

            return stringParts;
        }
    }
}
