# include <stdio.h>
# include <stdlib.h>

typedef struct node {
		int data;
		struct node *left, *right;
} node;

node* getNode(int x) {
		node* temp;
		temp = (node*) malloc(sizeof(node));
		temp->data = x;
		temp->left = temp->right = NULL;
		return temp;
}

void inorder(node* root) {
		if (root == NULL)
				return;
		printf("(");
		inorder(root->left);
		printf(") %d (", root->data);
		inorder(root->right);
		printf(")");
}

node* createTree(node* root) {
		root = getNode(1);
		root->left = getNode(2);
		root->right = getNode(3);
		root->left->left = getNode(4);
		root->left->right = getNode(5);
		root->right->left = getNode(6);
		root->right->right = getNode(7);
		return root;
}

int max(int x, int y) {
		if (x >= y)
				return x;
		return y;
}

int height(node* root) {
		if (root == NULL)
				return 0;
		return 1 + max(height(root->left), height(root->right));
}

node* getLeftMost(node* root) {
		while (root->left)
				root = root->left;
		return root;
}

node* getRightMost(node* root) {
		while (root->right)
				root = root->right;
		return root;
}

node* rotate(node* root) {
		node *leftSubTree, *rightSubTree, *leftMost, *rightMost;
		if (root == NULL || (root->left == NULL && root->right == NULL))
				return root;
		leftSubTree = root->left;
		root->left = NULL;
		rightSubTree = root->right;	   
		root->right = NULL;
		if (leftSubTree) {
				leftMost = getLeftMost(leftSubTree);
				rightMost = getRightMost(leftSubTree);		
				leftMost->left = rightSubTree;
				rightMost->right = root;
				return leftSubTree;
		}

		if (rightSubTree) {
				leftMost = getLeftMost(rightSubTree);
				leftMost->left = root;
				return rightSubTree;
		}
}

node* rotateSubtreeBy90Degree(node* root, int ht, int currHt) {
		if (ht == currHt) {
				root = rotate(root);
				return root;
		}
		if(root->left)
				root->left = rotateSubtreeBy90Degree(root->left, ht, currHt+1);
		if(root->right)
				root->right = rotateSubtreeBy90Degree(root->right, ht, currHt+1);
		return root;
}

node* rotateTreeBy90Degree(node* root) {	  
		int ht = height(root);
		if (root == NULL)
				return NULL;
		while(ht)
				root = rotateSubtreeBy90Degree(root, ht--, 1);
		return root;
}

void main() {
		node* root;
		root = createTree(root);
		inorder(root);
		printf("\n");
		root = rotateTreeBy90Degree(root);
		inorder(root);
}
