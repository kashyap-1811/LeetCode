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
    unordered_map<long long, int> mp;
    int paths;

    void traverse(TreeNode *root, int target, long long sum) {
        if (!root)
            return;
        
        sum += root->val;
        if (mp.count(sum - target))
            paths += mp[sum - target];
        
        mp[sum]++;

        traverse(root->left, target, sum);
        traverse(root->right, target, sum);

        mp[sum]--;
        sum -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        paths = 0;
        
        traverse(root, targetSum, 0);
        return paths;
    }
};