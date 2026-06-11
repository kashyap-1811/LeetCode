class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n, 0);

        for (auto &p : prerequisites)
            indegree[p[1]]++;
        
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0) q.push(i);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto &p : prerequisites) {
                int u = p[0], v = p[1];

                if (curr != u) continue;

                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        for (int i : indegree)
            if (i > 0) return false;

        return true;
    }
};