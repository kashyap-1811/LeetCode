class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;

        while(j < n && nums[j] < 0)
            j++;
        
        i = j-1;

        vector<int> ans;
        while(i>=0 && j<n){
            if(abs(nums[i]) < nums[j]){
                ans.push_back(nums[i] * nums[i]);
                i--;
            }else{
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
        }

        while(i >= 0){
            ans.push_back(nums[i] * nums[i]);
            i--;
        }

        while(j < n){
            ans.push_back(nums[j] * nums[j]);
            j++;
        }

        return ans;
    }
};