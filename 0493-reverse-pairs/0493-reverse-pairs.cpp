class Solution {
public:
    int merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> temp;
        int cnt = 0;
        int i = mid, j = high;

        while(i >= low && j > mid) {
            if(1LL * nums[i] > 2LL * nums[j]) {
                cnt += (j - mid);
                i--;
            } else j--;
        }

        i = low, j = mid + 1;

        while(i <= mid && j <= high) {
            if(nums[i] > nums[j])
                temp.push_back(nums[j++]);
            else temp.push_back(nums[i++]);
        }

        while(i <= mid) 
            temp.push_back(nums[i++]);

        while(j <= high)
            temp.push_back(nums[j++]);

        for(int w=low, x=0; w<=high; w++, x++)
            nums[w] = temp[x];
        
        return cnt;
    }

    int mergeSort(vector<int> &nums, int low, int high) {
        if(low >= high)
            return 0;
        
        int cnt = 0;
        int mid = (low + high) / 2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += merge(nums, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};