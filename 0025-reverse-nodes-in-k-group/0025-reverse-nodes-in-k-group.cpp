/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverse(ListNode* root) {
        if (root == nullptr || root->next == nullptr)
            return;

        ListNode* prev = nullptr;
        ListNode* curr = root;
        ListNode* succ = root->next;

        while (succ != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = succ;
            succ = succ->next;
        }

        curr->next = prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* kthNode = head;
        ListNode* succ = head->next;
        int count = 0;

        while (succ != nullptr) {
            count++;

            if (count == k) {
                if (prev != nullptr)
                    prev->next = nullptr;

                curr->next = nullptr;
                reverse(kthNode);

                if (prev != nullptr)
                    prev->next = curr;
                else
                    head = curr;

                kthNode->next = succ;
                prev = kthNode;
                kthNode = succ;
                curr = succ;
                succ = succ->next;

                count = 0;
            } else {
                curr = succ;
                succ = succ->next;
            }
        }

        count++;

        if (count == k) {
            if (prev != nullptr)
                prev->next = nullptr;

            curr->next == nullptr;
            reverse(kthNode);

            if (prev != nullptr)
                prev->next = curr;
            else
                head = curr;

            kthNode->next = succ;
        }

        return head;
    }
};