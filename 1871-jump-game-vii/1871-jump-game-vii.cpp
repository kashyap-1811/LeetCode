class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s.back() != '0') return false;

        // dp[i] will store whether index i is reachable
        vector<bool> dp(n, false);
        dp[0] = true; // We always start at index 0

        int reachable_count = 0;

        for (int i = 1; i < n; i++) {
            // Slide the window forward: add the newly entering element to our window count
            if (i >= minJump && dp[i - minJump]) {
                reachable_count++;
            }
            // Slide the window forward: remove the element that just left our window range
            if (i > maxJump && dp[i - maxJump - 1]) {
                reachable_count--;
            }

            // If the current character is '0' and there's a valid jump point in our window
            if (s[i] == '0' && reachable_count > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};