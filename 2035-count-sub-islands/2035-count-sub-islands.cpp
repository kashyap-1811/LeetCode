class Solution {
public:
    void recurse(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& vis, int& m, int& n, bool& check){
        vis[i][j] = true;
        if(grid1[i][j] != 1)
            check = false;

        // up
        if(i-1>=0 && grid2[i-1][j]==1 && !vis[i-1][j])
            recurse(i-1, j, grid1, grid2, vis, m, n, check);

        // down
        if(i+1<m && grid2[i+1][j]==1 && !vis[i+1][j])
            recurse(i+1, j, grid1, grid2, vis, m, n, check);

        //left
        if(j-1>=0 && grid2[i][j-1]==1 && !vis[i][j-1])
            recurse(i, j-1, grid1, grid2, vis, m, n, check);

        //right
        if(j+1<n && grid2[i][j+1]==1 && !vis[i][j+1])
            recurse(i, j+1, grid1, grid2, vis, m, n, check);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        int count = 0;
        vector<vector<bool>>vis(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid2[i][j]==1 && !vis[i][j]){
                    bool check = true;
                    recurse(i, j, grid1, grid2, vis, m, n, check);

                    if(check)
                        count++;
                }
            }
        }

        return count;
    }
};