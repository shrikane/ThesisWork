/*
Suppose that we have a sorted singly linked list with integer values. For example:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
We want to change the pointers of this linked list so that it becomes:
7->1->6->2->5->3->4

I did not have enough time left to finish my code and I could not think of a good solution.
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct node {
		int val;
		struct node *next;
}node;

node * getnode(int val) {
		node * temp;
		temp = (node *)malloc(sizeof(node *));
		temp->val = val;
		temp->next = NULL;
		return temp;
}

node * createlist(node *head, int n) {
		int i;
		node *p, * temp;
		for (i=n ; i>=1 ; i--) {
				if(!head) {
						head = getnode(i);
						p = head;
				}
				else {
						temp = getnode(i);
						p->next = temp;
						p = temp;
				}
		}
		return head;
}

void print(node * head) {
		node *p = head;
		while(p){
				printf("%d ",p->val);
				p = p->next;
		}
		printf("\n");
}

node * mixlist(node *head) {
		node *start=NULL, *prestart=NULL, *end=NULL, *preend=NULL;

		if(!head)
				return NULL;

		start = head;
		end = head;

		while(end->next)
				end = end->next;

		head = end;

		//while(start && end && (start->val < end->val)) { OR
		while (start && end && start != end) {
				preend = start;
				while(preend->next != end)
						preend = preend->next;
				preend->next = NULL;
				end->next = start;
				if (prestart)
						prestart->next = end;
				prestart = start;
				start = start->next;
				end = preend;
		}

		return head;
}

void main () {
		node *head = NULL;
		head = createlist(head, 10);
		print(head);
		head = mixlist(head);
		print(head);
}
