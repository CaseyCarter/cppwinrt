using System;

namespace Microsoft.Wcl.Projection
{
    /// <summary>
    /// Mirror from meta.h from the back end
    /// </summary>
    [Flags]
    enum TypeCategory
    {
        Unknown = 0,
        Value       = 0x0001, // 1
        String      = 0x0002, // 2
        Enumeration = 0x0004, // 4
        Structure   = 0x0008, // 8
        Interface   = 0x0010, // 16
        Delegate    = 0x0020, // 32
        Class       = 0x0040, // 64
        Boolean     = 0x0080, // 128
        Deprecated  = 0x0100, // 256
    }
}
