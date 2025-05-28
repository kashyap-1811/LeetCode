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
    Node * clone(Node* node, map<int, Node*>&m)
    {
        if(node == nullptr)
            return nullptr;

        Node* new_node = new Node(node->val);
        m.insert({new_node->val, new_node});

        vector<Node*> neighbors;
        for(int i=0; i<node->neighbors.size(); i++)
        {
            if(m.find(node->neighbors[i]->val) != m.end())
                neighbors.push_back(m[node->neighbors[i]->val]);
            else
                neighbors.push_back(clone(node->neighbors[i], m));
        }

        new_node->neighbors = neighbors;

        return new_node;
    }

    Node* cloneGraph(Node* node) {
        map<int, Node*>m;
        return clone(node, m);
    }
};