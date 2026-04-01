class TrieNode {
public:
    vector<TrieNode*> child;
    bool isWord;

    TrieNode() {
        // Initialize all 26 lowercase children as null
        child = vector<TrieNode*>(26, nullptr);
        isWord = false;
    }

    TrieNode* add(char c) {
        // Create node only if it doesn't exist
        if (this->child[c - 'a'] == nullptr) {
            this->child[c - 'a'] = new TrieNode();
        }
        return this->child[c - 'a'];
    }
};

class Solution {
    int m, n;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    bool hasChild(TrieNode* curr) {
        // Check if current Trie node has any children
        for (int i = 0; i < 26; i++) {
            if (curr->child[i]) return true;
        }
        return false;
    }

    void addToTrie(vector<string> &words, TrieNode* root) {
        // Build Trie from given words
        for (string &word : words) {
            TrieNode* curr = root;
            for (char &c : word) {
                curr = curr->add(c);
            }
            curr->isWord = true; // mark end of word
        }
    }

    void dfs(vector<vector<char>> &board, TrieNode* curr, int i, int j,
             vector<string> &res, string &temp) {

        char c = board[i][j];

        // Stop if visited or no matching Trie path
        if (c == '#' || curr->child[c - 'a'] == nullptr) return;

        board[i][j] = '#'; // mark visited
        temp += c;

        TrieNode* par = curr;
        curr = curr->child[c - 'a'];

        // Found a word
        if (curr->isWord) {
            res.push_back(temp);
            curr->isWord = false; // avoid duplicates
        }

        // Explore all 4 directions
        for (auto& [dx, dy] : dir) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < m && y >= 0 && y < n) {
                dfs(board, curr, x, y, res, temp);
            }
        }

        // Backtrack
        board[i][j] = c;
        temp.pop_back();

        // Optimization: prune Trie if no longer needed
        if (!curr->isWord && !hasChild(curr)) {
            par->child[c - 'a'] = nullptr;
            delete curr;
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        addToTrie(words, root);

        vector<string> res;
        m = board.size();
        n = board[0].size();
        string temp = "";

        // Start DFS from every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, root, i, j, res, temp);
            }
        }

        return res;
    }
};