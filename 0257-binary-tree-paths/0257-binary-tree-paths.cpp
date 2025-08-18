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
    void preOrder(TreeNode *root, vector<string>& ans, string temp){
        temp += to_string(root->val);
        temp += "->";
        
        if(root->left == nullptr && root->right == nullptr){
            temp.pop_back();
            temp.pop_back();
            ans.push_back(temp);
            return;
        }

        if(root->left)  preOrder(root->left, ans, temp);
        
        if(root->right) preOrder(root->right, ans, temp);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";

        preOrder(root, ans, temp);

        return ans;
    }
};