/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        
        unordered_map<int, Node*> mp;

        queue<Node*> q;
        mp[1] = new Node(1);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            int val = curr->val;

            for (auto nei : curr->neighbors) {
                if (mp.count(nei->val))
                    mp[val]->neighbors.push_back(mp[nei->val]);
                else {
                    Node *new_node = new Node(nei->val);
                    mp[val]->neighbors.push_back(new_node);
                    mp[nei->val] = new_node;
                    q.push(nei);
                }
            }
        }

        return mp[1];
    }
};