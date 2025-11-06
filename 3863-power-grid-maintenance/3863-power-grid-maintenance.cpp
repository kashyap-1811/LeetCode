class Solution {
public:
    unordered_map<int, set<int>> m;
    vector<int> parent;
    vector<int> myGroup;

    int find(int x){
        if(x == -1)
            return -1;
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void DFS(int u, vector<vector<int>> &adj, vector<bool> &vis, const int &groupId){
        vis[u] = true;
        m[groupId].insert(u);
        myGroup[u] = groupId;

        for(int v : adj[u]){
            if(!vis[v])
                DFS(v, adj, vis, groupId);
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c + 1);
        myGroup.resize(c + 1);
        for(int i=1; i<=c; i++)
            parent[i] = i;
        
        vector<vector<int>> adj(c + 1, vector<int>());
        for(auto &c : connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        vector<bool> vis(c + 1, false);
        int groupId = 0;

        for(int i=1; i<=c; i++){
            if(!vis[i]){
                groupId++;
                DFS(i, adj, vis, groupId);
            }
        }

        vector<int> ans;
        for(auto &q : queries){
            if(q[0] == 1)
                ans.push_back(find(q[1]));
            else{
                int gId = myGroup[q[1]];
                m[gId].erase(q[1]);

                if(m[gId].size() == 0)
                    parent[q[1]] = -1;
                else
                    parent[q[1]] = *(m[gId].begin());
            }
        }

        return ans;
    }
};