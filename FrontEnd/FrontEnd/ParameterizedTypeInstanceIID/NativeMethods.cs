using System;
using System.Runtime.InteropServices;

namespace Microsoft.Wcl.ParameterizedTypeInstanceIID
{
    internal static class NativeMethods
    {
        /// <summary>
        /// Delegat used to receive the callbacks from RoGetParameterizedTypeInstanceIID
        /// </summary>
        /// <param name="thisPtr">Not used. This is the 'this' pointer of the IRoMetaDataLocator object</param>
        /// <param name="nameElement">The type name that RoGetParameterizedTypeInstanceIID needs information for</param>
        /// <param name="roSimpleMetadataBuilder">The IRoSimpleMetaDataBuilder object used to provide information</param>
        /// <returns></returns>
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate int Locate([In] IntPtr thisPtr, [In] [MarshalAs(UnmanagedType.LPWStr)] string nameElement, [In] IntPtr roSimpleMetadataBuilder);

        [DllImport("Api-ms-win-core-winrt-roparameterizediid-l1-1-0.dll", PreserveSig = true, CharSet = CharSet.Unicode)]
        public static extern int RoGetParameterizedTypeInstanceIID([In] uint nameElementCount,
                                                                      [In] [MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr, SizeParamIndex = 0)] string[] nameElements,
                                                                      [In] /* ref IRoMetaDataLocator */ IntPtr metadataLocator,
                                                                      out Guid iid,
                                                                      IntPtr pExtra);

        [DllImport("wintypes.dll", PreserveSig = true, CharSet = CharSet.Unicode)]
        public static extern int RoParseTypeName([In] [MarshalAs(UnmanagedType.HString)] string typeName, out uint partsCount, out IntPtr typeNameParts);

        [DllImport("api-ms-win-core-winrt-string-l1-1-0.dll", PreserveSig = true, CharSet = CharSet.Unicode)]
        public static extern IntPtr WindowsGetStringRawBuffer([In] IntPtr hstring, [Out] out uint lenght);
    }
}
