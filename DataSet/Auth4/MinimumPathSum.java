package minimum_path_sum;

public class MinimumPathSum {

    public class Solution {
        public int minPathSum(int[][] grid) {
            assert grid != null && grid.length != 0 && grid[0].length != 0;
            int[] dp = new int[grid[0].length];
            for (int i = 0; i < grid.length; i++) {
                dp[0] = i == 0 ? grid[0][0] : dp[0] + grid[i][0];
                for (int j = 1; j < grid[0].length; j++) {
                    dp[j] = i == 0 ? dp[j - 1] : Math.min(dp[j], dp[j - 1]);
                    dp[j] += grid[i][j];
                }
            }
            return dp[grid[0].length - 1];
        }
    }

    public static class UnitTest {

    }
}
