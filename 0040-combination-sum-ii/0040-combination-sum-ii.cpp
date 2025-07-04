class Solution {
public:
    void backtrack(int start, int target, vector<int>& candidates,
                   vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        backtrack(0, target, candidates, temp, ans);
        
        return ans;
    }
};
