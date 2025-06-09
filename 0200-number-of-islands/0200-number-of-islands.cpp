class Solution {
public:
    void mark(vector<vector<char>>& grid, vector<vector<bool>>& vis, int &m, int &n, int i, int j){
        vis[i][j] = true;

        if(i-1>=0 && grid[i-1][j]=='1' && !vis[i-1][j])
            mark(grid, vis, m, n, i-1, j);

        if(i+1<m && grid[i+1][j]=='1' && !vis[i+1][j])
            mark(grid, vis, m, n, i+1, j);

        if(j-1>=0 && grid[i][j-1]=='1' && !vis[i][j-1])
            mark(grid, vis, m, n, i, j-1);

        if(j+1<n && grid[i][j+1]=='1' && !vis[i][j+1])
            mark(grid, vis, m, n, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int totalIslands = 0;
        vector<vector<bool>>vis(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    mark(grid, vis, m, n, i, j);
                    totalIslands++;
                }
            }
        }

        return totalIslands;
    }
};