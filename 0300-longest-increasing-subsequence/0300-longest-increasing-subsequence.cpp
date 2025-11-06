class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(nums[i] <= dp.back()){
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                int idx = distance(dp.begin(), it);
                dp[idx] = nums[i];
            }
            else{
                dp.push_back(nums[i]);
            }
        }
        return dp.size();
    }
};