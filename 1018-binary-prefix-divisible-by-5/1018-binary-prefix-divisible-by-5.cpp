class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int n = 0;

        for(int i : nums){
            n = n*2 + i;

            ans.push_back(n % 5 == 0);
            n %= 5;
        }

        return ans;
    }
};