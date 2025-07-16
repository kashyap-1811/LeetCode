class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenOdd = 0, evenEven = 0, odd = 0;
        int lastEven = -1; // 1->Odd 0->Even

        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0){
                evenEven++;
                if(lastEven==-1 || lastEven==1){
                    odd++;
                    lastEven = 0;
                }
            }else{
                evenOdd++;
                if(lastEven==-1 || lastEven==0){
                    odd++;
                    lastEven=1;
                }
            }
        }

        return max({evenOdd, evenEven, odd});
    }
};