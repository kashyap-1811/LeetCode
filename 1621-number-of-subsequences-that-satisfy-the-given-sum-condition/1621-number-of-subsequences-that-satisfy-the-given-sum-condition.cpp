class Solution {
public:
    int mod = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Precompute powers of 2
        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }

        long long total = 0;
        int i = 0, j = n - 1;

        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                total = (total + pow2[j - i]) % mod;
                i++;
            } else {
                j--;
            }
        }

        return total;
    }
};
