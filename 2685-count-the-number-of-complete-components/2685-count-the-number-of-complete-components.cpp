class Solution {
public:
    void DFS(int i, vector<int> &components, vector<bool> &vis, unordered_map<int, unordered_set<int>> &mp) {
        components.push_back(i);
        vis[i] = true;

        for (auto v : mp[i]) {
            if (!vis[v])
                DFS(v, components, vis, mp);
        }
    }


    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> mp;

        for (auto &e : edges) {
            mp[e[0]].insert(e[1]);
            mp[e[1]].insert(e[0]);
        }

        for (int i = 0; i < n; i++)
            mp[i].insert(i);

        int count = 0;

        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (vis[i] == true)
                continue;
            
            vector<int> components;
            DFS(i, components, vis, mp);
            bool check = true;

            for (int c : components) {
                if (components.size() != mp[c].size()) {
                    check = false;
                    break;
                }

                for (int temp : components) {
                    if (!mp[c].count(temp)) {
                        check = false;
                        break;
                    }
                }
            }

            if (check)
                count++;
        }

        return count;
    }
};