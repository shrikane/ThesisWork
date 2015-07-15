package remove_duplicates_from_sorted_list;

import common.ListNode;

public class RemoveDuplicatesfromSortedList {

    public class Solution {
        public ListNode deleteDuplicates(ListNode head) {
            if (head != null) {
                ListNode pre = head;
                ListNode p = pre.next;
                while (p != null) {
                    if (p.val == pre.val) {
                        pre.next = p.next;
                    } else {
                        pre = p;
                    }
                    p = p.next;
                }
            }
            return head;
        }
    }

    public static class UnitTest {

    }
}
