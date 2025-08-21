class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int ogColor = grid[row][col];

        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = true;

        vector<int> dx{-1, 1, 0, 0};
        vector<int> dy{0, 0, -1, 1};

        vector<pair<int,int>> borders; // store border cells

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            bool isBorder = false;
            for (int k = 0; k < 4; k++) {
                int nr = i + dx[k], nc = j + dy[k];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                    isBorder = true; // touches boundary
                } else if (grid[nr][nc] != ogColor) {
                    isBorder = true; // touches different color
                } else if (!vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }

            if (isBorder) borders.push_back({i, j});
        }

        // Recolor only border cells
        for (auto [i, j] : borders) {
            grid[i][j] = color;
        }

        return grid;
    }
};
