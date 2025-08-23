class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);

        for(char c : s)
            freq[c - 'a']++;
        for(char c : t)
            freq[c - 'a']--;

        int cnt = 0;
        for(int i=0; i<26; i++)
            cnt += abs(freq[i]);

        return cnt;
    }
};