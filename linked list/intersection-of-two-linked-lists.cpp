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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int length1=0,length2=0;
        while(temp1){
            temp1=temp1->next;
            length1++;
        }
        while(temp2){
            temp2=temp2->next;
            length2++;
        }
        temp1=headA;
        temp2=headB;
        if(length1>length2){
            for(int i=0;i<length1-length2;i++)temp1=temp1->next;
            while(temp1){
                if(temp1==temp2)return temp1;
                else{
                    temp1=temp1->next;
                    temp2=temp2->next;
                }
            }
        }else{
            for(int i=0;i<length2-length1;i++)temp2=temp2->next;
            while(temp1){
                if(temp1==temp2)return temp1;
                else{
                    temp1=temp1->next;
                    temp2=temp2->next;
                }
            }
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)return NULL;
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b){
            if(a==NULL)a=headB;
            else a=a->next;
            if(b==NULL)b=headA;
            else b=b->next;
        }
        return a;
    }
};
