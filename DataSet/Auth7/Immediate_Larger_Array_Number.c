/*
From the set of natural integer numbers 
Let x = 1234 = {1, 2, 3, 4} 
Let y = 2410 = {2, 4, 1, 0} 

Write an algorithm to compute the rearrangement of x that is closest to y but still greater than y. Both x and y have the same number of digits. 

So in the example above, the answer would be { 2, 4, 1, 3 } = 2413 which is greater than y = 2410 and closer than any other arrangements of x. 

And whats the time complexity of this algorithm?
*/

#include<stdio.h>

#define N 4

void print(int* X) {
		int i;
		for(i=0 ; i<N ; i++)
				printf(" %d ", X[i]);
		printf("\n");
}

void swap(int*x, int* y) {
		int z;
		z = *x;
		*x = *y;
		*y = z;
}

void countSort(int* X) {
		int count[10] = {0};
		int i, j;
		for(i=0 ; i<N ; i++)
				count[X[i]]++;
		for(j=0,i=0 ; j<10 ; j++)
				while(count[j]--)
						X[i++] = j;
}

int rearrange(int* X, int* Y) {
		if(X[N-1] < Y[0])
				return 0;

		int i=0, j=1, k=0;
		while(i<N && j<N && k<N) {
				if(X[i] == Y[k]) {
						i++;
						k++;
				} else if (X[i] < Y[k]) {
						swap(&X[i], &X[j]);
						j++;
				} else
						break;
		}
		if(i==N && k==N)
				return 1;
		return 0;
}

void main() {
		int X[4] = {1,2,0,4};
		int Y[4] = {2,4,1,3};
		countSort(X);
		if(rearrange(X, Y))
				printf("Rearranged\n");
		print(X);
}
