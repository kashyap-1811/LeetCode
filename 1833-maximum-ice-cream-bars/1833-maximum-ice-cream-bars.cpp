class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int count = 0;
        int sum = 0;

        for (int c : costs) {
            sum += c;
            if (sum <= coins) 
                count++;
            else break;
        }

        return count;
    }
};