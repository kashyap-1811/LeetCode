class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int can=nums[0];

        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
                can=nums[i];

            if(can==nums[i])
                count++;
            else 
                count--;
        }

        return can;
    }
};