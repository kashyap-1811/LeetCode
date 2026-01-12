class Solution {
public:
    TreeNode* parentX = nullptr;
    TreeNode* parentY = nullptr;
    int depthX = -1, depthY = -1;

    void dfs(TreeNode* node, TreeNode* parent, int depth, int x, int y) {
        if (!node) return;

        if (node->val == x) {
            parentX = parent;
            depthX = depth;
        }
        if (node->val == y) {
            parentY = parent;
            depthY = depth;
        }

        // EARLY STOP
        if (depthX != -1 && depthY != -1) return;

        dfs(node->left, node, depth + 1, x, y);
        dfs(node->right, node, depth + 1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr, 0, x, y);
        return depthX == depthY && parentX != parentY;
    }
};
