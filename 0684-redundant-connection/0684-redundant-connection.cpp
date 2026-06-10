class Solution {
public:
    int stPoint = -1;

    bool isCycle(int u, int par, vector<vector<int>> &adj, vector<bool> &vis, unordered_map<int, int> &cycleEdges) {
        vis[u] = true;

        for (int v : adj[u]) {
            if (v == par)
                continue;

            if (vis[v])
                stPoint = v;
            
            if (vis[v] || isCycle(v, u, adj, vis, cycleEdges)) {
                if (stPoint != -1)
                    cycleEdges[u] = v;
                
                if (stPoint == u)
                    stPoint = -1;
                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1, vector<int>());

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n + 1, false);
        unordered_map<int, int> cycleEdges;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && isCycle(i, -1, adj, vis, cycleEdges))
                break;
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];

            if ((cycleEdges.count(u) && cycleEdges[u] == v) 
                 || 
                (cycleEdges.count(v) && cycleEdges[v] == u)
            ) {
                return edges[i];
            }
        }

        return {};
    }
};