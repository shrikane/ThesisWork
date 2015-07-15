package gas_station;

public class GasStation {

    public class Solution {
        public int canCompleteCircuit(int[] gas, int[] cost) {
            int start = 0;
            while (start < gas.length) {
                int end = start;
                int rest = 0;
                do {
                    rest += gas[end] - cost[end];
                    end = (end + 1) % gas.length;
                    if (rest < 0) {
                        if (end <= start) {
                            return -1;
                        }
                        break;
                    }
                } while (end != start);
                if (end == start) {
                    return start;
                }
                start = end;
            }
            return -1;
        }
    }

    public static class UnitTest {

    }
}
