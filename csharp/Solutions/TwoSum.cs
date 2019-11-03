using System;
using System.Collections.Generic;

namespace leetcode
{
    public partial class Solution
    {
        public int[] TwoSum(int[] nums, int target)
        {
            var numIndexDic = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
            {
                var diff = target - nums[i];
                if (numIndexDic.ContainsKey(diff))
                {
                    return new int[] {numIndexDic[diff], i};
                }
                else
                {
                    numIndexDic[nums[i]] = i;
                }
            }

            return Array.Empty<int>();
        }
    }
}