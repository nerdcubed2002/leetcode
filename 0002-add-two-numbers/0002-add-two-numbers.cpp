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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode;
        ListNode* temp=dummy;
        int sum=0,carry=0;
        while(l1||l2)
        {
           sum=carry;
           if(l1)
           sum+=l1->val;
           if(l2)
           sum+=l2->val;
           carry=sum/10;
           ListNode* s=new ListNode(sum%10);
           temp->next=s;
           temp=s; 
           if(l1)
           l1=l1->next;
           if(l2)
           l2=l2->next;
        }
        if(carry)
        {
         ListNode* s=new ListNode(carry);
         temp->next=s;   
        }

        return dummy->next;
    }
};