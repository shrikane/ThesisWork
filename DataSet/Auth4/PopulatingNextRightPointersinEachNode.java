package populating_next_right_pointers_in_each_node;

import common.TreeLinkNode;

public class PopulatingNextRightPointersinEachNode {

    public class Solution {
        public void connect(TreeLinkNode root) {
            TreeLinkNode leftMost = root;
            while (leftMost != null) {
                TreeLinkNode p = leftMost;
                while (p.left != null) {
                    p.left.next = p.right;
                    if (p.next != null) {
                        p.right.next = p.next.left;
                        p = p.next;
                    } else {
                        break;
                    }
                }
                leftMost = leftMost.left;
            }
        }
    }

    public static class UnitTest {

    }
}
