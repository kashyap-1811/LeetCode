class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;
        for(auto e : grid) 
            for(auto i : e)
                total += i;

        long long curr = 0;
        for(auto e : grid) {
            for(auto i : e)
                curr += i;
            if(curr != 0 && curr == total-curr)
                return true;
        }

        curr = 0;
        for(int j=0; j<grid[0].size(); j++) {
            for(int i=0; i<grid.size(); i++)
                curr += grid[i][j];
            
            if(curr != 0 && curr == total-curr)
                return true;
        }

        return false;
    }
};