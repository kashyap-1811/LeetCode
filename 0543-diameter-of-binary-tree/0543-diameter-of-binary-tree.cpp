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
    int diameter(TreeNode* root, int& maX){ //pair stores <int->till max answer, int->deepest leaf>
        if(!root) return 0;

        int left = diameter(root->left, maX);
        int right = diameter(root->right, maX);

        maX = max(maX, abs(left + right));

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maX = 0;
        diameter(root, maX);

        return maX;
    }
};