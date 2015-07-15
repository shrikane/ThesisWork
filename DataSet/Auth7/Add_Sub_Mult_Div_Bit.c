# include <stdio.h>

static int remainder=0, a = 10, b = 2;

int add (int a, int b) {
    if (b == 0) return a;
	int sum = a ^ b; // add without carrying
	int carry = (a & b) << 1; 
	return add(sum, carry); // recurse 
} 

int sub (int x, int y) {
	return(add(x,add(~y,1))); 
} 

int multiply (int a, int b) {
	int m = 0; 
	while (a) {
		if (a&1)
			m = add(m, b); 
		a>>=1;
		b<<=1;
	} 
	return m; 
}

int division (int tdividend, int tdivisor) { 
	int quotient = 1;
	if (tdivisor == tdividend) {
		remainder = 0;
		return 1;
	} else if (tdividend < tdivisor) {
		remainder = tdividend; 
		return 0; 
	} 
 
	/* Here divisor < dividend, therefore left shift (multiply by 2) divisor and quotient */
	while (tdivisor <= tdividend) {
		tdivisor = tdivisor << 1;
		quotient = quotient << 1; 
	} 

	/* We have reached the point where divisor > dividend, therefore divide divisor and quotient by two */
	tdivisor = tdivisor >> 1;
	quotient = quotient >> 1;
 
	/* Call division recursively for the difference to get the exact quotient */
	quotient = add(quotient, division(sub(tdividend, tdivisor), b));
 
	return quotient;
}
 
/* Division of two numbers without using division operator */
int main()
{
    printf("\n%d + %d: addition = %d", a, b, add(a,b));
    printf("\n%d - %d: subtraction = %d", a, b, sub(a,b));
    printf("\n%d x %d: multiplication = %d", a, b, multiply(a,b));
	printf("\n%d / %d: quotient = %d, remainder = %d", a, b, division(a, b), remainder);
}