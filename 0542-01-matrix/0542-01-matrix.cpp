class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), -1));

        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            int currSteps = ans[i][j];

            vector<int> dx{-1, 1, 0, 0};
            vector<int> dy{0, 0, -1, 1};

            for(int k=0; k<4; k++){
                int nr = i + dx[k];
                int nc = j + dy[k];

                if(nr>=0 && nc>=0 && nr<mat.size() && nc<mat[0].size() && ans[nr][nc] == -1){
                    ans[nr][nc] = currSteps + 1;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};