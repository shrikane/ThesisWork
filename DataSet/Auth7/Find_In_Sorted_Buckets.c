/*
Array divided in buckkets: b0:{a[0]}, b1:{a[1],a[2]}, b2:{a[3],a[4],a[5]}, ...
any number in bi < any number in bj, where i < j
Find if number num is in the array
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define MAX 100

int findLinear(int* a, int n, int num) {
		int start = n*(n-1)/2;
		int i;
		for (i=0; i<n; i++)
				if(a[start+i] == num)
						return start+i;
		return -1;
}

int findBinary(int* a, int n, int num) {
		/* {m(m+1)/2 = n} -> {m^2 + m -2n = 0} -> m=(-1+(1+8n)^0.5)/2*/
		int m = ceil((float)((sqrt(1+8*n)-1)/2));
		int low=1, high=m, mid;
		int index;

		if (n < 1)
				return -1;

		while(low < high-1) {
				mid = (low+high)/2;
				index = (mid-1)*mid/2;
				if(a[index] == num)
						return index;
				if(num > a[index])
						low = mid;
				else
						high = mid;
		}

		index = findLinear(a,low, num);
		if(index != -1)
				return index;
		index = findLinear(a, high, num);
		if(index != -1)
				return index;
		return -1;
}

void main() {
		int a[MAX] = {0, 2,1, 5,4,3, 9,8,7,6, 11,10};
		int n = 12;
		int num = 5;
		int pos;
		pos = findBinary(a, n, num);
		if (pos != -1)
				printf("a[%d] = %d\n", pos, a[pos]);
		else
				printf("Not found\n");
}
