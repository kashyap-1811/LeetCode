class Solution {
public:
    void dfs(int i, int j, int &m, int &n, vector<vector<int>>& grid, vector<vector<bool>>& land){
        land[i][j] = true;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1 && !land[x][y])
                dfs(x, y, m, n, grid, land);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> land(m, vector<bool>(n, false));

        // check 1st row
        for(int j=0; j<n; j++)
            if(grid[0][j] == 1)
                dfs(0, j, m, n, grid, land);

        // check last row
        for(int j=0; j<n; j++)
            if(grid[m-1][j] == 1)
                dfs(m-1, j, m, n, grid, land);

        // check 1st col
        for(int i=0; i<m; i++)
            if(grid[i][0] == 1)
                dfs(i, 0, m, n, grid, land);

        // check last col
        for(int i=0; i<m; i++)
            if(grid[i][n-1] == 1)
                dfs(i, n-1, m, n, grid, land);

        int count = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1 && !land[i][j])
                    count++;

        return count;
    }
};