class Solution {
private: 
    int n;

    pair<int, int> cell(int curr) {
        int row = n - 1 - (curr - 1) / n;
        int col = (curr - 1) % n;
        if ((n - row) % 2 == 0)
            col = n - 1 - col;
        return {row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        vector<bool> vis(n*n + 1, false);

        queue<pair<int,int>> q;
        q.push({1, 0});
        vis[1] = true;

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            if (curr == n*n)
                return steps;

            for (int i = 1; i <= 6; i++) {
                int next = curr + i;
                if (next > n*n) break;

                auto [r, c] = cell(next);

                if (board[r][c] != -1)
                    next = board[r][c];

                if (!vis[next]) {
                    vis[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};