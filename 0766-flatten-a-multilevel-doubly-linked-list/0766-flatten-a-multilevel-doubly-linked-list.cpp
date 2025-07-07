/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* recurse(Node* prev, Node* curr, Node* succ) {
        curr->prev = prev;

        while (succ != nullptr) {
            if (curr->child == nullptr) {
                prev = curr;
                curr = succ;
                succ = succ->next;
            } else {
                curr->next = curr->child;
                Node* temp = curr->child;
                curr->child = nullptr;
                curr = recurse(curr, temp, temp->next);
                curr->next = succ;
                succ->prev = curr;
            }
        }

        if (curr->child != nullptr) {
            curr->next = curr->child;
            Node* temp = curr->child;
            curr->child = nullptr;
            curr = recurse(curr, temp, temp->next);
            curr->next = succ;
        }

        return curr;
    }

    Node* flatten(Node* head) {
        if (head == nullptr)
            return nullptr;

        Node* prev = nullptr;
        Node* curr = head;
        Node* succ = head->next;

        recurse(prev, curr, succ);

        return head;
    }
};