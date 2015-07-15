/*
c = ‘a’ 
w = “apple” 
c covers w, iff w contains c. 
c_set = {‘a’, ‘b’, ‘c’, ‘g’} 
w_set = {‘apple’, ‘ibm’, ‘cisco’, ‘google’} 
c_set covers w_set, iff every w in w_set is covered by some c in c_set. 
Given c_set and w_set, Whether w_set is covered by c_set? 

Follow up: if w_set is fixed say a book, how to determine whether a c_set covers this w_set?
*/

# include <stdio.h>

#define N_C 4
#define N_W 4
#define MAX 10

void print(int bitImage) {
		int i;
		printf("\n");
		for(i=0 ; i<32 ; i++) {
				printf("%d ", bitImage & 0x1);
				bitImage >>= 1;
		}
}
int setBit(int bitPos) {
		return (1 << bitPos);
}

int getBitImage(char* str) {
		int j, bitImage=0;
		for(j=0 ; str[j]!='\0' ; j++)
				bitImage |= setBit(str[j] - 'a');
		return bitImage;
}

int isCovered(char* c_set, char w_set[][MAX]) {
		int i, c_bitImage, w_bitImage, isCoveredFlag = 1;
		c_bitImage = getBitImage(c_set);
		for(i=0 ; i<N_W ; i++) {
				w_bitImage = getBitImage(w_set[i]);
				if(w_bitImage & c_bitImage)
						printf("%s is covered\n", w_set[i]);
				else {
						printf("%s is not covered\n", w_set[i]);
						isCoveredFlag = 0;
				}
		}
		return isCoveredFlag;
}
void main() {
		char c_set[N_C+1] = {'a','b','c','g','\0'};
		char w_set[N_W][MAX] = {"apple","ibm","cisco","google"};
		if(isCovered(c_set, w_set))
				printf("Is Covered\n");
		else
				printf("Not Covered\n");
}
