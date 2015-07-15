package construct_binary_tree_from_preorder_and_inorder_traversal;

import java.util.HashMap;
import java.util.Map;

import common.TreeNode;

public class ConstructBinaryTreefromPreorderandInorderTraversal {

    public class Solution {
        private TreeNode buildTree(int[] preorder, int b1,
                Map<Integer, Integer> inorderNodes, int b2, int len) {
            if (len == 0) {
                return null;
            }
            TreeNode node = new TreeNode(preorder[b1]);
            int i = inorderNodes.get(node.val);
            node.left = buildTree(preorder, b1 + 1, inorderNodes, b2, i - b2);
            node.right = buildTree(preorder, b1 + 1 + i - b2, inorderNodes,
                    i + 1, len - i + b2 - 1);
            return node;
        }

        public TreeNode buildTree(int[] preorder, int[] inorder) {
            assert (preorder != null && inorder != null && preorder.length == inorder.length);
            Map<Integer, Integer> inorderNodes = new HashMap<Integer, Integer>();
            for (int i = 0; i < inorder.length; i++) {
                inorderNodes.put(inorder[i], i);
            }
            return buildTree(preorder, 0, inorderNodes, 0, inorder.length);
        }
    }

    public static class UnitTest {

    }
}
