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
    int preOrder(TreeNode* root, map<int, int>& m){
        if(!root->left && !root->right){
            m[root->val]++;
            return root->val;
        }
        
        int left=0, right=0;
        if(root->left)
            left = preOrder(root->left, m);
        if(root->right)
            right = preOrder(root->right, m);

        m[left + right + root->val]++;
        return left + right + root->val;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int>m;

        preOrder(root, m);

        vector<int>ans;

        int maxFreq = 0;
        for(auto it : m){
            if(maxFreq < it.second){
                ans.clear();
                maxFreq = it.second;
            }

            if(maxFreq == it.second)
                ans.push_back(it.first);
        }

        return ans;
    }
};