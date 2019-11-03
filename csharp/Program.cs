using System;

namespace leetcode
{
    class Program
    {
        static void Main(string[] args)
        {
            Solution sln = new Solution();
            var l1 = new ListNode(9);
            l1.next = new ListNode(9);
            var l2 = new ListNode(2);
            l2.next = new ListNode(9);
            var res = sln.AddTwoNumbers(l1, l2);

            while(res != null)
            {
                Console.WriteLine(res.val);
                res = res.next;
            }
        }
    }
}
