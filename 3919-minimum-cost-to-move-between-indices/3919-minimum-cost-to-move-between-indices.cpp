class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;

        vector<int> closest(n);
        for (auto it = mp.begin(); it != mp.end(); it++) {
            auto prev = std::prev(it);
            auto next = std::next(it);

            if (it == mp.begin())
                closest[it->second] = next->second;
            else if (next == mp.end())
                closest[it->second] = prev->second;
            else if (abs(next->first - it->first) <
                     abs(prev->first - it->first))
                closest[it->second] = next->second;
            else if (abs(next->first - it->first) >
                     abs(prev->first - it->first))
                closest[it->second] = prev->second;
            else
                closest[it->second] = min(prev->second, next->second);
        }

        vector<int> prefix(n, 0), suffix(n, 0);

        // prefix[i] = total cost to reach index i from index 0
        for (int i = 0; i < n - 1; i++) {
            int cost = (closest[i] == i + 1) ? 1 : abs(nums[i + 1] - nums[i]);
            prefix[i + 1] = prefix[i] + cost;
        }

        // suffix[i] = total cost to reach index i from index n-1
        for (int i = n - 1; i > 0; i--) {
            int cost = (closest[i] == i - 1) ? 1 : abs(nums[i - 1] - nums[i]);
            suffix[i - 1] = suffix[i] + cost;
        }

        vector<int> ans;
        for (auto q : queries) {
            auto l = q[0], r = q[1];
            if(l < r)
                ans.push_back(prefix[r] - prefix[l]);
            else
                ans.push_back(suffix[r] - suffix[l]);
        }

        return ans;
    }
};