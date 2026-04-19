class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int i) {
        int ans = -1;
        int st = i, end = nums.size() - 1;

        while (st <= end) {
            int mid = (st + end) / 2;

            if (nums[mid] >= target) {
                ans = max(ans, mid);
                st = mid + 1;
            }
            else
                end = mid - 1;
        }

        return ans;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int j = binarySearch(nums2, nums1[i], i);
            // cout << i << " " << j << endl;
            maxDist = max(maxDist, j - i);
        }

        return maxDist;
    }
};