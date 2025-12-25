class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater());

        long long ans = 0;
        for(int i=0; i<k; i++){
            happiness[i] -= i;

            if(happiness[i] <= 0)
                break;
            ans += happiness[i];
        }

        return ans;
    }
};