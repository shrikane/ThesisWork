#include<stdio.h>
#include<string.h>

// Better
function match_internal(s1, s2, s1Index, s2Index){
  if(s1Index==s1.length && s2Index==s2.length)
    return true;
  while(s2[s2Index]!='*' && s2[s2Index]!='?' && s1Index < s1.length && s2Index < s2.length){
    if(s1[s1Index]!=s2[s2Index])
      return false;
    s1Index++;
    s2Index++;
  }
  if(s2[s2Index]=='?')
    return match_internal(s1, s2, s1Index, s2Index+1) || match_internal(s1,s2,s1Index+1, s2Index+1);
  if(s2[s2Index]=='*'){
    var zeroMatch = match_internal(s1, s2, s1Index, s2Index+1);
    if(zeroMatch)
      return true;
    var match = false;  
    for(var i=s1Index+1; i<s1.length;i++){
      match = match || match_internal(s1, s2, i, s2Index+1);
    }
    return match;
  }  
}


int isMatch(char * str , char * pattern) {
		printf("You entered :: %s , %s\n",str,pattern);
		int i , j , k , l;
		char temp[100];
		int index[100];

		for(i=0 ; i<strlen(pattern) ; i++) {
				j = i;
				k = 0;
				while(pattern[j] != '*' && pattern[j] != '\0' && pattern[j] != 0)
						temp[k++] = pattern[j++];
				temp[k] == '\0';

				index[l++] = strstr(str,temp) - str;

				printf("%s(%d , %d) , ",temp , strstr(str,temp) , str);

				i=j;
		}
		for (i=0 ; i<l ; i++)
				printf ("%d , ", index[i]);
		printf("\n");

		return 0;
}

int main() {
		int flagMatch = 0;
		char str[100];
		char pattern[100];
		printf("String :: ");
		scanf("\n%s",str);
		printf("Pattern :: ");
		scanf("\n%s",pattern);
		flagMatch = isMatch(str , pattern);
		return 0;
}
