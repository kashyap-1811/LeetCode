#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // dp[i][j] will store the minimum delete sum for s1[0...i-1] and s2[0...j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Initialize base case: if one string is empty, the delete sum is the sum of the ASCII values of the other string
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    // If characters match, no need to delete them
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // Otherwise, delete one character from either string
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                }
            }
        }

        // The value at dp[n][m] will be the minimum ASCII delete sum
        return dp[n][m];
    }
};
