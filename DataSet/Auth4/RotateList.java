package rotate_list;

import common.ListNode;

public class RotateList {

    public class Solution {
        public ListNode rotateRight(ListNode head, int n) {
            if (head == null) {
                return head;
            }
            int k = n;
            int listSize = 0;
            ListNode end = head;
            while (k > 0) {
                end = end.next;
                k--;
                listSize++;
                if (end == null) {
                    k = n % listSize;
                    end = head;
                    while (k > 0) {
                        end = end.next;
                        k--;
                    }
                    break;
                }
            }
            if (head == end) {
                return head;
            }
            ListNode start = head;
            while (end.next != null) {
                end = end.next;
                start = start.next;
            }
            end.next = head;
            head = start.next;
            start.next = null;
            return head;
        }
    }

    public static class UnitTest {

    }
}
