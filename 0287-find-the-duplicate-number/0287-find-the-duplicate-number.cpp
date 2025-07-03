class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int num = nums[i];
            if(num > n)
                num -= n;

            if(nums[ num - 1 ] > n)
                return num;
            else
                nums[ num - 1 ] += n;
        }

        return -1; //in case no duplicate
    }
};