class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int gm = 0, lm = 0;

        for(int i=0; i<s.size(); i++){
            if(i>=k && isVowel(s[i-k]))
                lm--;
            if(isVowel(s[i]))
                lm++;
            
            gm = max(gm, lm);
        }

        return gm;
    }
};