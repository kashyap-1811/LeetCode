class NumMatrix {
public:
    vector<vector<int>>left, down;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        left.clear();
        for(int i=0; i<m; i++){
            vector<int>temp(n, 0);

            temp[0] = matrix[i][0];
            for(int j=1; j<n; j++)
                temp[j] = temp[j-1] + matrix[i][j];

            left.push_back(temp);
        }

        down.clear();
        down.push_back(left[0]);
        for(int i=1; i<m; i++){
            vector<int>temp(n, 0);
            
            for(int j=0; j<n; j++)
                temp[j] = down[i-1][j] + left[i][j];

            down.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = down[row2][col2];
        // cout << down[row2][col2] << " ";

        if(row1 > 0){
            sum -= down[row1 - 1][col2];
            // cout << down[row1 -1][col2] << " ";
        }
        
        if(col1 > 0){
            sum -= down[row2][col1 - 1];
            // cout << down[row2][col1 - 1] << " ";
        }

        if(row1 > 0 && col1 > 0){
            sum += down[row1 - 1][col1 - 1];
            cout << down[row1 - 1][col1 - 1] << endl;
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */