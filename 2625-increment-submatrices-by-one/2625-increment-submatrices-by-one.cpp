class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for(auto &q : queries){
            int r1 = q[0], c1 = q[1];
            int r2 = q[2], c2 = q[3];

            for(int i=r1; i<=r2; i++){
                mat[i][c1]++;
                if(c2 + 1 < n)
                    mat[i][c2 + 1]--;
            }
        }

        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                count += mat[i][j];
                mat[i][j] = count;
            }
        }

        return mat;
    }
};