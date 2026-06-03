class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});

            if (i + 1 >= k) {
                while (i - pq.top().second >= k)
                    pq.pop();
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};