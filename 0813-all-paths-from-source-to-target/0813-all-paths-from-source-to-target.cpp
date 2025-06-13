class Solution {
public:
    // Helper function to perform Depth-First Search (DFS) to find all paths
    // from 'start' node to 'end' node in the directed acyclic graph.
    void DFS_helper(vector<vector<int>>& graph, int start, int end, vector<bool>& vis, vector<vector<int>>& path, vector<int>& temp) {
        vis[start] = true; // Mark the current node as visited
        temp.push_back(start); // Add current node to the current path

        if (start == end) { // If we reach the end node, add current path to result
            path.push_back(temp);
        } else {
            // Explore all neighboring nodes of the current node
            for (int v : graph[start]) {
                if (!vis[v]) { // Only visit unvisited nodes
                    DFS_helper(graph, v, end, vis, path, temp);
                }
            }
        }

        // Backtrack: remove the current node from the path and mark it unvisited
        temp.pop_back();
        vis[start] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size(), false); // Track visited nodes
        vector<vector<int>> path; // Store all paths from source to target
        vector<int> temp; // Temporary vector to store the current path

        // Start DFS from node 0 (source) to node graph.size() - 1 (target)
        DFS_helper(graph, 0, graph.size() - 1, vis, path, temp);

        return path; // Return all found paths
    }
};
