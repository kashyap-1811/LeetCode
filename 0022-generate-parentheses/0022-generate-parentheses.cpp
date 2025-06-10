class Solution {
public:
    void backtrack(int i, const int& n, vector<string>& ans, string temp, int open, int close){
        if(i == 2*n){
            ans.push_back(temp);
            return;
        }

        if(open < n)
            backtrack(i+1, n, ans, temp+'(', open+1, close);

        if(close < open)
            backtrack(i+1, n, ans, temp+')', open, close+1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;

        string temp = "(";
        int open = 1;
        int close = 0;

        backtrack(1, n, ans, temp, open, close);

        return ans;
    }
};