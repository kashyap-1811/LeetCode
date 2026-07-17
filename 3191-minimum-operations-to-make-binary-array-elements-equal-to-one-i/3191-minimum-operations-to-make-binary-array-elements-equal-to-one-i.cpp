class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (i + 2 >= nums.size())
                    return -1;
                
                nums[i] = 1;
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
                count++;
            }
        }

        return count;
    }
};