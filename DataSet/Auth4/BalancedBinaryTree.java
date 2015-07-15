package balanced_binary_tree;

import common.TreeNode;

public class BalancedBinaryTree {

    class Solution {
        private int getBalancedTreeHeight(TreeNode root) {
            if (root == null) {
                return 0;
            }
            int l = getBalancedTreeHeight(root.left);
            int r = getBalancedTreeHeight(root.right);
            if (l >= 0 && r >= 0) {
                if (Math.abs(l - r) <= 1) {
                    return Math.max(l, r) + 1;
                }
            }
            return -1;
        }

        public boolean isBalanced(TreeNode root) {
            return getBalancedTreeHeight(root) >= 0;
        }
    }

    public static class UnitTest {

    }
}
