class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            long long pilesPossible = 0;
            for (auto p : candies) {
                pilesPossible += (p / mid);
            }

            if (pilesPossible >= k) {
                ans = max(ans, mid);
                low = mid + 1;
            } else high = mid - 1;
        }

        return ans;
    }
};