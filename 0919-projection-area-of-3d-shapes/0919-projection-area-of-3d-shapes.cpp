class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy = 0, yz = 0, zx = 0;
        int n = grid.size();

        vector<int>rowMax(n, 0), columnMax(n, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] > rowMax[i])
                    rowMax[i] = grid[i][j];

                if(grid[j][i] > columnMax[i])
                    columnMax[i] = grid[j][i];

                if(grid[i][j])
                    xy++;
            }
        }

        yz = accumulate(rowMax.begin(), rowMax.end(), 0);
        zx = accumulate(columnMax.begin(), columnMax.end(), 0);

        return xy + yz + zx;
    }
};