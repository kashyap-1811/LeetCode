class Solution {
public:
    string make(string s, bool first, int& i){
        string ans = "";
        int n = 0;

        for(; i<s.size(); i++){
            if(isalpha(s[i]))
                ans += s[i];
            else if(isdigit(s[i])){
                n = n*10 + (s[i] - '0');
            }else if(s[i] == '['){
                i++;
                string temp = make(s, false, i);
                ans += temp; n--;

                while(n > 0){
                    ans += temp;
                    n--;
                }
                n = 0;
            }else if(s[i] == ']' && !first)
                break;
        }
        
        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        return make(s, true, i);
    }
};