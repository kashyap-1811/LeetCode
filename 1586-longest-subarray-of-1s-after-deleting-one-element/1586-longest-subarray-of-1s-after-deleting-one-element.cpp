class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroIdx = -1;
        int gm = INT_MIN;
        int lm = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                lm++;
            }else{
                if(zeroIdx != -1){
                    lm = i - zeroIdx - 1;
                }
                zeroIdx = i;
            }

            gm = max(lm, gm);
        }

        return gm==nums.size() ? gm-1 : gm;
    }
};