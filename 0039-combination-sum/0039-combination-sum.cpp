class Solution {
public:
    void backtrack(int i, vector<vector<int>>& ans, vector<int>& candidates, vector<int>& X, int cSum, int& target){
        if(i == candidates.size())
            return;

        if(cSum == target){
            ans.push_back(X);
            return;
        }

        //Include
        if(cSum + candidates[i] <= target){
            X.push_back(candidates[i]);
            backtrack(i, ans, candidates, X, cSum+candidates[i], target);
            X.pop_back();
        }

        //Exclude
        backtrack(i+1, ans, candidates, X, cSum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>X;

        int cSum = 0;

        backtrack(0, ans, candidates, X, cSum, target);

        return ans;
    }
};