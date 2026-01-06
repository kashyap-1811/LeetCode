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
    void preOrder(TreeNode *root, map<int, int> &m, int lvl){
        if(root == nullptr)
            return;
        
        m[lvl] += root->val;
        preOrder(root->left, m, lvl+1);
        preOrder(root->right, m, lvl+1);
    }

    int maxLevelSum(TreeNode* root) {
        map<int, int> m;
        preOrder(root, m, 1);

        int maxSum = m[1];
        int x = 1;

        for(auto &p : m){
            if(p.second > m[x]){
                x = p.first;
            }
        }

        return x;
    }
};