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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //checking if linked list size is less than k
        ListNode* temp=head;
        for(int i=0;i<k;i++){
            if(!temp)return head;
            temp=temp->next;
        }
        //reversing k nodes
        ListNode *prev=NULL,*curr=head,*next;
        int count=0;
        while(curr && count<k){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        //reversing next k nodes
        if(next){
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||k==1)return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode *prev=dummy,*curr=dummy,*next=dummy;
        int count=0;
        while(curr->next!=NULL){
            curr=curr->next;
            count++;
        }
        while(count>=k){
            curr=prev->next;
            next=curr->next;
            for(int i=1;i<k;i++){
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
            }
            prev=curr;
            count-=k;
        }
        return dummy->next;
    }
};
