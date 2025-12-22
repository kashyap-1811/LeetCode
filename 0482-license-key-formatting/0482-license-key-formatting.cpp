class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int group = 0;

        for(int i=s.size()-1; i>=0; i--){
            char c = s[i];

            if(c != '-'){
                group++;
                ans += toupper(c);
            }

            if(group == k){
                group = 0;
                ans += "-";
            }
        }

        if(ans.size() && ans.back() == '-')
            ans.pop_back();

        reverse(ans.begin(), ans.end());
        return ans;
    }
};