class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;

        // find the position where previous element is greater
        while (i > 0 && nums[i] <= nums[i-1])
            i--;
        
        if(i > 0) {
            // now we need to find minimum element which is > nums[i - 1]
            int minElement = nums[i];
            int idx = i;

            for (int j = i + 1; j < n; j++) {
                if(nums[j] < minElement && nums[j] > nums[i-1]) {
                    minElement = nums[i];
                    idx = j;
                }
            }

            // swap that with nums[i-1], so till 0 to i - 1 idx nextpermutation is done
            swap(nums[i-1], nums[idx]);
        }

        // now just need to sort elements from i + 1 to n
        sort(nums.begin() + i, nums.end());
    }
};
