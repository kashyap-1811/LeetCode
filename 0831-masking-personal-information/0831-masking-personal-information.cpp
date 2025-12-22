class Solution {
public:
    string email(string s){
        string ans = "";
        ans += tolower(s[0]);
        ans += "*****";
        bool add = false;

        for(int i=1; i<(int)s.size(); i++){
            if(add)
                ans += tolower(s[i]);
            else if(s[i] == '@'){
                add = true;
                i -= 2;
            }
        }

        return ans;
    }

    string phone(string s){
        string ans = "";
        queue<char> q;

        for(char &c : s){
            if(isdigit(c))
                q.push(c);
        }

        if(q.size() == 11)
            ans += "+*-";
        else if(q.size() == 12)
            ans += "+**-";
        else if(q.size() == 13)
            ans += "+***-";
        
        ans += "***-***-";

        while(!q.empty()){
            if(q.size() <= 4)
                ans += q.front();
            q.pop();
        }

        return ans;
    }

    string maskPII(string s) {
        return isalpha(s[0]) ? email(s) : phone(s);
    }
};