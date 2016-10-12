using System.Collections.Generic;
using System.Linq;

namespace Microsoft.Wcl
{
    internal enum ArgumentStatus
    {
        Invalid,
        Ignore,
        Ok
    }

    internal interface IArgumentValidator
    {
        ArgumentStatus Validate(string name, IList<string> values);
    }

    internal class ArgumentValidator : IArgumentValidator
    {
        string[] validArgumentNames = { "winmd", "?", "db"};

        public ArgumentStatus Validate(string name, IList<string> values)
        {
            var status = ArgumentStatus.Invalid;

            var nameCheckResult = this.validArgumentNames.Contains(name);
            if (nameCheckResult)
            {
                status = ValidateValues(name, values);
            }
            else
            {
                status = ArgumentStatus.Ignore;
            }

            return status;
        }

        private ArgumentStatus ValidateValues(string name, IList<string> values)
        {
            var status = ArgumentStatus.Ignore;

            switch (name)
            {
                case "winmd":
                    status = values.Count > 0 ? ArgumentStatus.Ok : ArgumentStatus.Invalid;
                    break;
                case "?":
                    status = values.Count == 0 ? ArgumentStatus.Ok : ArgumentStatus.Invalid;
                    break;
                case "db":
                    status = values.Count == 1 ? ArgumentStatus.Ok : ArgumentStatus.Invalid;
                    break;
                default:
                    status = ArgumentStatus.Ignore;
                    break;
            }

            return status;
        }
    }
}