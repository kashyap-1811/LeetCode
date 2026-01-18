/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode *root, TreeNode *par, int dist, int &k, vector<int> &ans, unordered_map<TreeNode*, TreeNode*> &parent){
        if(root == nullptr)
            return;
        
        if(dist == k){
            ans.push_back(root->val);
            return;
        }

        if(root->left != par)
            traverse(root->left, root, dist + 1, k, ans, parent);
        if(root->right != par)
            traverse(root->right, root, dist + 1, k, ans, parent);
        if(parent[root] != par)
            traverse(parent[root], root, dist + 1, k, ans, parent);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*>q;
        q.push(root);
        parent[root] = nullptr;

        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();

            if(curr->left){
                q.push(curr->left);
                parent[curr->left] = curr;
            }
            if(curr->right){
                q.push(curr->right);
                parent[curr->right] = curr;
            }
        }

        vector<int> ans;
        traverse(target, nullptr, 0, k, ans, parent);
        return ans;
    }
};