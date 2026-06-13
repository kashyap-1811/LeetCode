class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (auto &word : words) {
            int count = 0;
            for (char ch : word) 
                count += (weights[ch - 'a']);
            
            ans.push_back('z' - count % 26);
        }

        return ans;
    }
};