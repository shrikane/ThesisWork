# include <stdio.h>

int getInt(char* a, int* i) {
		int f = 0;
		while(a[*i]!='.' && a[*i]!='e' && a[*i]!='\0') {
				// if !isDigit(a[i]) return error
				f = f*10 + (a[*i] - '0');
				(*i)++;
		}
		return f;
}

float getDec(char* a, int* i) {
		float f = 0.0;
		int den = 10;
		while(a[*i]!='e' && a[*i]!='\0') {
				// if !isDigit(a[i]) return error
				f += (float)(a[*i] - '0')/den;
				den *= 10;
				(*i)++;
		}
		return f;
}

int getSign(char ch, int* i) {
		int sign = 1;
		if (ch == '-') {
				sign = -1;
				*i += 1;
		}
		else if (ch == '+') {
				sign = 1;
				*i += 1;
		}
		return sign;
}

int power(int x, int y) {
		int z;
		if (y == 0)
				return 1;
		if (y == 1)
				return x;
		z = power(x, (int)(y/2));
		if (y%2 == 0)
				return z*z;
		return z*z*x;
}

float atof(char* a) {
		int sign, i = 0, esign, eint;
		float f=0.0;

		sign = getSign(a[i], &i);

		f = getInt(a, &i);

		if (a[i] == '.') {
				i++;
				f = f + getDec(a, &i);
		}

		if (a[i] == 'e') {
				i++;
				esign = 1;
				esign = getSign(a[i], &i);
				eint = getInt(a, &i);
				if (esign == 1)
						f *= power(10, eint);
				else if (esign == -1)
						f /= power(10, eint);
		}
		return f;
}

void main() {
		char s[15];
		printf("A: ");
		scanf("%s", s);
		printf("F: %f\n", atof(s));
}
