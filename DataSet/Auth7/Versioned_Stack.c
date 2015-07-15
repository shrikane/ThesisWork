/*
You need to implement a versioned stack, i.e. version of stack will increment after each push/pop. Apart from push/pop, implement a method print(n) which would print stack state corresponding to version 'n'. For example: 
-> initially stack is empty. 
-> Version 1: 11 is pushed 
-> Version 2: 8 is pushed 
-> version 3: pop. only 11 left 
-> Version 4: 15 is pushed 
.... 
And so on. 

Print(n) should print state at version 'n'. 

Here 1 should print 11, 2 should print 8, 11... 

All methods should be as efficient as possible.
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *version_array[10] = {0};
int version = 0;

void push(int ele)
{
	struct node *new_node =(struct node *)malloc(sizeof(struct node));
	new_node->data = ele;
	new_node->next = version_array[version];
	version_array[++version] = new_node;
}

int pop(void)
{
	struct node *temp = version_array[version];
	if(temp){
		int v = temp->data;		
		temp = temp->next;
		version_array[++version]= temp;
		return v;
	}else{
		puts("UnderFlow");
		exit(1);
	}
}

void print(int n)
{
	if(n > version || n < 0)
		puts("Version Not Exist");
	else{
		struct node *top = version_array[n];
		while(top){
			printf("%d\t",top->data);
			top = top->next;
		}
	}
}

int main()
{
	int v;	
	push(11);
	push(8);
	v = pop(); printf("%d ",v);
	push(5);
	v = pop(); printf("%d ",v);
	v = pop(); printf("%d ",v);
	puts("");
	print(3);
	puts("");
	print(2);
	puts("");
	print(5);
	return 0;
}
