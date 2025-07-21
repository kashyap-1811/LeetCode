class Solution {
public:
    int recurse(int i, vector<int>& slices, vector<vector<vector<int>>>& dp, int& n, bool firstTake, int count) {
        if (i >= n || count == 0)
            return 0;

        if (dp[i][count][firstTake] != -1)
            return dp[i][count][firstTake];

        int take = 0;
        if (i == 0)
            take = slices[i] + recurse(i + 2, slices, dp, n, true, count - 1);
        else if (i == n - 1 && firstTake)
            take = 0; // cannot take last slice if first was taken
        else
            take = slices[i] + recurse(i + 2, slices, dp, n, firstTake, count - 1);

        int notTake = recurse(i + 1, slices, dp, n, firstTake, count);

        return dp[i][count][firstTake] = max(take, notTake);
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int count = n / 3;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(count + 1, vector<int>(2, -1)));
        return recurse(0, slices, dp, n, false, count);
    }
};
