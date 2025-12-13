class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string, string>>temp;

        for(int i=0; i<code.size(); i++){
            if(code[i].size() == 0 || (businessLine[i] != "electronics" && businessLine[i] != "grocery" && businessLine[i] != "pharmacy" && businessLine[i] != "restaurant"))
                continue;
            
            int j = 0;
            for(; j<code[i].size(); j++){
                if(!isalnum(code[i][j]) && code[i][j] != '_')
                    break;
            }

            if(j != code[i].size())
                continue;

            if(isActive[i])
                temp.push_back({businessLine[i], code[i]});
        }

        sort(temp.begin(), temp.end());

        vector<string>ans;
        for(int i=0; i<temp.size(); i++)
            ans.push_back(temp[i].second);

        return ans;
    }
};