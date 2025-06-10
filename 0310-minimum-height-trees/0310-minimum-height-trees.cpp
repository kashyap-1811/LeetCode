class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};

        vector<vector<int>>adj(n, vector<int>());
        vector<int>degree(n, 0);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);

            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        vector<int>ans;
        queue<int>leaves;

        for(int i=0; i<n; i++)
            if(degree[i] == 1)
                leaves.push(i);

        while(!leaves.empty()){
            ans.clear();
            int size = leaves.size();

            for(int i=0; i<size; i++){
                int curr = leaves.front();
                leaves.pop();
                cout<<curr<<" ";
                ans.push_back(curr);

                for(int &v : adj[curr]){
                    degree[v]--;

                    if(degree[v] == 1)
                        leaves.push(v);
                }
            }
            cout<<endl;
        }

        return ans;
    }
};