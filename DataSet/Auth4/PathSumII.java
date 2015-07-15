package path_sum_ii;

import java.util.ArrayList;

import common.TreeNode;

public class PathSumII {

    public class Solution {
        public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
            ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
            if (root != null) {
                pathSum(root, sum, new ArrayList<Integer>(), ans);
            }
            return ans;
        }

        private void pathSum(TreeNode root, int sum, ArrayList<Integer> nodes,
                ArrayList<ArrayList<Integer>> ans) {
            if (root.left == null && root.right == null) {
                if (root.val == sum) {
                    ArrayList<Integer> temp = new ArrayList<Integer>(nodes);
                    temp.add(root.val);
                    ans.add(temp);
                }
                return;
            }
            nodes.add(root.val);
            if (root.left != null) {
                pathSum(root.left, sum - root.val, nodes, ans);
            }
            if (root.right != null) {
                pathSum(root.right, sum - root.val, nodes, ans);
            }
            nodes.remove(nodes.size() - 1);
        }
    }

    public static class UnitTest {

    }
}
