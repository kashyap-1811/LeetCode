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
    void preOrder(TreeNode* root, queue<TreeNode*>& q){
        if(root == nullptr)
            return;

        q.push(root);
        preOrder(root->left, q);
        preOrder(root->right, q);
    }

    void flatten(TreeNode* root) {
        queue<TreeNode*>q;

        preOrder(root, q);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            temp->left = nullptr;
            if(!q.empty())
                temp->right = q.front();
        }
    }
};