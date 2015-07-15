/*
   Cracking the Coding Interviews 4.8
   You are given a binary tree in which each node contains a value.
   Design an algorithm to print all paths which sum up to that value.
   Note that it can be any path in the tree - it does not have to start at the root.
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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
		root = getnode(9);
		root->left = getnode(3);
		root->right = getnode(5);
		root->left->left = getnode(4);
		root->left->right = getnode(1);
		root->left->left->left = getnode(2);
		root->left->right->right = getnode(6);
		root->left->right->right->right = getnode(7);
		//root->right->right->right = getnode(8);
		return root;
}

void inorder(node* root) {
		if (root == NULL)
				return;

		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
}

void longesttreewalk(node *root, char *walk) {

		char lwalk[100]="", rwalk[100]="";
		int i, j, k, len, llen, rlen;

		if(!root){
				walk[0] = '\0';
				return;
		}

		longesttreewalk(root->left, lwalk);
		longesttreewalk(root->right, rwalk);

		llen = strlen(lwalk);
		rlen = strlen(rwalk);

		j = 0;

		if(llen != 0) {
				i = 0;
				while ((lwalk[i]!='\0') && (lwalk[i]!=root->left->data+'0'))
						i++;
				if (i >= llen - i - 1) {
						k = 0;
						while (k <= i)
								walk[j++] = lwalk[k++];	
				}
				else {
						k = i;
						while (k < llen)
								walk[j++] = lwalk[k++];
				}
		}

		walk[j++] = root->data + '0';

		if (rlen != 0) {
				i = 0;
				while ((rwalk[i]!='\0') && (rwalk[i]!=root->right->data+'0'))
						i++;
				if (i >= rlen - i - 1) {
						k = 0;
						while (k <= i)
								walk[j++] = rwalk[k++];
				}
				else {
						k = i;
				while (k < rlen)
						walk[j++] = rwalk[k++];
				}
		}

		walk[j] = '\0';

		len = strlen(walk);
		if ((llen>=len) && (llen>=rlen)) {
				i = 0;
				while (i<=llen) {
						walk[i] = lwalk[i];
						i++;
				}
		}
		else if ((rlen>=len) && (rlen>=llen)) {
				i = 0;
				while (i<=rlen) {
						walk[i] = rwalk[i];
						i++;
				}
		}

		return;
}

void main() {
		node * root;
		char walk[100]="";
		root = createtree(root);

		inorder(root);
		printf ("\n");

		longesttreewalk(root, walk);
		printf("Walk = %s\n",walk);
}
