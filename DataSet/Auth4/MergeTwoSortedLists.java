package merge_two_sorted_lists;

import common.ListNode;

public class MergeTwoSortedLists {

    public class Solution {
        public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            ListNode head = null;
            ListNode pre = null;
            while (l1 != null && l2 != null) {
                if (l1.val <= l2.val) {
                    if (head == null) {
                        head = l1;
                    } else {
                        pre.next = l1;
                    }
                    pre = l1;
                    l1 = l1.next;
                } else {
                    if (head == null) {
                        head = l2;
                    } else {
                        pre.next = l2;
                    }
                    pre = l2;
                    l2 = l2.next;
                }
            }
            if (l1 != null) {
                if (head == null) {
                    head = l1;
                } else {
                    pre.next = l1;
                }
            }
            if (l2 != null) {
                if (head == null) {
                    head = l2;
                } else {
                    pre.next = l2;
                }
            }
            return head;
        }
    }

    public static class UnitTest {

    }
}
