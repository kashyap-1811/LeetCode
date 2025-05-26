class Solution {
public:
    int DFS(int u, string& colors, vector<vector<int>>& lst, vector<bool>& vis,
            vector<bool>& rec, vector<vector<int>>& dp, bool& hasCycle) {
        if (rec[u]) {
            hasCycle = true;
            return 0;
        }

        if (vis[u])
            return *max_element(dp[u].begin(), dp[u].end());

        rec[u] = true;
        vis[u] = true;

        for (int v : lst[u]) {
            int res = DFS(v, colors, lst, vis, rec, dp, hasCycle);
            if (hasCycle)
                return 0;

            for (int c = 0; c < 26; ++c)
                dp[u][c] = max(dp[u][c], dp[v][c]);
        }

        dp[u][colors[u] - 'a']++;
        rec[u] = false;

        return *max_element(dp[u].begin(), dp[u].end());
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> lst(n);
        for (auto& edge : edges)
            lst[edge[0]].push_back(edge[1]);

        // Optional: debug adjacency list
        // for (int i = 0; i < n; ++i) {
        //     cout << i << ": ";
        //     for (int v : lst[i])
        //         cout << v << " ";
        //     cout << endl;
        // }

        vector<bool> vis(n, false), rec(n, false);
        vector<vector<int>> dp(n, vector<int>(26, 0)); // 26 letters
        bool hasCycle = false;
        int maxPath = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int val = DFS(i, colors, lst, vis, rec, dp, hasCycle);
                if (hasCycle)
                    return -1;
                maxPath = max(maxPath, val);
            }
        }

        return maxPath;
    }
};