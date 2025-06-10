class Solution {
public:
    vector<string>res;
    void backtrack(string s,string t, int i, string deg[]){
        if(i==s.size()){
            res.push_back(t);
            return;
        }
        int j=s[i]-'0';
        for(char c:deg[j]){
            backtrack(s,t+c,i+1,deg);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        string deg[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        backtrack(digits,"",0,deg);
        return res;
    }
};