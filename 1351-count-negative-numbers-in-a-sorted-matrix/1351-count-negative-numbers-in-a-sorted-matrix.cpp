class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int i = m-1, j = 0; 
        int cnt = 0;

        while(j<n && i>=0){
            while(j<n && grid[i][j] >= 0)
                j++;
            
            cnt += (n - j);
            i--;
        }

        return cnt;
    }
};