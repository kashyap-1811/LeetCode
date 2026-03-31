class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void recurse(int n, int k, int i) {
        if (k == 0) {
            ans.push_back(temp);
            return;
        }

        while (i <= n) {
            temp.push_back(i);
            recurse(n, k-1, i+1);
            temp.pop_back();
            i++;
        }
    }

    vector<vector<int>> combine(int n, int k) {
        recurse(n, k, 1);
        return ans;
    }
};