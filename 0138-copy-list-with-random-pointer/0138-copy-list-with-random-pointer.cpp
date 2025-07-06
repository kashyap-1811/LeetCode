/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        map<int, Node*>m; //it stores <random_index, random_Pointer>
        map<Node*, int>values; //to store the value that which Node address is at which address
        
        Node *new_head = new Node(head->val);
        Node *curr = new_head;
        Node *temp = head->next;
        int idx = 0;

        values[head] = idx;
        m[idx] = new_head;

        while(temp != nullptr)
        {
            curr->next = new Node(temp->val);
            values[temp] = ++idx;
            temp = temp->next;
            curr = curr->next;
            m[idx] = curr; //to store the Node* at next idx
        }

        temp = head;
        curr = new_head;
        while(temp != nullptr)
        {
            if(temp->random == nullptr)
                curr->random = nullptr;
            else{
                idx = values[temp->random];
                curr->random = m[idx];
            }

            temp = temp->next;
            curr = curr->next;
        }

        return new_head;
    }
};