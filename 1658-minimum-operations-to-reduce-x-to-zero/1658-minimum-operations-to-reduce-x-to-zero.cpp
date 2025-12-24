class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum < x)
            return -1;
        if(sum == x)
            return n;
        x = (sum - x);

        int l = 0, r = 0;
        int windowSum = 0;
        int maxWindowSize = -1;

        while (r < n) {
            windowSum += nums[r];

            while (windowSum >= x && l <= r) {
                if (windowSum == x)
                    maxWindowSize = max(maxWindowSize, r - l + 1);
                windowSum -= nums[l];
                l++;
            }

            r++;
        }

        return maxWindowSize != -1 ? n - maxWindowSize : -1;
    }
};