class Solution {
public:
    void DFS(int u, vector<vector<int>> &adj, vector<bool> &vis, int &edges, int &vertices){
        vis[u] = true;
        edges += adj[u].size();
        vertices++;

        for(int v : adj[u])
            if(!vis[v])
                DFS(v, adj, vis, edges, vertices);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int noOfExtraEdges = 0;
        int differentComponenets = -1; // default one component is there

        vector<bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int edges = 0;
                int vertices = 0;
                DFS(i, adj, vis, edges, vertices);

                edges /= 2;
                edges -= (vertices - 1);
                if(edges > 0)
                    noOfExtraEdges += edges;
                differentComponenets++;
            }
        }

        return noOfExtraEdges >= differentComponenets ? differentComponenets : -1;
    }
};