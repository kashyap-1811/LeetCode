class Solution {
public:
    bool isSafe(int k, int i, vector<int>& sol){
        for(int j=0; j<k; j++){
            if(sol[j]==i || abs(j-k)==abs(sol[j]-i))
                return false;
        }

        return true;
    }

    void NQueen(int k, int n, vector<int>& sol, int& count){
        for(int i=0; i<n; i++){

            if(isSafe(k, i, sol)){
                sol[k] = i;
                if(k == n-1){
                    count++;
                    return;
                }else{
                    NQueen(k+1, n, sol, count);
                }
            }
        }
    }

    int totalNQueens(int n) {
        vector<int>sol(n, -1);
        int count = 0;

        NQueen(0, n, sol, count);

        return count;
    }
};