/*
Question is verbose, uses search engine, string matching etc., but at the end boils down to this: There is two dimensional array where each sub array (row) is sorted, i.e. [[1 1000 2000] [20 10001 5000] [55 10002 222222]] Find a minimum range contain a number from each row. For above array it should be (1000-1002) range.
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct Range{
		int start, end;
} Range;

int isInRange(Range r, int key) {
		if (r.start <= key && key <= r.end)
				return 1;
		return 0;
}
int binarySearch(Range *ranges, int n, int key) {
		int low = 0, mid, high = n-1;
		while(low + 1 < high) {
				mid = (low+high)/2;
				if(isInRange(ranges[mid], key))
						return mid;
				if(isInRange(ranges[low], key))
						return low;			   
				if(isInRange(ranges[high], key) || ranges[high].start <= key)
						return high;
				if (key < ranges[mid].start)
						high = mid;
				else if (ranges[mid].end < key)
						low = mid;
		}
		return low;
}

Range getMinRange(int a[3][3], int n) {
		Range *ranges = (Range*)malloc(sizeof(Range)*n);
		int i, j, k, index, minRangeIndex;

		for (j=0 ; j<n ; j++)
				ranges[j].start = ranges[j].end = a[0][j];
		// we will keep all these ranges sorted in start.

		for (i=1 ; i<n ; i++) {
				for (j=0 ; j<n ;j++) {
						index = binarySearch(ranges, n, a[i][j]);
						if (isInRange(ranges[index], a[i][j]))
								continue;
						else if ((index+1 < n) && (a[i][j] - ranges[index].end > ranges[index+1].start - a[i][j]))
								ranges[index+1].start = a[i][j];
						else
								ranges[index].end = a[i][j];
				}
		}

		minRangeIndex = 0;
		for (i=1 ; i<n ; i++)
				if(ranges[i].end - ranges[i].start < ranges[minRangeIndex].end - ranges[minRangeIndex].start)
						minRangeIndex = i;
		return ranges[minRangeIndex];
}

void main() {
		int a[3][3] = {{1, 1000, 2000},
					   {20, 1001, 5000},
					   {55, 1002, 22222}};
		Range r = getMinRange(a, 3);
		printf("%d - %d\n", r.start, r.end);
}
