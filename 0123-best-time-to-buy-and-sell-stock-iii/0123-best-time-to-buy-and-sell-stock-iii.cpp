class Solution {
public:
    int dp[100001][2][3];

    int solve(int i, int buy, int k, vector<int>& prices) {
        if(i == prices.size() || k == 0) 
            return 0;

        if(dp[i][buy][k] != -1) 
            return dp[i][buy][k];

        int profit = 0;

        if(buy) {
            profit = max(
                -prices[i] + solve(i+1, 0, k, prices),
                solve(i+1, 1, k, prices)
            );
        } else {
            profit = max(
                prices[i] + solve(i+1, 1, k-1, prices),
                solve(i+1, 0, k, prices)
            );
        }

        return dp[i][buy][k] = profit;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 2, prices);
    }
};