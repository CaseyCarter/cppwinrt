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
            string originalChunk = input;
            var expandedArgs = new List<string>();

            // Parse the chunks and return a chunk per item in the list
            // A chunk can look like
            // 1. -winmd foo.winmd
            // 2. -winmd "foo.winmd"
            // 3. "foo.winmd"
            // 4. foo.winmd
            // A chunk can start and end with unlimited '\r', '\r' and ' '

            while (!string.IsNullOrEmpty(input))
            {
                int currentIndex = 0;

                // Skip through end of lines and empty spaces
                while ((currentIndex < input.Length) && (input[currentIndex] == '\r' || input[currentIndex] == '\n' || input[currentIndex] == ' '))
                {
                    currentIndex++;
                }

                // After skipping, did we reach the end of the input?
                if (currentIndex == input.Length)
                {
                    break;
                }

                int indexNextToken = 0;
                int beginIndex = 0;
                int endIndex = 0;
                bool nextTokenIsAQuote = input[currentIndex] == '\"';

                if (nextTokenIsAQuote)
                {
                    indexNextToken = input.IndexOf('\"', currentIndex + 1);

                    // Not finding the end quote means input is malformed
                    if (indexNextToken == -1)
                    {
                        throw new InvalidResponseFileException(input.Substring(currentIndex), originalChunk, currentIndex);
                    }

                    beginIndex = currentIndex + 1;
                    endIndex = indexNextToken;
                }
                else
                {
                    indexNextToken = input.IndexOfAny(new char[] { ' ', '\r', '\n' }, currentIndex);

                    // Not finding any of the expected tokens means that the rest of the string is a chunk.
                    // Indicate via indexNextToken that we are at the last chunk.
                    if (indexNextToken == -1)
                    {
                        indexNextToken = input.Length;
                    }

                    beginIndex = currentIndex;
                    endIndex = indexNextToken;
                }

                string chunk = input.Substring(beginIndex, endIndex - beginIndex);

                // Are we dealing with a chunk that somehow did NOT started with a '"',
                // but somehow has a '"'.
                // This can happen for a chunk like --> c:\folder\file.winmd"
                if (chunk.IndexOf("\"") >= 0)
                {
                    throw new InvalidResponseFileException(chunk, originalChunk, beginIndex);
                }

                expandedArgs.Add(chunk);

                // Are we at the end of the input?
                input = (indexNextToken == input.Length ? 
                            string.Empty : 
                            input.Substring(indexNextToken + 1));
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
    }
}
