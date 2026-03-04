class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        for(int i=0; i<m; i++) {
            int one = -1;
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1){
                    if(one != -1) {
                        one = -1;
                        break;
                    }
                    one = j;
                }
            }

            if(one == -1)
                continue;
            
            int ones = 0;
            for(int j=0; j<m; j++) {
                if(mat[j][one] == 1)
                    ones++;
            }

            if(ones == 1)
                ans++;
        }

        return ans;
    }
};