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
    int maxSum = INT_MIN;

    int traverse(TreeNode *root) {
        if (root == nullptr)
            return -2000;
        
        int left = traverse(root->left);
        int right = traverse(root->right);

        int maxVal = max({root->val, left + root->val, right + root->val});
        maxSum = max({maxSum, maxVal, left + right + root->val});
        return maxVal;
    }

    int maxPathSum(TreeNode* root) {
        traverse(root);
        return maxSum;
    }
};