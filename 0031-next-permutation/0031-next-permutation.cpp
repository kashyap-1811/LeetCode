class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;

        while(i>0 && nums[i]<=nums[i-1])
            i--;

        // cout<<i;

        if(i > 0)
        {
            int min = nums[i];
            int idx = i;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j]<min && nums[j]>nums[i-1])
                {
                    min = nums[j];
                    idx = j;
                }    
            }

            swap(nums[i-1], nums[idx]);
        }
        
        sort(nums.begin()+i, nums.end());
    }
};