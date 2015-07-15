# include <iostream>
# include <climits>

using namespace std;

# define MAX 3

class Matrix {
private:
		int matrix[MAX][MAX];
		void findMaxOfMinsInPathsHelper(int, int, int, int*);
public:
		Matrix();
		int findMaxOfMinsInPaths();
		void display();
};

Matrix :: Matrix() {
		int i, j;
		for(i=0; i<MAX; i++)
				for(j=0; j<MAX; j++)
						matrix[i][MAX-1-j] = i*MAX + j;
}

void Matrix :: display() {
		int i, j;
		for(i=0; i<MAX; i++) {
				for(j=0; j<MAX; j++)
						cout<<matrix[i][j]<<"\t";
				cout<<endl;
		}
}

int maxOf(int x, int y) {
	    return (x>=y)?x:y;
}

int minOf(int x, int y) {
	    return (x<=y)?x:y;
}

void Matrix :: findMaxOfMinsInPathsHelper(int i, int j, int minSoFar, int *maxOfMins) {
		int currMin;

		if (i>=MAX || j>=MAX)
				return;

		currMin = minOf(minSoFar, matrix[i][j]);

		if (i==MAX-1 && j==MAX-1) {
				*maxOfMins = maxOf(currMin, *maxOfMins);
				return;
		}

		findMaxOfMinsInPathsHelper(i+1, j, currMin, maxOfMins);
		findMaxOfMinsInPathsHelper(i, j+1, currMin, maxOfMins);
}

int Matrix :: findMaxOfMinsInPaths() {
		int max = INT_MIN;
		findMaxOfMinsInPathsHelper(0, 0, INT_MAX, &max);
		return max;
}

int main() {
		Matrix m;
		m.display();
		cout<<m.findMaxOfMinsInPaths()<<endl;
		return(0);
}
