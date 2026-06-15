/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;

        while (current != nullptr) {
            if (current->left == nullptr) {
                // Step 1: If there is no left child, visit this node and move right
                result.push_back(current->val);
                current = current->right;
            } else {
                // Step 2: Find the inorder predecessor of current
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                // Step 3: Make current the right child of its inorder predecessor
                if (predecessor->right == nullptr) {
                    predecessor->right = current; // Create temporary thread
                    current = current->left;      // Move to the left child
                } 
                // Step 4: The thread already exists, meaning we have processed the left subtree
                else {
                    predecessor->right = nullptr; // Clean up the thread
                    result.push_back(current->val); // Visit the node
                    current = current->right;     // Move to the right child
                }
            }
        }
        return result;
    }
};