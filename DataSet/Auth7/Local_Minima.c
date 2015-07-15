/*
Given a sequence of numbers such that A[0] >= A[1] and A[N-1] >= A[N-2] find at-least one triplet such that A[n-1] >= A[n] <= A[n+1]. Better than linear time is expected. 

Example: 9 8 5 4 3 2 6 7 
Answer: 3 2 6
*/
#include <stdio.h>

void local_minima(int* a, int n) {
		int l=0, u=n-1;
		int m;
		while (l < u-1) {
				int m = (l+u)/2;
				if(a[m-1]>=a[m] && a[m]<=a[m+1]) {
						printf("a[%d]=%d, a[%d]=%d, a[%d]=%d\n", m-1, a[m-1], m, a[m], m+1, a[m+1]);
						return;
				}
				if(a[m-1]>=a[m] && a[m]>=a[m+1]) {
						l = m;
				} else {
						u = m;
				}
		}
		printf("No Minima\n");
}

void rec_local_minima(int* a, int l, int u) {
		if(!(l < u-1)) {
				printf("No Minima\n");
				return;
		}
		int m = (l+u)/2;
		if(a[m-1]>=a[m] && a[m]<=a[m+1]) {
				printf("a[%d]=%d, a[%d]=%d, a[%d]=%d\n", m-1, a[m-1], m, a[m], m+1, a[m+1]);
				return;
		} else if(a[m-1]>=a[m] && a[m]>=a[m+1]) {
				rec_local_minima(a, m, u);
		} else if(a[m-1]<=a[m] && a[m]<=a[m+1]){
				rec_local_minima(a, l, m);
		} else {
				rec_local_minima(a, l, m);
				rec_local_minima(a, m, u);
		}
}

void main() {
		int a[] = {9,10,11,12,3,2,6,7};
		local_minima(a, 8);
		rec_local_minima(a, 0, 7);
}
