package reverse_linked_list_ii;

import common.ListNode;

public class ReverseLinkedListII {

    public class Solution {
        public ListNode reverseBetween(ListNode head, int m, int n) {
            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode prefix = dummy;
            int count = n - m + 1;
            m--;
            while (m > 0) {
                prefix = prefix.next;
                m--;
            }
            ListNode pre = null;
            ListNode p = prefix.next;
            ListNode reversedTail = p;
            while (count > 0) {
                ListNode temp = p.next;
                p.next = pre;
                pre = p;
                p = temp;
                count--;
            }
            prefix.next = pre;
            if (reversedTail != null) {
                reversedTail.next = p;
            }
            return dummy.next;
        }
    }

    public static class UnitTest {

    }
}
