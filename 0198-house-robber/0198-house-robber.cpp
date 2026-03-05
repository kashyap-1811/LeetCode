class Solution {
public:
    int house(vector<int>&nums, int i, vector<int>&dp)
    {
        if(i >= nums.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];

        //take
        int sum1 = nums[i] + house(nums, i+2, dp);

        //not take
        int sum2 = house(nums, i+1, dp);

        return dp[i] = max(sum1, sum2);
    }

    int rob(vector<int>& nums) {
        int i = 0;
        vector<int>dp(nums.size(), -1);
        return house(nums, i, dp);
    }
};