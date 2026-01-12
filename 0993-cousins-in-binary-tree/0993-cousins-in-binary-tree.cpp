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
    bool traverse(TreeNode *root, int &x, int &y, int &depthX, int &depthY, int lvl){
        if(root == nullptr)
            return true;
        
        if(root->left && root->right && ((root->left->val == x && root->right->val == y) || (root->left->val == y && root->right->val == x)))
            return false;
        
        if(root->val == x)
            depthX = lvl;
        if(root->val == y)
            depthY = lvl;
        
        if(!traverse(root->left, x, y, depthX, depthY, lvl + 1))
            return false;
        if(!traverse(root->right, x, y, depthX, depthY, lvl + 1))
            return false;
        return true;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int depthX = 0;
        int depthY = 0;

        if(!traverse(root, x, y, depthX, depthY, 1))
            return false;
        return depthX == depthY;
    }
};