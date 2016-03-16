using System;
using System.Runtime.InteropServices;

namespace Microsoft.Wcl.ParameterizedTypeInstanceIID
{
    /// <summary>
    /// In order to make the usage of RoGetParameterizedTypeInstanceIID this adapter takes care of the
    /// tricks/magic done for the IRoMetaDataLocator parameter.
    /// It basically wraps the need to know about the internals about the issues and
    /// the objects that get created in order to provide the functionality.
    /// </summary>
    internal class ParameterizedTypeInstanceIIDNativeAdapter
    {
        /// <summary>
        /// Delegate to be used by clients of GetParameterizedInstanceIID.
        /// When RoGetParameterizedTypeInstanceIID callsback to the adapter, the adapter will wrap things up for clients 
        /// and then it will invoke the delegate.
        /// </summary>
        /// <param name="nameElement"></param>
        /// <param name="builder"></param>
        /// <returns></returns>
        public delegate int Locate(string nameElement, SimpleMetadataBuilder builder);

        /// <summary>
        /// As an adapter, it will receive a client delegate and call it when RoGetParameterizedTypeInstanceIID calls back
        /// </summary>
        /// <param name="fullTypeName">Full type name for which the IID will be calculated</param>
        /// <param name="locateDelegate">Delegate that will be called when RoGetParameterizedTypeInstanceIID calls back</param>
        /// <returns></returns>
        public Guid GetParameterizedInstanceIID(string fullTypeName, Locate locateDelegate)
        {
            var guid = Guid.Empty;
            var nothing = IntPtr.Zero;
            int hresult = 0;

            using (var locator = new MetaDataLocatorAdapter(this.LocateInternal))
            {
                this.LocateDelegate = locateDelegate;
                string[] stringParts = TypeNameParser.GetParts(fullTypeName);

                try
                {
                    hresult = NativeMethods.RoGetParameterizedTypeInstanceIID((uint)stringParts.Length, stringParts, locator.Interop, out guid, nothing);
                    if (hresult != HResultConstants.S_OK)
                    {
                        Marshal.ThrowExceptionForHR(hresult);
                    }
                }
                finally
                {
                    this.LocateDelegate = null;
                }
            }

            return guid;
        }

        /// <summary>
        /// Now, do magic.
        /// This method will be called by RoGetParameterizedTypeInstanceIID.
        /// </summary>
        /// <param name="thisPtr">Due to the nature of calling by ref with a struct, we tell the CLR that we need to align things. So, first parameter is the 'this' pointer of the IRoMetaDataLocator object</param>
        /// <param name="nameElement">The type name that RoGetParameterizedTypeInstanceIID needs information for</param>
        /// <param name="roSimpleMetadataBuilder">IRoSimpleMetaDataBuilder (Struct by ref) provided by the callback</param>
        /// <returns></returns>
        private int LocateInternal(IntPtr thisPtr, string nameElement, IntPtr roSimpleMetadataBuilderPtr)
        {
            SimpleMetadataBuilder builder = new SimpleMetadataBuilder(roSimpleMetadataBuilderPtr);

            return this.LocateDelegate(nameElement, builder);
        }

        /// <summary>
        /// Cached delegate provided by clients which will be call when RoGetParameterizedTypeInstanceIID callsback.
        /// This is to hide the magic around getting structs by ref with methods.
        /// By doing this, clients provide a callback which is invoked with an objects that knows how to detail with the low level things around IntPtrs, vftables, etc.
        /// </summary>
        private Locate LocateDelegate { get; set; }
    }
}
