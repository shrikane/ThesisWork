/*
Given a BST and a value x. Find two nodes in the tree whose sum is equal x. Additional space: O(height of the tree). It is not allowed to modify the tree
*/

# include<stdio.h>
# include<stdlib.h>

typedef struct node {
		int data;
		struct node *left, *right;
}node;

typedef struct stack {
		node* arr[100];
		int top;
}stack;

void init(stack* s) {
		s->top = -1;
}

int isEmpty(stack* s) {
		if(s->top == -1)
				return 1;
		return 0;
}

void push(stack* s, node* n) {
		s->arr[++(s->top)] = n;
}

node* pop(stack* s) {
		return s->arr[(s->top)--];
}

int peek(stack* s) {
		return s->arr[s->top]->data;
}

node* getNode(int x) {
		node* temp;
		temp = (node*)malloc(sizeof(node));
		temp->data = x;
		temp->left = temp->right = NULL;
		return temp;
}

node* createBST(node* root) {
		root = getNode(4);
		root->left = getNode(2);
		root->right = getNode(6);
		root->left->left = getNode(1);
		root->left->right = getNode(3);
		root->right->left = getNode(5);
		root->right->right = getNode(7);
		return root;
}

void printBST_Inorder(node* root) {
		if(root == NULL)
				return;
		printBST_Inorder(root->left);
		printf(" %d ", root->data);
		printBST_Inorder(root->right);
}

void printPairOfNodesWithSum(node* root, int sum) {
		stack leftStack, rightStack;
		node* ptr;
		int leftData, rightData;

		init(&leftStack); init(&rightStack);

		ptr = root;
		while(ptr != NULL) {
				push(&leftStack, ptr);
				ptr = ptr->left;
		}

		ptr = root;
		while(ptr != NULL) {
				push(&rightStack, ptr);
				ptr = ptr->right;
		}

		do {
				leftData = peek(&leftStack);
				rightData = peek(&rightStack);
				if(leftData + rightData == sum) {
						printf("%d + %d = %d", leftData, rightData, sum);
						return;
				}
				if (leftData + rightData < sum) {
						if(isEmpty(&leftStack)) {
								printf("No Pair of Nodes\n");
								return;
						}
						ptr = pop(&leftStack);
						ptr = ptr->right;
						while(ptr != NULL) {
								push(&leftStack, ptr);
								ptr = ptr->left;
						}
				} else {
						if(isEmpty(&rightStack)) {
								printf("No Pair of Nodes\n");
								return;
						}
						ptr = pop(&rightStack);
						ptr = ptr->left;
						while(ptr != NULL) {
								push(&rightStack, ptr);
								ptr = ptr->right;
						}
				}
		} while (leftData <= rightData);
}

void main() {
		node* root;
		int sum = 8;
		root = createBST(root);
		printBST_Inorder(root);
		printf("\n");
		printPairOfNodesWithSum(root, sum);
}
