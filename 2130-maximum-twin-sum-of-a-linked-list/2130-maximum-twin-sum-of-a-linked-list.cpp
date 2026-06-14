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
    ListNode* reverse(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *succ = curr ? curr->next : nullptr;

        while (succ != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = succ;
            succ = succ->next;
        }

        curr->next = prev;
        return curr;
    }

    int pairSum(ListNode* head) {
        int n = 0;
        ListNode *curr = head;

        while (curr != nullptr) {
            curr = curr->next;
            n++;
        }

        curr = head;
        ListNode *prev = nullptr;
        int a = 1;
        while (a <= n / 2) {
            prev = curr;
            curr = curr->next;
            a++;
        }
        prev->next = nullptr;

        ListNode *tail = reverse(curr);
        ListNode *front = head;

        int maxSum = 0;
        while (front != nullptr) {
            maxSum = max(maxSum, front->val + tail->val);
            front = front->next;
            tail = tail->next;
        }

        return maxSum;
    }
};