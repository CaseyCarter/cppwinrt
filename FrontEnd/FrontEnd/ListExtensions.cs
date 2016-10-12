using System.Collections.Generic;

namespace Microsoft.Wcl
{
    /// <summary>
    /// Helpers to deal with adding collections to collections
    /// </summary>
    internal static class ListExtensions
    {
        public static void Add<T>(this IList<T> destination, IEnumerable<T> source)
        {
            foreach (var item in source)
            {
                destination.Add(item);
            }
        }

        public static void Add<T, K>(this IDictionary<T, K> destination, IEnumerable<KeyValuePair<T, K>> source)
        {
            foreach (var item in source)
            {
                destination.Add(item);
            }
        }

        public static void Add<T, K>(this IDictionary<T, K> destination, IEnumerator<KeyValuePair<T, K>> source)
        {
            while (source.MoveNext())
            {
                destination.Add(source.Current);
            }
        }
    }
}
