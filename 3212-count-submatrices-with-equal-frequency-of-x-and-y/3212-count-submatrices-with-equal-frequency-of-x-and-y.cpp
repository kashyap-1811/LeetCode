class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<int, int>>> prefix(n, vector<pair<int, int>>(m, {0,0}));
        int count = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 'X')
                    prefix[i][j].first++;
                else if(grid[i][j] == 'Y')
                    prefix[i][j].second++;

                if(i > 0) {
                    prefix[i][j].first += prefix[i-1][j].first;
                    prefix[i][j].second += prefix[i-1][j].second;
                }

                if(j > 0) {
                    prefix[i][j].first += prefix[i][j-1].first;
                    prefix[i][j].second += prefix[i][j-1].second;
                }

                if(i > 0 && j > 0) {
                    prefix[i][j].first -= prefix[i-1][j-1].first;
                    prefix[i][j].second -= prefix[i-1][j-1].second;
                }

                if(prefix[i][j].first != 0 && prefix[i][j].first == prefix[i][j].second)
                    count++;
                // cout << i << " " << j << " " << count << endl;
            }
        }

        return count;
    }
};