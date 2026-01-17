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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        vector<int> ans;

        while(!s.empty()){
            TreeNode *curr = s.top();
            s.pop();

            if(curr == nullptr)
                continue;
                
            ans.push_back(curr->val);
            s.push(curr->right);
            s.push(curr->left);
        }

        return ans;
    }
};