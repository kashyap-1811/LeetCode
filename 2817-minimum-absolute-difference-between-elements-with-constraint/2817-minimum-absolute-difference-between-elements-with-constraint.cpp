class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int> s;
        for(int i=x; i<nums.size(); i++) 
            s.insert(nums[i]);
        
        int minDiff = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            if(i >= x)
                s.insert(nums[i-x]);
            
            if(i > 0 && x > 0 && i + x - 1< nums.size())
                s.erase(s.find(nums[i+x-1]));
            
            auto it = s.lower_bound(nums[i]);
            if(it != s.end()) {
                minDiff = min(minDiff, abs(nums[i] - *it));
            }
            if(it != s.begin()) {
                it--;
                minDiff = min(minDiff, abs(nums[i] - *it));
            }
        }

        return minDiff;
    }
};