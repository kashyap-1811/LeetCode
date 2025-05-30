class Solution {
public:
    void DFS(int u, vector<vector<int>>&adj, vector<int>&colors, int par)
    {
        if(par == -1)
            colors[u] = 1;
        else{
            vector<bool>col(4, true);
            for(int i=0; i<adj[u].size(); i++)
                if(colors[adj[u][i]] != -1)
                    col[colors[adj[u][i]]-1] = false;

            for(int i=0; i<4; i++)
            {
                if(col[i] == true){
                    colors[u] = i+1;
                    break;
                }
            }
        }

        for(int i=0; i<adj[u].size(); i++)
        {
            if(colors[adj[u][i]] == -1)
                DFS(adj[u][i], adj, colors, u);
        }
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>colors(n, -1);

        vector<vector<int>>adj(n, vector<int>());

        for(int i=0; i<paths.size(); i++)
        {
            int u = paths[i][0]-1;
            int v = paths[i][1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0; i<n; i++)
        {
            if(colors[i] == -1){
                DFS(i, adj, colors, -1);
            }
        }

        return colors;
    }
};