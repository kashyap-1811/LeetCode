class Solution {
public:
    bool check(vector<int>& nums) {
        bool rotated = false;

        for(int i=1; i<nums.size(); i++) {
            if(rotated == true) {
                if(nums[i] < nums[i-1] || nums[i] > nums[0])
                    return false;
            }

            else if(nums[i] < nums[i-1]) {
                rotated = true;
                if(nums[i] > nums[0])
                    return false;
            }
        }

        return true;
    }
};