class Solution {
public:
    vector<vector<int>> dp;
    vector<int> primes;

    int memo(int n, int idx) {
        if (idx == 0)
            return n;

        if (dp[n][idx] != -1)
            return dp[n][idx];

        //  not take
        int not_take = memo(n, idx - 1);

        // take
        int take = INT_MAX;
        if (primes[idx] <= n) {
            int numbersNeeded = n / primes[idx];
            take = numbersNeeded + memo(n - numbersNeeded * primes[idx], idx - 1);
        }
        

        return dp[n][idx] = min(not_take, take);
    }

    int numSquares(int n) {
        int pNums = 0;
        for (int i = 1; i * i <= n; i++) {
            primes.push_back(i * i);
            // cout << primes.back() << " ";
            pNums++;
        }

        dp = vector<vector<int>>(n + 1, vector<int>(pNums, -1));
        return memo(n, pNums - 1);
    }
};