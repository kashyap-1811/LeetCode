class Solution {
public:
    int m;
    int n; 

    void fillArr(vector<vector<int>>& grid, int lvl, int k) {
        int i = lvl;
        int j = lvl;
        char dir = 'R';
        vector<int> arr;

        do {
            arr.push_back(grid[i][j]);

            if (dir == 'R') {
                j++;
                if(j == n - lvl) {
                    dir = 'D';
                    j = n - lvl - 1;
                    i++;
                }
            } else if (dir == 'D') {
                i++;
                if(i == m - lvl) {
                    dir = 'L';
                    i = m - lvl - 1;
                    j--;
                }
            } else if (dir == 'L') {
                j--;
                if(j == lvl - 1) {
                    dir = 'U';
                    i--;
                    j = lvl;
                }
            } else {
                i--;
            }
        } while(i != lvl || j != lvl);

        int lvlK = k % arr.size();
        int cnt = 0;
        i = lvl;
        j = lvl;
        dir = 'R';

        do {
            grid[i][j] = arr[(cnt + lvlK) % arr.size()];
            cnt++;

            if (dir == 'R') {
                j++;
                if(j == n - lvl) {
                    dir = 'D';
                    j = n - lvl - 1;
                    i++;
                }
            } else if (dir == 'D') {
                i++;
                if(i == m - lvl) {
                    dir = 'L';
                    i = m - lvl - 1;
                    j--;
                }
            } else if (dir == 'L') {
                j--;
                if(j == lvl - 1) {
                    dir = 'U';
                    i--;
                    j = lvl;
                }
            } else {
                i--;
            }
        } while(i != lvl || j != lvl);
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        for(int i=0; i<min(m/2, n/2); i++)
            fillArr(grid, i, k);

        return grid;
    }
};

/*

01 02 03 04 05 06
07 08 09 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24

*/