# include <stdio.h>

/*
void rotateMatrixBy90Deg(int a, int n)
{
    // Number of layers to rotate
    for (int layer = 0; layer < n / 2; layer++)
    {                
        int offset = 0;

        // Top left coordinate
        int first = layer;

        // Last coordinate
        int last = n - 1 - layer;

        // Each layer has n-1-(layer*2) elements to rotate in clockwise cycle (since for each replacement 2 elements of row are replaced)
        while (offset < last - layer)
        {                    
            int temp = A[first][last - offset];
            A[first][last - offset] = A[last - offset][last];

            temp = temp + A[first + offset][first];
            A[first + offset][first] = temp - A[first + offset][first];
            temp = temp - A[first + offset][first];

            temp = temp + A[last][first + offset];
            A[last][first + offset] = temp - A[last][first + offset];
            temp = temp - A[last][first + offset];

            A[last - offset][last] = temp;
        
            offset++;
        }
    }
}
*/
# define N 4

void print(int mat[N][N]) {
		int i,j;
		printf("\n");
		for (i=0; i<N ; i++) {
				for(j=0 ; j<N ; j++)
						printf("%d\t", mat[i][j]);
				printf("\n");
		}
}

void rotate(int mat[N][N]) {
		int layer, first, last, offset, i;
		for(layer=0 ; layer < N/2 ; layer++) {
				first = layer;
				last = N - layer - 1;
				for(i=first ; i<last ; i++){
						offset = i - first;
						int swap = mat[first][first+offset];
						mat[first][first+offset] = mat[first+offset][last];
						mat[first+offset][last] = mat[last][last-offset];
						mat[last][last-offset] = mat[last-offset][first];
						mat[last-offset][first] = swap;
				}
		}
}

void main() {
		int mat[N][N] = {{1,2,3,4},
					   {5,6,7,8},
					   {9,10,11,12},
					   {13,14,15,16}};
		print(mat);
		rotate(mat);
		print(mat);
}
