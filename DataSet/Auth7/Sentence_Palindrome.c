/*
Write a program which contains a class named String (please take care of the case). The class should be capable of 
holding a string containing more than one word. The class should at least have a parametric constructor by which we 
are going to supply a sentence at run time. The class should contain a member function ‘palindromecheck()’which 
reverses the words of the sentence in their proper original order. The class String should be user defined. You are free 
to add any other data members, member functions and constructors you think are necessary to solve the problem. 
Sample Run:- 
Enter sentence:- 
Mom…nothing can be better than you 
Output:- 
Sentence with reversed words is:- 
you than better be can nothing …moM 
Not Palindrome 
Sample Run:- 
Enter sentence:- 
wife loves husband,husband loves wife 
Output:- 
Sentence with reversed words is:- 
wife loves husband,husband loves wife. 
Palindrome 
You are free to add any C++ concepts, any other data members, member functions and constructors you think are 
necessary to solve the problem.
*/

#include<stdio.h>
#include<string.h>

int isStopLetter(char ch) {
		if (ch == ' ' || ch == '.' || ch == ',' || ch == '\0')
				return 1;
		return 0;
}
int isSentencePalindrome(char *str) {
		int i = 0, j = strlen(str)-1, k;
		while(1) {
				while(!isStopLetter(str[j]))
						j--;
				if (i >= j)
						break;
				k = j+1;
				while(!isStopLetter(str[i]) &&
					  !isStopLetter(str[k])) {
						if(str[i] != str[k])
								return 0;
						i++;
						k++;
				}
				if(!isStopLetter(str[i]) ||
				   !isStopLetter(str[k]))
						return 0;
				i++;
				j--;
		}
		return 1;
}

void main() {
		char str[100] = "wife loves husband means husband loves wife";
		if(isSentencePalindrome(str)) {
				printf("Yes\n");
		} else {
				printf("No\n");
		}		
}
