package binary_tree_maximum_path_sum;

import common.TreeNode;

public class BinaryTreeMaximumPathSum {

    public class Solution {
        private int maxPathSum(TreeNode root, int[] partSum) {
            int leftSum = 0;
            int leftPartSum = 0;
            int rightSum = 0;
            int rightPartSum = 0;
            if (root.left != null) {
                leftSum = maxPathSum(root.left, partSum);
                leftPartSum = partSum[0] > 0 ? partSum[0] : 0;
            }
            if (root.right != null) {
                rightSum = maxPathSum(root.right, partSum);
                rightPartSum = partSum[0] > 0 ? partSum[0] : 0;
            }
            int maxSum = leftPartSum + rightPartSum + root.val;
            if (root.left != null) {
                maxSum = Math.max(maxSum, leftSum);
            }
            if (root.right != null) {
                maxSum = Math.max(maxSum, rightSum);
            }
            partSum[0] = Math.max(leftPartSum, rightPartSum) + root.val;
            return maxSum;
        }

        public int maxPathSum(TreeNode root) {
            if (root == null) {
                return 0;
            }
            return maxPathSum(root, new int[1]);
        }
    }

    public static class UnitTest {

    }
}
