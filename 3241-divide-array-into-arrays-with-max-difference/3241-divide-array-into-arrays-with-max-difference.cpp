class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>>ans;
        int ans_idx = -1;

        for(int i=0; i<n; i+=3){
            vector<int>temp(nums.begin()+i, nums.begin()+i+3);
            ans.push_back(temp);
            ans_idx++;

            if(ans[ans_idx][2] - ans[ans_idx][0] > k)
                return {};
        }

        return ans;
    }
};