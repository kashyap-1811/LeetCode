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
            return head;
        
        map<Node*, Node*> m1;

        Node *new_head = new Node(head->val);
        Node *temp = head->next;
        Node *new_temp = new_head;

        m1[head] = new_head;

        while(temp != nullptr){
            Node *new_node = new Node(temp->val);
            new_temp->next = new_node;

            m1[temp] = new_node;

            temp = temp->next;
            new_temp = new_temp->next;
        }

        new_temp = new_head;
        temp = head;
        while(new_temp){
            if(temp->random != nullptr){
                new_temp->random = m1[temp->random];
            } 

            temp = temp->next;
            new_temp = new_temp->next;
        }

        return new_head;
    }
};