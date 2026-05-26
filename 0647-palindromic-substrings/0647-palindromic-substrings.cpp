class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int center = 0; center < n; ++center) {
            // Odd-length palindromes
            int l = center, r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }

            // Even-length palindromes
            l = center;
            r = center + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
        }

        return count;
    }
};
