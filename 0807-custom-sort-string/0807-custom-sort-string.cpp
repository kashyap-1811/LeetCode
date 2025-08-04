class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        vector<int> chars(26, 0);
        vector<bool> vis(26, false);

        for(int i=0; i<s.size(); i++){
            chars[s[i] - 'a']++;
        }

        for(int i=0; i<order.size(); i++){
            while(chars[order[i] - 'a'] > 0){
                ans += order[i];
                chars[order[i] - 'a']--;
            }
            vis[order[i] - 'a'] = true;
        }

        for(int i=0; i<26; i++){
            if(!vis[i]){
                while(chars[i] > 0){
                    ans += ('a' + i);
                    chars[i]--;
                }
            }
        }

        return ans;
    }
};