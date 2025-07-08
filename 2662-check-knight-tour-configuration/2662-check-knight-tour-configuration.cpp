class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) 
            return false;
            
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                bool larger = false, smaller = false;

                if(grid[i][j] == 0)
                    smaller = true;
                else if(grid[i][j] == n * n - 1)
                    larger = true;

                //left up two
                if(j-1>=0 && i-2>=0){
                    if(grid[i-2][j-1] == grid[i][j] - 1)
                        smaller = true;
                    else if(grid[i-2][j-1] == grid[i][j] + 1)
                        larger = true;
                }

                //left up one
                if(j-2>=0 && i-1>=0){
                    if(grid[i-1][j-2] == grid[i][j] - 1)
                        smaller = true;
                    else if(grid[i-1][j-2] == grid[i][j] + 1)
                        larger = true;
                }

                //left down two
                if(j-1>=0 && i+2<n){
                    if(grid[i+2][j-1] == grid[i][j] - 1)
                        smaller = true;
                    else if(grid[i+2][j-1] == grid[i][j] + 1)
                        larger = true;
                }

                //left down one
                if(j-2>=0 && i+1<n){
                    if(grid[i+1][j-2] == grid[i][j] - 1)
                        smaller = true;
                    else if(grid[i+1][j-2] == grid[i][j] + 1)
                        larger = true;
                }

                //right up two
                if(j+1<n && i-2>=0){
                    if(grid[i-2][j+1] == grid[i][j] - 1)
                        smaller = true;
                    else if(grid[i-2][j+1] == grid[i][j] + 1)
                        larger = true;
                }

                //right up one
                if(j+2<n && i-1>=0){
                    if(grid[i-1][j+2] == grid[i][j] - 1)
                        smaller = true;
                    else if(grid[i-1][j+2] == grid[i][j] + 1)
                        larger = true;
                }

                //right down two
                if(j+1<n && i+2<n){
                    if(grid[i+2][j+1] == grid[i][j] - 1)
                        smaller = true;
                    else if(grid[i+2][j+1] == grid[i][j] + 1)
                        larger = true;
                }

                //right down one
                if(j+2<n && i+1<n){
                    if(grid[i+1][j+2] == grid[i][j] - 1)
                        smaller = true;
                    else if(grid[i+1][j+2] == grid[i][j] + 1)
                        larger = true;
                }

                cout<< grid[i][j] <<" "<<smaller <<" " << larger<<endl;

                if(!smaller || !larger)
                    return false;
            }
        }

        return true;
    }
};