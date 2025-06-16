class Solution {
public:
    int maxDiff(int num) {
        vector<int>nums;

        while(num != 0){
            nums.push_back(num%10);
            num /= 10;
        }

        reverse(nums.begin(), nums.end());

        int max = 0;
        int changeMaxDigit = -1;

        int min = 0;
        int changeMinDigit = -1;
        int changeTo = -1;

        //for min
        if(nums[0] != 1){
            changeMinDigit = nums[0];
            changeTo = 1;
        }

        for(int i=0; i<nums.size(); i++){
            //for max
            if(nums[i] == 9)
                max = max*10 + 9;
            else if(changeMaxDigit == -1){
                changeMaxDigit = nums[i];
                max = max*10 + 9;
            }
            else if(changeMaxDigit == nums[i])
                max = max*10 + 9;
            else
                max = max*10 + nums[i];

            //for min
            if(nums[i] == 1){
                min = min*10 + 1;
            }
            else if(nums[i] == 0){
                min = min*10 + 0;
            }else if(changeMinDigit == -1){
                changeMinDigit = nums[i];
                changeTo = 0;
                min = min*10 + changeTo;
            }else if(changeMinDigit == nums[i]){
                min = min*10 + changeTo;
            }else{
                min = min*10 + nums[i];
            }
        }

        // cout<<max<<" "<<min;

        return max-min;
    }
};