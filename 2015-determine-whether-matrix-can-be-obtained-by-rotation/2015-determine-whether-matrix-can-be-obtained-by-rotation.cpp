class Solution {
public:
    void rotate(vector<vector<int>> &mat){
        for(int i=0; i<mat.size(); i++){
            for(int j=i; j<mat[i].size(); j++)
                swap(mat[i][j], mat[j][i]);

            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool check(vector<vector<int>>& mat, vector<vector<int>>& target){
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++)
                if(mat[i][j] != target[i][j])   return false;
        }

        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(check(mat, target))
            return true;
        
        for(int i=0; i<3; i++){
            rotate(mat);

            if(check(mat, target))
                return true;
        }

        return false;
    }
};