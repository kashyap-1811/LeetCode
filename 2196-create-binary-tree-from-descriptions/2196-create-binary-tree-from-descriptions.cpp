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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> notRoot;

        for(auto d : descriptions) {
            int p = d[0], c = d[1];
            bool isLeftChild = d[2];

            TreeNode *pNode, *cNode;
            if (mp.count(p))
                pNode = mp[p];
            else {
                pNode = new TreeNode(p);
                mp[p] = pNode;
            }

            if (mp.count(c))
                cNode = mp[c];
            else {
                cNode = new TreeNode(c);
                mp[c] = cNode;
            }
            
            if (isLeftChild)
                pNode->left = cNode;
            else
                pNode->right = cNode;

            notRoot.insert(c);
        }

        for(auto d : descriptions) {
            if(!notRoot.count(d[0]))
                return mp[d[0]];
        } 

        return nullptr;
    }
};