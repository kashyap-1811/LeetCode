class Solution {
public:
    void merge(vector<int> &nums, int l, int mid, int r) {
        vector<int> temp;
        int i = l, j = mid + 1;

        while(i <= mid && j <= r) {
            if(nums[i] < nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while(i <= mid)
            temp.push_back(nums[i++]);
        while(j <= r)
            temp.push_back(nums[j++]);

        for(int w=l, x=0; w<=r; w++, x++)
            nums[w] = temp[x];
    }

    int countPairs(vector<int> &nums, int l, int mid, int r) {
        int cnt = 0;
        int i = l, j = mid + 1;

        while(i <= mid) {
            while(j <= r && 1LL * nums[i] > 2LL * nums[j])
                j++;
            cnt += (j - (mid + 1));
            i++;
        }

        return cnt;
    }

    int mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r)
            return 0;
        
        int cnt = 0;
        int mid = (l + r) / 2;
        cnt += mergeSort(nums, l, mid);
        cnt += mergeSort(nums, mid + 1, r);
        cnt += countPairs(nums, l, mid, r);
        merge(nums, l, mid, r);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};