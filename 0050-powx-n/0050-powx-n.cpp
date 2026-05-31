class Solution {
public:
    double helper(double x, long long n) {
        if (n == 0) return 1.0;
        if (n % 2 == 0) {
            double half = helper(x, n / 2);
            return half * half;
        } else {
            double half = helper(x, (n - 1) / 2);
            return x * half * half;
        }
    }

    double myPow(double x, int n) {
        long long nLong = n; // Avoid overflow when n == INT_MIN
        double result = helper(x, abs(nLong));
        return n >= 0 ? result : 1.0 / result;
    }
};
