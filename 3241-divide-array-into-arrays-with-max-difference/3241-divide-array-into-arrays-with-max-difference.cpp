class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>>ans;
        int ans_idx = -1;

        for(int i=0; i<n; i+=3){
            ans_idx++;
            ans.push_back({});
            for(int j=i; j<i+3; j++){
                ans[ans_idx].push_back(nums[j]);
            }

            if(ans[ans_idx][2] - ans[ans_idx][0] > k)
                return {};
        }

        return ans;
    }
};