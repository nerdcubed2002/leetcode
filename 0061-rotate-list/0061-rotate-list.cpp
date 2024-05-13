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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head; // Empty list or single node

        // Calculate the length of the list
        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Handle large values of k
        k %= len;
        if (k == 0) return head;

        // Connect the tail to the head, forming a cycle
        tail->next = head;

        // Move to the new head position
        int steps = len - k;
        while (steps--) {
            tail = tail->next;
        }

        // Disconnect the cycle and return the new head
        ListNode* newHead = tail->next;
        tail->next = nullptr;
        return newHead;
    }
};