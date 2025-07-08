class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int range = maxVal - minVal + 1;

        vector<int> count(range, 0);
        vector<int> output(nums.size());

        for (int x : nums)
            count[x - minVal]++;

        for (int i = 1; i < range; ++i)
            count[i] += count[i - 1];

        for (int i = nums.size() - 1; i >= 0; --i)
            output[--count[nums[i] - minVal]] = nums[i];

        nums = output;
        return nums;
    }
};