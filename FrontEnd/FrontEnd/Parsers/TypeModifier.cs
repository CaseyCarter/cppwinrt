using System.Reflection.Metadata;

namespace Microsoft.Wcl.Parsers
{
    /// <summary>
    /// Used to save information about optional modifiers and required modifiers while parsing the metadata
    /// </summary>
    internal class TypeModifier
    {
        public SignatureTypeCode TypeCode;
        public string FullTypeName;
    }
}
