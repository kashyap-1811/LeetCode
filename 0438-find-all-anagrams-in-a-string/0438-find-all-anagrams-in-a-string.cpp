class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans, alphabets(26, 0), compare(26, 0);

        for(char c : p)
            alphabets[c - 'a']++;

        for(int i=0; i<s.size(); i++){
            if(i >= p.size())
                compare[s[i - p.size()] - 'a']--;

            compare[s[i] - 'a']++;

            int k = 0;
            for(; k<26; k++){
                if(alphabets[k] != compare[k])
                    break;
            }

            if(k == 26)
                ans.push_back(i - p.size() + 1);
        }

        return ans;
    }
};