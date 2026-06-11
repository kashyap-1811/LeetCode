class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for (auto f : flights) 
            adj[f[0]].push_back({f[1], f[2]});
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> cost(n, vector<int>(k + 2, INT_MAX));
        pq.push({0, 0, src}); // cost, stops, node
        cost[src][0] = 0;

        while (!pq.empty()) {
            auto [d, stops, u] = pq.top();
            pq.pop();

            if (u == dst)
                return d;

            if (stops > k)
                continue;
                     
            for (auto [v, wt] : adj[u]) {
                int newCost = d + wt;
                if (cost[v][stops + 1] > newCost) {
                    cost[v][stops + 1] = newCost;
                    pq.push({newCost, stops + 1, v});
                }
            }
        }

        return -1;
    }
};