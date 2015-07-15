package binary_tree_preorder_traversal;

import java.util.ArrayDeque;
import java.util.ArrayList;

import common.TreeNode;

public class BinaryTreePreorderTraversal {

    public class Solution {
        private void preorderTraversal(TreeNode root,
                ArrayList<Integer> preorder) {
            if (root == null) {
                return;
            }
            preorder.add(root.val);
            preorderTraversal(root.left, preorder);
            preorderTraversal(root.right, preorder);
        }

        public ArrayList<Integer> preorderTraversal(TreeNode root) {
            ArrayList<Integer> preorder = new ArrayList<Integer>();
            preorderTraversal(root, preorder);
            return preorder;
        }

        public ArrayList<Integer> preorderTraversalWithIterative(TreeNode root) {
            ArrayList<Integer> preorder = new ArrayList<Integer>();
            ArrayDeque<TreeNode> stack = new ArrayDeque<TreeNode>();
            if (root != null) {
                stack.offerLast(root);
                while (!stack.isEmpty()) {
                    TreeNode p = stack.removeLast();
                    while (p != null) {
                        preorder.add(p.val);
                        if (p.right != null) {
                            stack.offerLast(p.right);
                        }
                        p = p.left;
                    }
                }
            }
            return preorder;
        }
    }

    public static class UnitTest {

    }
}
