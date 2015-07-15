package sum_root_to_leaf_numbers;

import common.TreeNode;

public class SumRoottoLeafNumbers {

    public class Solution {
        private int sumNumbers(TreeNode root, int base) {
            if (root.left == null && root.right == null) {
                return base;
            }
            int sum = 0;
            if (root.left != null) {
                sum += sumNumbers(root.left, base * 10 + root.left.val);
            }
            if (root.right != null) {
                sum += sumNumbers(root.right, base * 10 + root.right.val);
            }
            return sum;
        }

        public int sumNumbers(TreeNode root) {
            if (root == null) {
                return 0;
            }
            return sumNumbers(root, root.val);
        }
    }

    public static class UnitTest {

    }
}
