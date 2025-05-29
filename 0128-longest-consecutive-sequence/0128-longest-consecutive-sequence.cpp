class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
            
        sort(nums.begin(), nums.end());
        int lm = 1, gm = 1;

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-1]+1)
            {
                lm++;
                gm = max(lm, gm);
            }
            else if(nums[i] != nums[i-1])   
                lm = 1;
        }

        return max(lm, gm);
    }
};