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
    // Helper function to check the height of each subtree and determine if it's balanced.
    // Returns the height if the subtree is balanced, or -1 if it is not.
    int check(TreeNode *root) {
        // Base case: if the node is null, height is 0
        if (root == nullptr)
            return 0;

        // Recursively calculate the height of the left subtree
        int leftHeight = check(root->left);
        // Recursively calculate the height of the right subtree
        int rightHeight = check(root->right);

        // If either subtree is unbalanced, propagate -1 up to indicate imbalance
        if (leftHeight == -1 || rightHeight == -1)
            return -1;
        
        // If the current node is unbalanced (height difference > 1), return -1
        if (abs(leftHeight - rightHeight) > 1)
            return -1;
            
        // If balanced, return the height of this subtree
        return max(leftHeight, rightHeight) + 1;
    }

    // Main function to determine if the entire tree is balanced
    bool isBalanced(TreeNode* root) {
        // An empty tree is balanced
        if (root == nullptr)
            return true;

        // Call the check function, and return true if the tree is balanced
        return check(root) != -1;
    }
};
