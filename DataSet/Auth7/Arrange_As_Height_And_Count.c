/*
You are given two array, first array contain integer which represent heights of persons and second array contain how many persons in front of him are standing who are greater than him in term of height and forming a queue. Ex 
A: 3 2 1 
B: 0 1 1 
It means in front of person of height 3 there is no person standing, person of height 2 there is one person in front of him who has greater height then he, similar to person of height 1. Your task to arrange them 
Ouput should be. 
3 1 2 
Here - 3 is at front, 1 has 3 in front ,2 has 1 and 3 in front.
*/

# include <stdio.h>

# define N 5

void print(int* height, int* count, int n) {
		int i;
		printf("\nHeight :\t");
		for(i=0; i<n; i++)
				printf("%d\t", height[i]);
		printf("\n Count :\t");
		for(i=0; i<n; i++) 
				printf("%d\t", count[i]);
		printf("\n");
}

void swap(int* x, int* y) {
		int z;
		z = *x;
		*x = *y;
		*y = z;
}

void desc_quick_sort(int* a, int* b, int n) {
		if(n<2)
				return;
		int pivot = 0;
		int start = 0, end = n-1;
		while(start <= end) {				
				while(a[start] > a[pivot])
						start++;
				while(a[end] < a[pivot])
						end--;
				if(start <= end) {
						swap(&a[start], &a[end]);
						swap(&b[start], &b[end]);
						start++;
						end--;
				}
		}
		desc_quick_sort(a, b, end);
		desc_quick_sort(&a[start], &b[start], n-start);
}

void arrange(int* height, int* count, int n) {
		int i, j, shiftCnt;

		desc_quick_sort(height, count, n);

		for (i=0; i<n; i++) {
				shiftCnt = i - count[i];
				for(j=i; shiftCnt>0; j--, shiftCnt--) {
						swap(&height[j], &height[j-1]);
						swap(&count[j], &count[j-1]);
				}
		}
}

void main() {
		int height[N] = {5,1,2,3,4};
		int count[N] = {1,3,2,0,0};
		arrange(height, count, N);
		print(height, count, N);
}
