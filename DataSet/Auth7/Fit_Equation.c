/*
Given a series of numbers as the input, the last one as the result. Use the rest numbers to calculate the result,only +, -, *, / are allowed. The order of the input cannot be changed. If there is an equation, print it; or print "no equation". If more than one solution, any working equation is fine. 

example: 
input: 2, 3, 1, 4 
output: 2+3-1 = 4.
*/

# include <stdio.h>

int operate(float x, float y, char op) {
		switch(op) {
		case '+' : return x+y;
		case '-' : return x-y;
		case '*' : return x*y;
		case '/' : return x/y;
		}
}

int fitequation(float *L, int n, int R, char *op) {
		float newL[4];
		int i;
		if(n==1) {
				if(L[0]==R)
						return 1;
				else
						return 0;
		}
		
		for (i=0; i<n-2; i++)
				newL[i] = L[i];

		for (i=0; i<4; i++) {			 
				int temp = L[n-2];
				//newL[n-2] = operate(L[n-2], L[n-1], op[i]);
				//if(fitequation(newL, n-1, R, op)) {
				L[n-2] = operate(L[n-2], L[n-1], op[i]);
				if(fitequation(L, n-1, R, op)) {
						L[n-2] = temp;
						printf("%.0f %c ",L[n-2], op[i], L[n-1]);
						return 1;
				}
				L[n-2] = temp;
		}
		return 0;
}

int fitNewEquation(float* L, int start, int end, int R, char* op) {
		int i;
		if (start==end) {
				if(L[start] == R)
						return 1;
				else
						return 0;
		}

		for (i=1 ; i<4 ; i++) {
				int temp = L[start+1];
				L[start+1] = operate(L[start], L[start+1], op[i]);
				if(fitNewEquation(L, start+1, end, R, op)) {
						L[start+1] = temp;
						printf("%.0f %c %.0f\n", L[start], op[i], L[start+1]);
						return 1;
				}
				L[start+1] = temp;
		}
		return 0;
}

void main() {
		float a[4] = {6,3,2,4};
		int n = 4;
		char op[4] = {'+', '-', '*', '/'};
		
		//if(fitequation(a,n-1,a[n-1],op))		
		if(fitNewEquation(a, 0, n-2, a[n-1], op))
				printf("%.0f = %.0f\n", a[n-2], a[n-1]);
		else
				printf("Not Possible\n");
}
