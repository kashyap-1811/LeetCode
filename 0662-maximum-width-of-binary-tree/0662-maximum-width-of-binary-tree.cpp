/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unsigned long long ans;
    vector<int> dp;

    void traverse(TreeNode* root, int level, unsigned long long width) {
        if (!root)
            return;

        if (level > dp.size())
            dp.push_back(width);
        else
            ans = max(ans, width - dp[level - 1]);

        traverse(root->left, level + 1, 2 * width - 1);
        traverse(root->right, level + 1, 2 * width);
    }

    int widthOfBinaryTree(TreeNode* root) {
        traverse(root, 1, 1);
        return ans + 1;
    }
};