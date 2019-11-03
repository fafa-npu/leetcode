using System;
using System.Collections.Generic;

namespace leetcode
{
    public partial class Solution
    {
        public int LengthOfLongestSubstring(string s)
        {
            if (s.Length <= 1)
            {
                return s.Length;
            }

            var pRight = 1;
            var pLeft = 0;
            var maxLength = 0;
            var charIndexDic = new Dictionary<char, int>();
            charIndexDic[s[0]] = 0;
            
            for (; pRight < s.Length; pRight++)
            {
                maxLength = Math.Max(maxLength, pRight - pLeft);
                if (charIndexDic.ContainsKey(s[pRight]))
                {
                    var removeEnd = charIndexDic[s[pRight]];
                    while (pLeft < removeEnd)
                    {
                        charIndexDic.Remove(s[pLeft]);
                        pLeft ++;
                    }

                    pLeft = removeEnd + 1;
                }

                charIndexDic[s[pRight]] = pRight;
            }

            maxLength = Math.Max(maxLength, pRight - pLeft);

            return maxLength;
        }
    }
}