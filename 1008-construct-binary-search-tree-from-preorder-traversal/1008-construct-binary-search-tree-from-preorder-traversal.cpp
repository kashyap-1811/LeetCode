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
    TreeNode* traverse(vector<int> &pre, int &idx, int parVal) {
        if (idx == pre.size())
            return nullptr;
        
        TreeNode *root = new TreeNode(pre[idx]);
    
        if (idx + 1 < pre.size() && root->val > pre[idx + 1])
            root->left = traverse(pre, ++idx, root->val);
        
        if (idx + 1 < pre.size() && root->val < pre[idx + 1] && pre[idx + 1] < parVal)
            root->right = traverse(pre, ++idx, parVal);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return traverse(preorder, idx, INT_MAX);
    }
};