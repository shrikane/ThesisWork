package merge_intervals;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import common.Interval;

public class MergeIntervals {

    public class Solution {
        public ArrayList<Interval> merge(ArrayList<Interval> intervals) {
            Collections.sort(intervals, new Comparator<Interval>() {

                @Override
                public int compare(Interval i1, Interval i2) {
                    if (i1.start == i2.start) {
                        return i1.end - i2.end;
                    }
                    return i1.start - i2.start;
                }

            });

            ArrayList<Interval> ans = new ArrayList<Interval>();
            Interval newInterval = null;
            for (Interval i : intervals) {
                if (newInterval == null) {
                    newInterval = new Interval(i.start, i.end);
                } else {
                    if (newInterval.end < i.start) {
                        ans.add(newInterval);
                        newInterval = new Interval(i.start, i.end);
                    } else {
                        newInterval.end = Math.max(newInterval.end, i.end);
                    }
                }
            }
            if (newInterval != null) {
                ans.add(newInterval);
            }
            return ans;
        }
    }

    public static class UnitTest {

    }
}
