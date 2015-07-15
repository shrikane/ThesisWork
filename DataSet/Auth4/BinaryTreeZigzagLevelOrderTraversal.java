package binary_tree_zigzag_level_order_traversal;

import java.util.ArrayList;

import common.TreeNode;

public class BinaryTreeZigzagLevelOrderTraversal {

    public class Solution {
        public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
            ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
            if (root == null) {
                return ans;
            }
            ArrayList<TreeNode> q = new ArrayList<TreeNode>();
            q.add(root);
            int tail = 0;
            boolean reverse = false;
            while (tail != q.size()) {
                int begin = tail;
                tail = q.size();
                for (int i = begin; i < tail; i++) {
                    TreeNode p = q.get(i);
                    if (p.left != null) {
                        q.add(p.left);
                    }
                    if (p.right != null) {
                        q.add(p.right);
                    }
                }
                ArrayList<Integer> level = new ArrayList<Integer>();
                if (reverse) {
                    for (int i = tail - 1; i >= begin; i--) {
                        level.add(q.get(i).val);
                    }
                } else {
                    for (int i = begin; i < tail; i++) {
                        level.add(q.get(i).val);
                    }
                }
                ans.add(level);
                reverse = !reverse;
            }
            return ans;
        }
    }

    public static class UnitTest {

    }
}
