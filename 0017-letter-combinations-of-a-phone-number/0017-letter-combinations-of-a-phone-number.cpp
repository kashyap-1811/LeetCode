class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};

        vector<string>phone = {"", "", "abc", "def", 
                                "ghi", "jkl", "mno",
                                "pqrs", "tuv", "wxyz"
                              };

        vector<string>ans;

        int digit = digits[0] - '0';
        for(int i=0; i<phone[digit].size(); i++)
            ans.push_back(string(1, phone[digit][i]));

        for(int i=1; i<digits.size(); i++){
            vector<string>temp;
            int digit = digits[i] - '0';

            for(int k=0; k<ans.size(); k++){
                string t = ans[k];
                for(int j=0; j<phone[digit].size(); j++){
                    temp.push_back(t + phone[digit][j]);
                }
            }

            ans = temp;
        }

        return ans;
    }
};