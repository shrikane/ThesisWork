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
Good Approach

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

#include<iostream>
using namespace std;

char *get_longest_str(char *set, char *str[], int n) {
	int set_len = strlen(set);
	int hash[26];
	int i, j;
	int final_len = 0;
	int temp_len = 0;
	char *ret = NULL;
	for(i = 0; i < n; i++) {
		memset(hash, 0, sizeof(int) * 26);
		for(j = 0; j < set_len; j++)
			hash[set[j] - 'a']++;
		temp_len = strlen(str[i]);
		for(j = 0; j < temp_len; j++)
			hash[str[i][j] - 'a']--;
		for(j = 0; j < 26; j++) {
			if(hash[j] < 0)
				break;
		}
		if(j >= 26) {
			if(temp_len > final_len) {
				final_len = temp_len;
				ret = str[i];
			}
		}
	}
	return ret;
}

int main(int argc, char *argv[]) {
	char *str[] = {"abacus", "deltoid", "gaff", "giraffe", "microphone", "reef", "qar"};
	char set[] = {'a', 'e', 'f', 'f', 'g', 'i', 'r', 'q'};
	int n = sizeof(str) / sizeof(char*);
	char *ret = get_longest_str(set, str, n);
	cout << ret << endl;
	cin.get();
	return 0;
}
