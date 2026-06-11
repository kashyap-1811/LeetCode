class Solution {
public:
    vector<int> par;

    int find (int x) {
        if (par[x] == x)
            return x;
        
        return par[x] = find(par[x]);
    } 

    void unite(int a, int b) {
        par[a] = b;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        par.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i;
        
        vector<vector<int>> edges;
        for (int i = 0; i < n; i++) {
            auto p1 = points[i];
            for (int j = i + 1; j < n; j++) {
                auto p2 = points[j];
                int d = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
                edges.push_back({d, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        int totalCost = 0;

        for (auto e : edges) {
            int cost = e[0], u = e[1], v = e[2];

            if (find(u) != find(v)) {
                totalCost += cost;
                unite(par[u], par[v]);
            }
        }

        return totalCost;
    }
};