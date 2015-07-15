# include <stdio.h>
# include <limits.h>

# define CHANGE 5
# define COINS 6

int coins[6] = {1,2,5,10,20,25};
int dp[1000][10] = {-1};

int minOf(int x, int y) {
		return(x <= y ? x : y);
}

int recCoinChange(int Change) {	   
		int i, min = INT_MAX;
		if(Change < 0)
				return INT_MAX;
		if(Change == 0) {
				return 0;
		}

		for(i=0; i<6; i++) {
				if(Change - coins[i] >= 0) {
						min = minOf(min, recCoinChange(Change - coins[i]));
				}
		}

		return(min + 1);
}

/*
int memorecCoinChange(int Change, int coin) {
		int i, count;
		for(i=0; i<COINS; i++) {
				for(count=0; count<=CHANGE; count++) {
						if(dp[count][i] == -1)
								printf("-");
						else
								printf("%d", dp[count][i]);
				}
				printf("\n");
		}
		printf("\n");
		if(Change == 0)
				return 1;
		if(dp[Change][coin] != -1)
				return dp[Change][coin];
		count = 0;
		for(i=0; i<=coin; i++) {
				if(Change - coins[i] >= 0) {
						count += memorecCoinChange(Change - coins[i], i);
				}
		}
		dp[Change][coin] = count;
		return dp[Change][coin];
}
*/

void main() {
		printf("Rec = %d", recCoinChange(CHANGE));
		/*		int i, count;
		for(i=0; i<=COINS; i++)
				for(count=0; count<=CHANGE; count++)
						dp[count][i] = -1;
		
						printf("Memorec = %d", memorecCoinChange(CHANGE, COINS));*/
}
