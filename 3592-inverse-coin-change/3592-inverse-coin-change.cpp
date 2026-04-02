class Solution {
public:
    int waysPossible(int i, int sum, vector<int> &nums, int target, vector<vector<int>> &dp) {
        if(sum == target) return 1;
        if(i == nums.size()) return 0;

        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        // take
        int take = 0;
        if(sum + nums[i] <= target)
            take = waysPossible(i, sum + nums[i], nums, target, dp);

        // not take
        int notTake = waysPossible(i + 1, sum, nums, target, dp);

        return dp[i][sum] = take + notTake;
    }

    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> ans;

        for(int i = 1; i <= n; i++) {
            int target = i;

            vector<vector<int>> dp(ans.size() + 1, vector<int>(target + 1, -1));
            int ways = waysPossible(0, 0, ans, target, dp);

            if(ways + 1 == numWays[i-1])
                ans.push_back(i);
            else if (ways != numWays[i-1])
                return {};
        }

        return ans;
    }
};