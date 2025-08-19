class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0;
        int currMul = 1;

        for (int r = 0; r < nums.size(); r++) {
            currMul *= nums[r];

            while (l <= r && currMul >= k) {
                currMul /= nums[l];
                l++;
            }

            if (currMul < k) {
                ans += (r - l + 1);
            }

            // cout << ans << endl;
        }

        return ans;
    }
};