/*
Given a char array color[]={'a','b','c','d','e','f'.......'z'}

and a random array arr[]= {'f','a','b','b','z','a','a','a'}

you need to sort them such that resultant array will be {'a','a','a','a','b','b','f','z'}.

Conditions:
1) You should use swap function.
2) Every element may repeat minimum 5 times and maximum 26 times.
3) 'a' can be swapped only 1 time, 'b' can be swapped max 2 times,'c' can be swapped 3 times ...... z can be swapped max 26 times.
4) You cannot make elements of given array to 0.
5) you should not write helper functions.

Input will be of 100 elements each.
*/

# include <stdio.h>

int rank[26];

void print(char *arr, int n) {
		int i;
		for (i=0 ; i<n ; i++)
				printf("%c ",arr[i]);
		printf("\n");
}

void swap(char *x, char *y) {
		char t;
		t = *x;
		*x = *y;
		*y = t;
}

void main () {
		char color[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		char arr[] = {'f','a','b','b','z','a','a','a'};
		int swaps[26] = {0};
		int i, j, minindex;

		for(i=0 ; i<26 ; i++)
				rank[color[i] - 'a'] = i;

		print(arr,8);

		for(i=0 ; i<8 ; i++) {
				minindex = i;
				for (j=i ; j<8 ; j++)
						if(rank[arr[j]-'a'] < rank[arr[minindex]-'a'])
								minindex = j;
				if (i != minindex) {
						swaps[arr[i]-'a']++;
						swaps[arr[minindex]-'a']++;
						swap(&arr[minindex],&arr[i]);
				}
		}

		print(arr, 8);

		for (i=0 ; i<26 ; i++)
				if(swaps[i])
						printf("%d ",swaps[i]);
		printf("\n");
}
