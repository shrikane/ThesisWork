/* Get string permutations */

/*
Given two strings .Print all the interleavings of the two strings. 
Interleaving means that the if B comes after A .It should also come after A in the interleaved string. 
ex- 
AB and CD 
ABCD 
ACBD 
ACDB 
CABD 
CADB 
CDAB
*/

#include <stdio.h>
#include <string.h>

void permute(char *fixcopy, char *dyncopy) {
		int i,j,dynlen = strlen(dyncopy),fixlen = strlen(fixcopy);
		char fix[10], dyn[10];
		if (dynlen == 0)
				printf("%s\n",fixcopy);
		for(i=0; i<dynlen; i++) {

				strcpy(dyn,dyncopy);
				strcpy(fix,fixcopy);

				fix[fixlen] = dyn[i];
				fix[fixlen+1] = '\0';

				for(j=i+1; j<=dynlen; j++)
						dyn[j-1] = dyn[j];

				permute(fix, dyn);				
		}

}

void allpermutations(char *rem, int remlen, char *sofar, int sofarlen) {
		char newrem[100];
		int i, j;

		if (remlen == 0) {
				printf("\n%s", sofar);
				return;
		}

		for (i=0; i<remlen; i++) {
				sofar[sofarlen] = rem[i];
				sofar[sofarlen + 1] = '\0';

				strcpy(newrem, rem);
				for (j=i+1; j<=remlen; j++)
						newrem[j-1] = rem[j];

				allpermutations(newrem, remlen-1, sofar, sofarlen+1);
		}
}

void interleavepermutations(char *a, int alen, char *b, int blen, char *sofar, int sofarlen) {
		int i, j;

		if (alen==0 && blen==0) {
				printf("\n%s", sofar);
				return;
		}

		if (alen==0) {
				for (i=0; i<=blen; i++)
						sofar[sofarlen+i] = b[i];
				printf("\n%s", sofar);
				return;
		}

		if (blen==0) {
				for (i=0; i<=alen; i++)
						sofar[sofarlen+i] = a[i];
				printf("\n%s", sofar);
				return;
		}

		sofar[sofarlen] = a[0];
		sofar[sofarlen+1] = '\0';
		interleavepermutations(&a[1], alen-1, b, blen, sofar, sofarlen+1);

		sofar[sofarlen] = b[0];
		sofar[sofarlen+1] = '\0';
		interleavepermutations(a, alen, &b[1], blen-1, sofar, sofarlen+1);
}

void swap(char *x, char* y) {
		char z;
		z = *x;
		*x = *y;
		*y = z;
}

void duplicatePermute(char* str, int i) {
		int j;
		char visited[256] = {0};
		if(str[i] == '\0') {
				printf("%s\n", str);
				return;
		}

		for(j=i; str[j]!='\0'; j++) {
				if(visited[str[j]])
						continue;
				swap(&str[i], &str[j]);
				duplicatePermute(str, i+1);
				swap(&str[i], &str[j]);
				visited[str[i]] = 1;
		}
}
void main(){
		char a[10]="aab", b[10]="cd", null[2]="";
		//permute(null, str);
		//allpermutations(a, strlen(a), null, 0);
		//interleavepermutations(a, strlen(a), b, strlen(b), null, 0);
		duplicatePermute(a,0);
}
