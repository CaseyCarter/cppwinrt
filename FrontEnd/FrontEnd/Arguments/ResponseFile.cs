using System;
using System.Collections.Generic;
using System.IO;

namespace Microsoft.Wcl
{
    internal class ResponseFileParser
    {
        public IList<string> Parse(string file)
        {
            var responseFileContent = GetResponseFileContent(file);
            var expandedArgs = ParseResponseFileContent(responseFileContent);
            return expandedArgs;
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

                // Find where a chunk begins and ends. For example, where -winmd starts and where it ends (right before -db)
                var beginIndex = input.IndexOfAny(delimiter);
                var endIndex = input.IndexOfAny(delimiter, beginIndex + 1);

                if (endIndex == -1)
                {
                    endIndex = input.Length;
                }

                // Get a chunk eg --> -winmd foo.winmd bar.winmd
                // and break it down
                var chunk = input.Substring(beginIndex, endIndex);
                var spaceIndex = chunk.IndexOfAny(delimiter2);

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
            var list = new List<string>();
            const char delimiter = '\"';

            while (!string.IsNullOrEmpty(input))
            {
                int index = 0;
                int startIndex = 0;
                int endIndex = 0;
                int nextIndex = 0;

                // Are we dealing with a value that has spaces, therefore it starts with "?
                if (input[0] == delimiter)
                {
                    //Find the next " which is where it ends
                    index = input.IndexOf(delimiter, 1);

                    if (index > 0)
                    {
                        startIndex = 1;
                        endIndex = index - 1;
                    }

                    // Last one?
                    if ((index + 2) < input.Length)
                    {
                        nextIndex = index + 2;
                    }
                    else
                    {
                        nextIndex = index + 1;
                    }

                }
                else
                {
                    // Not a value with spaces (because it did not start with "), find the next space
                    index = input.IndexOf(' ');

                    if (index > 0)
                    {
                        startIndex = 0;
                        endIndex = index;
                        nextIndex = index + 1;
                    }
                    else
                    {
                        // Last one
                        if (input.Length > 0)
                        {
                            index = input.Length;
                            startIndex = 0;
                            endIndex = input.Length;
                            nextIndex = input.Length;
                        }
                    }
                }

                // If we have a value here, get it. Otherwise, we are done (which will be implied by input becoming the empty string)
                if (index > 0)
                {
                    var value = input.Substring(startIndex, endIndex);
                    list.Add(value);
                }

                input = input.Substring(nextIndex);
            }

            return list;
        }
    }
}
