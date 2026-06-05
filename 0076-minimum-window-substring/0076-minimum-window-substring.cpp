class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq1, freq2;

        for(char c : t)
            freq1[c]++;
        
        int minLen = INT_MAX;
        int st = -1, end = -1;
        int l = 0, r = 0;

        while(r < s.size() + 1) {
            if(r < s.size())
                freq2[s[r]]++;

            while(l <= r && (!freq1.count(s[l]) || freq2[s[l]] > freq1[s[l]])) {
                freq2[s[l]]--;
                l++;
            }

            bool isEqual = true;

            for(auto [ch, count] : freq1) {
                if(!freq2.count(ch) || freq2[ch] < count) {
                    isEqual = false;
                    break;
                }
            }

            if(isEqual == true && r - l + 1 < minLen) {
                minLen = r - l + 1;
                st = l;
                end = r;
            }

            r++;
        }

        return minLen != INT_MAX ? s.substr(st, minLen) : "";
    }
};