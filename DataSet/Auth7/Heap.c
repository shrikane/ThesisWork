# include <stdio.h>

# define MAX 100

void print(int* heap, int n) {
		int i;
		printf("Current heap(%d) = ", n);
		for (i = 0 ; i < n ; i++) {
				printf("%d ", heap[i]);
		}
		printf("\n");
}

void swap(int* a, int* b) {
		int c = *a;
		*a = *b;
		*b = c;
}

void downheap(int* heap, int parent, int n) {
		int left = 2 * parent + 1;
		int right = 2 * parent + 2;
		int largest = parent;
		if ((left < n) && (heap[left] > heap[largest]))
				largest = left;
		if ((right < n) && (heap[right] > heap[largest]))
				largest = right;
		if (parent != largest) {
				swap(&heap[parent], &heap[largest]);
				downheap(heap, largest, n);
		}
}

void heapify(int* heap, int n) {
		int i;
		for (i = n - 1 ; i >= 0 ; i--)
				downheap(heap, i, n);
}

void upheap(int* heap, int n) {
		int child = n;
		int parent = (child - 1) / 2;
		while (parent >= 0) {
				if (heap[parent] >= heap[child])
						break;
				swap(&heap[parent], &heap[child]);
				child = parent;
				parent = (child - 1) / 2;
		}
}

void insert(int* heap, int n, int new) {
		heap[n] = new;
		upheap(heap, n);
}

void delete(int* heap, int n) {
		swap(&heap[0], &heap[n-1]);
		downheap(heap, 0, n-1);
}

void heapsort(int* heap, int n) {
		int i;
		for (i = n - 1 ; i > 0 ; i--) {
				heapify(heap, i+1);
				swap(&heap[0], &heap[i]);				
		}
}

void main () {
		int heap[100];
		int n, i, new;
		printf("n = ");
		scanf("%d", &n);
		printf("Enter heap(%d) = ", n);
		for(i = 0 ; i < n ; i++) {
				scanf("%d",&heap[i]);
		}
		print(heap, n);
		heapify(heap, n);
		print(heap, n);
		printf("Insert = ");
		scanf("%d", &new);
		insert(heap, n++, new);
		print(heap, n);
		//delete(heap, n--);
		//print(heap, n);
		heapsort(heap, n);
		print(heap, n);
}
