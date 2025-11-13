class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            int idx = -1;

            if(nums[i] > 0)
                idx = nums[i] - 1;
            else
                idx = (nums[i] + n + i) - 1;

            if(nums[idx] > 0){
                nums[idx] -= (n + idx);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};