class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};

        q.push({0, 0});
        vis[0][0] = true;
        int path = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int s = 0; s < size; s++) {
                auto [x, y] = q.front();
                q.pop();

                if (x == n - 1 && y == n - 1)
                    return path;

                for (int d = 0; d < 8; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                        !vis[nx][ny] && grid[nx][ny] == 0) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            path++;
        }

        return -1;
    }
};
