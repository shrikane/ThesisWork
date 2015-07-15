/* Get Best Fit node for size M , ZigZagOrder*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
		struct node_t *left, *right;
		int data;
}node;

node * getNode(){
		node *temp;
		temp = (node *) malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = 0;
		return temp;
}

node * insert(node *root, int val) {
		if (root == NULL) {
				root = getNode();
				root->data = val;
				return root;
		}
		if (val > root->data)
				root->right = insert(root->right, val);
		else if (val < root->data)
				root->left = insert(root->left, val);
		return root;
}

void inorder(node * root) {
		if(root == NULL)
				return;
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
}


void zigzagorder(node *root) {
		node *lr[20], *rl[20], *temp;
		int toplr = -1, toprl = -1, flag = 0;

		if (root == NULL)
				return;

		lr[++toplr] = root;
		do {
				printf("\n");

				if (flag == 0){
						while(toplr >= 0){
								temp = lr[toplr--];
								printf("%d ", temp->data);
								if(temp->left != NULL)
										rl[++toprl] = temp->left;
								if(temp->right != NULL)
										rl[++toprl] = temp->right;
						}
						flag = 1;
				}
				else {
						while(toprl >= 0){
								temp = rl[toprl--];
								printf("%d ", temp->data);
								if(temp->right != NULL)
										lr[++toplr] = temp->right;
								if(temp->left != NULL)
										lr[++toplr] = temp->left;
						}
						flag = 0;
				}
		} while (!((toplr == -1) && (toprl == -1)));
}

node * findBestFit(node * root, int M, node *fit) {
		if (root == NULL)
				return fit;
		if (root->data == M)
				return root;
		if (root->data < M)
				return findBestFit(root->right, M, fit);
		else{
				if (fit == NULL || ((fit->data > root->data) && (root->data > M)))
						fit = root;
				return findBestFit(root->left, M, fit);
		}
}

void main() {
		node *root = NULL, *fit=NULL;
		int val;

		printf("\nValue = ");
		scanf("%d",&val);
		while(val >= 0) {
				root = insert(root, val);
				printf("Value = ");
				scanf("%d",&val);				
		}

		printf("\n");
		inorder(root);
		zigzagorder(root);
		printf("\n");

		printf("\nM :: ");
		scanf("%d",&val);
		fit = findBestFit(root, val, NULL);
		if (fit != NULL)
				printf("Best Fit :: %d\n",fit->data);
		else
				printf("No Fit\n");
}
