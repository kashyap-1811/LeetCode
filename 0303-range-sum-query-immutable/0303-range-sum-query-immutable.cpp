class NumArray {
public:
    vector<int>preFix;
    NumArray(vector<int>& nums) {
        preFix.resize(nums.size(), 0);

        preFix[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
            preFix[i] = nums[i] + preFix[i-1];
    }
    
    int sumRange(int left, int right) { 
        if(left != 0)
            return preFix[right] - preFix[left-1];
        else
            return preFix[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */