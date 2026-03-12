class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int k = 0;
        bool check = false;

        vector<vector<int>>copy = grid;

        while(1)
        {
            check = false;

            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(grid[i][j] == 2)
                    {
                        if(i>0 && grid[i-1][j]==1)
                        {
                            copy[i-1][j] = 2;
                            check = true;
                        }
                        if(i+1<m && grid[i+1][j]==1)
                        {
                            copy[i+1][j] = 2;
                            check = true;
                        }
                        if(j>0 && grid[i][j-1]==1)
                        {
                            copy[i][j-1] = 2;
                            check = true;
                        } 
                        if(j+1<n && grid[i][j+1]==1)
                        {
                            copy[i][j+1] = 2;
                            check = true;
                        }
                    }
                }
            }

            if(check == false)
                break;
            
            grid = copy;
            k++;
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return k;
    }
};