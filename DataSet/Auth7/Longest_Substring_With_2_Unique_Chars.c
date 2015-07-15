/*
Given a string.Find the longest substring in it such that the substring contains only 2 unique characters.Ex- aabbcbbbadef Ans-bbcbbb
*/

# include <stdio.h>
# include <string.h>

void longestSubstr2UniqueChar(char * str) {
		char ch[2] = {str[0], '\0'};
		int i;
		int start[2] = {0,-1}, end[2] = {0, -1};
		int curr_start = 0, curr_end = 0, ans_start = 0, ans_end = 0;

		for (i=1 ; str[i]!='\0' ; i++) {
				if (ch[1] == '\0') {
						if (str[i] == ch[0]) {
								end[0] = curr_end = i;
						}
						else if (str[i] != ch[0]) {
								ch[1] = str[i];
								start[1] = end[1] = curr_end = i;
						}
				}
				else {
						if (str[i] == ch[0]) {
								ch[0] = ch[1];
								start[0] = start[1];
								end[0] = end[1];
								ch[1] = str[i];
								start[1] = end[0] + 1;
								end[1] = curr_end = i;
						}
						else if (str[i] == ch[1]) {
								end[1] = curr_end = i;
						}
						else {
								ch[0] = ch[1];
								start[0] = end[0] + 1;
								end[0] = end[1];
								ch[1] = str[i];
								start[1] = end[1] = curr_end = i;
								curr_start = start[0];
						}
				}
				if (curr_end - curr_start > ans_end - ans_start) {
						ans_start = curr_start;
						ans_end = curr_end;
				}
		}

		for (i=ans_start ; i<=ans_end ; i++)
				printf("%c",str[i]);
		printf("\n");
}

void main() {
		char s[20] = "aabbaaaaccaa";
		longestSubstr2UniqueChar(s);
}
