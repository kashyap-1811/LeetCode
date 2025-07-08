class Solution {
public:
    void merge(int p, int q, int r, vector<int>& nums){
        vector<int>temp;
        int i = p, j = q+1;

        while(i<=q && j<=r){
            if(nums[i] >= nums[j])
                temp.push_back(nums[j++]);
            else
                temp.push_back(nums[i++]);
        }

        while(i <= q)
            temp.push_back(nums[i++]);

        while(j <= r)
            temp.push_back(nums[j++]);

        for(int k=p, x=0; k<=r; k++,x++)
            nums[k] = temp[x];
    }

    void mergeSort(int p, int r, vector<int>& nums){
        if(p >= r)
            return;
        
        int q = (p + r) / 2;
        mergeSort(p, q, nums);
        mergeSort(q+1, r, nums);
        merge(p, q, r, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size()-1, nums);

        return nums;
    }
};