/*
How to print the outside frame of a binary tree.

the order is top to down, left to right, then down to top
print all leftest node and rightest nodes
print all leaf nodes
print all nodes which only have 1 leaf

         100
        /   \ 
      50     150
     / \      /
   24   57   130
  /  \    \    \
12   30    60   132
e.g: the output should be 100, 50, 24, 12, 30, 57, 60, 130, 132, 150
*/

void printBorder (node *root) {
	node *level[2][100], *curr;
	int flag = 0, newflag, index[2] = {-1};

	level[flag][++index[flag]] = root;

	while(index[0]!=-1 || index[1]!=-1) {
		newflag = (flag + 1) % 2;
		for (i=0; i<=index[flag]; i++) {
			curr = level[flag][i];
			if (i==0 || i==index[flag])				// left or right outside node
				printf("%d, ", curr.data);
			else if (curr->left == NULL && curr->right == NULL)	// leaf node
				printf("%d, ", curr.data);
			else if (curr->left != NULL && curr->right == NULL) {	// parent of leaf with only one child
				child = curr->left;
				if (child->left == NULL && child->right == NULL)
					printf("%d, ", curr.data)
			}
			else if (curr->left == NULL && curr->right != NULL) {
				child = curr->right;
				if (child->left == NULL && child->right == NULL)
					printf("%d, ", curr.data)
			}
			if (curr->left != NULL)
				level[newflag][++index[newflag]] = curr->left;
			if (curr->right != NULL)
				level[newflag][++index[newflag]] = curr->right;
		}
		index[flag] = -1;
		flag = newflag;
	}
}
