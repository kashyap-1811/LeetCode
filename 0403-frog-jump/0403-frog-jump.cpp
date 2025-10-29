class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> dp;

    bool helper(int idx, int k, vector<int>& stones, int n) {
        if (idx == n - 1)
            return true;
        if (dp[idx].count(k))
            return dp[idx][k];

        for (int d = -1; d <= 1; d++) {
            int jump = k + d;
            if (jump <= 0) continue;

            int nextPos = stones[idx] + jump;
            int nextIdx = lower_bound(stones.begin() + idx + 1, stones.end(), nextPos) - stones.begin();
            if (nextIdx < n && stones[nextIdx] == nextPos) {
                if (helper(nextIdx, jump, stones, n))
                    return dp[idx][k] = true;
            }
        }

        return dp[idx][k] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false; // first jump must be 1
        return helper(1, 1, stones, n);
    }
};
