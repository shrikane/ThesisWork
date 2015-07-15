/*
Given a sequence of numbers A(1) ..A(n), find the continuous subsequenceA(i)..A(j) for which the sum of elements is maximum. 

condition: we should not select two contiguous numbers
*/

# include <stdio.h>

int max4(int a, int b, int c, int d)
{
    int temp = a>b?a:b;
    int temp1 = c>d?c:d;
    return temp>temp1?temp:temp1;
}
 
int main()
{
    int maxi=0,i;
    //int a[] = {1,3,5,-1,12,6,7,11};
	int a[] = {1,0,4,-3,2};
    
    for(i=2;i<sizeof(a)/sizeof(a[0]);i++){        
        a[i] = max4(a[i-2], a[i-1], a[i-2]+a[i], a[i]);
        //printf("%d\n", a[i]);
    }
    printf("%d\n", a[(sizeof(a)/sizeof(a[0]))-1]);
}

//-----------------------

#include<stdio.h>
 
/*Function to return max sum such that no two elements
 are adjacent */
int FindMaxSum(int arr[], int n)
{
  int incl = arr[0];
  int excl = 0;
  int excl_new;
  int i;
 
  for (i = 1; i < n; i++)
  {
     /* current max excluding i */
     excl_new = (incl > excl)? incl: excl;
 
     /* current max including i */
     incl = excl + arr[i];
     excl = excl_new;
  }
 
   /* return max of incl and excl */
   return ((incl > excl)? incl : excl);
}
 
/* Driver program to test above function */
int main()
{
  int arr[] = {5, 5, 10, 100, 10, 5};
  printf("%d \n", FindMaxSum(arr, 6));
  getchar();
  return 0;
}
