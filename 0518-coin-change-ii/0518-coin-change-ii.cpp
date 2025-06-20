class Solution {
public:
    int memo(int i, int curr, int& amount, vector<int>& coins, vector<vector<int>>&dp, int& n){
        if(i == n){
            if(curr == amount)
                return 1;
            return 0;
        }

        if(dp[i][curr] != -1)
            return dp[i][curr];

        int notTake = memo(i+1, curr, amount, coins, dp, n);

        int take = 0;
        if(curr + coins[i] <= amount)
            take = memo(i, curr+coins[i], amount, coins, dp, n);

        return dp[i][curr] = notTake + take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));

        return memo(0, 0, amount, coins, dp, n);
    }
};