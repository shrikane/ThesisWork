/*
SMS Problem 
1 - NULL, 2 - ABC, 3 - DEF, 4 - GHI, 5 - JKL, 6 - MON, 7 - PQRS, 8 - TUV, 9 - WXYZ, * - <Space>, # - <Break> 
We must convert the numbers to text. 
Eg 
I/P - O/P 
22 - B 
23 - AD 
223 - BD 
22#2 - BA (# breaks the cycle) 
3#33 - DE 
2222 - 2 
2222#2 - 2A 
22222 - A (cycle must wrap around) 
222222 - B
*/

# include <iostream>
# include <string.h>

using namespace std;

class SMS {
private:
		char buttons[10][5];
		int isdigit(char);
		char getChar(char, int);
public:
		SMS();
		void getText(char*);
};

SMS :: SMS() {
		strcpy(buttons[0], "0");
		strcpy(buttons[1], "1");
		strcpy(buttons[2], "ABC2");
		strcpy(buttons[3], "DEF3");
		strcpy(buttons[4], "GHI4");
		strcpy(buttons[5], "JKL5");
		strcpy(buttons[6], "MON6");
		strcpy(buttons[7], "PQRS7");
		strcpy(buttons[8], "TUV8");
		strcpy(buttons[9], "WXYZ9");
}

int SMS :: isdigit(char ch) {
		if('0' <= ch && ch <= '9') {
				return(1);
		}
		return(0);
}

char SMS :: getChar(char ch, int count) {
		int num = ch - '0';
		int buttonLen = strlen(buttons[num]);
		return(buttons[num][(count-1)%buttonLen]);		
}

void SMS :: getText(char* ip) {
		int i=0, count=0;
		while(isdigit(ip[i]) || ip[i] == '*' || ip[i] == '#' || ip[i] == '\0') {
				if(i == 0 || ip[i-1] == ip[i]) {
						count++;
						i++;
						continue;
				}
				// ip[i-1] != ip[i]
				if(isdigit(ip[i-1]))
						cout << getChar(ip[i-1], count);
				if(ip[i-1] == '*')
						cout << " ";
				count = 1;
				if (ip[i] == '\0')
						break;
				i++;
		}
		cout << endl;
}

int main() {
		SMS s;
		char ip[10] = "22222#2";
		s.getText(ip);
		return(0);
}
