class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        multiset<int> ms;
        for(int i=indexDifference; i<nums.size(); i++)
            ms.insert(nums[i]);
        
        for(int i=0; i<nums.size(); i++) {
            if(i >= indexDifference)
                ms.insert(nums[i-indexDifference]);
            
            if(i > 0 && indexDifference > 0 && i + indexDifference - 1 < nums.size())
                ms.erase(ms.find(nums[i+indexDifference-1]));
            
            // compare with begin && end
            if(ms.size() > 0 && (
                (abs(*ms.begin() - nums[i]) >= valueDifference)
                             ||
                (abs(*prev(ms.end()) - nums[i]) >= valueDifference)
            )) {
                for(int k=0; k<nums.size(); k++) {
                    if(abs(i - k) >= indexDifference && abs(nums[i] - nums[k]) >= valueDifference)
                        return vector<int> {i, k};
                }
            }

        }

        return vector<int>{-1, -1};
    }
};