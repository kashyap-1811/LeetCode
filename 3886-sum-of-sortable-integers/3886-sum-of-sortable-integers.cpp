class Solution {
public:
    bool isSortable(vector<int>& nums, int k) {
        int n = nums.size();
        int maxFromLastSubarray = 0;

        for (int i = 0; i < n; i += k) {
            bool rotationNeeded = false; // eg: 4 5 6 1 2 3
            int maxFromCurrSubarray = nums[i];

            if(nums[i] < maxFromLastSubarray)
                return false;

            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] < maxFromLastSubarray)
                    return false;

                if (nums[j - 1] > nums[j]) {
                    if (rotationNeeded)
                        return false;
                    rotationNeeded = true;
                }

                maxFromCurrSubarray = max(maxFromCurrSubarray, nums[j]);
            }

            if(rotationNeeded && nums[i] < nums[i+k-1]) // eg: 4 5 6 1 2 3 7
                return false;
            maxFromLastSubarray = maxFromCurrSubarray;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k == 0 && isSortable(nums, k))
                ans += k;
        }

        return ans;
    }
};