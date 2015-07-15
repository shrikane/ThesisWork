package binary_tree_level_order_traversal;

import java.util.ArrayList;

import common.TreeNode;

public class BinaryTreeLevelOrderTraversal {

    public class Solution {
        private void search(TreeNode root, int level,
                ArrayList<ArrayList<Integer>> ans) {
            if (root == null) {
                return;
            }
            if (level >= ans.size()) {
                ans.add(new ArrayList<Integer>());
            }
            ans.get(level).add(root.val);
            search(root.left, level + 1, ans);
            search(root.right, level + 1, ans);
        }

        public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
            ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
            search(root, 0, ans);
            return ans;
        }
    }

    public static class UnitTest {

    }
}
