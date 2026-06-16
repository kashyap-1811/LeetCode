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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        int ansLvl = 0;
        int ansSum = INT_MIN;
        int currLvl = 1;
        int currSum = 0;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (curr == nullptr) {
                if (ansSum < currSum) {
                    ansSum = currSum;
                    ansLvl = currLvl;
                }

                currSum = 0;
                currLvl++;

                if (!q.empty())
                    q.push(nullptr);
                else
                    break;
            } else {
                currSum += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }

        return ansLvl;
    }
};