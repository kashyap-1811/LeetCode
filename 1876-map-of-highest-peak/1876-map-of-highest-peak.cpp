class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int, int>>q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        vector<vector<int>> heights(m, vector<int>(n, 0));
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            if(i-1>=0 && !vis[i-1][j]){
                heights[i-1][j] = 1 + heights[i][j];
                vis[i-1][j] = true;
                q.push({i-1, j});
            }

            if(i+1<m && !vis[i+1][j]){
                heights[i+1][j] = 1 + heights[i][j];
                vis[i+1][j] = true;
                q.push({i+1, j});
            }

            if(j-1>=0 && !vis[i][j-1]){
                heights[i][j-1] = 1 + heights[i][j];
                vis[i][j-1] = true;
                q.push({i, j-1});
            }

            if(j+1<n && !vis[i][j+1]){
                heights[i][j+1] = 1 + heights[i][j];
                vis[i][j+1] = true;
                q.push({i, j+1});
            }
        }   

        return heights;
    }
};