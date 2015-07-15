/*
m x n integer array, 0 or 1, given a src and dest cell, find the number of all paths from src to dst with all '0' cell visited once, the cell with value '1' can not be visited. 
you can move up, down, left, right 

e,g,


s 0 0    s -> 0 -> 0   or  s    0 -> 0
                   |       |    ^    |
0 0 0    0 <- 0 <- 0       0    0    0
         |                 |    ^    |
0 0 d    0 -> 0 -> d       0 -> 0    d     total 2

s 0 0 

0 1 0 

0 0 d total paths 0
*/

# include <stdio.h>

#define N 4

int isInvalid(int x) {
		if ((x < 0) || (x >= N))
				return 1;
		return 0;
}

int getTotalPaths(int mat[N][N], int i, int j, int dest_i, int dest_j, int pathlen) {
		if (isInvalid(i) || isInvalid(j) || mat[i][j] == 1)
				return 0;
		if (pathlen==1) {
				if ((i == dest_i) && (j == dest_j))
						return 1;
				return 0;
		}
		mat[i][j] = 1;
		int paths = getTotalPaths(mat, i+1, j  , dest_i, dest_j, pathlen-1) +
				    getTotalPaths(mat, i-1, j  , dest_i, dest_j, pathlen-1) +
  				    getTotalPaths(mat, i  , j+1, dest_i, dest_j, pathlen-1) +
				    getTotalPaths(mat, i  , j-1, dest_i, dest_j, pathlen-1);
		mat[i][j] = 0;
		return paths;
}

void main() {
		int mat[N][N] = {{0,0,0,0},
						 {0,0,0,0},
						 {0,0,0,0},
						 {0,0,0,0}};
		int src_i = 0, src_j = 0;
		int dest_i = N-1, dest_j = N-1;
		int total_paths;
		total_paths = getTotalPaths(mat, src_i, src_j, dest_i, dest_j, N*N);
		printf("%d\n", total_paths);
}
