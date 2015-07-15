package merge_k_sorted_lists;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

import common.ListNode;

public class MergekSortedLists {

    public class Solution {
        public ListNode mergeKLists(ArrayList<ListNode> lists) {
            PriorityQueue<ListNode> heap = new PriorityQueue<ListNode>(10,
                    new Comparator<ListNode>() {

                        @Override
                        public int compare(ListNode l1, ListNode l2) {
                            return l1.val - l2.val;
                        }
                    });
            for (ListNode node : lists) {
                if (node != null) {
                    heap.add(node);
                }
            }
            ListNode head = null;
            ListNode pre = null;
            while (!heap.isEmpty()) {
                ListNode top = heap.poll();
                if (head == null) {
                    head = top;
                } else {
                    pre.next = top;
                }
                pre = top;
                if (top.next != null) {
                    heap.add(top.next);
                }
            }
            return head;
        }
    }

    public static class UnitTest {

    }
}
