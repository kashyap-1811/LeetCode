class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //counting sort
        int xMax = *max_element(costs.begin(), costs.end());
        vector<int> freq(xMax + 1, 0);

        for (int c : costs)
            freq[c]++;
        
        int count = 0;
        for (int x = 1; x <= xMax; x++) {
            int f = freq[x];

            if (f == 0)
                continue;
            
            int buy = min(coins / x, f);
            if (buy == 0) break;

            count += buy;
            coins -= buy * x;
        }

        return count;
    }
};