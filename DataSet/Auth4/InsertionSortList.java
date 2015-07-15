package insertion_sort_list;

import common.ListNode;

public class InsertionSortList {

    public class Solution {
        public ListNode insertionSortList(ListNode head) {
            ListNode dummy = new ListNode(0);
            ListNode p = head;
            while (p != null) {
                ListNode pre = dummy;
                while (pre.next != null) {
                    if (pre.next.val <= p.val) { // stable sort
                        pre = pre.next;
                    } else {
                        break;
                    }
                }
                ListNode temp = p.next;
                p.next = pre.next;
                pre.next = p;
                p = temp;
            }
            return dummy.next;
        }
    }

    public static class UnitTest {

    }
}
