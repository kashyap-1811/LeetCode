class Solution {
public:
    int dfs(int node, int parent, vector<vector<pair<int,int>>> &adj) {
        int cost = 0;
        for (auto &p : adj[node]) {
            int nbr = p.first;
            int w = p.second;
            if (nbr == parent) continue;
            cost += w + dfs(nbr, node, adj);
        }
        return cost;
    }

    void reroot(int node, int parent, vector<vector<pair<int,int>>> &adj, vector<int> &ans) {
        for (auto &p : adj[node]) {
            int nbr = p.first;
            int w = p.second;
            if (nbr == parent) continue;
            if (w == 0) ans[nbr] = ans[node] + 1;
            else ans[nbr] = ans[node] - 1;
            reroot(nbr, node, adj, ans);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }
        vector<int> ans(n);
        ans[0] = dfs(0, -1, adj);
        reroot(0, -1, adj, ans);
        return ans;
    }
};