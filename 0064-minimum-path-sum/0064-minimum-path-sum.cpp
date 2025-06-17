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

        // return memo(0, 0, grid, dp, m, n);

        dp[0][0] = grid[0][0];

        for(int i=1; i<m; i++)
            dp[i][0] = grid[i][0] + dp[i-1][0];
        
        for(int j=1; j<n; j++)
            dp[0][j] = grid[0][j] + dp[0][j-1];

        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];

        return dp[m-1][n-1];
    }
};