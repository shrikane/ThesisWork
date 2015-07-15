/*
You are given a dictionary, in the form of a file that contains one word per line. E.g., 
abacus 
deltoid 
gaff 
giraffe 
microphone 
reef 
qar 
You are also given a collection of letters. E.g., {a, e, f, f, g, i, r, q}. 
The task is to find the longest word in the dictionary that can be spelled with the collection of 
letters. For example, the correct answer for the example values above is “giraffe”. (Note that 
“reef” is not a possible answer, because the set of letters contains only one “e”.)
*/

/*
we take an array of size=26 and initialize it by first 26 prime no. 
eg: 2 , 3, 5, 7,........ 
now these prime nos. will represent alphabet 
i.e a=2,b=3,c=5...... 
pro=a* e* f* f* g* r* q=2*11*13*13..... 

now we can check with every dictionary word 
1) p= product of every letter of a dictionary word 
eg: reef=61 * 11 * 11 * 13 
2) if pro % p == 0 
store l = length(word); and index // if l is greater than previous value 
3)finally index will give the result of location of word
*/

void initHash(char *letters, char *hash) {
	for (int i=0; i<26; i++)
		hash[i] = 0;
	i = 0;
	while(letters[i]!='\0')
		hash[letters[i]-'a']++;
}

void copy(char *hash, char *thash) {
	for (int i=0; i<26; i++)
		thash[i] = hash[i];
}

int match(char *word, char *hash) {
	int i=0;
	while(word[i]!='\0')
		if (hash[word[i]-'a']==0)
			return 0;
		hash[word[i]-'a']--;
	return 1;
}

char * findLongestWord(FILE *dict, char *letters, char *longestWord) {
	char hash[26];
	char thash[26];
	char word[15] = "";

	initHash(letters,hash);

	while(getWord(dict, word)) {
		copy(hash, thash);
		if(match(word, thash))
			if (strlen(word) > strlen(longestWord))
				strcpy(longestWord, word);
	}
}
