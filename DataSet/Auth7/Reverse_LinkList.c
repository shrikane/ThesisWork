#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
		int data;
		struct node_t * next;
}node;

node * getnode(int num) {
		node * temp;
		temp = (node *)malloc(sizeof(node));
		temp->data = num;
		temp->next = NULL;
		return temp;
}

node * populate(node *head, int n) {
		node *ptr, *temp;
		int i;

		for(i=1;i<=n;i++) {
				if(!head){
						head = getnode(i);
						ptr = head;
				}
				else {
						temp = getnode(i);
						ptr->next = temp;
						ptr = temp;
				}
		}
		return head;
}

void print(node *head) {
		node *temp = head;
		while(temp) {
				printf("%d ",temp->data);
				temp = temp->next;
		}
		printf("\n");
}

node * reverse(node *head) {
		node *p, *q, *r;

		p = head;
		r = NULL;

		while(p) {
				q = p->next;
				p->next = r;
				r = p;
				p = q;
		}
		return r;
}

node * partialreverse(node *head, int partsize) {
		node *p, *q, *r, *last, *first;
		int i, flag = 0;

		p = head;
		r = NULL;

		while(p) {
				i=0;
				last = r;
				first = p;
				r = NULL;
				while((i<partsize) && p) {
						q = p->next;
						p->next = r;
						r = p;
						p = q;
						i++;
				}

				if (!flag) {
						flag = 1;
						head = r;
				}
				else
						last->next = r;

				first->next = p;
				r = first;
		}

		return head;
}

node * krevmtrav(node *head, int k, int m) {
		int kcount, mcount, flag = 0;
		node *p, *q, *r, *first, *last;

		p = head;
		r = NULL;

		while (p) {
				kcount = 0;
				first = p;
				last = r;
				r = NULL;
				while((kcount<k) && p) {
						q = p->next;
						p->next = r;
						r = p;
						p = q;
						kcount++;
				}

				if (!flag){
						head = r;
						flag = 1;
				}
				else
						last->next = r;

				first->next = p;
				r = first;

				mcount = 0;
				while ((mcount<m) && (p != NULL)) {
						p = p->next;
						r = r->next;
						mcount++;
				}
		}

		return head;
}

void main() {
		node *head;
		
		head = populate(head,11);

		print(head);

		//head = reverse(head);
		//head = partialreverse(head, 3);
		head = krevmtrav(head,3,1);

		print(head);
}
