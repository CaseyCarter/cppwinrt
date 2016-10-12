using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace Microsoft.Wcl
{
    internal class Argument
    {
        public Argument(string name, IList<string> values)
        {
            this.Name = name;
            this.Values = values;
        }
        public string Name { get; set; }
        public IList<string> Values { get; set; }
    }

    internal class ArgumentsParseException : Exception
    {
        public ArgumentsParseException(string message) : base(String.Format(StringExceptionFormats.ArgumentParseExceptionMessage, message))
        { }
    }

    internal class NotEnoughArgumentsParseException : Exception
    {
        public NotEnoughArgumentsParseException() : base(StringExceptionFormats.NotEnoughParameters)
        { }
    }

    internal class ArgumentsParser
    {
        /// <summary>
        /// Initializes the object with the provided args. Args typically would come from the main function
        /// </summary>
        /// <param name="args"></param>
        public ArgumentsParser(string[] args)
        {
            if (args == null)
            {
                throw new ArgumentNullException("args");
            }

            this.Args = args;
        }

        public ArgumentsParser(string[] args, IArgumentValidator argumentValidator)
        {
            this.Args = args;
            this.ArgumentValidator = argumentValidator;
        }

        public void Parse()
        {
            string parameterName = null;
            var values = new List<string>();
            var argumentsDictionary = new Dictionary<string, Argument>();
            var regex = new Regex(ArgumentsParser.ArgsPrefixRegEx);

            foreach (string chunk in this.Args)
            {
                var parts = regex.Split(chunk);

                if (parts.Length == 3)
                {
                    // If we are encountering a new parameter, save the current one in the dictionary
                    if (parameterName != null)
                    {
                        this.ValidateAndAddParameterToDictionary(argumentsDictionary, parameterName, values);

                        // Clear up to get ready for the next parameter and prepare the list for the incoming values
                        parameterName = null;
                        values = new List<string>();
                    }

                    // If no exception was thrown, we got a parameter name
                    parameterName = parts[2];
                }
                else if (parts.Length == 1)
                {
                    // We got a value. If we did not get a name, that is bad.
                    if (parameterName == null)
                    {
                        throw new ArgumentsParseException(String.Format(StringExceptionFormats.ArgumentValueWithoutName, parts[0]));
                    }

                    values.Add(parts[0]);
                }
            }

            // For the last case
            if (parameterName != null)
            {
                this.ValidateAndAddParameterToDictionary(argumentsDictionary, parameterName, values);

                // Clear up the value to get ready for the next parameter
                parameterName = null;
            }

            this.ArgumentsDictionary = argumentsDictionary;
        }

        private void ValidateAndAddParameterToDictionary(Dictionary<string, Argument> argumentsDictionary, string parameterName, IList<string> values)
        {
            var status = ValidateInput(argumentsDictionary, parameterName, values);

            switch (status)
            {
                case ArgumentStatus.Ok:
                    Argument argument = null;
                    if (argumentsDictionary.TryGetValue(parameterName, out argument))
                    {
                        argument.Values.Add(values);
                    }
                    else
                    {
                        argumentsDictionary.Add(parameterName, new Argument(parameterName, values));
                    }
                    
                    break;
                case ArgumentStatus.Ignore:
                    break;
                case ArgumentStatus.Invalid:
                    throw new ArgumentException(String.Format(StringExceptionFormats.InvalidParameter, parameterName));
                default:
                    throw new NotImplementedException(String.Format(StringExceptionFormats.InvalidArgumentStatus, status));
            }
        }

        private ArgumentStatus ValidateInput(Dictionary<string, Argument> argumentsDictionary, string parameterName, IList<string> candidateValues)
        {
            var status = ArgumentStatus.Ok;

            if (this.ArgumentValidator != null)
            {
                // Build temporary input that aggregates potential existing one + the candidate one
                var newValues = new List<string>();

                Argument argument = null;
                if (argumentsDictionary.TryGetValue(parameterName, out argument))
                {
                    newValues.Add(argument.Values);
                }

                newValues.Add(candidateValues);

                status = this.ArgumentValidator.Validate(parameterName, newValues);
            }

            return status;
        }

        private string[] Args { get; set; }

        public IDictionary<string, Argument> ArgumentsDictionary { get; private set; }

        private const string ArgsPrefixRegEx = @"(^-|^/)";

        private IArgumentValidator ArgumentValidator { get; set; }
    }
}