class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int min_index =
            distance(nums.begin(), min_element(nums.begin(), nums.end()));
        if (min_index == 0)
            return 1;

        int max_left = min_index;
        for (int i = min_index - 1; i >= 0; i--) {
            if (nums[i] > nums[max_left])
                max_left = i;
        }
        int min_right =
            distance(nums.begin(),
                     min_element(nums.begin() + min_index + 1, nums.end()));

        while (nums[min_right] < nums[max_left]) {
            min_index = min_right;
            // max_left =
            // distance(nums.begin(),max_element(nums.begin(),nums.begin()+min_index));
            max_left = min_index;
            for (int i = min_index - 1; i >= 0; i--) {
                if (nums[i] > nums[max_left])
                    max_left = i;
            }

            min_right =
                distance(nums.begin(),
                         min_element(nums.begin() + min_index + 1, nums.end()));
        }

        cout << max_left << " " << nums[max_left];

        int i = max_left + 1;
        for (; i < nums.size(); i++) {
            if (nums[i] >= nums[max_left]) {
                break;
            }
        }

        return i;
    }
};