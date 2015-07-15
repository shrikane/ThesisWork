#include <stdio.h>

void print(int *a , int n) {
		int i;
		for (i=0; i<n ; i++)
				printf("%d ",a[i]);
		printf("\n");
}

void swap(int *x, int *y) {
		int temp;
		temp = *x;
		*x = *y;
		*y = temp;
}

void bubblesort(int *a, int n) {
		int i , j;
		for (i=0; i<n; i++)
				for (j=0 ; j<n-i-1 ; j++)
						if(a[j]>a[j+1])
								swap(&a[j],&a[j+1]);
}

void selectionsort(int *a , int n) {
		int i, j , minindex;
		for (i=0; i<n; i++) {
				minindex = i;
				for (j=i ; j<n ; j++)
						if (a[j] < a[minindex])
								minindex = j;
				swap(&a[i], &a[minindex]);
		}
}

void insertionsort(int *a , int n) {
		int i , j , current;
		for (i=1 ; i<n ; i++) {
				current = a[i];
				for (j=i-1 ; j>=0 && a[j]>current ; j--) {
						a[j+1] = a[j];
				}
				a[j+1] = current;
		}
}

void quicksort(int *a, int start, int end) {
		int i , j , pivot;
		if (start == end)
				return;

		pivot = a[start];
		i = start;
		j = end;
		while (i<=j && i<=end && j>=start) {
				if (a[i]>=pivot && a[j]<=pivot) {
						swap(&a[i] , &a[j]);
						i++;
						j--;
				}
				else if (a[i]<=pivot)
						i++;
				else if (a[j]>=pivot)
						j--;
		}
		if (j<end)
				quicksort(a, start , j);
		if (i>start)
				quicksort(a, i , end);
}

void shiftdown(int *a, int start, int end) {
		int root = start , child;
		while(root*2+1 <= end) {
				child = root*2+1;
				if((child+1 <= end) && a[child+1] > a[child])
						child++;
				if(a[root]<a[child]) {
						swap(&a[root] , &a[child]);
						root = child;
				}
				else
						return;
		}
}

void heapify(int *a , int n) {
		int start = (n-2)/2;
		while(start>=0)
				shiftdown(a,start--,n-1);
}

void heapsort(int *a , int n) {
		int end;
		heapify(a , n);
		end = n-1;
		while (end>=0) {
				swap(&a[end] , &a[0]);
				end--;
				shiftdown(a, 0, end);
		}
}

void merge(int *a, int start, int mid, int end) {
		int b[15],i,j,k;
		i=start;
		j=mid+1;
		k=0;
		while(i<=mid && j<=end) {
				if(a[i]<=a[j])
						b[k++] = a[i++];
				else
						b[k++] = a[j++];
		}
		while(i<=mid)
				b[k++] = a[i++];
		while(j<=end)
				b[k++] = a[j++];
		for(i=start,j=0 ; j<k ; i++,j++)
				a[i] = b[j];
}

void mergesort(int *a, int start, int end) {
		int mid = (start + end) / 2;

		if(start >= end)
				return;

		mergesort(a, start, mid);
		mergesort(a, mid+1, end);
		merge(a, start, mid, end);
}

void main() {
		int a[] = {-9,1,4,-5,6,2,-10};
		print(a,7);
		//bubblesort(a, 7);
		//selectionsort(a, 7);
		//insertionsort(a, 7);
		//quicksort(a, 0, 6);
		//heapsort(a , 7);
		mergesort(a, 0, 6);
		print(a, 7);
}
