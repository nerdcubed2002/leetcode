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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        cnt=cnt/2+1;
        int data=0;
        temp=head;
        for(int i=1;i<cnt;i++)
        {
            data=temp->val;
            temp=temp->next;
        }
        return temp;
    }
};