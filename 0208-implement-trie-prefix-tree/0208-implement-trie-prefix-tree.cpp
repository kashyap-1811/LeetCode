class TrieNode {
public:
    vector<TrieNode*> next;
    vector<int> alphabets; // -1 -> not in trie, 0 -> in trie, 1 -> end alphabet

    TrieNode() {
        next.resize(26, nullptr);
        alphabets.resize(26, -1);
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode(); 
    }

    // helper to free memory
    void freeNode(TrieNode* node) {
        if (!node) return;
        for (TrieNode* child : node->next) {
            freeNode(child);
        }
        delete node;
    }

    ~Trie() {
        freeNode(root);
    }
    
    void insert(const string& word) {
        TrieNode* temp = root;

        for (int i = 0; i < (int)word.size(); i++) {
            int idx = word[i] - 'a';

            if (temp->next[idx] == nullptr) {
                temp->alphabets[idx] = 0; // mark as "in trie"
                temp->next[idx] = new TrieNode();
            }

            if (i == word.size() - 1) {
                temp->alphabets[idx] = 1; // mark as "end alphabet"
            }

            temp = temp->next[idx];
        }
    }
    
    bool search(const string& word) const {
        TrieNode* temp = root;

        for (int i = 0; i < (int)word.size(); i++) {
            int idx = word[i] - 'a';

            if (temp->alphabets[idx] == -1) {
                return false;
            }

            if (i == word.size() - 1) {
                return temp->alphabets[idx] == 1;
            }

            temp = temp->next[idx];
        }

        return false; // shouldn't reach here
    }
    
    bool startsWith(const string& prefix) const {
        TrieNode* temp = root;

        for (char c : prefix) {
            int idx = c - 'a';

            if (temp->alphabets[idx] == -1) {
                return false;
            }
            temp = temp->next[idx];
        }

        return true;
    }
};
