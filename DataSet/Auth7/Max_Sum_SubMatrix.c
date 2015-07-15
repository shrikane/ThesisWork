/*
Given a matrix of both +ve and -ve numbers, find out the maximum sum sub matrix. First of all we will calculate the sum matrix where s[i][j] = sum of all the elements from [0,0] to [i,j]
*/
int s[ROW][COL];
void computeSumMatrix(int a[][COL], int r, int c) {
		for (int i = 0; i < r; i++)
				if (i == 0)
						s[i][0] = a[i][0];
				else
						s[i][0] = s[i - 1][0] + a[i][0];
		
		for (int j = 0; j < c; j++)
				if (j == 0)
						s[0][j] = a[0][j];
				else
						s[0][j] = s[0][j - 1] + a[0][j];
		
		for (int i = 1; i < r; i++) {
				for (int j = 1; j < c; j++) {
						s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
				}
		}
}

/*
Now we will write a method to get the sum of a sub matrix given upper-left (r1,c1) indexes and lower-bottom (r2,c2) indexes
*/
int getSubmatSum(int r1, int c1, int r2, int c2) {
		if (r1 == 0 && c1 == 0)
				return s[r2][c2];
		if (r1 == 0)
				return s[r2][c2] - s[r2][c1 - 1];
		if (c1 == 0)
				return s[r2][c2] - s[r1 - 1][c2];
		return s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1];
}

/*
Using both these methods, we can iterate through all the possible sub matrices and get their sum in O(1). To iterate though all the possible sub-matrices would take O(n^4).
*/
int getMaxSubmatSum(int a[][COL], int r, int c) {
		int maxsum = 0;
		for (int r1 = 0; r1 < r; r1++) {
				for (int c1 = 0; c1 < c; c1++) {
						for (int r2 = r1; r2 < r; r2++) {
								for (int c2 = c1; c2 < c; c2++) {
										int sum = getSubmatSum(r1, c1, r2, c2);
										maxsum = max(sum, maxsum);
								}
						}
				}
		}
		return maxsum;
}

/*
Now, we are going to optimize this solution to O(n^3). The trick is to apply Kadane's algorithm on a 2D matrix. We will consider all the possible 2D matrices which are starting from 0th column and treat them as 1D arrays.
*/
int getMaxSubmatSum2(int a[][COL], int r, int c) {
		int globalmax = 0;
		
		for (int i = 0; i < r; i++)
				for (int j = i; j < r; j++) {
						int localmax = 0;
						for (int k = 0; k < c; k++) {
								localmax = max(localmax + getSubmatSum(i, k, j, k), 0);
								globalmax = max(localmax, globalmax);
						}
				}
		
		return globalmax;
}
