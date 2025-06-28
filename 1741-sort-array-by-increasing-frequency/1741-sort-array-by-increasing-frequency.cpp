class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int>m;
        for(int& i : nums)
            m[i]++;

        sort(nums.begin(), nums.end(), [&m](int& a, int& b){
            if(m[a] != m[b]) return m[a] < m[b];
            else return a > b;
        });

        return nums;
    }
};