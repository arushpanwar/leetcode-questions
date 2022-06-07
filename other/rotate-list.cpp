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
        if(!head)return head;
        ListNode *temp=head,*fast=head,*slow=head,*newHead;
        int length=0;
        while(temp){
            temp=temp->next;
            length++;
        }
        k%=length;
        while(k--)fast=fast->next;
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        newHead=slow->next;
        slow->next=NULL;
        fast->next=head;
        return newHead;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        ListNode *start=head,*last=head,*newNode;
        int length=1;
        while(last->next){
            last=last->next;
            length++;
        }
        last->next=head;
        k%=length;
        k=length-k;
        for(int i=1;i<k;i++)start=start->next;
        newNode=start->next;
        start->next=NULL;
        return newNode;
    }
};
