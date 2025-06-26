class Solution {
public:
    int memo(int i, int j, string& s, vector<vector<int>>& dp, int& n){
        if(i >= j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = memo(i+1, j-1, s, dp, n);

        return dp[i][j] = min(memo(i+1, j, s, dp, n), memo(i, j-1, s, dp, n)) + 1;
    }

    int minInsertions(string s) {
        int n = s.size();

        vector<vector<int>>dp(n, vector<int>(n, -1));

        return memo(0, n-1, s, dp, n);
    }
};