class Solution {
public:
    vector<int> dp;

    int memo(int i, string s, vector<string> &dictionary) {
        if(i == s.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];

        // skip
        int skip = 1 + memo(i+1, s, dictionary);

        // take if possible
        int take = INT_MAX;
        for(auto d : dictionary) {
            if(d.size() > s.size() - i)
                continue;
            string substr = s.substr(i, d.size());
            if(substr == d)
                take = min(take, memo(i+d.size(), s, dictionary));
        }

        return dp[i] = min(skip, take);
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        dp = vector<int>(s.size(), -1);
        return memo(0, s, dictionary);
    }
};