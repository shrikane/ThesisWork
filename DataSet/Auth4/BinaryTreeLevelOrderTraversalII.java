package binary_tree_level_order_traversal_ii;

import java.util.ArrayList;
import java.util.Collections;

import common.TreeNode;

public class BinaryTreeLevelOrderTraversalII {

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

        public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
            ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
            search(root, 0, ans);
            Collections.reverse(ans);
            return ans;
        }
    }

    public static class UnitTest {

    }
}
