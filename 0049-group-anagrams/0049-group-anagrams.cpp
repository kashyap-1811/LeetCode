class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>copy = strs;
        for(int i=0; i<copy.size(); i++)
            sort(copy[i].begin(), copy[i].end());

        vector<vector<string>>ans;
        unordered_map<string, int>m;
        int x = -1;

        for(int i=0; i<copy.size(); i++){
            if(m.find(copy[i]) != m.end()){
                ans[m[copy[i]]].push_back(strs[i]);
            }else{
                x++;
                ans.push_back({});
                ans[x].push_back(strs[i]);
                m[copy[i]] = x;
            }
        }

        return ans;
    }
};