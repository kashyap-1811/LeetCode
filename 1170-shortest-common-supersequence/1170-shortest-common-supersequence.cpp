class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        vector<vector<char>>sol(m+1, vector<char>(n+1, '$'));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    sol[i][j] = 'd';
                }else if(dp[i-1][j] >= dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    sol[i][j] = 'u';
                }else{
                    dp[i][j] = dp[i][j-1];
                    sol[i][j] = 'p';
                }
            }
        }

        string ans = "";
        int i=m, j=n;

        while(i>0 && j>0){
            if(sol[i][j] == 'd'){
                ans += str1[i-1];
                i--;
                j--;
            }else if(sol[i][j] == 'u'){
                ans += str1[i-1];
                i--;
            }else if(sol[i][j] == 'p'){
                ans += str2[j-1];
                j--;
            }
        }    

        while(i > 0){
            ans += str1[i-1];
            i--;
        }

        while(j > 0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};