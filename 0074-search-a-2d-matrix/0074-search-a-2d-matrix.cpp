class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int st = 0;
        int end = m-1;

        while(st <= end){
            int mid = (st + end) / 2;

            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] > target)
                end--;
            else
                st++;
        }

        int row = st-1;
        if(row<0 || row==m)
            return false;
            
        st = 0;
        end = n-1;

        while(st <= end){
            int mid = (st + end) / 2;

            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] > target)
                end--;
            else
                st++;
        }

        return false;
    }
};