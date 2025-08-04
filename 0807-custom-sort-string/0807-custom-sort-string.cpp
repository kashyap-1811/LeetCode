class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        vector<bool>vis(s.size(), false);

        for(int i=0; i<order.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(s[j] == order[i]){
                    ans += s[j];
                    vis[j] = true;
                }
            }
        }

        for(int j=0; j<s.size(); j++){
            if(!vis[j])
                ans += s[j];
        }

        return ans;
    }
};