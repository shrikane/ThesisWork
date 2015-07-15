package course_schedule;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class CourseSchedule {

    public class Solution {
        public boolean canFinish(int numCourses, int[][] prerequisites) {
            Map<Integer, List<Integer>> outNodes = new HashMap<Integer, List<Integer>>();
            int[] inDegree = new int[numCourses];
            Set<Integer> courses = new HashSet<Integer>(numCourses);
            for (int i = 0; i < numCourses; i++) {
                courses.add(i);
                outNodes.put(i, new ArrayList<Integer>());
            }
            for (int[] edge : prerequisites) {
                int from = edge[1];
                int to = edge[0];
                inDegree[to]++;
                List<Integer> nodes = outNodes.get(from);
                nodes.add(to);
            }
            while (!courses.isEmpty()) {
                List<Integer> toRemoved = new ArrayList<Integer>();
                for (int course : courses) {
                    if (inDegree[course] == 0) {
                        toRemoved.add(course);
                        for (int node : outNodes.get(course)) {
                            inDegree[node]--;
                        }
                    }
                }
                if (toRemoved.isEmpty()) {
                    return false;
                }
                courses.removeAll(toRemoved);
            }
            return true;
        }
    }

}

