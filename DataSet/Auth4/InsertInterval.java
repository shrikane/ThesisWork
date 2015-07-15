package insert_interval;

import common.Interval;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.assertEquals;

public class InsertInterval {

    public class Solution {

        public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
            List<Interval> newIntervals = new ArrayList<Interval>();
            for (Interval interval : intervals) {
                if (newInterval == null || interval.end < newInterval.start) {
                    newIntervals.add(interval);
                } else if (interval.start > newInterval.end) {
                    newIntervals.add(newInterval);
                    newIntervals.add(interval);
                    newInterval = null;
                } else {
                    newInterval.start = Math.min(newInterval.start, interval.start);
                    newInterval.end = Math.max(newInterval.end, interval.end);
                }
            }
            if (newInterval != null) {
                newIntervals.add(newInterval);
            }
            return newIntervals;
        }
    }

    public static class UnitTest {

        @Test
        public void testInsert() {
            Solution s = new InsertInterval().new Solution();
            assertEquals(
                    Arrays.asList(new Interval(0, 0), new Interval(1, 5)),
                    s.insert(Arrays.asList(new Interval(1, 5)), new Interval(0, 0)));
        }
    }
}
