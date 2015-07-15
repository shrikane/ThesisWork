/*
Code: String to Long conversion
Author: Manish Chavan
 */

/*
Question 1.
Given a string, write a routine that converts the string to a long, without using the built in functions that would do this. Describe what (if any) limitations the code has.
 */

# include <stdio.h>

// Macro to check if character is 'space'
# define isSpace(ch) ((ch == ' ') ? 1 : 0)

// Macro to check if character is digit (0-9)
# define isDigit(ch) ((('0' <= ch) && (ch <= '9')) ? 1 : 0)

// Fuction to check the sign
int getSign(char ch, int* i) {
		int sign = 1;
		if (ch == '-') {
				sign = -1;
				*i += 1;
		}
		else if (ch == '+') {
				*i += 1;            // sign already 1
		}

		return sign;
}

// Function to convert string to long
long stringToLong(char* str) {
		int sign, i = 0;
		long l = 0;

		// ignore leading spaces
		while(isSpace(str[i]))
				i++;

		// get the sign of the long
		sign = getSign(str[i], &i);

		// scan the string till non-digit character is seen
		while(isDigit(str[i]))
				l = l*10 + (str[i++] - '0');

		return sign*l;
}

// Test Template
void test(char* testName, long predicted, long actual) {
		printf("%s: ", testName);
		if (predicted == actual)
				printf("Success");
		else
				printf("Failure");
		printf("\n");
}

void main() {
		// Unit Tests
		test("Empty_String_Test",  0,    stringToLong(""));
		test("Zero_Test",          0,    stringToLong("0"));
		test("Negative_Test",      -123, stringToLong("-123"));
		test("Positive_Test",      123,  stringToLong("123"));
		test("Spaces_Test",        123,  stringToLong("   123   "));
		test("Non_Digit_Test",     0,    stringToLong("no digit"));
		test("Partial_Digit_Test", 12,   stringToLong("12e"));
}
