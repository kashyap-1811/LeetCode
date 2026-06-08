class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;
        int mid = (st + end) / 2;

        while (st <= end) {
            mid = (st + end) / 2;

            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 0)
                    end = mid - 1;
                else
                    st = mid + 1;
            } 
            
            else if (mid < n - 1 && nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 0) 
                    st = mid + 1;
                else
                    end = mid - 1;
            } 
            
            else break;
        }

        return nums[mid];
    }
};