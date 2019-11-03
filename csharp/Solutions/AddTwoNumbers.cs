namespace leetcode
{
    public partial class Solution
    {
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            ListNode resHead = new ListNode(0);
            ListNode curNode = resHead;
            var carry = 0;

            while(l1 != null && l2 != null) {
                var curSum = l1.val + l2.val + carry;
                if (curSum > 9){
                    curSum -= 10;
                    carry = 1;
                }else{
                    carry = 0;
                }

                l1 = l1.next;
                l2 = l2.next;

                curNode.next = new ListNode(curSum);
                curNode = curNode.next;
            }

            curNode.next = l1 == null ? l2 : l1;

            while (carry == 1){
                if (curNode.next == null){
                    curNode.next = new ListNode(1);
                    break;
                }else if (curNode.next.val == 9){
                    curNode.next.val = 0;
                    curNode = curNode.next;
                }else{
                    curNode.next.val += 1;
                    carry = 0;
                }
            }

            return resHead.next;
        }
    }
}