package binary_tree_right_side_view;

import common.TreeNode;

import java.util.ArrayList;
import java.util.List;

public class BinaryTreeRightSideView {

    public class Solution {
        public List<Integer> rightSideView(TreeNode root) {
            List<Integer> result = new ArrayList<Integer>();
            if (root != null) {
                List<TreeNode> level = new ArrayList<TreeNode>();
                level.add(root);
                while (!level.isEmpty()) {
                    result.add(level.get(level.size() - 1).val);
                    List<TreeNode> nextLevel = new ArrayList<TreeNode>();
                    for (TreeNode node : level) {
                        if (node.left != null) {
                            nextLevel.add(node.left);
                        }
                        if (node.right != null) {
                            nextLevel.add(node.right);
                        }
                    }
                    level = nextLevel;
                }
            }
            return result;
        }
    }
}

