/* Cracking the Coding Interviews 4.8
   You are given a binary tree in which each node contains a value.
   Design an algorithm to print all paths which sum up to that value.
   Note that it can be any path in the tree - it does not have to start at the root.
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct node {
		int data;
		struct node *left, * right;
}node;

node * getnode(int val) {
		node * temp;
		temp = (node *) malloc (sizeof(node));
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
}

node * createtree(node * root) {
		root = getnode(1);
		root->left = getnode(3);
		root->right = getnode(5);
		root->left->left = getnode(-1);
		root->left->left->left = getnode(1);
		root->right->right = getnode(-2);
		root->right->right->right = getnode(1);
		return root;
}

void inorder(node* root) {
		if (root == NULL)
				return;

		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
}

void printpath(int *path, int start, int end) {
		int i;
		for (i=start ; i<=end ; i++)
				printf ("%d ",path[i]);
		printf("\n");
}

node * findpath(node *root, int sum, int *path, int pathlen) {
		int tempsum = sum, i, leftpath[10], rightpath[10];

		if (root == NULL)
				return;

		path[pathlen++] = root->data;
		for (i = pathlen-1 ; i>=0 ; i--) {
				tempsum -= path[i];
				if (tempsum == 0)
						printpath(path, i, pathlen-1);
		}

		for (i=0 ; i<pathlen ; i++) {
				leftpath[i] = path[i];
				rightpath[i] = path[i];
		}

		findpath(root->left, sum, leftpath, pathlen);
		findpath(root->right, sum, rightpath, pathlen);
}

void main() {
		node * root;
		int sum = 4, path[10];
		root = createtree(root);
		//inorder(root);
		findpath(root, sum, path, 0);
}
