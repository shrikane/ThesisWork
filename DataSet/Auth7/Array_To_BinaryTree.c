# include <stdio.h>
# include <stdlib.h>

# define MAX 100

typedef struct node {
		int data;
		struct node *left, *right;
} node;

node* getNode(int val) {
		node* p = (node*)malloc(sizeof(node));
		p->data = val;
		p->left = NULL;
		p->right = NULL;
		return p;
}

typedef struct queue {
		node* q[MAX];
		int front;
		int back;
} queue;

void printQ(queue Q) {
		int i = Q.front;
		printf("\n%d, %d, ", Q.front, Q.back);
		while(i<Q.back) {
				printf("%d ", Q.q[i]->data);
				i++;
		}
}

void initQ(queue Q) {
		Q.front = 0;
		Q.back = 0;
		printQ(Q);
}

int isEmpty(queue Q) {
		if ((Q.front+1)%MAX == Q.back)
				return 1;
		return 0;
}

int isFull(queue Q) {
		if (Q.front == Q.back)
				return 1;
		return 0;
		
}

void enqueue(queue Q, node* val) {
		Q.q[Q.back] = val;
		Q.back = (Q.back + 1) % MAX;
}

node* dequeue(queue Q) {	
		node* val = Q.q[Q.front];
		Q.front = (Q.front + 1) % MAX;
		return val;
}


node* buildTree(int* arr, int n, node* root) {
		int i;
		node* p;
		queue Q;

		initQ(Q);
		printQ(Q);
		if (n<1)
				return NULL;
		root = getNode(arr[0]);
		enqueue(Q, root);
		printQ(Q);
		i = 1;
		while(i<n) {
				p = dequeue(Q);
				p->left = getNode(arr[i]);
				enqueue(Q, p->left);
				if(i+1 < n) {
						p->right = getNode(arr[i+1]);
						enqueue(Q, p->right);
				}
				i = i+2;
		}
		return root;
}

void main() {
		node* root;
		int arr[10] = {1,2,3,4,5,6,7,8,9};
		int n=1;
		root = buildTree(arr, n, root);
}
