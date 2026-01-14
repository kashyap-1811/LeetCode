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
    void add(TreeNode *root, vector<int>&arr, int &level ,int currLevel)
    {
        if(root == nullptr)
            return;
        
        if(currLevel > level)
        {
            arr.push_back(root->val);
            level = currLevel;
        }
        add(root->right, arr, level, currLevel+1);
        add(root->left, arr, level, currLevel+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>arr;
        int level = 0;

        add(root, arr, level, 1);

        return arr;
    }
};