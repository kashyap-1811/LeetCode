class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> phone = {"", "", "abc", "def", 
                                "ghi", "jkl", "mno",
                                "pqrs", "tuv", "wxyz"
                              };

        vector<string>ans;

        for(char digit : digits) {
            int d = digit - '0';
            vector<string> temp;

            for(char c : phone[d]) {
                for(string &ss : ans) 
                    temp.push_back(ss + string(1, c));
                
                if(ans.size() == 0)
                    temp.push_back(string(1, c));
            }

            ans = temp;
        }

        return ans;
    }
};