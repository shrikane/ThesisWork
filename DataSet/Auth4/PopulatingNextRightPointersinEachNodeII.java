package populating_next_right_pointers_in_each_node_ii;

import common.TreeLinkNode;

public class PopulatingNextRightPointersinEachNodeII {

    public class Solution {
        public void connect(TreeLinkNode root) {
            TreeLinkNode leftMost = root;
            while (leftMost != null) {
                TreeLinkNode p = leftMost;
                TreeLinkNode pre = null;
                leftMost = null;
                while (p != null) {
                    if (p.left != null) {
                        if (leftMost == null) {
                            leftMost = p.left;
                        }
                        if (pre != null) {
                            pre.next = p.left;
                        }
                        pre = p.left;
                    }
                    if (p.right != null) {
                        if (leftMost == null) {
                            leftMost = p.right;
                        }
                        if (pre != null) {
                            pre.next = p.right;
                        }
                        pre = p.right;
                    }
                    p = p.next;
                }
            }
        }
    }

    public static class UnitTest {

    }
}
