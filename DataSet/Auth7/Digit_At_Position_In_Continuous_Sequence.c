/*
Imagine you have a sequence of the form 0123456789101112131415... where each digit is in a position, for example the digit in the position 5 is 5, in the position 13 is 1, in the position 19 is 4, etc. 

Write a function that given a position returns the digit in that position. 

(You could think that this sequence is an array where each cell only holds one digit so given an index return what digit is in that index, however you cannot really create an array since the sequence is infinite, you need a way to based on the index calculate the digit that goes there). 

The function has to return a single digit. 

Other examples: 

index = 100, result = 5 
index = 30, result = 2 
index = 31, result = 0 
index = 1000, result = 3
*/
		
#include <stdio.h>
#include <stdlib.h>

int getMax(int number_of_digits) {
	 int max = 9;
	 while(number_of_digits > 1) {
		 max = max*10 + 9;
		 number_of_digits--;
	 }
	 return max;
}

int getDigitAtPosition(int position) {
	 int number_of_digits = 0;
	 int min, max = -1;
	 int span, number, digit;
	 char num[10];
	 int i;

	 while(1) {
		 number_of_digits++;
		 min = max + 1;
		 max = getMax(number_of_digits);
		 span = (max - min + 1) * number_of_digits;
		 if(span > position)
				 break;
		 position -= span;
	 }
	 number = min + position/number_of_digits;
	 digit = position % number_of_digits;
	 sprintf(num, "%d", number);
	 return num[digit] - '0';
}
void main() {
    int position = 1000;
	printf("%d\n", getDigitAtPosition(position));
}
