class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int max = nums[0];
        int pos = 0;
        priority_queue<int> pq;
        pq.push(nums[0]);

        for(int i=1; i<nums.size(); i++){
            if(nums[i] < max){
                pos = i;
                max = pq.top();
            }else{
                pq.push(nums[i]);
            }
        }

        return pos + 1;
    }
};