package max_points_on_a_line;

import java.awt.Point;
import java.util.ArrayList;
import java.util.List;

public class MaxPointsonaLine {

    public class Solution {

        private boolean isOnLine(Point p1, Point p2, Point p3) {
            return (p1.y - p2.y) * (p2.x - p3.x) == (p1.x - p2.x)
                    * (p2.y - p3.y);
        }

        public int maxPoints(Point[] points) {
            List<Point[]> lines = new ArrayList<Point[]>();
            for (int i = 0; i < points.length; i++) {
                for (int j = i + 1; j < points.length; j++) {
                    if (points[i].x != points[j].x
                            || points[i].y != points[j].y) {
                        lines.add(new Point[] { points[i], points[j] });
                    }
                }
            }
            if (lines.isEmpty()) {
                return points.length;
            }
            int max = 0;
            for (Point[] line : lines) {
                int count = 0;
                for (Point point : points) {
                    if (isOnLine(line[0], line[1], point)) {
                        count++;
                    }
                }
                max = Math.max(max, count);
            }
            return max;
        }
    }

    public static class UnitTest {

    }
}
