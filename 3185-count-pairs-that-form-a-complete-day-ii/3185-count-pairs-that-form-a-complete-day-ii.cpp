class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<long long> dp(24, 0);
        long long ans = 0;

        for(int h : hours) {
            int remainder = h % 24;
            ans += dp[(24 - remainder) % 24];
            dp[remainder]++;
        }

        return ans;
    }
};