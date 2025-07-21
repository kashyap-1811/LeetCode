class Solution {
public:
    string makeFancyString(string s) {
        string str = "";
        int i=0;
        for(; i<=1 && i<s.size(); i++)
            str += s[i];
    
        for(; i<s.size(); i++)
        {
            if(s[i]==s[i-1] && s[i]==s[i-2])
                continue;
            str += s[i];
        }

        return str;
    }
};