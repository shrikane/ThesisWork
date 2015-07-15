/*
Given a source string and a destination string write a program to display sequence of strings to travel from source to destination. Rules for traversing: 
1. You can only change one character at a time 
2. Any resulting word has to be a valid word from dictionary 
Example: Given source word CAT and destination word DOG , one of the valid sequence would be 
CAT -> COT -> DOT -> DOG 
Another valid sequence can be 
CAT -> COT - > COG -> DOG 

One character can change at one time and every resulting word has be a valid word from dictionary
*/
# include <stdio.h>
# include <string.h>

# define MAX 10

int isWord(char *word) {
		if (!strcmp(word,"A") || !strcmp(word,"B"))
				return 1;
		if (!strcmp(word,"MAT") || !strcmp(word,"CAT") || !strcmp(word,"COT") || !strcmp(word,"DOT") || !strcmp(word,"DOG"))
				return 1;
		return 0;
}

int printSeq(char *curr, char *dest) {
		char new[MAX] = "";
		int i = 0, len = strlen(dest);
		
		if (strlen(curr) != len)
				return 0;
		if (!strcmp(curr, dest)) {
				printf("%s",dest);
				return 1;
		}
		while (i < len) {
				if (curr[i] == dest[i]) {
						i++;
						continue;
				}
				strcpy(new, curr);
				new[i] = dest[i];
				if (isWord(new) && printSeq(new, dest)) {
						printf("\n%s", curr);
						return 1;
				}
				i++;
		}
		return 0;
}

void main() {
		char curr[MAX] = "CAT", dest[MAX] = "DOG";
		if(!printSeq(curr, dest))
				printf("\nNot Possible\n");
}
