using System.Collections.Generic;
using System.Reflection.Metadata;

namespace Microsoft.Wcl.Parsers
{
    /// <summary>
    /// Types used when reading custom attributes from metadata. In the bulk of the cases, not all data needs to be read from the associated BlobReader.
    /// So, to avoid spending cycles reading data that may get discared, the data is placed on hold and only used when needed.
    /// </summary>
    internal class TypeHolderInfo
    {
        public BlobReader BlobReader;
        public IList<TypeHolderInfoItem> Items;
    }

    internal class TypeHolderInfoItem
    {
        public SignatureTypeCode SignatureTypeCode;
        public EntityHandle Handle;
    }
}
