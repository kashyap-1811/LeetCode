class Solution {
public:
    vector<int> dp;

    bool memo(int i, string s, vector<string> &wordDict) {
        if(i == s.size()) 
            return true;
        if(dp[i] != -1)
            return dp[i];
        
        for(auto word : wordDict) {
            if(word.size() > s.size() - i)
                continue;
            string substr = s.substr(i, word.size());

            if(word == substr && memo(i+word.size(), s, wordDict))
                return dp[i] = true;
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        dp = vector<int>(s.size(), -1);
        return memo(0, s, wordDict);
    }
};