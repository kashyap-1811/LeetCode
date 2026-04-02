class Solution {
public:
    vector<int> dp;

    int memo(int i, vector<int> &days, vector<int> &costs) {
        if(i == days.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        // single day pass
        int single = costs[0] + memo(i+1, days, costs);

        // 7-day pass
        int j = i+1;
        while(j < days.size() && days[j] < days[i] + 7)
            j++;
        int seven = costs[1] + memo(j, days, costs);

        // 30-day pass
        int k = i+1;
        while(k < days.size() && days[k] < days[i] + 30)
            k++;
        int thirty = costs[2] + memo(k, days, costs);

        return dp[i] = min({single, seven, thirty});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp = vector<int>(days.size(), -1);
        return memo(0, days, costs);
    }
};