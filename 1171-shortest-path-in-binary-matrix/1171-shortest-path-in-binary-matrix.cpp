class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1)
            return -1;

        queue<pair<int, int>>q;
        vector<int>vis(n*n, false);
        q.push({0, 0});
        int path = 1;
        q.push({-1, -1});
        int lvl = 0;

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            cout<<i<<" "<<j<<endl;

            if(i==-1 && j==-1){
                path++;
                q.push({-1, -1});
                lvl++;

                if(lvl == n*n)
                    return -1;
                continue;
            }

            vis[i*n + j] = true;

            if(i==n-1 && j==n-1)
                return path;

            //check all eight directions
            //up
            if(i-1>=0 && !vis[(i-1)*n + (j)] && grid[i-1][j]==0){
                q.push({i-1, j});
                vis[(i-1)*n + (j)] = true;
            }

            //down
            if(i+1<n && !vis[(i+1)*n + (j)] && grid[i+1][j]==0){
                q.push({i+1, j});
                vis[(i+1)*n + (j)] = true;
            }

            //left
            if(j-1>=0 && !vis[(i)*n + (j-1)] && grid[i][j-1]==0){
                q.push({i, j-1});
                vis[(i)*n + (j-1)] = true;
            }

            //right
            if(j+1<n && !vis[(i)*n + (j+1)] && grid[i][j+1]==0){
                q.push({i, j+1});
                vis[(i)*n + (j+1)] = true;
            }

            //up-left
            if(i-1>=0 && j-1>=0 && !vis[(i-1)*n + (j-1)] && grid[i-1][j-1]==0){
                q.push({i-1, j-1});
                vis[(i-1)*n + (j-1)] = true;
            }

            //up-right
            if(i-1>=0 && j+1<n && !vis[(i-1)*n + (j+1)] && grid[i-1][j+1]==0){
                q.push({i-1, j+1});
                vis[(i-1)*n + (j+1)] = true;
            }

            //down-left
            if(i+1<n && j-1>=0 && !vis[(i+1)*n + (j-1)] && grid[i+1][j-1]==0){
                q.push({i+1, j-1});
                vis[(i+1)*n + (j-1)] = true;
            }

            //down-right
            if(i+1<n && j+1<n && !vis[(i+1)*n + (j+1)] && grid[i+1][j+1]==0){
                q.push({i+1, j+1});
                vis[(i+1)*n + (j+1)] = true;
            }
        }

        return -1;
    }
};