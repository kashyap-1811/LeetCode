class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<int, int>> freq(26, {-1, -1});

        for(int i=0; i<word.size(); i++) {
            char c = word[i];

            if(islower(c)) 
                freq[c - 'a'].first = i;
            
            else if (freq[tolower(c) - 'a'].second == -1)
                freq[tolower(c) - 'a'].second = i;
        }

        int cnt = 0;
        for(auto [a, b] : freq) {
            if(a != -1 && b != -1 && b > a)
                cnt++;
        }

        return cnt;
    }
};