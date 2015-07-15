/*
Given a matrix of letters and a word, check if the word is present in the matrix. E,g., suppose matrix is: 
a b c d e f 
z n a b c f 
f g f a b c 
and given word is fnz, it is present. However, gng is not since you would be repeating g twice. 
You can move in all the 8 directions around an element.
*/

# include <stdio.h>

# define MAX 10

typedef struct coord {
		int row, col;
} coord;

typedef struct occur {
		coord c[MAX];
		int size;
} occur;

void initHash(occur* hash) {
		int i;
		for (i=0 ; i<26 ; i++) {
				hash[i].size = 0;
		}
}

void add(occur* hash, char ch, int i, int j) {
		int size = hash[ch-'a'].size;
		hash[ch-'a'].c[size].row = i;
		hash[ch-'a'].c[size].col = j;
		hash[ch-'a'].size++;
}

void fillHash(char mat[][6], int m, int n, occur* hash) {
		int i, j;
		char ch;

		initHash(hash);

		for(i=0 ; i<m ; i++)
				for (j=0 ; j<n ; j++)
						add(hash, mat[i][j], i, j);		
}

int isNeighbor(coord x, coord y) {
		if((abs(x.row-y.row) <= 1) && (abs(x.col-y.col) <= 1))
				return 1;
		return 0;
}

int isWordPresentHelper(occur* hash, char* word, int i, coord prev) {
		int j, ret=0;
		char ch;

		if(word[i] == '\0')
				return 1;

		ch = word[i] - 'a';
		for (j=0 ; j<hash[ch].size ; j++) {
				if (i==0 || isNeighbor(prev, hash[ch].c[j]))
						ret |= isWordPresentHelper(hash, word, i+1, hash[ch].c[j]);
		}
		printf("ch=%c, size=%d, ret=%d\n", word[i], hash[ch].size, ret);
		return ret;
}

int isWordPresent(char mat[][6], int m, int n, char *word) {
		occur hash[26];
		coord prev;
		fillHash(mat, m, n, hash);
		return isWordPresentHelper(hash, word, 0, prev);
}
void main() {
		char mat[3][6] = {"abcdef",
						  "znabcf",
						  "fgfabc"};
		char word[10] = "fnz";
		if(isWordPresent(mat, 3, 6, word))
				printf("Present\n");		
}
