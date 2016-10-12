using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Microsoft.Wcl
{
    enum OutputLevel
    {
        Normal,
        Verbose
    }

    interface IOutput
    {
        void WriteLine(string value);
        void WriteLine(OutputLevel level, string value);
        void WriteLine(string format, object arg);
        void WriteLine(OutputLevel level, string format, object arg);
        void WriteLine(string format, params object[] args);
        void WriteLine(OutputLevel level, string format, params object[] args);
    }

    class ConsoleBasedOutput : IOutput
    {
        OutputLevel OutputLevel = OutputLevel.Normal;

        public void WriteLine(string value)
        {
            this.WriteLine(OutputLevel.Normal, value);
        }

        public void WriteLine(string format, params object[] args)
        {
            this.WriteLine(OutputLevel.Normal, format, args);
        }

        public void WriteLine(string format, object arg)
        {
            this.WriteLine(OutputLevel, format, arg);
        }

        public void WriteLine(OutputLevel level, string value)
        {
            if (this.OutputLevel >= level)
            {
                Console.WriteLine(value);
            }
        }

        public void WriteLine(OutputLevel level, string format, params object[] args)
        {
            if (this.OutputLevel >= level)
            {
                Console.WriteLine(format, args);
            }
        }

        public void WriteLine(OutputLevel level, string format, object arg)
        {
            if (this.OutputLevel >= level)
            {
                Console.WriteLine(format, arg);
            }
        }
    }
}