/*
Given an unordered array of positive integers, create an algorithm that makes sure no group of integers of size bigger than M have the same integers. 

Input: 2,1,1,1,3,4,4,4,5 M = 2 
Output: 2,1,1,3,1,4,4,5,4
 */

# include <stdio.h>

// extra space
// struct {num,count}
void reGroupStackHelper(int *a, int n, int M) {
		Stack s; // {struct [], top}
		int i, j, count, limit;
		for (i=1 ;i<=n ; i++) {
				if(i==0)
						count = 1;
				else if(i == n)
						push(s, a[i-1], count);
				else if(a[i] != a[i-1]) {
						push(s, a[i-1], count);
						count = 1;
				}
				else {
						count++;
				}
		}

		i = 0;
		while(i<n) {
				ele = pop(s);
				limit = (M < ele.count) ? M : ele.count;
				limit = (isEmpty(s)) ? ele.count : limit;
				j = 0;
				while(j < limit) {
						a[i++] = ele.num;
						j++;
				}
				if (ele.count > M && !isEmpty(s)) {
						ele1 = pop(s);
						a[i++] = ele1.num;
						push(s, ele1.num, ele1.count-1);
						push(s, ele.num, ele.count-M);
				}
		}
}

void reGroupStack(int *a, int n, int M) {
		reGroupStackHelper(a, n, M);
		reGroupStackHelper(a, n, M);
}


// no extra space
void swap(int* x, int* y) {
		int z;
		z = *x;
		*x = *y;
		*y = z;
}

void reGroupHelper(int* a, int n, int M, int step) {
		int i, j, count=1;
		i = (step == 1) ? 1 : n-2;
		while(i>=0 && i<n) {
				if(a[i] == a[i-step]) {
						count ++;
						if (count > M) {
								j = i + step;
								while(j>=0 && j<n) {
										if(a[i] != a[j])
												break;
										j += step;
								}
								if(j>=0 && j<n) {
										swap(&a[i], &a[j]);
								}
								count = 1;
						}
				} else {
						count = 1;
				}
				i += step;
		}
}

void reGroup(int *a, int n, int M) {
		reGroupHelper(a, n, M, 1);
		reGroupHelper(a, n, M, -1);
}

void main() {
		int a[100] = {2,1,1,1,3,4,4,4,5,5,5,5}, n=12, M=2, i;
		reGroup(a, n, M);
		for(i=0 ; i<n ; i++)
				printf("%d, ", a[i]);
		printf("\n");
}
