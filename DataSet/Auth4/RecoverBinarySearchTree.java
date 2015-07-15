package recover_binary_search_tree;

import common.TreeNode;

public class RecoverBinarySearchTree {

    public class Solution {
        public void recoverTree(TreeNode root) {
            TreeNode first = null;
            TreeNode second = null;
            TreeNode p = root;
            TreeNode pre = null;
            while (p != null) {
                if (p.left == null) {
                    if (pre != null && pre.val > p.val) {
                        if (first == null) {
                            first = pre;
                            second = p;
                        } else {
                            second = p;
                        }
                    }
                    pre = p;
                    p = p.right;
                } else {
                    TreeNode temp = p.left;
                    while (temp.right != null && temp.right != p) {
                        temp = temp.right;
                    }
                    if (temp.right == null) {
                        temp.right = p;
                        p = p.left;
                    } else {
                        if (pre != null && pre.val > p.val) {
                            if (first == null) {
                                first = pre;
                                second = p;
                            } else {
                                second = p;
                            }
                        }
                        temp.right = null;
                        pre = p;
                        p = p.right;
                    }
                }
            }
            int temp = first.val;
            first.val = second.val;
            second.val = temp;
        }
    }

    public static class UnitTest {
    }
}
