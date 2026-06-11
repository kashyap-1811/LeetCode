class Solution {
public:     
    bool isCycle(int i, vector<vector<int>> &prerequisites, vector<bool> &vis, vector<bool> &rec) {
        vis[i] = true;
        rec[i] = true;

        for (auto &p : prerequisites) {
            int u = p[0], v = p[1];

            if (i != u)
                continue;
            
            if (rec[v] || (!vis[v] && isCycle(v, prerequisites, vis, rec)))
                return true;
        }

        rec[i] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> vis(n, false);
        vector<bool> rec(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i] && isCycle(i, prerequisites, vis, rec))
                return false;
        }

        return true;
    }
};