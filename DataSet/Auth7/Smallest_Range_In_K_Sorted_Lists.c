/*
You have k lists of sorted integers. Find the smallest range that includes at least one number from each of the k lists. 

For example, 
List 1: [4, 10, 15, 24, 26] 
List 2: [0, 9, 12, 20] 
List 3: [5, 18, 22, 30] 

The smallest range here would be [20, 24] as it contains 24 from list 1, 20 from list 2, and 22 from list 3.
*/

# include <stdio.h>

void swap(int *x, int *y) {
		*x = (*x) + (*y);
		*y = (*x) - (*y);
		*x = (*x) - (*y);
}

void sort(int *heap, char *index) {
		int i, j;
		for (i=0; i<3; i++)
				for (j=0; j<3-i-1; j++) {
						printf("%d, %d, %d\n",index[0],index[1],index[2]);
						if (heap[j] > heap[j+1]) {
								swap(&heap[j], &heap[j+1]);
								swap(&index[j], &index[j+1]);
						}
				}
}

void findRange(int *a, int alen, int *b, int blen, int *c, int clen) {
		int ai=1, bi=1, ci=1, range = 9999;
		int heap[3] = {a[0], b[0], c[0]};
		int index[3] = {1,2,3};

		while (ai<alen && bi<blen && ci<clen) {
				sort(heap, index);
				if (range > (heap[2] - heap[0]))
						range = heap[2] - heap[0];
				switch(index[0]) {
				case 1: {
						heap[0] = a[ai++];
						break;
				}
				case 2: {
						heap[0] = b[bi++];
						break;
				}
				case 3: {
						heap[0] = c[ci++];
						break;
				}
				}
		}
		printf("%d\n", range);
}
void main() {
		int a[5] = {4, 10, 15, 24, 26}, b[4] = {0, 9, 12, 20}, c[4] = {5, 18, 22, 30};
		findRange(a,5,b,4,c,4);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LIST_LEN 256
#define MAX_K 128

struct LinkNode{
	int _data;
	struct LinkNode *_next;
};

struct MinHeap{
	struct LinkNode *_min_heap[MAX_K+1];
	int _k;
	int _max;
};

void MinHeapInit(MinHeap &MH) {
	MH._k = 0;
}

void MinHeapPush(MinHeap &MH, struct LinkNode *node) {
	MH._k++;	
	int parent;
	int cur = MH._k;
	MH._min_heap[cur] = node;

	while( parent = cur / 2 ) {
		if (node->_data >= MH._min_heap[parent]->_data) {
			break;
		}
		MH._min_heap[cur] = MH._min_heap[parent];
		cur = parent;
	}
	MH._min_heap[cur] = node;
	return;	
}


void MinHeapAdjust(MinHeap &MH) {
	if (MH._k < 1) {
		return;
	}
	int cur = 1;
	struct LinkNode *cur_node = MH._min_heap[1];

	while (cur*2 <= MH._k) {
		int left = cur*2;
		int right = left + 1;
		int min = left;
		if (right <= MH._k && MH._min_heap[left]->_data >= MH._min_heap[right]->_data) {
			min = right;
		}
		if (MH._min_heap[cur]->_data > MH._min_heap[min]->_data) {
			MH._min_heap[cur] = MH._min_heap[min];
			cur = min;
		} else
			break;
	}
	MH._min_heap[cur] = cur_node;
}

void MinRangeOfKList(struct LinkNode *lists[MAX_K], int k) {
	struct MinHeap mh;
	if (k < 1) {
		return;
	}
	MinHeapInit(mh);
	// init min heap
	int max = lists[0]->_data;
	int min_range;
	for (int i = 0; i < k ;i++) {
		assert(lists[i]);
		MinHeapPush(mh, lists[i]);
		if (lists[i]->_data > max) {
			max = lists[i]->_data;
		}
	}
	mh._max = max;
	min_range = max - mh._min_heap[1]->_data;

	// loop pop 
	struct LinkNode *node;
	int range;
	while (node = mh._min_heap[1]->_next) {
		mh._min_heap[1] = node;
		if (node->_data > mh._max)
			mh._max = node->_data;
		MinHeapAdjust(mh);
		range = mh._max - mh._min_heap[1]->_data;
		if (min_range > range) {
			min_range = range;
			max = mh._max;
		}
	}	
	printf("minimum range is [%d,%d]\n", max - min_range, max);
}

int main(int argc, char *argv[]) {
	const int K = 1;
	struct LinkNode *lists[K];
	for (int i = 0; i < K; i++) {
		struct LinkNode **ptr = &lists[i];
		int N;
		while (scanf("%d", &N)) {
			if (N == -1) break;
			*ptr = (struct LinkNode *)malloc(sizeof(LinkNode));
			(*ptr)->_data = N;
			ptr = &(*ptr)->_next;
			*ptr = NULL;
		}
	}
	MinRangeOfKList(lists, K);
	for (int i = 0; i < K; i++) {
		struct LinkNode *cur = lists[i];
		struct LinkNode *saved = cur;
		while (cur) {
			saved = cur->_next;
			free(cur);
			cur = saved;
		}
	}
	return 0;
}
*/
