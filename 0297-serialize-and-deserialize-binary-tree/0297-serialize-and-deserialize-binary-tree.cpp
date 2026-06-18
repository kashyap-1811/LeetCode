/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void traverse(TreeNode *root, string &ans) {
        if (root == nullptr) {
            ans += "null ";
            return;
        }
        
        ans += to_string(root->val);
        ans += " ";
        traverse(root->left, ans);
        traverse(root->right, ans);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        traverse(root, ans);
        return ans;    
    }
    
    TreeNode* recreate(stringstream &ss) {
        string word;
        ss >> word;

        if (word == "null")
            return nullptr;
        
        TreeNode *root = new TreeNode(stoi(word));
        root->left = recreate(ss);
        root->right = recreate(ss);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return recreate(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));