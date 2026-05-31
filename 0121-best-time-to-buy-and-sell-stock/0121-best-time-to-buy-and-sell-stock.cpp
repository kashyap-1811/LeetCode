class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n, INT_MAX);

        buy[0] = prices[0];
        for(int i=1; i<n; i++)  
            buy[i] = min(buy[i-1], prices[i]);
        
        int maxProfit = 0;
        for(int i=0; i<n; i++)
            maxProfit = max(maxProfit, prices[i] - buy[i]);

        return maxProfit;
    }
};