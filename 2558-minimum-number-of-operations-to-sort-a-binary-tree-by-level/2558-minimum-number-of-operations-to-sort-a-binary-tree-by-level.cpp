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
    int getMinSwaps(vector<int>& original) {
        int swaps = 0;
        vector<int> target = original;
        sort(target.begin(), target.end());

        // Map to track current positions of values
        unordered_map<int, int> pos;
        for (int i = 0; i < original.size(); i++) {
            pos[original[i]] = i;
        }

        // For each position, swap until correct value is placed
        for (int i = 0; i < original.size(); i++) {
            if (original[i] != target[i]) {
                swaps++;

                // Update position of swapped values
                int curPos = pos[target[i]];
                pos[original[i]] = curPos;
                swap(original[curPos], original[i]);
            }
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        if(root == nullptr)
            return {};

        queue<TreeNode*>q;
        vector<int>temp;
        int count = 0;

        q.push(root);
        q.push(nullptr);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == nullptr){
                count += getMinSwaps(temp);
                temp.clear();

                if(q.empty())
                    break;
                else
                    q.push(nullptr);
            }else{
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return count;
    }
};