class Solution {
public:
    int memo(int i, string &s, vector<int> &dp){
        if(i == s.size())
            return 1;
        if(s[i] == '0')
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        int one = memo(i+1, s, dp);

        int two = 0;
        if(i + 1 < s.size()){
            int num = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(num >= 10 && num <= 26)
                two = memo(i+2, s, dp);
        }

        return dp[i] = one + two;
    }

    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        vector<int> dp(s.size(), -1);
        return memo(0, s, dp);
    }
};