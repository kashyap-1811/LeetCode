class Solution {
public:
    void mark(vector<vector<int>>& grid, vector<vector<bool>>& land, int& m, int& n, int i, int j, char ch){
        land[i][j] = true;

        if(ch!='r' && i-1>=0 && grid[i-1][j]==1 && !land[i-1][j])
            mark(grid, land, m, n, i-1, j, 'l');
        
        if(ch!='l' && i+1<m && grid[i+1][j]==1 && !land[i+1][j])
            mark(grid, land, m, n, i+1, j, 'r');

        if(ch!='d' && j-1>=0 && grid[i][j-1]==1 && !land[i][j-1])
            mark(grid, land, m, n, i, j-1, 'u');

        if(ch!='u' && j+1<n && grid[i][j+1]==1 && !land[i][j+1])
            mark(grid, land, m, n, i, j+1, 'd');
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>land(m, vector<bool>(n, false));

        // 1st row
        for(int j=0; j<n; j++)
            if(grid[0][j]==1 && !land[0][j])
                mark(grid, land, m, n, 0, j, 'n');

        // last row
        for(int j=0; j<n; j++)
            if(grid[m-1][j]==1 && !land[m-1][j])
                mark(grid, land, m, n, m-1, j, 'n');

        // 1st col
        for(int i=0; i<m; i++)
            if(grid[i][0]==1 && !land[i][0])
                mark(grid, land, m, n, i, 0, 'n');

        // last col
        for(int i=0; i<m; i++)
            if(grid[i][n-1]==1 && !land[i][n-1])
                mark(grid, land, m, n, i, n-1, 'n');

        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !land[i][j])
                    count++;
            }
        }

        return count;
    }
};