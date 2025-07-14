class Solution {
public:
    int recurse(int i, vector<int>& nums, int& n, vector<int>& dp){
        if(i >= n)
            return INT_MAX;
        if(i == n-1)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        int minJumps = INT_MAX;
        for(int k=1; k<=nums[i]; k++)
            minJumps = min(minJumps, recurse(i + k, nums, n, dp));

        return dp[i] = minJumps==INT_MAX ? INT_MAX : minJumps + 1;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);

        return recurse(0, nums, n, dp);
    }
};