class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;

        for(int i : arr1) {
            string ss = to_string(i);
            for(int j=0; j<ss.size(); j++)
                st.insert(ss.substr(0, j+1));
        }

        int ans = 0;
        for(int i : arr2) {
            string ss = to_string(i);
            for(int j=0; j<ss.size() && st.count(ss.substr(0, j+1)); j++)
                ans = max(ans, j+1); 
        }

        return ans;
    }
};