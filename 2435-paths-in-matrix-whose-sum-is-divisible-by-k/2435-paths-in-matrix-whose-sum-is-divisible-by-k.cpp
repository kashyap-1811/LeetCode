class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int memo(int i, int j, int sum, const vector<vector<int>> &grid, const int &k){
        int m = grid.size();
        int n = grid[0].size();

        if(i == m || j == n) 
            return 0;

        // only terminal when at bottom-right cell
        if(i == m - 1 && j == n - 1)
            return ((sum + grid[i][j]) % k == 0) ? 1 : 0;

        if(dp[i][j][sum] != -1)
            return dp[i][j][sum];

        int newSum = (sum + grid[i][j]) % k;

        // down
        long long down = memo(i+1, j, newSum, grid, k);

        // right
        long long right = memo(i, j+1, newSum, grid, k);

        long long res = (down + right) % MOD;
        dp[i][j][sum] = (int)res;
        return dp[i][j][sum];
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return memo(0, 0, 0, grid, k);
    }
};
