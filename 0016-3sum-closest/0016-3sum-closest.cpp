class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++)
            cout<<nums[i]<<" ";

        int ans = INT_MAX/2;
        
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;

            int j = i+1;
            int k = n-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(abs(target-ans) > abs(abs(target - sum)))
                    ans = sum;

                if(sum < target)
                    j++;
                else if(sum > target)
                    k--;
                else
                    return ans;
            }
        }

        return ans;
    }
};