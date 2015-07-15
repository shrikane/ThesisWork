package construct_binary_tree_from_inorder_and_postorder_traversal;

import java.util.HashMap;
import java.util.Map;

import common.TreeNode;

public class ConstructBinaryTreefromInorderandPostorderTraversal {

    public class Solution {
        private TreeNode buildTree(Map<Integer, Integer> inorder, int b1,
                int[] postorder, int b2, int len) {
            if (len == 0) {
                return null;
            }
            TreeNode node = new TreeNode(postorder[b2 + len - 1]);
            int i = inorder.get(node.val);
            node.left = buildTree(inorder, b1, postorder, b2, i - b1);
            node.right = buildTree(inorder, i + 1, postorder, b2 + i - b1, len
                    - i + b1 - 1);
            return node;
        }

        public TreeNode buildTree(int[] inorder, int[] postorder) {
            assert inorder != null && postorder != null
                    && inorder.length == postorder.length;
            Map<Integer, Integer> inorderNodes = new HashMap<Integer, Integer>();
            for (int i = 0; i < inorder.length; i++) {
                inorderNodes.put(inorder[i], i);
            }
            return buildTree(inorderNodes, 0, postorder, 0, inorder.length);
        }
    }

    public static class UnitTest {

    }
}
