class Solution {
public:
    void mark(vector<vector<char>>& board, vector<vector<bool>>&vis, int m, int n, int row, int col){
        //check horizontally
        for(int j=col; j<n; j++)
        {
            if(board[row][j] == 'X')
                vis[row][j] = true;
            else
                break;
        }

        //check vertically
        for(int i=row; i<m; i++)
        {
            if(board[i][col] == 'X')
                vis[i][col] = true;
            else
                break;
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int totalShips = 0;

        vector<vector<bool>>vis(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='X' && !vis[i][j])
                {
                    mark(board, vis, m, n, i, j);
                    totalShips++;
                }
            }
        }

        return totalShips;
    }
};