package binary_tree_postorder_traversal;

import java.util.ArrayDeque;
import java.util.ArrayList;

import common.TreeNode;

public class BinaryTreePostorderTraversal {

    public class Solution {
        private void postorderTraversal(TreeNode root,
                ArrayList<Integer> postorder) {
            if (root == null) {
                return;
            }
            postorderTraversal(root.left, postorder);
            postorderTraversal(root.right, postorder);
            postorder.add(root.val);
        }

        public ArrayList<Integer> postorderTraversal(TreeNode root) {
            ArrayList<Integer> postorder = new ArrayList<Integer>();
            postorderTraversal(root, postorder);
            return postorder;
        }

        public ArrayList<Integer> postorderTraversalWithIterative(TreeNode root) {
            ArrayList<Integer> postorder = new ArrayList<Integer>();
            if (root == null) {
                return postorder;
            }
            ArrayDeque<TreeNode> stack = new ArrayDeque<TreeNode>();
            TreeNode pre = null;
            stack.offerLast(root);
            while (!stack.isEmpty()) {
                TreeNode p = stack.peekLast();
                if (pre == null || pre.left == p || pre.right == p) {
                    if (p.left != null) {
                        stack.offerLast(p.left);
                    } else if (p.right != null) {
                        stack.offerLast(p.right);
                    }
                } else if (p.left == pre) {
                    if (p.right != null) {
                        stack.offerLast(p.right);
                    }
                } else {
                    postorder.add(p.val);
                    stack.removeLast();
                }
                pre = p;
            }
            return postorder;
        }
    }

    public static class UnitTest {

    }
}
