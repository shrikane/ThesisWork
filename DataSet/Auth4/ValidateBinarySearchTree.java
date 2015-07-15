package validate_binary_search_tree;

import common.TreeNode;

public class ValidateBinarySearchTree {

    public class Solution {
        private boolean isValidBST(TreeNode root, int[] minMax) {
            int min = root.val;
            int max = root.val;
            if (root.left != null) {
                if (!isValidBST(root.left, minMax) || root.val <= minMax[1]) {
                    return false;
                }
                min = minMax[0];
            }
            if (root.right != null) {
                if (!isValidBST(root.right, minMax) || root.val >= minMax[0]) {
                    return false;
                }
                max = minMax[1];
            }
            minMax[0] = min;
            minMax[1] = max;
            return true;
        }

        public boolean isValidBST(TreeNode root) {
            if (root == null) {
                return true;
            }
            return isValidBST(root, new int[2]);
        }
    }

    public static class UnitTest {

    }
}
