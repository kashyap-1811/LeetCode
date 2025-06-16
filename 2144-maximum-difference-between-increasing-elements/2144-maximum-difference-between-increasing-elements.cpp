class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int min = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(min!=nums[i] && diff<nums[i]-min)
                diff = nums[i] - min;

            if(min > nums[i])
                min = nums[i];
        }

        return diff;
    }
};