class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        // Min-heap: {time, x, y}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, x, y] = pq.top(); pq.pop();

            if (x == n-1 && y == n-1)
                return time;

            if (vis[x][y])
                continue;

            vis[x][y] = true;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    pq.push({max(time, grid[nx][ny]), nx, ny});
                }
            }
        }

        return -1; // should never reach here
    }
};
