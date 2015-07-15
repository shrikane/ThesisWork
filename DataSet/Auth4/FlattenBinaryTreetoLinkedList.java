package flatten_binary_tree_to_linked_list;

import common.TreeNode;

public class FlattenBinaryTreetoLinkedList {

    public class Solution {
        private TreeNode flattenTree(TreeNode root) {
            if (root == null) {
                return null;
            }
            TreeNode tail = root;
            TreeNode right = root.right;
            if (root.left != null) {
                tail = flattenTree(root.left);
                root.right = root.left;
                tail.right = right;
                root.left = null;
            }
            if (right != null) {
                tail = flattenTree(right);
            }
            return tail;
        }

        public void flatten(TreeNode root) {
            flattenTree(root);
        }
    }

    public static class UnitTest {

    }
}
