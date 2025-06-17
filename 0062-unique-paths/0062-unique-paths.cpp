class Solution {
public:
    int memo(int i, int j, int &m, int &n, vector<vector<int>>& dp){
        if(i==m || j==n)
            return 0;

        if(i==m-1 && j==n-1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = memo(i, j+1, m, n,  dp) + memo(i+1, j, m, n, dp);
    }

    int uniquePaths(int m, int n) {
        if(n==1 || m==1)
            return 1;

        vector<vector<int>>dp(m, vector<int>(n, -1));

        return memo(0, 0, m, n, dp);
    }
};