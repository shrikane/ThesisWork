package unique_paths_ii;

public class UniquePathsII {

    public class Solution {
        public int uniquePathsWithObstacles(int[][] obstacleGrid) {
            int m = obstacleGrid.length;
            int n = obstacleGrid[0].length;
            int[] dp = new int[n];
            dp[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
            for (int i = 0; i < m; i++) {
                dp[0] = obstacleGrid[i][0] == 1 ? 0 : dp[0];
                for (int j = 1; j < n; j++) {
                    dp[j] = obstacleGrid[i][j] == 1 ? 0 : dp[j - 1] + dp[j];
                }
            }
            return dp[n - 1];
        }
    }

    public static class UnitTest {

    }
}
