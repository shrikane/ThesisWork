package best_time_to_buy_and_sell_stock_iv;

public class BestTimetoBuyandSellStockIV {

    public class Solution {
        private int maxProfitUnlimited(int[] prices) {
            int profit = 0;
            for (int i = 1; i < prices.length; i++) {
                profit += Math.max(0, prices[i] - prices[i - 1]);
            }
            return profit;
        }

        public int maxProfit(int k, int[] prices) {
            int n = prices.length;
            if (n <= 1) {
                return 0;
            }
            if (k >= n) {
                return maxProfitUnlimited(prices);
            }
            int[] global = new int[k + 1];
            int[] local = new int[k + 1];
            for (int i = 1; i < n; i++) {
                int diff = prices[i] - prices[i - 1];
                for (int j = k; j >= 1; j--) {
                    local[j] = Math.max(global[j - 1] + Math.max(diff, 0), local[j] + diff);
                    global[j] = Math.max(global[j], local[j]);
                }
            }
            return global[k];
        }
    }
}

