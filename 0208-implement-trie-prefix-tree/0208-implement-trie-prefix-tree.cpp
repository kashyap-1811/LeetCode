class TrieNode {
public:
    vector<TrieNode*> next;
    bool isEnd;

    TrieNode() {
        next.resize(26, nullptr);
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode(); 
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(char c : word) {
            int idx = c - 'a';
            if(temp->next[idx] == nullptr) {
                temp->next[idx] = new TrieNode();
            }
            temp = temp->next[idx];
        }
        temp->isEnd = true;  // mark end of word
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(char c : word) {
            int idx = c - 'a';
            if(temp->next[idx] == nullptr)
                return false;
            temp = temp->next[idx];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(char c : prefix) {
            int idx = c - 'a';
            if(temp->next[idx] == nullptr)
                return false;
            temp = temp->next[idx];
        }
        return true;
    }
};
