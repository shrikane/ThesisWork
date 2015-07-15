/*
Rearrange an array using swap with 0. 

You have two arrays src, tgt, containing two permutations of the numbers 0..n-1. You would like to rearrange src so that it equals tgt. The only allowed operations is “swap a number with 0”, e.g. {1,0,2,3} -> {1,3,2,0} (“swap 3 with 0”). Write a program that prints to stdout the list of required operations. 

Practical application: 

Imagine you have a parking place with n slots and n-1 cars numbered from 1..n-1. The free slot is represented by 0 in the problem. If you want to rearrange the cars, you can only move one car at a time into the empty slot, which is equivalent to “swap a number with 0”. 

Example: 
src={1,0,2,3}; tgt={0,2,3,1};
*/

# include <stdio.h>

#define N 4

void print(int* a) {
		int i;
		printf("{");
		for(i=0; i<N; i++)
				printf("%d, ", a[i]);
		printf("}\n");
}
int findIndex(int* a, int x) {
		int i;
		for(i=0; i<N; i++) {
				if(a[i]==x)
						return i;
		}
}

void swapAtIndex(int* a, int i, int zeroIndex) {
		a[zeroIndex] = a[i];
		a[i] = 0;
}

void main() {
		int src[] = {1,0,2,3};
		int tgt[] = {0,2,3,1};
		int indexInSrc, indexOfZeroInSrc, i;

		for (i=0; i<N; i++) {
				if(tgt[i]!=0 && tgt[i]!=src[i]) {
						indexOfZeroInSrc = findIndex(src, 0);
						swapAtIndex(src, i, indexOfZeroInSrc);
						print(src);
						indexInSrc = findIndex(src, tgt[i]);
						swapAtIndex(src, indexInSrc, i);
						print(src);
						printf("\n");
				}
		}
}
