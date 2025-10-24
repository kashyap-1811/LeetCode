class Solution {
public:
    bool DFS(int src, vector<vector<int>>& conditions, vector<bool>& vis,
             vector<bool>& rec, stack<int>& st) {
        vis[src] = true;
        rec[src] = true;

        for (int v : conditions[src]) {
            if (rec[v])
                return false;
            else if (!vis[v] && !DFS(v, conditions, vis, rec, st))
                return false;
        }

        rec[src] = false;
        st.push(src);
        return true;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<vector<int>> rowConstraints(k + 1, vector<int>());
        for (int i = 0; i < rowConditions.size(); i++)
            rowConstraints[rowConditions[i][0]].push_back(rowConditions[i][1]);

        vector<vector<int>> colConstraints(k + 1, vector<int>());
        for (int i = 0; i < colConditions.size(); i++)
            colConstraints[colConditions[i][0]].push_back(colConditions[i][1]);

        stack<int> st;
        vector<bool> vis(k + 1, false);
        vector<bool> rec(k + 1, false);
        for (int i = 1; i <= k; i++)
            if (!vis[i] && !DFS(i, rowConstraints, vis, rec, st))
                return vector<vector<int>>{};

        vector<int> rowSeq;
        while (!st.empty()) {
            rowSeq.push_back(st.top());
            st.pop();
        }

        for (int i = 1; i <= k; i++) {
            vis[i] = false;
            rec[i] = false;
        }

        for (int i = 1; i <= k; i++)
            if (!vis[i] && !DFS(i, colConstraints, vis, rec, st))
                return vector<vector<int>>{};

        map<int, int> colSeq;
        int i = 0;
        while (!st.empty()) {
            colSeq[st.top()] = i++;
            st.pop();
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 0; i < rowSeq.size(); i++) {
            int idx = colSeq[rowSeq[i]];
            ans[i][idx] = rowSeq[i];
        }

        return ans;
    }
};