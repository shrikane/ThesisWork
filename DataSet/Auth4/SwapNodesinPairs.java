package swap_nodes_in_pairs;

import common.ListNode;

public class SwapNodesinPairs {

    public class Solution {
        public ListNode swapPairs(ListNode head) {
            ListNode first = head;
            ListNode pre = null;
            while (first != null && first.next != null) {
                ListNode second = first.next;
                if (pre == null) {
                    head = second;
                } else {
                    pre.next = second;
                }
                pre = first;
                first.next = second.next;
                second.next = first;
                first = first.next;
            }
            return head;
        }
    }

    public static class UnitTest {

    }
}
