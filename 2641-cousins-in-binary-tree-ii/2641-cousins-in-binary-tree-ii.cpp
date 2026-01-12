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
    vector<int> lvlSum;

    void traverse(TreeNode *root, int lvl, int siblingsValue){
        if(root == nullptr)
            return;
        
        root->val = lvlSum[lvl] - root->val - siblingsValue;

        int rightSibling = root->right ? root->right->val : 0;
        int leftSibling = root->left ? root->left->val : 0;
        
        traverse(root->left, lvl + 1, rightSibling);
        traverse(root->right, lvl + 1, leftSibling);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);   
        q.push(nullptr);   
        int currLvlSum = 0;

        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();

            if(curr == nullptr){
                lvlSum.push_back(currLvlSum);
                currLvlSum = 0;
                if(q.empty())
                    break;
                q.push(nullptr);
            }else{
                currLvlSum += curr->val;
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        } 

        for(int i : lvlSum)
            cout << i << " ";
        traverse(root, 0, 0);
        return root;
    }
};