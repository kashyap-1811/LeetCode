class Solution {
public:
    bool DFS(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& rec){
        vis[u] = true;
        rec[u] = true;

        for(int v : adj[u]){
            if(rec[v])
                return false;
            else if(!vis[v] && !DFS(v, adj, vis, rec))
                return false;
        }

        rec[u] = false;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses, vector<int>());

        for(auto edge : prerequisites)
            adj[edge[0]].push_back(edge[1]);

        vector<bool>vis(numCourses, false), rec(numCourses, false);

        for(int i=0; i<numCourses; i++)
            if(!vis[i])
                if(!DFS(i, adj, vis, rec))
                    return false;

        return true;
    }
};