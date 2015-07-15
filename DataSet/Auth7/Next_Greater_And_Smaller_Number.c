#include <stdio.h>
#include <string.h>

void swap(char* x, char* y) {
    char z = *x;
    *x = *y;
    *y = z;
}

void reverse(char* s, int start, int end) {
    while (start < end) {
        swap(&s[start], &s[end]);
        start++;
        end--;
    }
}

/*
From right to left,
1st digit s.t. left > right,
select left,
find digit in (left+1)-to-end, just less than left,
swap left and digit,
(sort) i.e. reverse (as already in order) (left+1)-to-end.
*/
void nextSmaller(char* num) {
    int breakIndex = strlen(num) - 2, i, maxIndex;
    while(breakIndex >= 0) {
        if (num[breakIndex] > num[breakIndex+1])
            break;
        breakIndex--;
    }
    
    if (breakIndex < 0)
        return;
    
    maxIndex = breakIndex+1;
    for (i=breakIndex+1 ; i<strlen(num) ; i++) {
        if (num[i] < num[breakIndex] && num[i] > num[maxIndex])
            maxIndex = i;
    }
    
    swap(&num[maxIndex], &num[breakIndex]);
    
    reverse(num, breakIndex+1, strlen(num)-1);
}

/*
From right to left,
1st digit s.t. left < right,
select left,
find digit in (left+1)-to-end, just greater than left,
swap left and digit,
(sort) i.e. reverse (as already in order) (left+1)-to-end.
*/
void nextGreater(char* num) {
    int breakIndex = strlen(num) - 2, i, minIndex;
    while(breakIndex >= 0) {
        if (num[breakIndex] < num[breakIndex+1])
            break;
        breakIndex--;
    }
    
    if (breakIndex < 0)
        return;
    
    minIndex = breakIndex+1;
    for (i=breakIndex+1 ; i<strlen(num) ; i++) {
        if (num[i] < num[breakIndex] && num[i] < num[minIndex])
            minIndex = i;
    }
    
    swap(&num[minIndex], &num[breakIndex]);
    
    reverse(num, breakIndex+1, strlen(num)-1);
}

main()
{
    char num[100] = "13625", smaller[100], greater[100];
    printf("\nNumber: %s", num);
    strcpy(smaller, num);
    nextSmaller(smaller);
    printf("\nSmaller: %s", smaller);
    strcpy(greater, num);
    nextGreater(greater);
    printf("\nGreater: %s", greater);
}
