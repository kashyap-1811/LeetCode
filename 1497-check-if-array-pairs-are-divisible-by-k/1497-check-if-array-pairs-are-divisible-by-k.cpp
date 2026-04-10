class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> dp(k, 0);

        for(int i : arr) {
            dp[(i % k + k) % k]++;
        }

        for(int i=1; i<k; i++) {
            if(dp[i] != dp[k-i])
                return false;
        }

        return dp[0] % 2 == 0;
    }
};