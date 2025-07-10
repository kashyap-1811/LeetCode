class Solution {
public:
    void recurse(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& m, int& n, int& area){
        vis[i][j] = true;
        area += grid[i][j]; 

        // up
        if(i-1>=0 && grid[i-1][j]!=0 && !vis[i-1][j])
            recurse(i-1, j, grid,vis, m, n, area);

        // down
        if(i+1<m && grid[i+1][j]!=0 && !vis[i+1][j])
            recurse(i+1, j, grid,vis, m, n, area);

        //left
        if(j-1>=0 && grid[i][j-1]!=0 && !vis[i][j-1])
            recurse(i, j-1, grid,vis, m, n, area);

        //right
        if(j+1<n && grid[i][j+1]!=0 && !vis[i][j+1])
            recurse(i, j+1, grid,vis, m, n, area);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mxArea = 0;
        vector<vector<bool>>vis(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                    int area = 0;
                    recurse(i, j, grid, vis, m, n, area);
                    mxArea = max(mxArea, area);
                }
            }
        }

        return mxArea;
    }
};