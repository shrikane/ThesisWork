/*
Given an equation in the form 2^i * 3^j * 5^k * 7^l where i,j,k,l >=0 are integers.write a program to generate numbers from that equation in sorted order efficiently. 

for example numbers from that equation will be in the order 2,3,5,6,7,8,9.....and so on..
*/

#include <stdio.h>
#include <malloc.h>
int min2(int a,int b)
{
	return (a<b?a:b);
}
int min4(int a,int b,int c,int d)
{
	return min2(a,min2(b,min2(c,d)));
}
void printAllMultiples(int n)
{
	unsigned *ugly=(unsigned *)malloc(sizeof(ugly));
	unsigned next_multiple_2=2;
	unsigned next_multiple_3=3;
	unsigned next_multiple_5=5;
	unsigned next_multiple_7=7;
	unsigned i2=0,i3=0,i5=0,i7=0;
	ugly[0]=1;
	unsigned next_ugly_no;
	int i;
	printf(" %d ",ugly[0]);
	for(i=1;i<n;i++)
	{
		next_ugly_no=min4(next_multiple_2,next_multiple_3,next_multiple_5,
						 next_multiple_7);
		ugly[i]=next_ugly_no;
		printf(" %d ",next_ugly_no);

		if(next_ugly_no==next_multiple_2)
		{
			i2=i2+1;
			next_multiple_2=ugly[i2]*2;
		}
		if(next_ugly_no==next_multiple_3)
		{
			i3=i3+1;
			next_multiple_3=ugly[i3]*3;
		}
		if(next_ugly_no==next_multiple_5)
		{
			i5=i5+1;
			next_multiple_5=ugly[i5]*5;
		}
		if(next_ugly_no==next_multiple_7)
		{
			i7=i7+1;
			next_multiple_7=ugly[i7]*7;
		}
	}
	
} 
int main()

{
	printAllMultiples(20);
}
