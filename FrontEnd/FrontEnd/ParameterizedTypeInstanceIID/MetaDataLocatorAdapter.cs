using System;
using System.Runtime.InteropServices;

namespace Microsoft.Wcl.ParameterizedTypeInstanceIID
{
    /// <summary>
    /// Same case as IRoSimpleMetaDataBuilderVftbl.
    /// To mimic IRoMetaDataLocator vftable, a struct with one entry is created.
    /// This is needed because a struct with methods cannot be marshalled between native code and managed code.
    /// This vftable will be used as the single entry in IRoMetaDataLocator struct to have something that looks and feels like a normal struct
    /// </summary>
    internal struct IRoMetaDataLocatorVftbl
    {
        public NativeMethods.Locate Locate;
    }

    /// <summary>
    /// /// Same case as IRoSimpleMetaDataBuilder
    /// This is the real struct that has methods, but they are embedded in the vftable.
    /// This struct will be used to do the dance of callbacks when using RoGetParameterizedIIDs
    /// </summary>
    /// <remarks>
    /// Ignore the fact that the type starts with an I and because of that it seems to be an interface.
    /// It sort of is as a contract, but it is not an actual interface type.
    /// </remarks>
    internal struct IRoMetaDataLocator
    {
        public IntPtr Vftbl;
    }

    /// <summary>
    /// This mimics ParameterizedTypeInstanceIIDNativeAdapter where a wrapper is built to hide the internal native
    /// things done to hide the usage of structs with methods that need to be marshalled
    /// </summary>
    internal class MetaDataLocatorAdapter : IDisposable
    {
        public MetaDataLocatorAdapter(NativeMethods.Locate locateDelegate)
        {
            // Create and initialize the virtual function dispatch table
            IRoMetaDataLocatorVftbl vftbl = new IRoMetaDataLocatorVftbl();

            // Keep delegate from being GC-ed while this Locator is reachable
            LocateDelegate = locateDelegate;
            vftbl.Locate = locateDelegate;

            // Now created the unmanaged version of this struct.
            // This essentially marshalls to native the vftable that has the delegate on it.
            var unmanagedVftbl = Marshal.AllocCoTaskMem(Marshal.SizeOf(vftbl));
            Marshal.StructureToPtr(vftbl, unmanagedVftbl, false);

            // Create the instance of the IRoMetaDataLocator struct to pass to the RoGetParameterizedTypeInstanceIID API
            IRoMetaDataLocator metaDataLocator = new IRoMetaDataLocator();

            // Give this instance the appropriate virtual function table pointer
            metaDataLocator.Vftbl = unmanagedVftbl;

            // Create the unmanaged version of this struct
            this.Interop = Marshal.AllocCoTaskMem(Marshal.SizeOf(metaDataLocator));
            Marshal.StructureToPtr(metaDataLocator, Interop, false);
        }

        /// <summary>
        /// This is what MUST be sent as a parameter for the IMetaDataLocator parameter when calling RoGetParameterizedTypeInstanceIID API
        /// </summary>
        public IntPtr Interop { get; set; }

        private NativeMethods.Locate LocateDelegate { get; set; }

        #region IDisposable Support
        private bool disposed = false;

        protected virtual void Dispose(bool disposing)
        {
            if (!disposed)
            {
                if (disposing)
                {
                    // Before we free the locator block of memory, we need to get the vftbl unmanaged memory pointer from it
                    IRoMetaDataLocator metaDataLocator = (IRoMetaDataLocator)Marshal.PtrToStructure(Interop, typeof(IRoMetaDataLocator));

                    // Save the vftbl pointer for subsequent release
                    IntPtr ptr = metaDataLocator.Vftbl;

                    // Free the first block
                    Marshal.FreeCoTaskMem(Interop);

                    // Free the second block
                    Marshal.FreeCoTaskMem(ptr);
                }

                disposed = true;
            }
        }

        ~MetaDataLocatorAdapter()
        {
            Dispose(false);
        }

        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }
        #endregion
    }
}
