class Solution {
public:
    vector<vector<int>> dp;

    int memo(int i, int curr, vector<int> &coins, int &amount){
        if(i == -1)
            return curr == amount ? 0 : INT_MAX;
        if(dp[i][curr] != -1)
            return dp[i][curr];
        
        // NOT TAKE
        int notTake = memo(i - 1, curr, coins, amount);

        // TAKE
        int take = INT_MAX;
        if(curr + coins[i] <= amount){
            take = memo(i, curr + coins[i], coins, amount);
            if(take != INT_MAX) take++;
        }

        return dp[i][curr] = min(notTake, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp = vector<vector<int>>(n, vector<int>(amount + 1, INT_MAX));

        // int ans = memo(n-1, 0, coins, amount);
        // return ans != INT_MAX ? ans : -1;

        // Tabular
        // initialization
        for(int i=0; i<n; i++)
            dp[i][0] = 0;
        for(int j=0; j<=amount; j++)
            if(j % coins[0] == 0)
                dp[0][j] = j / coins[0];
        
        for(int i=1; i<n; i++){
            for(int j=1; j<=amount; j++){
                int notTake = dp[i-1][j];

                int take = INT_MAX;
                if(coins[i] <= j){
                    take = dp[i][j - coins[i]];
                    if(take != INT_MAX) take++;
                }

                dp[i][j] = min(notTake, take);
            }
        }

        return dp[n-1][amount] != INT_MAX ? dp[n-1][amount] : -1;
    }
};