class Solution {
public:
    bool DFS(int u, vector<vector<int>>&adj, vector<bool>&vis, const int &destination, int par)
    {
        if(u == destination)
            return true;
            
        vis[u] = true;

        for(int i=0; i<adj[u].size(); i++)
        {
            if(adj[u][i] == par)
                continue;

            if(!vis[adj[u][i]])
                if(DFS(adj[u][i], adj, vis, destination, u))
                    return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n, vector<int>());

        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n, false);

        return DFS(source, adj, vis, destination, -1);
    }
};