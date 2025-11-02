class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '$'));

        for(auto g : guards)
            grid[g[0]][g[1]] = 'G';
        for(auto w : walls)
            grid[w[0]][w[1]] = 'W';
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 'G'){
                    // up
                    for(int k=i-1; k>=0; k--){
                        if(grid[k][j] == 'W' || grid[k][j] == 'G')
                            break;
                        grid[k][j] = '.';
                    }

                    // down
                    for(int k=i+1; k<m; k++){
                        if(grid[k][j] == 'W' || grid[k][j] == 'G')
                            break;
                        grid[k][j] = '.';
                    }

                    // left
                    for(int k=j-1; k>=0; k--){
                        if(grid[i][k] == 'W' || grid[i][k] == 'G')
                            break;
                        grid[i][k] = '.';
                    }

                    // right
                    for(int k=j+1; k<n; k++){
                        if(grid[i][k] == 'W' || grid[i][k] == 'G')
                            break;
                        grid[i][k] = '.';
                    }
                }
            }
        }

        int total = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '$')
                    total++;
            }
        }

        return total;
    }
};