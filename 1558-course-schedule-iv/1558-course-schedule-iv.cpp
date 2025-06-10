class Solution {
public: 
    void DFS(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& rec, map<int, set<int>>& m){
        vis[u] = true;
        rec[u] = true;

        for(int v : adj[u]){
            if(!rec[v] && !vis[v]){
                DFS(v, adj, vis, rec, m);
            }

            m[u].insert({v});

            for(auto it : m[v])
                m[u].insert({it});
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses, vector<int>());

        for(auto edge : prerequisites){
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool>vis(numCourses, false), rec(numCourses, false);

        map<int, set<int>>m;

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                DFS(i, adj, vis, rec, m);
            }
        }

        vector<bool>ans(queries.size(), false);

        for(int i=0; i<queries.size(); i++){
            if(m[queries[i][0]].count(queries[i][1]))
                ans[i] = true;
        }

        return ans;
    }
};