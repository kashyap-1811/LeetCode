class Solution {
public:
    string reverseWords(string s) {
        vector<string>str;
        stringstream ss(s);
        string words;

        while(ss>>words)
        {
            str.push_back(words);
        }

        string ans = str[str.size()-1];

        for(int i=str.size()-2; i>=0; i--)
        {   
            ans += " ";
            ans += (str[i]);
        }

        return ans;
    }
};