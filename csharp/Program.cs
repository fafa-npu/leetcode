using System;

namespace leetcode
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution sln = new Solution();
            var res = sln.TwoSum(new int[] { 3, 2, 4 }, 6);

            foreach (var num in res)
            {
                Console.WriteLine(num);
            }
        }
    }
}
