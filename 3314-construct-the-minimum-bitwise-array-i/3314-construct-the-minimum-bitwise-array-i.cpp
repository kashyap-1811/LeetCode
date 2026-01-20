class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for(int i : nums){
            int k = 0;
            for(k=0; k<=i; k++){
                if((k | k+1) == i){
                    ans.push_back(k);
                    break;
                }
            }

            if(k == i+1)
                ans.push_back(-1);
        }

        return ans;
    }
};