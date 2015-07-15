/*
   Cracking the Coding Interviews 4.4
   Given a binary search tree, design an algorithm which
   creates a linked list of all the nodes at each depth
   (i.e., if you have a tree with depth D, you'll have D linked lists).
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct treenode {
		int data;
		struct treenode *left, * right;
}treenode;

typedef struct listnode {
		treenode *node;
		struct listnode *next;
}listnode;

typedef struct levelnode {
		treenode *node;
		listnode *next;
		struct levelnode *down;
} levelnode;

treenode * gettreenode(int val) {
		treenode * temp;
		temp = (treenode *) malloc (sizeof(treenode));
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
}

listnode * getlistnode(treenode *node) {
		listnode * temp;
		temp = (listnode *) malloc (sizeof(listnode));
		temp->node = node;
		temp->next = NULL;
		return temp;
}

levelnode * getlevelnode (treenode * node){
		levelnode * temp;
		temp = (levelnode * )malloc (sizeof(levelnode));
		temp->node = node;
		temp->next = NULL;
		temp->down = NULL;
		return temp;
}

treenode * createtree(treenode * root) {
		root = gettreenode(1);
		root->left = gettreenode(3);
		root->right = gettreenode(5);
		root->left->left = gettreenode(-1);
		root->left->left->left = gettreenode(1);
		root->right->right = gettreenode(-2);
		root->right->right->right = gettreenode(1);
		return root;
}

void inorder(treenode* root) {
		if (root == NULL)
				return;

		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
}

levelnode *insert(levelnode *levellist, treenode *node) {
		levelnode *temp = getlevelnode(node);
		levelnode *p = levellist;
		if (levellist == NULL)
				return temp;
		while (p->down != NULL)
				p = p->down;
		p->down = temp;
		return levellist;
}

void insertinlist(levelnode *levellist, treenode * node) {
		levelnode *p = levellist;
		listnode *temp = getlistnode(node), *q;
		while(p->down != NULL)
				p = p->down;
		if (p->next == NULL)
				p->next = temp;
		else {
				q = p->next;
				while(q->next != NULL)
						q = q->next;
				q->next = temp;
		}
}

void print(levelnode * levellist) {
		levelnode *p = levellist;
		listnode *q;
		while (p) {
				printf("%d ", p->node->data);
				q = p->next;
				while (q) {
						printf("%d ", q->node->data);
						q = q->next;
				}
				p = p->down;
				printf("\n");
		}
}

levelnode * createlevellist(treenode *root, levelnode *levellist) {
		treenode * Q[100], *temp;
		int front=-1 , back=-1, isfirstinlevel=1;

		if (root == NULL)
				return NULL;

		Q[0] = root; front=0; back=0;
		Q[++back] = NULL;

		while(front<=back) {
				temp = Q[front++];
				if (temp != NULL) {
						isfirstinlevel = 1; 
						while (temp!=NULL) {
								if (isfirstinlevel) {
										levellist = insert(levellist, temp);
										isfirstinlevel = 0;
								}
								else
										insertinlist(levellist, temp);

								if (temp->left)
										Q[++back] = temp->left;
								if (temp->right)
										Q[++back] = temp->right;
								temp = Q[front++];
						}
						Q[++back] = NULL;
				}
		}
		return levellist;
}

void main() {
		treenode * root;
		levelnode *levellist = NULL;
		int sum = 4, path[10];
		root = createtree(root);
		//inorder(root);
		levellist = createlevellist(root,levellist);
		print(levellist);
}
