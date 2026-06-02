class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currSum = 0;
        int total = 0;

        for (int i : nums) {
            currSum += i;

            if(mp.count(currSum - k))
                total += mp[currSum - k];
            
            mp[currSum]++;
        }

        return total;
    }
};