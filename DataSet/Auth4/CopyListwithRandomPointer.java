package copy_list_with_random_pointer;

import common.RandomListNode;

public class CopyListwithRandomPointer {

    public class Solution {

        public RandomListNode copyRandomList(RandomListNode head) {
            if (head == null) {
                return null;
            }
            RandomListNode p = head;
            while (p != null) {
                RandomListNode newP = new RandomListNode(p.label);
                newP.next = p.next;
                newP.random = p.random;
                p.next = newP;
                p = newP.next;
            }
            p = head;
            RandomListNode newHead = p.next;
            while (p != null) {
                RandomListNode newP = p.next;
                if (newP.random != null) {
                    newP.random = newP.random.next;
                }
                p = newP.next;
            }
            p = head;
            while (p != null) {
                RandomListNode newP = p.next;
                p.next = newP.next;
                if (newP.next != null) {
                    newP.next = newP.next.next;
                }
                p = p.next;
            }
            return newHead;
        }
    }

    public static class UnitTest {

    }
}
