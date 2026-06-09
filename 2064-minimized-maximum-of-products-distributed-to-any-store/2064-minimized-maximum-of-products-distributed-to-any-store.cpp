class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            int requiredStores = 0;

            for (int q : quantities) {
                requiredStores += (q + mid - 1) / mid; // Ceiling division without floating-point arithmetic
            }

            if (requiredStores > n) {
                left = mid + 1; // We need more stores, increase the maximum limit
            } else {
                right = mid; // Try a smaller maximum if possible
            }
        }

        return left;
    }
};