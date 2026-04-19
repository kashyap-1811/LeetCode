class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++) {
            int num = nums[i];

            if(mp.count(num))
                ans = min(ans, i - mp[num]);

            vector<int> temp;
            while(num > 0) {
                temp.push_back(num % 10);
                num /= 10;
            }

            int st = 0;
            while(st < temp.size() && temp[st] == 0)
                st++;
            int ans = 0;
            while(st < temp.size()) {
                ans = ans * 10 + temp[st];
                st++;
            }

            mp[ans] = i;
        }

        return ans != INT_MAX ? ans : -1;
    }
};