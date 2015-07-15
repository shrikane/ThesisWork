package intersection_of_two_linked_lists;

import common.ListNode;

public class IntersectionofTwoLinkedLists {

    public class Solution {
        public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
            if (headA == null) {
                return null;
            }
            ListNode tailA = headA;
            while (tailA.next != null) {
                tailA = tailA.next;
            }
            tailA.next = headB;

            // Find the beginning of the cycle
            ListNode fast = headA;
            ListNode slow = headA;
            do {
                if (fast == null || fast.next == null) {
                    tailA.next = null;
                    return null;
                }
                fast = fast.next.next;
                slow = slow.next;
                if (slow == fast) {
                    fast = headA;
                    while (fast != slow) {
                        fast = fast.next;
                        slow = slow.next;
                    }
                    tailA.next = null;
                    return fast;
                }
            } while (true);
        }
    }

    public static class UnitTest {

    }
}

