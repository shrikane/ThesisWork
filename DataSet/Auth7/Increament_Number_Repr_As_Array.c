/*
Add a number to array and if there is carry increase array size. 
---------------------------------------------------------------------- 
For example input = {7,3,5,3,9} convert this to number 73539, add 1 so it becomes 73540 and convert to array {7,3,5,4,0}. 
Array can be of any length, so you can't always represent array in form of in-built number format. So you have to do this summation in-place. Also, how would you increase array size in-case input = {9,9,9} so output = (1,0,0,0} 

Assume, all elements of arrays are between 0 and 9.
*/

# include <stdio.h>
# include <stdlib.h>

void print(int* a, int n) {
		int i;
		for (i=0 ; i<n ; i++)
				printf(" %d ", a[i]);		
		printf("\n");
}

int add(int* a, int n, int val) {
		int i;
		int sum, carry = 0;
		for(i=n-1 ; i>=0 ; i--) {
				sum = a[i] + (val%10) + carry;
				a[i] = sum % 10;
				carry = sum / 10;
				val = val / 10;
		}

		if(carry) {
				//a = (int*)realloc(a, (n)*sizeof(int));
				int* b = (int*) malloc((n+1)*sizeof(int));
				//(a+n) = (int*)malloc(sizeof(int));
				for(i=n-1 ; i>=0 ; i++)
						b[i+1] = a[i];
				b[0] = carry;
				n++;
				print(b,n);
				return n;
		}
		print(a,n);
		return n;
}

void main() {
		int* a = (int*)malloc(5*sizeof(int));
		a[0] = 9; a[1] = 9; a[2] = 9; a[3] = 9; a[4] = 9;
		int val = 11;
		int n = 5;

		//int n = add(a, 5, val);
		int i;
		int sum, carry = 0;
		for(i=n-1 ; i>=0 ; i--) {
				sum = a[i] + (val%10) + carry;
				a[i] = sum % 10;
				carry = sum / 10;
				val = val / 10;
		}

		if(carry) {
				a = (int*)realloc(a, (n)*sizeof(int));
				if(a == NULL) {
						free(a);
						printf("Cannot Allocate");
				} else {
				for(i=n-1 ; i>=0 ; i++)
						a[i+1] = a[i];
				a[0] = carry;
				n++;}
		}
		print(a,n);
}
