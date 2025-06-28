class Solution {
public:
    string frequencySort(string s) {
        map<char, int>m;
        for(char c : s)
            m[c]++;

        sort(s.begin(), s.end(), [&m](const char& a, const char& b){
            if(m[a] != m[b])    return m[a] > m[b];
            else return a < b;
        });

        return s;
    }
};