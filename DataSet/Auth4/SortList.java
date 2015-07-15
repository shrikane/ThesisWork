package sort_list;

import common.ListNode;

public class SortList {

    public class Solution {

        private ListNode merge(ListNode h1, ListNode h2) {
            ListNode dummy = new ListNode(0);
            ListNode prefix = dummy;
            while (h1 != null || h2 != null) {
                if (h2 == null || (h1 != null && h1.val < h2.val)) {
                    prefix.next = h1;
                    prefix = h1;
                    h1 = h1.next;
                } else {
                    prefix.next = h2;
                    prefix = h2;
                    h2 = h2.next;
                }
            }
            return dummy.next;
        }

        private ListNode sortList(ListNode head, int start, int end,
                ListNode[] tail) {
            if (start == end) {
                tail[0] = head;
                return null;
            }
            if (end - start == 1) {
                tail[0] = head.next;
                head.next = null;
                return head;
            }
            int mid = start + (end - start) / 2;
            ListNode left = sortList(head, start, mid, tail);
            ListNode right = sortList(tail[0], mid, end, tail);
            return merge(left, right);
        }

        private int len(ListNode head) {
            int len = 0;
            while (head != null) {
                len++;
                head = head.next;
            }
            return len;
        }

        public ListNode sortList(ListNode head) {
            return sortList(head, 0, len(head), new ListNode[1]);
        }
    }

    public static class UnitTest {
    }
}
