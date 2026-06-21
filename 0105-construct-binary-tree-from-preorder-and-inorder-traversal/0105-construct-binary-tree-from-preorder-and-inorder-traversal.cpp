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
    int i;
    int j;
    unordered_set<int> st;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *new_node = new TreeNode(preorder[i]);
        st.insert(preorder[i]);

        // cout << i << " " << j << " " << new_node->val << endl;

        if (i == preorder.size())
            return new_node;

        // left child 
        if (preorder[i] != inorder[j]) {
            i++;
            new_node->left = build(preorder, inorder);
        }else {
            i++;
            j++;
        }

        // right child
        if (j < inorder.size() && !st.count(inorder[j])) 
            new_node->right = build(preorder, inorder);
        else
            j++;

        return new_node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        i = 0;
        j = 0;
        return build(preorder, inorder);
    }
};