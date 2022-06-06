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
        int length=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            length++;
        }
        temp=head;
        length/=2;
        while(length--){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* middleNode(ListNode* head) {
        if(!head)return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast){
            if(fast->next==NULL)return slow->next;
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
