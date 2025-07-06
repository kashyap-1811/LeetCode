class Solution {
public:
    bool isSafe(int r, int c, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (i != c && board[r][i] == board[r][c])
                return false;
            if (i != r && board[i][c] == board[r][c])
                return false;
        }

        int cellr = (r / 3) * 3;
        int cellc = (c / 3) * 3;

        for (int i = cellr; i < cellr + 3; i++) {
            for (int j = cellc; j < cellc + 3; j++) {
                if ((i != r || j != c) && board[i][j] == board[r][c])
                    return false;
            }
        }

        return true;
    }

    bool sudoku(int r, int c, vector<vector<char>>& board) {
        if (r == 9)
            return true;

        int nextR = (c == 8) ? r + 1 : r;
        int nextC = (c + 1) % 9;

        if (board[r][c] != '.')
            return sudoku(nextR, nextC, board);

        for (int k = 1; k <= 9; k++) {
            board[r][c] = k + '0';
            if (isSafe(r, c, board)) {
                if (sudoku(nextR, nextC, board))
                    return true;
            }
            board[r][c] = '.';  // backtrack
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        sudoku(0, 0, board);
    }
};
