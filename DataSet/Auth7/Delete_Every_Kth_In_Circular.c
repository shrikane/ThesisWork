/*
Given a circular single linked list.Write a program that deletes every kth node until only one node is left. 
After kth node is deleted, start the procedure from (k+1)th node. 
e.g.list is 1->2->3->4->5->1 
k=3 
1. You are at 1, delete 3. 
List is: 1->2->4->5->1 
2. You are at 4, delete 1 
List is: 2->4->5->2 
3. You are at 2,delete 5 
List is: 2->4->2 
4. You are at 2, delete 2 
List is: 4 
Return 4. 
*/

#include<stdio.h>
#include<stdlib.h>

#define N 5

typedef struct node {
		int data;
		struct node *next;
} node;

node* getNode(int x) {
		node* temp;
		temp = (node*) malloc(sizeof(node));
		temp->data = x;
		temp->next = NULL;
}

void printCircularList(node* head) {
		node* ptr;
		ptr = head;
		printf("List : ");
		if(head == NULL)
				return;
		do {
				printf(" %d ", ptr->data);
				ptr = ptr->next;
		} while(ptr!=head);
		printf("\n");
}

node* createCircularList(node* head, int n) {
		node* ptr = NULL;
		int i;
		for(i=1 ; i<=n ; i++) {
				if(head == NULL) {
						head = getNode(i);
						head->next = head;
						ptr = head;
				} else {
						node* tmp = getNode(i);
						tmp->next = ptr->next;
						ptr->next = tmp;
						ptr = tmp;
				}
		}
		return head;
}

void deleteNode(node* curr, node* prev) {
		prev->next = curr->next;
		curr->next = NULL;
		free(curr);
}

node* delete_kth(node* head, int K) {
		node *curr, *prev;
		int i;
		if(head == NULL || head->next == head)  // if 0 or 1 node present
				return head;

		prev = curr = head;
		while (prev->next != head) {
				prev = prev->next;
		}

		while(prev != curr) {
				for(i=1 ; i<K ; i++) {
						prev = curr;
						curr = curr->next;
				}
				deleteNode(curr, prev);
				curr = prev->next;
				printCircularList(curr);
		}
		return curr;
}

void main() {
		node* head = NULL;
		int K = 5;
		head = createCircularList(head, N);
		printCircularList(head);
		head = delete_kth(head, K);
}
