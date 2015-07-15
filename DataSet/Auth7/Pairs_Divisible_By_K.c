/*
Write a program to determine whether n/2 distintinctve pairs can be formed from given n integers where n is even and each pair's sum is divisible by given k. Numbers cannot be repeated in the pairs, that means only you can form total n/2 pairs.
*/

#include<stdio.h>

#define N 10

int isPairable(int* A, int K) {
		int i, count[K];
		if(K == 0)
				return 0;
		for(i=0 ; i<K ; i++)
				count[i] = 0;
		for(i=0 ; i<N; i++) {
				count[A[i]%K]++;
		}
		if(count[0] & 0x1)  // if (count[0] is odd)
				return 0;
		if(!(K & 0x1))      // if (K is not odd) i.e if (K is even)
				if(count[K/2] & 0x1)    // if (count[K/2] is odd)
						return 0;
		for(i=1; i<=K/2 ; i++)
				if(count[i] != count[K-i])
						return 0;
		return 1;
}

// binarySearch(int* A, int l, int u, int key)
// if found return index
// else -1
int isPairableWithoutExtraSpace(int* A, int K) {
		int i;
		for(i=0 ; i<N ; i++)
				A[i] = A[i] % K;
		for(i=0 ; i<N ; i+=2) {
				if(A[i] == 0)
						continue;
				ret = binarySearch(A, i+1, N-1, K-A[i]);
				if(ret == -1)
						return 0;
				swap(A[i+1], A[ret]);
		}
}

void main() {
		int A[N] = {0,1,2,3,4,5,6,7,8,9}, K = 4;
		if(isPairable(A, K))
				printf("Yes\n");
		else
				printf("No\n");
}
