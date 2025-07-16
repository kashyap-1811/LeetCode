/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preOrder(TreeNode* root, vector<double>& ans, int lvl, map<int, int>& m){
        if(!root) return;

        if(ans.size() <= lvl){
            ans.push_back(root->val);
        }else{
            ans[lvl] += root->val;
        }

        m[lvl]++;

        preOrder(root->left, ans, lvl+1, m);
        preOrder(root->right, ans, lvl+1, m);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        map<int, int> m;
        int lvl = 0;

        preOrder(root, ans, lvl, m);

        for(int i=0; i<ans.size(); i++){
            ans[i] /= (m[i]);
        }

        return ans;
    }
};