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
    TreeNode* traverse(TreeNode *root, int &lastVal) {
        if (root == nullptr)
            return nullptr;

        TreeNode *right = traverse(root->right, lastVal);

        root->val += lastVal;        
        lastVal = root->val;
        
        TreeNode *left = traverse(root->left, lastVal);

        return root;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int lastVal = 0;
        return traverse(root, lastVal);
    }
};