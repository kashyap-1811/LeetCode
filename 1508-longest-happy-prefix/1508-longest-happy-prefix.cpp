class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0, i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }

        return s.substr(0, lps[n - 1]);
    }
};
