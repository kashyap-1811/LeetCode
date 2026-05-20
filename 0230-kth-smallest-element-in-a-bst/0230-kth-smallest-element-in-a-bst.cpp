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
    void recurse(TreeNode* root, int &idx, int &k, int &ans) {
        if(root == nullptr)
            return;
        
        recurse(root->left, idx, k, ans);
        
        idx++;
        if(idx == k) {
            ans = root->val;
            return;
        }

        recurse(root->right, idx, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int idx = 0;
        int ans;

        recurse(root, idx, k, ans);
        return ans;
    }
};