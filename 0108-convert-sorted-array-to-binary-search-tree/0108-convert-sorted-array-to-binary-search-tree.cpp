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
    TreeNode* recurse(vector<int> &nums, int st, int end) {
        int mid = (st + end) / 2;
        TreeNode *new_node = new TreeNode(nums[mid]);

        if(st == end)
            return new_node;
        
        if(st != mid)
            new_node->left = recurse(nums, st, mid-1);
        new_node->right = recurse(nums, mid+1, end);

        return new_node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recurse(nums, 0, nums.size()-1);
    }
};