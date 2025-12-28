class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int last_negative_index;
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<grid[0].size();i++)
        {
            if(grid[grid.size()-1][i] < 0)
            {
                last_negative_index = i;
                ans += (m-i);
                break;
            }
        }

        for(int i=grid.size()-2;i>=0;i--)
        {
            while(last_negative_index < m && grid[i][last_negative_index] >= 0)
            {
                last_negative_index++;
            }
            ans+=(m - last_negative_index);
        }

        return ans;
    }
};