package binary_tree_inorder_traversal;

import java.util.ArrayList;

import common.TreeNode;

public class BinaryTreeInorderTraversal {

    public class Solution {
        public ArrayList<Integer> inorderTraversal(TreeNode root) {
            ArrayList<Integer> ans = new ArrayList<Integer>();
            TreeNode p = root;
            while (p != null) {
                if (p.left == null) {
                    ans.add(p.val);
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
                        ans.add(p.val);
                        temp.right = null;
                        p = p.right;
                    }
                }
            }
            return ans;
        }
    }

    public static class UnitTest {

    }
}
