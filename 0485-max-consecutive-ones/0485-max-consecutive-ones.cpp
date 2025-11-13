class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int Max = 0;
        int curr = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0){
                Max = max(Max, curr);
                curr = 0;
            }else   curr++;
        }

        Max = max(Max, curr);
        return Max;
    }
};