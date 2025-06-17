class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, int& m, int& n){
        if(i==m || j==n)   
            return INT_MAX;

        if(i==m-1 && j==n-1)
            return grid[i][j];

        if(dp[i][j] != INT_MAX)
            return dp[i][j];

        return dp[i][j] = min(memo(i+1, j, grid, dp, m, n), memo(i, j+1, grid, dp, m, n)) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, INT_MAX));

        return memo(0, 0, grid, dp, m, n);
    }
};