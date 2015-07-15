package partition_list;

import common.ListNode;

public class PartitionList {

    public class Solution {
        public ListNode partition(ListNode head, int x) {
            ListNode lessHead = null;
            ListNode lessTail = null;
            ListNode greaterHead = null;
            ListNode greaterTail = null;
            ListNode p = head;
            while (p != null) {
                if (p.val < x) {
                    if (lessHead == null) {
                        lessHead = p;
                    } else {
                        lessTail.next = p;
                    }
                    lessTail = p;
                } else {
                    if (greaterHead == null) {
                        greaterHead = p;
                    } else {
                        greaterTail.next = p;
                    }
                    greaterTail = p;
                }
                p = p.next;
            }
            if (lessHead == null) {
                if (greaterTail != null) {
                    greaterTail.next = null;
                }
                return greaterHead;
            } else {
                lessTail.next = greaterHead;
                if (greaterTail != null) {
                    greaterTail.next = null;
                }
                return lessHead;
            }
        }
    }

    public static class UnitTest {

    }
}
