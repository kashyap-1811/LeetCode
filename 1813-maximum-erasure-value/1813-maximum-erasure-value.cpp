class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int>prefix(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i++)
            prefix[i] += prefix[i-1];

        int maxSum = 0, lastIdx = -1;
        map<int, int>m;

        for(int i=0; i<nums.size(); i++){
            if(m.count(nums[i]) && lastIdx<m[nums[i]])
                lastIdx = m[nums[i]];

            m[nums[i]] = i;

            if(lastIdx != -1)
                maxSum = max(maxSum, prefix[i] - prefix[lastIdx]);
            else
                maxSum = prefix[i];
        }

        return maxSum;
    }
};