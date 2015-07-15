# include <stdio.h>

#define N 4

int max(int a, int b) {
		return (a > b)? a : b;
}

void memoized_0_1_knapsack(int* W, int* V, int M) {
		int K[N+1][M+1];
		int i, w;

		for(i=0 ; i<=N ; i++) {
				for(w=0 ; w<=M ; w++) {
						if (i==0 || w==0)
								K[i][w] = 0;
						else if (W[i-1] <= w) // i-1 is current item
								K[i][w] = max(V[i-1] + K[i-1][w-W[i-1]],  K[i-1][w]);
						else
								K[i][w] = K[i-1][w];
				}
		}

		printf("DAG :");
		for(i=0 ; i<=N ; i++) {
				printf("\n");
				for(w=0 ; w<=M ; w++) {
						printf(" %d ", K[i][w]);
				}
		}
		printf("\n");
}

int unmemoized_0_1_knapsack(int* W, int* V, int m, int n) {
   // Base Case
   if (n == 0 || m == 0)
		   return 0;
 
   // If weight of the nth item is more than Knapsack capacity W, then
   // this item cannot be included in the optimal solution
   if (W[n-1] > m)
		   return unmemoized_0_1_knapsack(W, V, m, n-1);
 
   // Return the maximum of two cases: (1) nth item included (2) not included
   else
		   return max(V[n-1] + unmemoized_0_1_knapsack(W, V, m-W[n-1], n-1),
					  unmemoized_0_1_knapsack(W, V, m, n-1));
}

void main() {
		int W[N] = {6,3,4,2};
		int V[N] = {30,16,14,9};
		int M = 10;
		memoized_0_1_knapsack(W, V, M);
		printf("\n%d\n", unmemoized_0_1_knapsack(W, V, M, N));
}
