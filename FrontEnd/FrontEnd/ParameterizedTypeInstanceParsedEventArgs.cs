using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Microsoft.Wcl
{
    internal class ParameterizedTypeInstanceParsedEventArgs
    {
        public string FullTypeName { get; private set; }

        public string OpenInterfaceFullTypeName { get; private set; }

        public ParameterizedTypeInstanceParsedEventArgs(string openInterfaceFullTypeName, string fullTypeName)
        {
            this.OpenInterfaceFullTypeName = openInterfaceFullTypeName;
            this.FullTypeName = fullTypeName;
        }
    }
}
