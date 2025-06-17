class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int>dp(triangle[0].begin(), triangle[0].end());

        // cout<<dp[0]<<endl;

        for(int i=1; i<triangle.size(); i++){
            int n = triangle[i].size();
            vector<int>temp(n, INT_MAX);

            temp[0] = triangle[i][0] + dp[0];

            for(int j=1; j<n-1; j++){
                temp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            }

            temp[n-1] = triangle[i][n-1] + dp[n-2];

            dp = temp;

            // for(int i=0; i<dp.size(); i++)
            //     cout<<dp[i]<<" ";
            // cout<<endl;
        }

        return *min_element(dp.begin(), dp.end());
    }
};