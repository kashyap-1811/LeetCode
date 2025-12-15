class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long descent = 1;
        int descentDays = 1;

        for(int i=1; i<prices.size(); i++){
            if(prices[i] == prices[i-1]-1)
                descentDays++;
            else
                descentDays = 1;

            descent += descentDays;
        }

        return descent;
    }
};