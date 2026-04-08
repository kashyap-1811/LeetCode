class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq; // distance, price, x, y
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<tuple<int, int, int>> q; // x, y, steps
        q.push({start[0], start[1], 0});
        vis[start[0]][start[1]] = true;
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()) {
            auto [x, y, steps] = q.front();
            q.pop();

            if(grid[x][y] == 0)
                continue;
            
            if(grid[x][y] >= pricing[0] && grid[x][y] <= pricing[1])
                pq.push({steps, grid[x][y], x, y});

            for(int w=0; w<dir.size(); w++) {
                int nx = x + dir[w][0];
                int ny = y + dir[w][1];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, steps + 1});
                }
            }
        }

        
        vector<vector<int>> ans;
        while(k-- && pq.size()) {
            auto [_, __, x, y] = pq.top();
            pq.pop();
            // cout << _ << " " << __ << " " << x << " " << y << " " << endl;
            ans.push_back({x, y});
        }

        return ans;
    }
};
