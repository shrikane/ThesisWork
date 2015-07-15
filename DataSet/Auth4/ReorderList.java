package reorder_list;

import common.ListNode;

public class ReorderList {

    public class Solution {
        private ListNode reverse(ListNode head) {
            ListNode pre = null;
            ListNode p = head;
            while (p != null) {
                ListNode temp = p.next;
                p.next = pre;
                pre = p;
                p = temp;
            }
            return pre;
        }

        private ListNode[] split(ListNode head) {
            ListNode[] lists = new ListNode[2];
            lists[0] = head;
            if (head == null || head.next == null) {
                return lists;
            }
            ListNode slow = head;
            ListNode fast = head.next.next;
            while (fast != null) {
                slow = slow.next;
                if (fast.next == null) {
                    break;
                }
                fast = fast.next.next;
            }
            lists[1] = slow.next;
            slow.next = null;
            return lists;
        }

        private void zip(ListNode l1, ListNode l2) {
            while (l2 != null) {
                ListNode temp = l1.next;
                l1.next = l2;
                l1 = temp;
                temp = l2.next;
                l2.next = l1;
                l2 = temp;
            }
        }

        public void reorderList(ListNode head) {
            ListNode[] lists = split(head);
            lists[1] = reverse(lists[1]);
            zip(lists[0], lists[1]);
        }
    }

    public static class UnitTest {
    }
}
