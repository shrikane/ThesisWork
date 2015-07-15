/*
find the distance between 2 values in a binary search tree. Node will have value, left node and right node
implement the function int Distance(Node root, int val1, int val2) without recursion

int Distance(Node root, int val1, int val2) {
if(val1== val2) {
  return 0;
}
while((root.val<val1 && root.val <val2) || (root.val >val1 && root.val2 >val2)) {
   if(val1 < root.val) {
       root = root.left;
   } else {
        root = root.right;
   }
   
}
return depth(root, val1) + depth(root,val2)
}
Note: function depth(root, val) returns the depth of sub tree. Interviewer is ok about the depth of tree functionality but he asked me if Distance(Node root, int val1, int val2) implementation is correct. 
Complexity is O(logN)
*/

int Distance(node *root, int val1, int val2) {
		if (val1 == val2)
				return 0;
		while(root) {
				if (((root->data > val1) && (root->data < val2)) || 
					((root->data < val1) && (root->data > val2)))
						break;
				else if ((root->data == val1) ||
						 (root->data == val2))
						break;
				else if ((root->data < val1) && (root->data < val2))
						root = root->left;
				else if ((root->data > val1) && (root->data > val2))
						root = root->right;
		}

		return depth(root, val1) + depth(root, val2);
}
