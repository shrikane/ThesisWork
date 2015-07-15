/*
Code: Insertion and Deletion in Trinary Search Tree.
Author: Manish Chavan
*/

/*
Question 2.
Implement insert and delete in a tri-nary tree. A tri-nary tree is much like a binary tree but with three child nodes for each parent instead of two -- with the left node being values less than the parent, the right node values greater than the parent, and the middle nodes values equal to the parent. 

For example, suppose I added the following nodes to the tree in this order: 5, 4, 9, 5, 7, 2, 2. 
The resulting tree would look like this: 

     5 
   / | \ 
  4  5  9 
 /      / 
 2     7 
 | 
 2

 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// types of node
# define LEAF           0  // 000
# define HAS_ONLY_RIGHT 1  // 001
# define HAS_ONLY_MID   2  // 010
# define HAS_MID_RIGHT  3  // 011
# define HAS_ONLY_LEFT  4  // 100
# define HAS_LEFT_RIGHT 5  // 101
# define HAS_LEFT_MID   6  // 110
# define HAS_ALL        7  // 111

// structure for the node
typedef struct node{
		int val;
		struct node *left, *mid, *right;
}node;

// function to allocate space for a node
node* getNode(int v) {
		node* temp;
		temp = (node*) malloc(sizeof(node));
		temp->val = v;
		temp->left = temp->mid = temp->right = NULL;
		return temp;
}

// function for inserting new value in tree
node* insert(node* root, int v) {
		if (root == NULL)
				root = getNode(v);	  
		else if (v == root->val)
				root->mid = insert(root->mid, v);
		else if (v < root->val)
				root->left = insert(root->left, v);
		else
				root->right = insert(root->right, v);
		return root;
}

// functio to find the type of the node depending on the number of children
int typeOfNode(node* root) {
		int type = 0;
		if (root->left != NULL)
				type |= 0x4;
		if (root->mid != NULL)
				type |= 0x2;
		if (root->right != NULL)
				type |= 0x1;
		return type;
}

// functio to delete a node with some value
node* delete(node* root, int v) {
		int type;
		node *newroot, *parent;

		// the value does not exist in the tree
		if (root == NULL)
				return NULL;

		// found the node with the value
		if (v == root->val) {
				type = typeOfNode(root);

				// target node is leaf node
				// its replacement is NULL
				if (type == LEAF) {
						newroot = NULL;
				}

				// target node has only one child
				// the only child is its replacement
				if (type == HAS_ONLY_LEFT || type == HAS_ONLY_MID || type == HAS_ONLY_RIGHT) {
						if (type == HAS_ONLY_LEFT) {
								newroot = root->left;
								root->left = NULL;
						} else if (type == HAS_ONLY_MID) {
								newroot = root->mid;
								root->mid = NULL;
						} else if (type == HAS_ONLY_RIGHT) {
								newroot = root->right;
								root->right = NULL;
						}
				} 

				// target node has two or more children (one is mid)
				// the mid child is its replacement
				if (type == HAS_LEFT_MID || type == HAS_MID_RIGHT || type == HAS_ALL) {
						newroot = root->mid;
						newroot->left = root->left;
						root->left = NULL;
						newroot->right = root->right;
						root->right = NULL;
				}
			
				// target node has only left and right children
				// min in right subtree is the replacement
				if (type == HAS_LEFT_RIGHT) {
						newroot = root->right;
						parent = NULL;
						// go to min node in right subtree
						while(newroot->left) {
								parent = newroot;
								newroot = newroot->left;
						}
						// if immediate right node of root is not the min
						if (parent != NULL) {
								parent->left = newroot->right;
								newroot->right = root->right;
						}
						root->right = NULL;
						newroot->left = root->left;
						root->left = NULL;
				}

				// delete the node and return its replacement
				root = NULL;
				free(root);
				return newroot;
		}

		// if value is less than current value, go left
		else if (v < root->val)
				root->left = delete(root->left, v);

		// if value is less than current value, go left
		else
				root->right = delete(root->right, v);

		return root;
}

// Test Framework

// function for preorder traversal of the tree
void preorder(node* root, char* order) {
		if(root == NULL)
				return;
		sprintf(order+strlen(order), "%d ", root->val);
		preorder(root->left, order);
		preorder(root->mid, order);
		preorder(root->right, order);
}

// Test Template
void test(char* testName, char* predicted, char* actual) {
		printf("%s: ", testName);
		if (!strcmp(predicted, actual))
				printf("Success");
		else
				printf("Failure");
		printf("\n");
}

// Unit Tests
void unitTest() {
		node* root;
		int values[7] = {5, 4, 9, 5, 7, 2, 2}, i;
		char order[100];

		// test for empty tree
		root = NULL;
		order[0] = '\0';
		preorder(root, order);
		test("Empty_Tree_Test", "", order);

		// test for insertion
		for (i=0 ; i<(sizeof(values)/sizeof(values[0])) ; i++)
				root = insert(root, values[i]);
		order[0] = '\0';
		preorder(root, order);
		test("Insert_Test", "5 4 2 2 5 9 7 ", order);

		// test for 3 children node deletion
		root = delete(root, 5);
		order[0]='\0';
		preorder(root, order);
		test("Delete_Tree_Children_Node_Test", "5 4 2 2 9 7 ", order);

		// test for 2 children node deletion
		root = delete(root, 5);
		order[0]='\0';
		preorder(root, order);
		test("Delete_Two_Children_Node_Test", "7 4 2 2 9 ", order);		

		// test for 1 child node deletion
		root = delete(root, 4);
		order[0]='\0';
		preorder(root, order);
		test("Delete_One_Children_Node_Test", "7 2 2 9 ", order);		

		// test for leaf node deletion
		root = delete(root, 9);
		order[0]='\0';
		preorder(root, order);
		test("Delete_Leaf_Node_Test", "7 2 2 ", order);		
}

void main() {
		unitTest();
}
