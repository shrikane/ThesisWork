package clone_graph;

import java.util.HashMap;

import common.UndirectedGraphNode;

public class CloneGraph {

    public class Solution {
        private UndirectedGraphNode cloneGraph(UndirectedGraphNode node,
                HashMap<UndirectedGraphNode, UndirectedGraphNode> nodes) {
            UndirectedGraphNode newNode = new UndirectedGraphNode(node.label);
            nodes.put(node, newNode);
            for (UndirectedGraphNode neighbor : node.neighbors) {
                UndirectedGraphNode newNeighbor = nodes.get(neighbor);
                if (newNeighbor == null) {
                    newNeighbor = cloneGraph(neighbor, nodes);
                }
                newNode.neighbors.add(newNeighbor);
            }
            return newNode;
        }

        public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
            if (node == null) {
                return null;
            }
            return cloneGraph(node,
                    new HashMap<UndirectedGraphNode, UndirectedGraphNode>());
        }
    }

    public static class UnitTest {

    }
}
