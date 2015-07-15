/*In 1-9 keypad one key is not working. If some one enters a password then not working key will not be entered. You have given expected password and entered password. Check that entered password is valid or not 
Ex: entered 164, expected 18684 (you need to take care as when u enter 18684 and 164 only both will be taken as 164 input)*/

# include <iostream>
# include <string.h>

# define MAX 100

using namespace std;

class Password {
private:
		char original[MAX], typed[MAX];
public:
		Password();
		int isValid();
};

Password :: Password() {
		strcpy(original, "18648");
		strcpy(typed, "164");
}

int Password :: isValid() {
		int originalHash[10]={0}, typedHash[10]={0};
		int i, lenDiff, diff;
		for(i=0; original[i]!='\0'; i++)
				originalHash[original[i] - '0'] += 1;
		for(i=0; typed[i]!='\0'; i++)
				typedHash[typed[i] - '0'] += 1;
		lenDiff = strlen(original) - strlen(typed);
		if(lenDiff < 0)
				return(0);
		for(i=0; i<10; i++) {
				diff = originalHash[i] - typedHash[i];
				if(diff < 0)
						return(0);
				if(diff != 0 && diff != lenDiff)
						return(0);
		}
		return(1);
}

int main() {
		Password p;
		if(p.isValid())
				cout << "Valid" << endl;
		else
				cout << "Invalid" << endl;
		return(0);
}
