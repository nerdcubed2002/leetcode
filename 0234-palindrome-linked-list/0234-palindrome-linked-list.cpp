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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next&&fast->next->next)
        {
           slow=slow->next;
           fast=fast->next->next;
        }
        ListNode* mid=slow;
        ListNode* newhead=rs(mid->next);
        slow=head;
        fast=newhead;
        while(fast)
        {
            if(slow->val!=fast->val)
            {
               rs(newhead);
               return false; 
            }
            slow=slow->next;
            fast=fast->next;
        }
        rs(newhead);
        return true;
    }

    ListNode* rs(ListNode* head)
    {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* front=nullptr;
        while(temp)
        {
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};