class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = (nums.size() + 1) / 2 - 1, j = nums.size() - 1;

        vector<int> temp;
        // 1 1 2 2 2 3
        while (i >= 0) {
            temp.push_back(nums[i]);
            temp.push_back(nums[j]);
            i--;
            j--;
        }

        if(nums.size() % 2 == 1)
            temp.pop_back();

        nums = temp;
    }
};