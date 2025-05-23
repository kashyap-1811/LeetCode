class Solution {
public:
    bool check(vector<int>& nums) {
        int i;
        int j;

        for(i=1; i<nums.size(); i++)
        {
            if(nums[i] < nums[i-1]){
                cout<<i<<endl;
                break;
            }
        }

        for(j=i+1; j<nums.size();j++)
        {
            if(nums[j] < nums[j-1]){
                cout<<"H"<<j<<" "<<nums[j]<<endl;
                return false;
            }
        }

        if(i!=nums.size() && nums[nums.size()-1]>nums[0])
            return false;

        for(j=1; j<i; j++)
        {
            if(nums[j]<nums[j-1]){
                cout<<"Y"<<j<<" "<<nums[j]<<endl;
                return false;
            }
        }

        return true;
    }
};