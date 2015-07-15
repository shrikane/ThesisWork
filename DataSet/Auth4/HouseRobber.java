package house_robber;

public class HouseRobber {

    public class Solution {
        public int rob(int[] nums) {
            if (nums.length == 0) {
                return 0;
            }
            if (nums.length < 2) {
                return nums[0];
            }
            int f1 = nums[0];
            int f2 = Math.max(nums[0], nums[1]);
            for (int i = 2; i < nums.length; i++) {
                // f(i) = max { f(i - 2) + nums[i], f(i - 1) }
                int f = Math.max(f1 + nums[i], f2);
                f1 = f2;
                f2 = f;
            }
            return f2;
        }
    }
}

