class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>m;

        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;

        int freq = 0;
        int numbers = 0;

        for(auto it : m)
        {
            if(it.second > freq)
            {
                freq = it.second;
                numbers = it.second;
            }
            else if(it.second == freq)
                numbers += it.second;
        }

        return numbers;
    }
};