using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

namespace Microsoft.Wcl.ParameterizedTypeInstanceIID
{
    // 
    // In the following set of delegates, the magic is that the CLR needs 'this' pointer as the first parameter (even though in MSDN they do not exists, in the native APIs).
    // This is done this way as a way to adapt to a Struct with methods used by native APIs in a callback. CLR does not deal well with marshalling Structs with methods.
    // In all delegates, the pThis represents the 'this' pointer to the IRoSimpleMetaDataBuilder object 
    internal delegate int SetWinRtInterface([In] IntPtr pThis, [In] Guid iid);
    internal delegate int SetDelegate([In] IntPtr pThis, [In] Guid iid);
    internal delegate int SetInterfaceGroupSimpleDefault([In] IntPtr pThis, [In] [MarshalAs(UnmanagedType.LPWStr)] string name, [In] [MarshalAs(UnmanagedType.LPWStr)] string defaultInterfaceName, [In] ref Guid defaultInterfaceIID);
    internal delegate int SetInterfaceGroupParameterizedDefault([In] IntPtr pThis, [In] [MarshalAs(UnmanagedType.LPWStr)] string name, uint elementCount, [In] [MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr)] string[] defaultInterfaceNameElements);
    internal delegate int SetRuntimeClassSimpleDefault([In] IntPtr pThis, [In] [MarshalAs(UnmanagedType.LPWStr)] string name, [In] [MarshalAs(UnmanagedType.LPWStr)] string defaultInterfaceName, [In] ref Guid defaultInterfaceIID);
    internal delegate int SetRuntimeClassParameterizedDefault([In] IntPtr pThis, [In] [MarshalAs(UnmanagedType.LPWStr)] string name, uint elementCount, [In] [MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr)] string[] defaultInterfaceNameElements);
    internal delegate int SetStruct([In] IntPtr pThis, [In] [MarshalAs(UnmanagedType.LPWStr)] string name, uint numFields, [In] [MarshalAs(UnmanagedType.LPArray, ArraySubType = UnmanagedType.LPWStr)] string[] fieldTypeNames);
    internal delegate int SetEnum([In] IntPtr pThis, [In] [MarshalAs(UnmanagedType.LPWStr)] string name, [In] [MarshalAs(UnmanagedType.LPWStr)] string baseType);
    internal delegate int SetParameterizedInterface([In] IntPtr pThis, Guid iid, uint numArgs);
    internal delegate int SetParameterizedDelegate([In] IntPtr pThis, Guid iid, uint numArgs);

    /// <summary>
    /// Same case as IRoMetaDataLocatorVftbl
    /// This is the real struct that has methods, but they are embedded in the vftable.
    /// This struct will be used to do the dance of callbacks when using RoGetParameterizedIIDs
    /// </summary>
    /// <remarks>
    /// Ignore the fact that the type starts with an I and because of that it seems to be an interface.
    /// It sort of is as a contract, but it is not an actual interface type.
    internal struct IRoSimpleMetaDataBuilderVftbl
    {
        public SetWinRtInterface SetWinRtInterface;
        public SetDelegate SetDelegate;
        public SetInterfaceGroupSimpleDefault SetInterfaceGroupSimpleDefault;
        public SetInterfaceGroupParameterizedDefault SetInterfaceGroupParameterizedDefault;
        public SetRuntimeClassSimpleDefault SetRuntimeClassSimpleDefault;
        public SetRuntimeClassParameterizedDefault SetRuntimeClassParameterizedDefault;
        public SetStruct SetStruct;
        public SetEnum SetEnum;
        public SetParameterizedInterface SetParameterizedInterface;
        public SetParameterizedDelegate SetParameterizedDelegate;
    }

    /// <summary>
    /// Same case as IRoMetaDataLocator
    /// To mimic IRoSimpleMetaDataBuilder vftable, a struct with one entry is created.
    /// This is needed because a struct with methods cannot be marshalled between native code and managed code.
    /// This vftable will be used as the single entry in IRoMetaDataLocator struct to have something that looks and feels like a normal struct
    /// </summary>
    internal struct IRoSimpleMetaDataBuilder
    {
        public IntPtr Vftbl;
    }

    /// <summary>
    /// Wrapper around the IRoSimpleMetaDataBuilder magic done with the above code.
    /// The wrapper avoids having to carry around the IRoSimpleMetaDataBuilder provided during the native callback into managed code.
    /// </summary>
    /// <remarks>
    /// From the original RoSimpleMetadataBuilder, method SetInterfaceGroupSimpleDefault and SetInterfaceGroupParameterizedDefault 
    /// are not implemented because they are not used. Windows never shipped the Interface Group feature
    /// </remarks>
    internal class SimpleMetadataBuilder
    {
        IRoSimpleMetaDataBuilderVftbl RoSimpleMetaDataBuilderVftbl { get; set; }
        IntPtr RoSimpleMetaDataBuilderPtr;

        public SimpleMetadataBuilder(IntPtr roSimpleMetaDataBuilderPtr)
        {
            // Let's cache the pointer. It is needed later on when calling methods on this object.
            this.RoSimpleMetaDataBuilderPtr = roSimpleMetaDataBuilderPtr;
            // Marshall the actual IRoSimpleMetaDataBuilder so that we have access to the vfttable which cached for later usage when calling the actual methods
            IRoSimpleMetaDataBuilder roSimpleMetadataBuilder = (IRoSimpleMetaDataBuilder)Marshal.PtrToStructure(roSimpleMetaDataBuilderPtr, typeof(IRoSimpleMetaDataBuilder));
            this.RoSimpleMetaDataBuilderVftbl = (IRoSimpleMetaDataBuilderVftbl)Marshal.PtrToStructure(roSimpleMetadataBuilder.Vftbl, typeof(IRoSimpleMetaDataBuilderVftbl));
        }

        public void SetWinRtInterface(Guid iid)
        {
            var hresult = this.RoSimpleMetaDataBuilderVftbl.SetWinRtInterface(this.RoSimpleMetaDataBuilderPtr, iid);
            if (hresult != HResultConstants.S_OK)
            {
                Marshal.ThrowExceptionForHR(hresult);
            }
        }

        public void SetDelegate(Guid iid)
        {
            var hresult = this.RoSimpleMetaDataBuilderVftbl.SetDelegate(this.RoSimpleMetaDataBuilderPtr, iid);
            if (hresult != HResultConstants.S_OK)
            {
                Marshal.ThrowExceptionForHR(hresult);
            }
        }

        public void SetRuntimeClassSimpleDefault(string name, string defaultInterfaceName, ref Guid defaultInterfaceIID)
        {
            Debug.Assert(!name.Contains(":"));
            Debug.Assert(!defaultInterfaceName.Contains(":"));

            var hresult = this.RoSimpleMetaDataBuilderVftbl.SetRuntimeClassSimpleDefault(this.RoSimpleMetaDataBuilderPtr, name, defaultInterfaceName, ref defaultInterfaceIID);
            if (hresult != HResultConstants.S_OK)
            {
                Marshal.ThrowExceptionForHR(hresult);
            }
        }

        public void SetRuntimeClassParameterizedDefault(string name, string[] defaultInterfaceNameElements)
        {
            Debug.Assert(!name.Contains(":"));
            foreach (var element in defaultInterfaceNameElements)
            {
                Debug.Assert(!element.Contains(":"));
            }

            var hresult = this.RoSimpleMetaDataBuilderVftbl.SetRuntimeClassParameterizedDefault(this.RoSimpleMetaDataBuilderPtr, name, (uint)defaultInterfaceNameElements.Length, defaultInterfaceNameElements);
            if (hresult != HResultConstants.S_OK)
            {
                Marshal.ThrowExceptionForHR(hresult);
            }
        }

        public void SetStruct(string name, string[] fieldTypeNames)
        {
            Debug.Assert(!name.Contains(":"));
            foreach (var element in fieldTypeNames)
            {
                Debug.Assert(!element.Contains(":"));
            }

            var hresult = this.RoSimpleMetaDataBuilderVftbl.SetStruct(this.RoSimpleMetaDataBuilderPtr, name, (uint)fieldTypeNames.Length, fieldTypeNames);
            if (hresult != HResultConstants.S_OK)
            {
                Marshal.ThrowExceptionForHR(hresult);
            }
        }

        public void SetEnum(string name, string baseType)
        {
            Debug.Assert(!name.Contains(":"));
            Debug.Assert(!baseType.Contains(":"));

            var hresult = this.RoSimpleMetaDataBuilderVftbl.SetEnum(this.RoSimpleMetaDataBuilderPtr, name, baseType);
            if (hresult != HResultConstants.S_OK)
            {
                Marshal.ThrowExceptionForHR(hresult);
            }
        }

        public void SetParameterizedInterface(Guid iid, uint numArgs)
        {
            var hresult = this.RoSimpleMetaDataBuilderVftbl.SetParameterizedInterface(this.RoSimpleMetaDataBuilderPtr, iid, numArgs);
            if (hresult != HResultConstants.S_OK)
            {
                Marshal.ThrowExceptionForHR(hresult);
            }
        }

        public void SetParameterizedDelegate(Guid iid, uint numArgs)
        {
            var hresult = this.RoSimpleMetaDataBuilderVftbl.SetParameterizedDelegate(this.RoSimpleMetaDataBuilderPtr, iid, numArgs);
            if (hresult != HResultConstants.S_OK)
            {
                Marshal.ThrowExceptionForHR(hresult);
            }
        }
    }
}