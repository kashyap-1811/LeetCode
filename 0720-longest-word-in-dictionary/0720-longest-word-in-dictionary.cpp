class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            if(a.size() == b.size())
                return a < b;
            return a.size() < b.size();
        });

        unordered_set<string> s;
        s.insert({""});
        string ans = "";

        for(string word : words){
            if(s.find(word.substr(0, word.size() - 1)) != s.end()){
                if(ans.size() < word.size())
                    ans = word;
                
                s.insert({word});
            }
        }
        
        return ans;
    }
};