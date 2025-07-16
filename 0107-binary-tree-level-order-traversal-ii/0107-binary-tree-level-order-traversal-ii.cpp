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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr)
            return {};

        queue<TreeNode*>q;
        vector<vector<int>>ans;
        vector<int>temp;

        q.push(root);
        q.push(nullptr);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == nullptr){
                ans.push_back(temp);
                temp.clear();

                if(q.empty())
                    break;
                else{
                    q.push(nullptr);
                }
            }else{
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};