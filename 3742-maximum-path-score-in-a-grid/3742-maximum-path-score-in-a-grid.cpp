class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int memo(int i, int j, int cost, vector<vector<int>> &grid, int k) {
        if(i >= m || j >= n) return INT_MIN;

        int newCost = cost + (grid[i][j] != 0);
        if(newCost > k) return INT_MIN;

        if(i == m-1 && j == n-1)
            return grid[i][j];

        if(dp[i][j][newCost] != INT_MIN)
            return dp[i][j][newCost];

        int right = memo(i, j+1, newCost, grid, k);
        int down  = memo(i+1, j, newCost, grid, k);

        return dp[i][j][newCost] = grid[i][j] + max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        dp = vector<vector<vector<int>>>(m,
             vector<vector<int>>(n, vector<int>(k+1, INT_MIN)));

        int res = memo(0, 0, 0, grid, k);
        return res < 0 ? -1 : res;
    }
};