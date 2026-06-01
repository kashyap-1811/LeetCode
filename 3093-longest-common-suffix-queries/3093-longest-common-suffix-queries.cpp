class TrieNode {
public:
    TrieNode* child[26];
    int idx;

    TrieNode() {
        idx = -1;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++)
            delete child[i];
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(const string& ss, int stringIdx, vector<string>& wordsContainer) {
        TrieNode* temp = root;

        for (int i = ss.size() - 1; i >= 0; i--) {
            int ch = ss[i] - 'a';

            if (temp->idx == -1 || ss.size() < wordsContainer[temp->idx].size()) {
                temp->idx = stringIdx;
            }

            if (temp->child[ch] == nullptr)
                temp->child[ch] = new TrieNode();

            temp = temp->child[ch];
        }

        if (temp->idx == -1 || ss.size() < wordsContainer[temp->idx].size()) {
            temp->idx = stringIdx;
        }
    }

    int longestSuffix(const string& ss) {
        TrieNode* temp = root;

        for (int i = ss.size() - 1; i >= 0; i--) {
            int ch = ss[i] - 'a';

            if (temp->child[ch] == nullptr)
                break;

            temp = temp->child[ch];
        }

        return temp->idx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie T;

        for (int i = 0; i < wordsContainer.size(); i++) {
            T.insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;

        for (string& q : wordsQuery) {
            ans.push_back(T.longestSuffix(q));
        }

        return ans;
    }
};