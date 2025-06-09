class Solution {
public:
    void mark(vector<vector<char>>& board, vector<vector<bool>>& regions, int &m, int &n, int i, int j){
        regions[i][j] = true;

        if(i-1>=0 && board[i-1][j]=='O' && !regions[i-1][j])
            mark(board, regions, m, n, i-1, j);

        if(i+1<m && board[i+1][j]=='O' && !regions[i+1][j])
            mark(board, regions, m, n, i+1, j);

        if(j-1>=0 && board[i][j-1]=='O' && !regions[i][j-1])
            mark(board, regions, m, n, i, j-1);

        if(j+1<n && board[i][j+1]=='O' && !regions[i][j+1])
            mark(board, regions, m, n, i, j+1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>>regions(m, vector<bool>(n, false));

        //check 1st row
        for(int j=0; j<n; j++)
        {
            if(board[0][j]=='O' && !regions[0][j])
                mark(board, regions, m, n, 0, j);
        }

        //check last row
        for(int j=0; j<n; j++)
        {
            if(board[m-1][j]=='O' && !regions[m-1][j])
                mark(board, regions, m, n, m-1, j);
        }

        //check 1st column
        for(int i=0; i<m; i++)
        {
            if(board[i][0]=='O' && !regions[i][0])
                mark(board, regions, m, n, i, 0);
        }

        //check last column
        for(int i=0; i<m; i++)
        {
            if(board[i][n-1]=='O' && !regions[i][n-1])
                mark(board, regions, m, n, i, n-1);
        }

        //convert O -> X
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' && !regions[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};