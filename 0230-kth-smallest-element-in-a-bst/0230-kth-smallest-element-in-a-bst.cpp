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
    int traverse(TreeNode *root, int k, int &idx) {
        if (root == nullptr)
            return -1;

        int ans;
        if ((ans = traverse(root->left, k, idx)) != -1)
            return ans;

        idx++;
        if (k == idx)
            return root->val;

        if ((ans = traverse(root->right, k, idx)) != -1)
            return ans;

        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int idx = 0;
        return traverse(root, k, idx);
    }
};