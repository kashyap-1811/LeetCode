class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        ans.push_back(1);   // Start with base beautiful array

        while(ans.size() < n) {
            vector<int> temp;

            // Generate all possible odd numbers
            for(int i = 0; i < ans.size(); i++) {
                if(ans[i] * 2 - 1 <= n)
                    temp.push_back(ans[i] * 2 - 1);
            }

            // Generate all possible even numbers
            for(int i = 0; i < ans.size(); i++) {
                if(ans[i] * 2 <= n)
                    temp.push_back(ans[i] * 2);
            }

            ans = temp;  // Update array
        }

        return ans;
    }
};