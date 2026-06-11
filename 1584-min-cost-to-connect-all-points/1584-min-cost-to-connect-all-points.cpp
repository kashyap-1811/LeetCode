class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n; i++) {
            auto p1 = points[i];
            for (int j = i + 1; j < n; j++) {
                auto p2 = points[j];
                int d = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        int totalCost = 0;

        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (vis[u])
                continue;
            
            vis[u] = true;
            totalCost += d;

            for (auto [v, wt] : adj[u]) {
                if (!vis[v]) 
                    pq.push({wt, v});
            }
        }

        return totalCost;
    }
};