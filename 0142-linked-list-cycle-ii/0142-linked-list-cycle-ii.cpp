/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       unordered_set<ListNode*>s;
       ListNode* temp = head;

       while(temp != nullptr){
            if(s.count(temp))
                return temp;
            else
                s.insert({temp});
            temp = temp->next;
       }

       return nullptr;
    }
};