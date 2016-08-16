using System;
using System.Collections.Generic;
using System.IO;

namespace Microsoft.Wcl
{
    internal class ResponseFileNotFoundException : FileNotFoundException
    {
        public ResponseFileNotFoundException(string responseFile) : base(String.Format(StringExceptionFormats.ResponseFileNotFound, responseFile))
        { }
    }

    internal class InvalidResponseFileException : FileNotFoundException
    {
        public InvalidResponseFileException(string responseNear, string responseChunk, int index) : base(String.Format(StringExceptionFormats.InvalidResponseFile, responseNear, responseChunk, index))
        { }
    }

    internal class ResponseFileParser
    {
        public IList<string> Parse(string file)
        {
            if (File.Exists(file))
            {
                var responseFileContent = GetResponseFileContent(file);
                var expandedArgs = ParseResponseFileContent(responseFileContent);
                return expandedArgs;
            }
            else
            {
                throw new ResponseFileNotFoundException(file);
            }
        }

        /// <summary>
        /// It will break the response file into pieces where each piece will become an entry in the returned list.
        /// This mimics input from the console.
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        protected IList<string> ParseResponseFileContent(string input)
        {
            var expandedArgs = new List<string>();

            // Used to find parameter names
            char[] delimiter = { '-', '/' };
            // Used to find the first parameter value
            char[] delimiter2 = { ' ', '"' };

            // Example -winmd foo.winmd bar.winmd -db mydatabase.db
            while (!String.IsNullOrEmpty(input))
            {
                // All index == -1 checks are to deal with the last one, where the delimiter will not be found in the remaining string

                // Find where a chunk begins and ends. For example, in "-winmd file1.winmd, file2.winmd -db c:\temp\output.db" find where -winmd starts and where it ends (right before -db)
                var beginIndex = input.IndexOfAny(delimiter);
                var endIndex = input.IndexOfAny(delimiter, beginIndex + 1);

                // If the delimiter was not found for the second time, consider the current string as a full chunk (if there was more than one, this is the last one)
                if (endIndex == -1)
                {
                    endIndex = input.Length;
                }

                // Get a chunk eg --> -winmd foo.winmd bar.winmd
                // and break it down.
                // This will find where -winmd starts and where it ends
                var chunk = input.Substring(beginIndex, endIndex - beginIndex);
                var spaceIndex = chunk.IndexOfAny(delimiter2);

                // 1. When there is a space or quotes were found, the parameter includes values, eg -winmd file1.winmd
                // 2. When there are not spaces or a quote, we are dealing with a parameter name only, eg -?
                if (spaceIndex > 0)
                {
                    // Break down parameter name and parameter values
                    var parameterName = chunk.Substring(0, spaceIndex);
                    var values = chunk.Substring(spaceIndex + 1).Trim();

                    expandedArgs.Add(parameterName);
                    // Get foo.winmd, bar.winmd, etc
                    var valuesList = BreakDownValues(values);

                    expandedArgs.Add(valuesList);
                }
                else
                {
                    expandedArgs.Add(chunk);
                }

                // Move to the next chunk, eg -db mydatabase.db
                input = input.Substring(endIndex);
            }

            return expandedArgs;

        }

        private string GetResponseFileContent(string file)
        {
            string output = null;

            using (var reader = new StreamReader(file))
            {
                output = reader.ReadToEnd();
            }

            return output;
        }

        /// <summary>
        /// Will break values into lines, for example, foo.winmd bar.winmd will become two entries in the returned array "foo.winmd" and "bar.wind".
        /// It knows how to deal with values with spaces, for example "c:\program files\foo.winmd" bar.winmd
        /// </summary>
        /// <param name="input">String to be parsed</param>
        /// <returns>Array that contains one entry per parsed element</returns>
        private IList<string> BreakDownValues(string input)
        {
            var originalInput = input;
            var list = new List<string>();
            const char delimiter = '\"';
            int previousIndex = 0;

            while (!string.IsNullOrEmpty(input))
            {
                input = input.TrimStart(new char[] { ' ', '\r', '\n' });

                int index = 0;
                int startIndex = 0;
                int endIndex = 0;
                int nextIndex = 0;

                // Two main cases:
                // 1. Value starts with quotes (most likely provided like that by the client because the path has spaces)
                // 2. Value does not have any spaces
                if (input[0] == delimiter)
                {
                    //Find the next " which is where it ends
                    index = input.IndexOf(delimiter, 1);

                    if (index > 0)
                    {
                        startIndex = 1;
                        endIndex = index - 1;
                        nextIndex = index + 1;
                    }
                }
                else
                {
                    // Remaining input did not start with a quote. It is expected that the next space (or end of string) 
                    // is where the current value ends.
                    index = input.IndexOf(' ');

                    if (index > 0)
                    {
                        startIndex = 0;
                        endIndex = index;
                        nextIndex = index;
                    }
                    else
                    {
                        // Last one. Fix up the values for that case
                        if (input.Length > 0)
                        {
                            index = input.Length;
                            startIndex = 0;
                            endIndex = input.Length;
                            nextIndex = input.Length;
                        }
                    }
                }

                if (index > 0)
                {
                    var value = input.Substring(startIndex, endIndex);
                    list.Add(value);

                    previousIndex = index;
                }
                else
                {
                    // Most likely the previous parse chunk lead to this. Use the previous index to provide a hint.
                    throw new InvalidResponseFileException(originalInput, input, previousIndex);
                }

                input = input.Substring(nextIndex);

                // If this is the last one, input will be empty.
                // If not, the next one must be a space, otherwise input if malformed. For example, "c:\foo.winmd""d:\bar.winmd". Such input is malformed.
                if (!String.IsNullOrEmpty(input) && input[0] != ' ')
                {
                    throw new InvalidResponseFileException(originalInput, input, nextIndex);
                }
            }

            return list;
        }
    }
}
